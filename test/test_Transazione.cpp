#include <gtest/gtest.h>
#include "../Transazione.h"

// Definisci un test case con Google Test
TEST(TransazioneTest, TestValoriIniziali) {
    // Crea una transazione
    Transazione transazione(100, true, "2023-09-27");

    // Verifica che l'importo iniziale sia corretto
    EXPECT_EQ(transazione.getImporto(), 100);

    // Verifica che sia un'entrata
    EXPECT_TRUE(transazione.getIn());

    // Verifica che la data sia corretta
    EXPECT_EQ(transazione.getData(), "2023-09-27");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
