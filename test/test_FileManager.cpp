#include <gtest/gtest.h>
#include "../Transazione.h"
#include "../ContoCorrente.h"
#include "../FileManager.h"
#include <fstream>



TEST(FileManagerTest, TestGestioneFile) {
    std::string PercorsoTest = "/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/test/ListaTest.txt";
    ContoCorrente c1("Mario Rossi");
    Transazione t1 (200,true,"15-07-2004");

    //Test scrittura delle Transazioni su file
    c1.addTransazione(t1,PercorsoTest);
    //voglio verificare che venga scritta sul file indicato
    std::ifstream fin (PercorsoTest);
    std::string input;

    if (!fin.is_open()) {
        std::cerr << "Impossibile aprire il file" << std::endl;
    }
    else (std::getline(fin, input));
    fin.close();

    EXPECT_EQ("ID: "+std::to_string(t1.getID())+ " "+std::to_string(t1.getImporto()) +" Entrata"+" "+t1.getData()+" Non Conciliata",input);
    c1.deleteTransazione(t1.getID());

    //Test upload di Transazione da file
    std::string UploadTest = "/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/test/UploadTest.txt";

    std::ofstream fout(UploadTest);
    //Crea le Transazioni
    fout << "ID: 1 200 Entrata 01-09-2023 Conciliata"<<std::endl;
    fout << "ID: 2 300 Uscita 02-09-2023 Non Conciliata"<<std::endl;
    fout.close();

    c1.uploadTransazioni(UploadTest);

    EXPECT_EQ(c1.Transazioni.size(),2);

    //Verifica che le Transazioni siano presenti
    EXPECT_EQ(c1.Transazioni.back().getImporto(), 300);
    EXPECT_FALSE(c1.Transazioni.back().getIn());
    EXPECT_EQ(c1.Transazioni.back().getData(), "02-09-2023");
    EXPECT_FALSE(c1.Transazioni.back().getConciliata());

    EXPECT_EQ(c1.Transazioni[c1.Transazioni.size()-2].getImporto(), 200);
    EXPECT_TRUE(c1.Transazioni[c1.Transazioni.size()-2].getIn());
    EXPECT_EQ(c1.Transazioni[c1.Transazioni.size()-2].getData(), "01-09-2023");
    EXPECT_TRUE(c1.Transazioni[c1.Transazioni.size()-2].getConciliata());

}

//TODO: migliorare il test di upload da file, con formato errato
TEST(FileManagerTest, TestConciliazione) {
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

    c1.uploadTransazioni(UploadEstrattoTest);

    //Verifico che la Transazione sia conciliata
    Transazione temp = c1.Transazioni[0];

    c1.checkTransazione(temp,EstrattoTest);

    EXPECT_TRUE(temp.getConciliata());

    //Verifico anche il metodo per tutte le Transazioni
    c1.checkAllTransaizoni(EstrattoTest);

    EXPECT_TRUE(c1.Transazioni[1].getConciliata());
    EXPECT_TRUE(c1.Transazioni[2].getConciliata());
}

TEST (FileManagerTest, TestNonConciliazione) {
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

    c1.checkTransazione()
}
