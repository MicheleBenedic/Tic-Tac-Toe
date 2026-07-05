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

static const int BOARD_SIZE = 3;

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

int main() {
    char play_board[BOARD_SIZE][BOARD_SIZE];
    init_board(play_board);
    print_board(play_board);
    printf("\n");
    return 0;
}
