CC      := clang-22
STD     := -std=c23
WARN    := -Wall -Wextra -Wpedantic -Wconversion
SAN     := -fsanitize=address -fsanitize=undefined
CFLAGS  := $(STD) $(WARN) -g
SRC     := src/main.c
BIN     := tic-tac-toe
BIN_D	:= tic-tac-toe-DEBUG
BIN_DIR := bin
FILE_F	:= format_report
FILE_L	:= linting_report

.PHONY: all run release clean format tidy compdb

all: $(BIN)

$(BIN): $(SRC)
	$(CC) $(CFLAGS) $(SAN) $(SRC) -o $(BIN_D)

run: all
	./$(BIN_D)

release: CFLAGS := $(STD) $(WARN) -O2
release: $(BIN_DIR)/$(BIN)

$(BIN_DIR)/$(BIN): $(SRC) | $(BIN_DIR)
	$(CC) $(CFLAGS) $(SRC) -o $@

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

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
	rm -f $(BIN) $(BIN_DIR)/$(BIN) compile_commands.json
