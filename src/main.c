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
    int row, col;
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

static bool read_index(const char *label, int *out) {
    char input[32];
    char *endptr;

    printf("%s: ", label);
    if (fgets(input, sizeof(input), stdin) == NULL) {
        return false;
    }

    long value = strtol(input, &endptr, 10);
    if (endptr == input || (*endptr != '\n' && *endptr != '\0')) {
        return false; /* non era un numero */
    }
    if (value < 0 || value >= BOARD_SIZE) {
        return false; /* fuori dai limiti */
    }

    *out = (int)value;
    return true;
}

static int player_number(char marker) {
    return (marker == 'X') ? 1 : 2;
}

/* language server: Function 'player_move' has cognitive complexity
of 38 (threshold 25), perché? */
static void player_move(char marker, char board[BOARD_SIZE][BOARD_SIZE]) {
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

/* Ritorna il carattere del vincitore ('X' o 'O') se una linea è
 * completa con lo stesso simbolo non vuoto, altrimenti ' '. */
static char winner(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        /* righe */
        if (board[i][0] != ' ' &&
            board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
        /* colonne */
        if (board[0][i] != ' ' &&
            board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }

    /* diagonali */
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

/* True se non ci sono più caselle libere. */
static bool board_full(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            if (board[row][col] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char play_board[BOARD_SIZE][BOARD_SIZE];
    init_board(play_board);
    printf("\n");

    char current = 'X'; /* segno del giocatore di turno */
    char won = ' ';

    while (true) {
        player_move(current, play_board);

        won = winner(play_board);
        if (won != ' ' || board_full(play_board)) {
            break;
        }

        current = (current == 'X') ? 'O' : 'X'; /* passa il turno */
    }

    print_board(play_board);
    if (won != ' ') {
        printf("Player %d (%c) has won!\n", player_number(won), won);
    } else {
        puts("Tie!");
    }

    return 0;
}
