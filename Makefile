CC      := clang-22
STD     := -std=c23
WARN    := -Wall -Wextra -Wpedantic -Wconversion
SAN     := -fsanitize=address -fsanitize=undefined
CFLAGS  := $(STD) $(WARN) -g
SRC     := src/main.c
BIN     := tic-tac-toe
FILE_F	:= format_report
FILE_L	:= linting_report

.PHONY: all run release clean format tidy compdb

all: $(BIN)

$(BIN): $(SRC)
	$(CC) $(CFLAGS) $(SAN) $(SRC) -o $(BIN)

run: all
	./$(BIN)

release: CFLAGS := $(STD) $(WARN) -O2
release: $(BIN)

format:
	clang-format-22 -i $(SRC) > $(FILE_F) 
	code $(FILE_F)

lint: compdb
	clang-tidy-22 $(SRC) -- $(STD) > $(FILE_L)
	code $(FILE_L)

compdb:
	python3 gen_compdb.py

push:
	@./gitpush.sh

clean:
	rm -f $(BIN) compile_commands.json
