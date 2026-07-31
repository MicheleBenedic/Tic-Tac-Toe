#include "game.h"

#include <stdio.h>

int main(void) {
    char play_board[BOARD_SIZE][BOARD_SIZE];
    init_board(play_board);
    printf("\n");

    char current = 'X'; /* 1st player sign */
    char won = ' ';

    while (true) {
        player_move(current, play_board);

        won = winner(play_board);
        if (won != ' ' || board_full(play_board)) {
            break;
        }

        current = (current == 'X') ? 'O' : 'X';
    }

    print_board(play_board);
    if (won != ' ') {
        printf("Player %d (%c) has won!\n", player_number(won), won);
    } else {
        puts("Tie!");
    }

    return 0;
}
