#include <gtest/gtest.h>
#include "../Transazione.h"
#include "../ContoCorrente.h"
#include "../ObjectNotFound.h"
#include "../ObjectNotReady.h"
#include <fstream>

std::string ListaTransazioni = "/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/FileTesto/VisualizzaTransazioni.txt";
const std::string PercorsoTestLettura = "UploadTest.txt";
const std::string PercorsoTestScrittura = "ListaTest.txt";

TEST(ContoCorrenteTest, TestValoriIniziali) {
    ContoCorrente c1("Mario Rossi");

    EXPECT_EQ(c1.getNome(), "Mario Rossi");

}
TEST(ContoCorrenteTest, TestOPTransazioni){
    ContoCorrente c1 ("Mario Rossi");
    Transazione t1 (200, true, "12-01-2003");
    Transazione t2(300, false, "13-01-2003");
    c1.addTransazione(t1, ListaTransazioni);
    std::map<int, Transazione> transazioni = c1.getTransazioni();
    EXPECT_EQ(transazioni.size(),1);

    auto it = transazioni.find(t1.getID());
    //Test su aggiunta Transazione al CC
    EXPECT_NE(it,transazioni.end());

    //Test sulla modifica di una Transazione dal CC
    int IDTest = t1.getID();
    c1.modTransazione(IDTest,400,false,"16-05-2000");

    //Verifico se la transazione ne CC è stata modificata correttamente
    transazioni = c1.getTransazioni();
    auto modifiedTransactionIt = transazioni.find(IDTest);

    EXPECT_NE(modifiedTransactionIt, transazioni.end());

    EXPECT_EQ(modifiedTransactionIt->second.getImporto(),400);
    EXPECT_FALSE(modifiedTransactionIt->second.getIn());
    EXPECT_EQ(modifiedTransactionIt->second.getData(), "16-05-2000");

    c1.addTransazione(t2, ListaTransazioni);

    //Controllo in numero di Transazioni
    ASSERT_EQ(c1.getTransazioni().size(), 2);

    //Test sulla cancellazione di una Transazione dal CC
    c1.deleteTransazione(IDTest);
    //Verifico il numero di Transazioni e che sia rimasta solo la 2
    ASSERT_EQ(c1.getTransazioni().size(),1);

    auto transazioniAggiornate = c1.getTransazioni();
    auto remainingTransactionIt = transazioniAggiornate.find(t2.getID());

    ASSERT_NE(remainingTransactionIt, transazioniAggiornate.end());
    EXPECT_EQ(remainingTransactionIt->second.getID(), t2.getID());
}

TEST(ContoCorrenteTest, TransazioniInesistenti) {

    ContoCorrente c1("Mario Rossi");
    Transazione t1(200, true, "12-01-2003");
    c1.addTransazione(t1, ListaTransazioni);

    // Tenta di modificare una transazione con ID inesistente
    EXPECT_THROW(c1.modTransazione(999, 500, false, "15-01-2003"), ObjectNotFound);

    // Verifica che la transazione originale non sia stata modificata
    auto transazioni = c1.getTransazioni();
    auto it = transazioni.find(t1.getID());

    ASSERT_NE(it, transazioni.end()); // Assicura che t1 esista ancora
    EXPECT_EQ(it->second.getImporto(), 200);
    EXPECT_TRUE(it->second.getIn());
    EXPECT_EQ(it->second.getData(), "12-01-2003");

    // Tenta di cancellare una transazione con ID inesistente
    EXPECT_THROW(c1.deleteTransazione(999),ObjectNotFound);

    // Verifica che la transazione originale non sia stata cancellata
    ASSERT_EQ(c1.getTransazioni().size(), 1); // Solo t1 dovrebbe rimanere

    it = transazioni.find(t1.getID());
    ASSERT_NE(it, transazioni.end()); // Assicura che t1 esista ancora
    EXPECT_EQ(it->second.getID(), t1.getID());
}


