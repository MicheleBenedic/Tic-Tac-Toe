/*
 * Tris (Tic Tac Toe) - Progetto per il corso EDUBE C Essentials 1
 *
 * TODO per completare il gioco:
 *  1. Gestire il turno dei due giocatori (X e O).
 *  2. Leggere la mossa da tastiera (riga/colonna) e validarla:
 *     dentro i limiti del tabellone e su una casella libera.
 *  3. Dopo ogni mossa, controllare se c'e' un vincitore (riga, colonna
 *     o diagonale completa) oppure un pareggio (tabellone pieno).
 *  4. Ripetere il ciclo finche' la partita non finisce, poi stampare
 *     il risultato finale.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

static const int BOARD_SIZE = 3;

typedef struct {
    long x_axis, y_axis;
} action;

static void init_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            board[row][col] = ' ';
        }
    }
}

static void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
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

/* language server: Function 'player_move' has cognitive complexity
of 38 (threshold 25), perché? */
static void player_move(bool which_player, char board[BOARD_SIZE][BOARD_SIZE]) {
    while (true) {
        action move;
        move.x_axis = -1;
        move.y_axis = -1;
        char input[32];
        char *endptr;
        print_board(board);
        if (!which_player) {
            puts("Giocatore 1, inserisci le coordinate della tua mossa:");
            while ((move.x_axis < 0 || move.x_axis > 2) && (move.y_axis < 0 || move.y_axis > 2)) {
                printf("asse x: ");
                if (fgets(input, sizeof(input), stdin) != NULL) {
                    move.x_axis = strtol(input, &endptr, 10);
                }
                printf("\nasse y: ");
                if (fgets(input, sizeof(input), stdin) != NULL) {
                    move.y_axis = strtol(input, &endptr, 10);
                }
            }
            while (board[move.x_axis][move.y_axis] == ' ') {
                puts("Coordinate già occupate, inseriscine altre!");
                board[move.x_axis][move.y_axis] = 'X';
                which_player = ((!which_player) != 0);
            }
        } else {
            puts("Giocatore 2, inserisci le coordinate della tua mossa:");
            while ((move.x_axis < 0 || move.x_axis > 2) && (move.y_axis < 0 || move.y_axis > 2)) {
                printf("asse x: ");
                if (fgets(input, sizeof(input), stdin) != NULL) {
                    move.x_axis = strtol(input, &endptr, 10);
                }
                printf("\nasse y: ");
                if (fgets(input, sizeof(input), stdin) != NULL) {
                    move.y_axis = strtol(input, &endptr, 10);
                }
            }
            while (board[move.x_axis][move.y_axis] == ' ') {
                puts("Coordinate già occupate, inseriscine altre!");
                board[move.x_axis][move.y_axis] = 'O';
                which_player = ((!which_player) != 0);
            }
        }
    }
}

static bool game_result(bool status, char board[BOARD_SIZE][BOARD_SIZE]) {
    status = true;
    
    for (int i = 0; i < BOARD_SIZE - 1; ++i) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            status = false;
            return status;
        }
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            status = false;
            return status;
        }
    }

    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        status = false;
    }

    if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        status = false;
    }

    return status;
}

int main() {
    bool players = false;
    bool still_playing = true;
    char play_board[BOARD_SIZE][BOARD_SIZE];
    init_board(play_board);
    printf("\n");

    /* language server: This loop is infinite; none of its condition variables (still_playing)
    are updated in the loop body, non è vero, perché protesta? */
    while (still_playing) {
        player_move(players, play_board);
        still_playing = game_result(still_playing, play_board);
    }

    return 0;
}
