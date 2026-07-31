#ifndef GAME_H
#define GAME_H

#include <stdbool.h>

enum { BOARD_SIZE = 3 };

typedef struct {
    int row, col;
} action;

/* Logica pura: testabile senza I/O */
void init_board(char board[BOARD_SIZE][BOARD_SIZE]);
int player_number(char marker);
char winner(char board[BOARD_SIZE][BOARD_SIZE]);
bool board_full(char board[BOARD_SIZE][BOARD_SIZE]);

/* Interazione con l'utente: dipende da stdin/stdout */
void print_board(char board[BOARD_SIZE][BOARD_SIZE]);
bool read_index(const char *label, int *out);
void player_move(char marker, char board[BOARD_SIZE][BOARD_SIZE]);

#endif /* GAME_H */
