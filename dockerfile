# syntax=docker/dockerfile:1
# Doc: https://docs.docker.com/build/building/multi-stage/

# --- STAGE 1: builder - qui compiliamo come fai tu in locale ---
FROM ubuntu:24.04 AS builder

# Installiamo esattamente quello che usi tu + valgrind per i test memoria
# Doc: https://packages.ubuntu.com/ - clang, make, valgrind
RUN apt-get update && apt-get install -y \
    make \
    valgrind \
    lsb-release \
    wget \
    gpg \
    software-properties-common \
    ca-certificates \
    && rm -rf /var/lib/apt/lists/*

# Scarica ed esegue lo script per installare LLVM 22
RUN wget -q https://apt.llvm.org/llvm.sh -O /tmp/llvm.sh \
    && chmod +x /tmp/llvm.sh \
    && /tmp/llvm.sh 22 \
    && rm /tmp/llvm.sh

WORKDIR /app

# Copiamo prima solo Makefile e sorgenti per sfruttare la cache di Docker
COPY Makefile ./
COPY src/ ./src/
COPY tests/ ./tests/
COPY lib/ ./lib/

# Compila. Usa i target che già hai
# Se il tuo Makefile ha 'test', lancia anche quello qui per fallire subito se rotto
RUN make clean && make test && make release

# --- STAGE 2: runtime - immagine finale piccola, solo il binario ---
FROM ubuntu:24.04 AS runtime

WORKDIR /app

# Prendiamo SOLO il binario dallo stage builder
COPY --from=builder /app/bin/tic-tac-toe ./bin/tic-tac-toe

# Il container quando parte lancia il gioco
CMD ["./bin/tic-tac-toe"]
