#include "game.h"

#include <stdio.h>
#include <stdlib.h>

void init_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            board[row][col] = ' ';
        }
    }
}

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            printf(" %c ", board[row][col]);
            if (col < BOARD_SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (row < BOARD_SIZE - 1) {
            printf("-----------\n");
        }
    }
}

bool read_index(const char *label, int *out) {
    char input[32];
    char *endptr;

    printf("%s: ", label);
    if (fgets(input, sizeof(input), stdin) == NULL) {
        return false;
    }

    long value = strtol(input, &endptr, 10);
    if (endptr == input || (*endptr != '\n' && *endptr != '\0')) {
        return false;
    }
    if (value < 0 || value >= BOARD_SIZE) {
        return false;
    }

    *out = (int)value;
    return true;
}

int player_number(char marker) {
    return (marker == 'X') ? 1 : 2;
}

void player_move(char marker, char board[BOARD_SIZE][BOARD_SIZE]) {
    print_board(board);
    printf("Player %d (%c), insert the coordinates of your move:\n",
           player_number(marker), marker);

    while (true) {
        action move;

        if (!read_index("row (0-2)", &move.row) ||
            !read_index("column (0-2)", &move.col)) {
            puts("Coordinates not available, try again.");
            continue;
        }
        if (board[move.row][move.col] != ' ') {
            puts("Square already occupied, insert new coordinates.");
            continue;
        }

        board[move.row][move.col] = marker;
        return;
    }
}

char winner(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[i][0] != ' ' &&
            board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
        if (board[0][i] != ' ' &&
            board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }
    if (board[0][0] != ' ' &&
        board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] != ' ' &&
        board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    return ' ';
}

bool board_full(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            if (board[row][col] == ' ') {
                return false;
            }
        }
    }
    return true;
}
