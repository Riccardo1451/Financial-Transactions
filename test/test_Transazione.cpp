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

    EXPECT_FALSE(transazione.getConciliata());
}

TEST(TransazioneTest, TestSetter) {
    Transazione transazione(100, true, "2023-09-27");

    transazione.setImporto(-500); //test di NON inserimento di valore negativo
    EXPECT_EQ(transazione.getImporto(), 100);

    transazione.setImporto(100);
    EXPECT_EQ(transazione.getImporto(),100);

    transazione.setData("2002-07-13");
    EXPECT_EQ(transazione.getData(), "2002-07-13");

    transazione.setIn(false);
    EXPECT_FALSE(transazione.getIn());

    transazione.setConciliata(true);
    EXPECT_TRUE(transazione.getConciliata());

    EXPECT_EQ(transazione.getInfo(), "ID: "+ std::to_string(transazione.getID())+" "+"100"+" "+"Uscita"+" "+"2002-07-13"+" "+"Conciliata");

}

TEST(TransazioneTestIncrementalID, TestID) {
    Transazione transizione1(100, true, "2023-09-27");
    Transazione transizione2(200, false, "2023-09-28");

    //Test che due transaizone consecutive abbiano ID consecuitvo
    EXPECT_EQ(transizione2.getID(), transizione1.getID() + 1);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
