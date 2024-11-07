#include <gtest/gtest.h>

#include "../ContoCorrente.h"
#include "../Transazione.h"


TEST(TransazioneTest, TestValoriIniziali) {

    Transazione transazione(100, true, "27-09-2023");

    // Verifica che l'importo iniziale sia corretto
    EXPECT_EQ(transazione.getImporto(), 100);

    // Verifica che sia un'entrata
    EXPECT_TRUE(transazione.getIn());

    // Verifica che la data sia corretta
    EXPECT_EQ(transazione.getData(), "27-09-2023");

    //Verifica che non sia conciliata
    EXPECT_FALSE(transazione.getConciliata());

}

TEST(TransazioneTest, TestSetter) {
    Transazione transazione(100, true, "27-09-2023");

    //Test con valore negativo


    EXPECT_THROW(transazione.setImporto(-500),std::invalid_argument);

    //Test modifica importo
    transazione.setImporto(100);
    EXPECT_EQ(transazione.getImporto(),100);

    //Test modifica data
    transazione.setData("13-07-2002");
    EXPECT_EQ(transazione.getData(), "13-07-2002");

    //Test modifica entrata
    transazione.setIn(false);
    EXPECT_FALSE(transazione.getIn());

    //test modifica conciliato
    transazione.setConciliata(true);
    EXPECT_TRUE(transazione.getConciliata());

    //Test metodo getInfo
    EXPECT_EQ(transazione.getInfo(),"ID: "+std::to_string(transazione.getID())+" "+std::to_string(100)+" "+"Uscita"+" "+"13-07-2002"+" "+"Conciliata");

}
TEST(TransazioneTest, TestDatiNonValidi) {
    EXPECT_THROW(Transazione t1(200, true, "323-13-2003", false), std::invalid_argument);
    EXPECT_THROW(Transazione t2(-250, true, "23-13-2003", false), std::invalid_argument);
}
//Test su formato transazioni

TEST(TransazioneTestIncrementalID, TestID) {
    Transazione transazione1(100, true, "27-09-2023");
    Transazione transazione2(200, false, "28-09-2023");
    ContoCorrente c1("Mario Rossi");

    c1.addTransazione(transazione1, "");
    c1.addTransazione(transazione2, "");

    // Recupera le transazioni dal conto corrente per controllare gli ID assegnati
    auto transazioni = c1.getTransazioni();
    auto it1 = transazioni.find(transazione1.getID());
    auto it2 = transazioni.find(transazione2.getID());

    ASSERT_NE(it1, transazioni.end()); // Verifica che la prima transazione esista
    ASSERT_NE(it2, transazioni.end()); // Verifica che la seconda transazione esista

    // Verifica che gli ID siano consecutivi
    EXPECT_EQ(it2->second.getID(), it1->second.getID() + 1);
}


int main(int argc, char **argv) {
   ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
