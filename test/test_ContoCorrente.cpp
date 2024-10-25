#include <gtest/gtest.h>
#include "../Transazione.h"
#include "../ContoCorrente.h"
std::string ListaTransazioni = "/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/FileTesto/VisualizzaTransazioni.txt";

TEST(ContoCorrenteTest, TestValoriIniziali) {
    ContoCorrente c1("Mario Rossi");

    EXPECT_EQ(c1.getNome(), "Mario Rossi");

}
TEST(ContoCorrenteTest, TestOPTransazioni){
    ContoCorrente c1 ("Mario Rossi");
    Transazione t1 (200, true, "12-01-2003");
    Transazione t2(300, false, "13-01-2003");
    c1.addTransazione(t1, ListaTransazioni);


    //Test su aggiunta Transazione al CC
    EXPECT_EQ(t1.getInfo(), c1.getTransazioni().back().getInfo());

    //Test sulla modifica di una Transazione dal CC
    int IDTest = t1.getID();
    c1.modTransazione(IDTest,400,false,"16-05-2000");
    //Verifico se la transazione ne CC è stata modificata correttamente
    EXPECT_EQ(c1.getTransazioni().back().getImporto(),400);
    EXPECT_FALSE(c1.getTransazioni().back().getIn());
    EXPECT_EQ(c1.getTransazioni().back().getData(), "16-05-2000");

    c1.addTransazione(t2, ListaTransazioni);

    //Controllo in numero di Transazioni
    ASSERT_EQ(c1.getTransazioni().size(),2);

    //Test sulla cancellazione di una Transazione dal CC
    c1.deleteTransazione(IDTest);
    //Verifico il numero di Transazioni e che sia rimasta solo la 2
    ASSERT_EQ(c1.getTransazioni().size(),1);
    EXPECT_EQ(c1.getTransazioni().back().getID(),t2.getID());
}

TEST(ContoCorrenteTest, TransazioniInesistenti) {

    ContoCorrente c1("Mario Rossi");
    Transazione t1(200, true, "12-01-2003");
    c1.addTransazione(t1, ListaTransazioni);

    
    testing::internal::CaptureStderr();
    // Tenta di modificare una transazione con ID inesistente
    c1.modTransazione(999, 500, false, "15-01-2003");
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_EQ(output,"Transazione con ID: "+std::to_string(999)+" non trovata.\n");

    // Verifica che la transazione originale non sia stata modificata
    EXPECT_EQ(c1.getTransazioni().back().getImporto(), 200);
    EXPECT_TRUE(c1.getTransazioni().back().getIn());
    EXPECT_EQ(c1.getTransazioni().back().getData(), "12-01-2003");

    // Tenta di cancellare una transazione con ID inesistente
    c1.deleteTransazione(999);

    // Verifica che la transazione originale non sia stata cancellata
    ASSERT_EQ(c1.getTransazioni().size(), 1);
    EXPECT_EQ(c1.getTransazioni().back().getID(), t1.getID());
}
