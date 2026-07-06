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
static const int MAX_CHAR_INPUT = 1;

typedef struct {
    int x_axis, y_axis;
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

static char player_move(bool which_player, char board[BOARD_SIZE][BOARD_SIZE]) {
    while (true) {
        action move;
        char input = 0;
        print_board(board);
        if (!which_player) {
            puts("Giocatore 1, inserisci le coordinate della tua mossa:");
            printf("asse x: ");
            move.x_axis = fgets( &input, 1, stdin);
            printf("\nasse y: ");
            move.y_axis = fgets(&input,  1, stdin)
            
        } else {
            puts("Giocatore 2, inserisci le coordinate della tua mossa:");
            printf("asse x: ");
            scanf("%i", &move.x_axis);
            printf("\nasse y: ");
            scanf("%i", &move.y_axis);
        }
    }
}

int main() {
    bool players = false;
    char play_board[BOARD_SIZE][BOARD_SIZE];
    init_board(play_board);
    printf("\n");

    /* bool game = true;
    while (game) {
        print_board(play_board);
        if (!players) {
            
        } else {
            
        }

        if ( caselle tutte piene ) {
            if ( un giocatore ha vinto ) {
                printf("Il giocatore x ha vinto la partita!\n");
                game = false;
            } else {
                puts("La partita è terminata in pareggio...");
                game = false;
            }
        }

    } */

    return 0;
}
