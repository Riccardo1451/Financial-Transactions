#include <gtest/gtest.h>

#include "../ContoCorrente.h"
#include "../Transazione.h"


TEST(TransazioneTest, TestValoriIniziali) {

    Transazione transazione(100, true, "2023-09-27");

    // Verifica che l'importo iniziale sia corretto
    EXPECT_EQ(transazione.getImporto(), 100);

    // Verifica che sia un'entrata
    EXPECT_TRUE(transazione.getIn());

    // Verifica che la data sia corretta
    EXPECT_EQ(transazione.getData(), "2023-09-27");

    //Verifica che non sia conciliata
    EXPECT_FALSE(transazione.getConciliata());
}

TEST(TransazioneTest, TestSetter) {
    Transazione transazione(100, true, "2023-09-27");

    //Test con valore negativo
    transazione.setImporto(-500);
    EXPECT_EQ(transazione.getImporto(), 100);

    //Test modifica importo
    transazione.setImporto(100);
    EXPECT_EQ(transazione.getImporto(),100);

    //Test modifica data
    transazione.setData("2002-07-13");
    EXPECT_EQ(transazione.getData(), "2002-07-13");

    //Test modifica entrata
    transazione.setIn(false);
    EXPECT_FALSE(transazione.getIn());

    //test modifica conciliato
    transazione.setConciliata(true);
    EXPECT_TRUE(transazione.getConciliata());

    //Test metodo getInfo
    EXPECT_EQ(transazione.getInfo(),"ID: "+std::to_string(transazione.getID())+" "+std::to_string(100)+" "+"Uscita"+" "+"2002-07-13"+" "+"Conciliata");

}

TEST(TransazioneTestIncrementalID, TestID) {
    Transazione transizione1(100, true, "2023-09-27");
    Transazione transizione2(200, false, "2023-09-28");
    ContoCorrente c1 ("Mario Rossi");
    c1.addTransazione(transizione1,"");
    c1.addTransazione(transizione2,"");

    //Test su due transaizone consecutive
    //Verifica ID consecutivi
    EXPECT_EQ(transizione2.getID(), transizione1.getID() + 1);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
