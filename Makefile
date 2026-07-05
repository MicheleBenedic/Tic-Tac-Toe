CC      := clang-22
STD     := -std=c23
WARN    := -Wall -Wextra -Wpedantic -Wconversion
SAN     := -fsanitize=address -fsanitize=undefined
CFLAGS  := $(STD) $(WARN) -g
SRC     := src/main.c
BIN     := tic-tac-toe

.PHONY: all run release clean format tidy compdb

all: $(BIN)

$(BIN): $(SRC)
	$(CC) $(CFLAGS) $(SAN) $(SRC) -o $(BIN)

run: all
	./$(BIN)

release: CFLAGS := $(STD) $(WARN) -O2
release: $(BIN)

format:
	clang-format -i $(SRC)

tidy: compdb
	clang-tidy $(SRC) -- $(STD)

compdb:
	python3 gen_compdb.py

clean:
	rm -f $(BIN) compile_commands.json
