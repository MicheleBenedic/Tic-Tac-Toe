#include "unity/unity.h"
#include "unity/unity_internals.h"

#include "../src/game.h"

/* Fixture condivisa: ogni test parte da una board pulita */
static char board[BOARD_SIZE][BOARD_SIZE];

/* Eseguito prima di OGNI test */
void setUp(void) {
    init_board(board);
}

/* Eseguito dopo OGNI test */
void tearDown(void) {}

/* Helper: riempie la board da una stringa di 9 caratteri, riga per riga.
   Esempio: "XXX OO   " -> riga 0 = "XXX", riga 1 = " OO", riga 2 = "   " */
static void set_board(const char *cells) {
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            board[row][col] = cells[(row * BOARD_SIZE) + col];
        }
    }
}

/* ------------------------------------------------------------------ */
/* Esempi gia' scritti: usali come modello                             */
/* ------------------------------------------------------------------ */

static void test_init_board_riempie_di_spazi(void) {
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            TEST_ASSERT_EQUAL_CHAR(' ', board[row][col]);
        }
    }
}

static void test_winner_riga_completa(void) {
    set_board("XXX"
              "OO "
              "   ");
    TEST_ASSERT_EQUAL_CHAR('X', winner(board));
}

static void test_mossa_valida(void) {
    set_board("   "
              "   "
              "   ");
    TEST_ASSERT_EQUAL_CHAR(' ', board[0][0]);
    board[0][0] = 'X';
    TEST_ASSERT_EQUAL_CHAR('X', board[0][0]);
}

static void test_winner_colonna_completa(void) {
    set_board("XOO"
              "XO "
              "X   ");
    TEST_ASSERT_EQUAL_CHAR('X', winner(board));
}

static void test_winner_diagonale_principale(void) {
    set_board("XOO"
              " XO"
              "  X");
    TEST_ASSERT_EQUAL_CHAR('X', winner(board));
}

static void test_winner_antidiagonale(void) {
    set_board(" OX"
              " XO"
              "X  ");
    TEST_ASSERT_EQUAL_CHAR('X', winner(board));
}

static void test_winner_su_board_vuota(void) {
    set_board("   "
              "   "
              "   ");
    TEST_ASSERT_EQUAL_CHAR(' ', winner(board));
}

static void test_winner_su_board_piena_senza_vincitore(void) {
    set_board("XOX"
              "XOO"
              "OXX");
    TEST_ASSERT_EQUAL_CHAR(' ', winner(board));
}

static void test_board_full_su_board_vuota(void) {
    set_board("   "
              "   "
              "   ");
    TEST_ASSERT_EQUAL_CHAR(false, board_full(board));
}
static void test_board_full_con_una_cella_libera(void) {
    set_board("XOX"
              "O O"
              "XOX");
    TEST_ASSERT_EQUAL_CHAR(false, board_full(board));
}
static void test_board_full_su_board_piena(void) {
    set_board("XOX"
              "OXO"
              "XOX");
    TEST_ASSERT_EQUAL_CHAR(true, board_full(board));
}

static void test_player_number_marcatore_x(void) {
    TEST_ASSERT_EQUAL_INT(1, player_number('X'));
}

static void test_player_number_marcatore_o(void) {
    TEST_ASSERT_EQUAL_INT(2, player_number('O'));
}
/* ------------------------------------------------------------------ */
/* TODO: scrivi tu questi test                                         */
/* ------------------------------------------------------------------ */

/* TODO: winner() su una colonna completa -> restituisce il marker */
/* TODO: winner() sulla diagonale principale (0,0)-(1,1)-(2,2) */
/* TODO: winner() sull'antidiagonale (0,2)-(1,1)-(2,0) */
/* TODO: winner() su board vuota -> ' ' */
/* TODO: winner() su board piena senza vincitore (pareggio) -> ' ' */
/* TODO: board_full() su board vuota -> false */
/* TODO: board_full() con una sola casella libera -> false */
/* TODO: board_full() su board piena -> true */
/* TODO: player_number('X') -> 1, player_number('O') -> 2 */

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_init_board_riempie_di_spazi);
    RUN_TEST(test_winner_riga_completa);
    RUN_TEST(test_mossa_valida);
    RUN_TEST(test_winner_colonna_completa);
    RUN_TEST(test_winner_diagonale_principale);
    RUN_TEST(test_winner_antidiagonale);
    RUN_TEST(test_winner_su_board_vuota);
    RUN_TEST(test_winner_su_board_piena_senza_vincitore);
    RUN_TEST(test_board_full_su_board_vuota);
    RUN_TEST(test_board_full_con_una_cella_libera);
    RUN_TEST(test_board_full_su_board_piena);
    RUN_TEST(test_player_number_marcatore_x);
    RUN_TEST(test_player_number_marcatore_o);
    /* TODO: aggiungi qui una RUN_TEST per ogni test che scrivi sopra */
    return UNITY_END();
}