TEST(ContoCorrenteTest, TestConciliazione) {
    std::string UploadEstrattoTest = "/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/test/UploadEstrattoTest.txt";
    std::string EstrattoTest = "/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/test/EstrattoTest.txt";
    ContoCorrente c1 ("Mario Rossi");

    std::ofstream fout (UploadEstrattoTest);
    fout << "ID: 1 200 Entrata 01-09-2023 Non Conciliata"<<std::endl;
    fout << "ID: 2 300 Uscita 02-09-2023 Non Conciliata"<<std::endl;
    fout << "ID: 3 700 Uscita 27-11-2007 Non Conciliata"<<std::endl;
    fout.close();

    std::ofstream testout (EstrattoTest);
    testout << "ID: 1 200 Entrata 01-09-2023 Non Conciliata"<<std::endl;
    testout << "ID: 2 300 Uscita 02-09-2023 Non Conciliata"<<std::endl;
    testout << "ID: 3 700 Uscita 27-11-2007 Non Conciliata"<<std::endl;
    testout.close();

    c1.LoadTransactionFromFile(UploadEstrattoTest);

    //Verifico che la Transazione sia conciliata
    Transazione temp = c1.getTransazioni().begin()->second;

    c1.ConciliaTransaction(temp,EstrattoTest);

    EXPECT_TRUE(temp.getConciliata());

    //Verifico anche il metodo per tutte le Transazioni
    c1.ConciliaAllTransactions(EstrattoTest);

    EXPECT_TRUE(c1.getTransazioni()[1].getConciliata());
    EXPECT_TRUE(c1.getTransazioni()[2].getConciliata());
}
TEST(ContoCorrenteTest, TestNonConciliazione) {
    //verifico che se una transazione non è conciliata risulti in errore
    std::string UploadEstrattoTest = "/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/test/UploadEstrattoTest.txt";
    std::string EstrattoTest = "/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/test/EstrattoTest.txt";
    ContoCorrente c1("Mario Rossi");

    std::ofstream testout (EstrattoTest);
    testout << "ID: 1 200 Entrata 01-09-2023 Non Conciliata"<<std::endl;
    testout << "ID: 2 300 Uscita 02-09-2023 Non Conciliata"<<std::endl;
    testout << "ID: 3 700 Uscita 27-11-2007 Non Conciliata"<<std::endl;
    testout.close();

    Transazione temp (200, false, "03-12-2000"); //transazione non nell'estratto conto

    c1.addTransazione(temp,"");

    //Tentativo di conciliazione
    EXPECT_THROW(c1.ConciliaTransaction(temp,EstrattoTest),ObjectNotReady);

    //Verifico che se tutte le transazioni non sono conciliate renda un messaggio di errore
    Transazione t1 (300, false, "02-09-2023");
    Transazione t2 (700, false, "27-11-2007");
    Transazione t3 (200, true, "01-09-2023");
    Transazione tn (150, true, "04-25-2001");

    ContoCorrente c2 ("Mario Verdi");

    c2.addTransazione(t1,"");
    c2.addTransazione(t2,"");
    c2.addTransazione(t3,"");
    c2.addTransazione(tn,""); //Transazione non presente

    EXPECT_THROW(c2.ConciliaAllTransactions(EstrattoTest),ObjectNotReady);
}
TEST(ContoCorrenteTest, TestRefusoFormattazione) {
    //Verifica il comportamento quando dal file di upload il formato delle transazione è errato
    std::string UploadEstrattoTest = "/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/test/UploadEstrattoTest.txt";
    ContoCorrente c1("Mario Rossi");

    std::ofstream testout (UploadEstrattoTest);
    testout << "ID: 1 Entrata Non Conciliata 200 01-09-2023" << std::endl;
    testout << "ID: 1 Non Conciliata 01-09-2023 Entrata 200" << std::endl; //Transazioni con formato errato
    testout.close();

    //Tentativo di upload
    EXPECT_THROW(c1.LoadTransactionFromFile(UploadEstrattoTest),std::invalid_argument);
}
// Test per verificare la scrittura su file
TEST(ContoCorrenteTest, TestScritturaSuFile) {
    ContoCorrente c1("Mario Rossi");
    Transazione t1(200, true, "15-07-2004");

    // Esegue la scrittura della transazione sul file
    c1.addTransazione(t1, PercorsoTestScrittura);

    // Apre il file e legge la riga scritta
    std::ifstream fin(PercorsoTestScrittura);


    std::string input;
    std::getline(fin, input);
    fin.close();

    // Confronta la riga letta con il formato atteso
    std::string expectedOutput = "ID: " + std::to_string(t1.getID()) + " 200 Entrata 15-07-2004 Non Conciliata";
    EXPECT_EQ(expectedOutput, input);
}

// Test per verificare il caricamento delle transazioni da un file
TEST(ContoCorrenteTest, TestCaricamentoDaFile) {
    // Prepara il file di input con transazioni di esempio
    std::ofstream fout(PercorsoTestLettura);
    fout << "ID: 1 200 Entrata 01-09-2023 Conciliata\n";
    fout << "ID: 2 300 Uscita 02-09-2023 Non Conciliata\n";
    fout.close();

    ContoCorrente c1("Mario Rossi");

    // Carica le transazioni dal file
    c1.LoadTransactionFromFile(PercorsoTestLettura);
    auto transazioni = c1.getTransazioni();

    // Verifica che siano state caricate 2 transazioni
    ASSERT_EQ(c1.getTransazioni().size(), 2);

    // Verifica la consistenza della prima transazione caricata
    auto it = transazioni.find(1);
    ASSERT_NE(it, transazioni.end());
    EXPECT_EQ(it->second.getImporto(), 200);
    EXPECT_TRUE(it->second.getIn());
    EXPECT_EQ(it->second.getData(), "01-09-2023");
    EXPECT_TRUE(it->second.getConciliata());

    // Verifica la consistenza della seconda transazione caricata
    it = transazioni.find(2);
    ASSERT_NE(it, transazioni.end());
    EXPECT_EQ(it->second.getImporto(), 300);
    EXPECT_FALSE(it->second.getIn());
    EXPECT_EQ(it->second.getData(), "02-09-2023");
    EXPECT_FALSE(it->second.getConciliata());
}

// Test per verificare la gestione di file con formati non validi
TEST(ContoCorrenteTest, TestCaricamentoDaFileFormatoNonValido) {
    // Prepara un file con un formato non valido
    std::ofstream fout(PercorsoTestLettura);
    fout << "ID: A B Entrata C Conciliata\n";  // Righe con formato errato
    fout.close();

    ContoCorrente c1("Mario Rossi");

    // Si aspetta che venga lanciata un'eccezione durante il caricamento
    EXPECT_THROW(c1.LoadTransactionFromFile(PercorsoTestLettura), std::invalid_argument);
}

