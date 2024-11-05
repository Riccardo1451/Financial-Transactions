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

//TODO:Come gestire transazine duplicate ??
TEST(TransazioneTestIncrementalID, TestID) {
    Transazione transizione1(100, true, "27-09-2023");
    Transazione transizione2(200, false, "28-09-2023");
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
