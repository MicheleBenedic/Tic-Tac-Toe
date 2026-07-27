#include "unity/unity.h"

/* Eseguito prima di OGNI test */
void setUp(void) {}

/* Eseguito dopo OGNI test */
void tearDown(void) {}

/* Il "test vuoto": non verifica nulla del gioco,
   serve solo a dimostrare che il meccanismo gira. */
void test_infrastruttura_funziona(void) {
    TEST_ASSERT_TRUE(1);   // asserzione banale, sempre vera
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_infrastruttura_funziona);
    return UNITY_END();
}
