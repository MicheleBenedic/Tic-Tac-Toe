CC      := clang-22
STD     := -std=c23
WARN    := -Wall -Wextra -Wpedantic -Wconversion
SAN     := -fsanitize=address -fsanitize=undefined
CFLAGS  := $(STD) $(WARN) -g
SRC     := src/main.c src/game.c
BIN     := tic-tac-toe
BIN_D	:= tic-tac-toe-DEBUG
BIN_DIR := bin
FILE_F	:= format_report
FILE_L	:= linting_report

# --- Unity / test ---
TEST_DIR  := tests
UNITY_DIR := $(TEST_DIR)/unity
UNITY_SRC := $(UNITY_DIR)/unity.c
TEST_SRC  := $(wildcard $(TEST_DIR)/*.c)
# Tutta la logica tranne main.c: la main() dei test la fornisce test_game.c
GAME_SRC  := $(filter-out src/main.c,$(SRC))
TEST_BIN  := $(BIN_DIR)/test_game

.PHONY: all run release test clean format tidy compdb

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

# Compila ed esegue la suite Unity (con sanitizer, come la build di debug)
test: $(TEST_BIN)
	./$(TEST_BIN)

$(TEST_BIN): $(TEST_SRC) $(GAME_SRC) $(UNITY_SRC) | $(BIN_DIR)
	$(CC) $(CFLAGS) $(SAN) -I$(TEST_DIR) $^ -o $@

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
	rm -f $(BIN) $(BIN_D) $(BIN_DIR)/$(BIN) $(TEST_BIN) compile_commands.json
