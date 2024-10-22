
#ifndef CONTOCORRENTE_H
#define CONTOCORRENTE_H
#include "Transazione.h"
#include <string>
#include <vector>

#include "FileManager.h"


class ContoCorrente {

public:
    ContoCorrente(std::string Nome, int Budget = 0); //TODO: budget come si modifica, ogni add,mod,delte

    std::string getNome() const;

    void addTransazione(Transazione &Transazione, std::string Percorso); //TODO:const

    void modTransazione(int ID, int nuovoImporto, bool nuovoIn, std::string nuovaData); //TODO: ID->mappa

    void deleteTransazione(int ID);

    void uploadTransazioni(std::string nomeFile); //TODO: load
    //TODO: cercare transazioni

    void checkTransazione(Transazione &transazione,std::string estrattoConto);
    void checkAllTransaizoni(std::string estrattoConto); //TODO: refactor



private:
    std::string Intestatario;
    int Budget;

    int IDcontatore;

    std::vector<Transazione> Transazioni; //vettore di transazioni dell relativo conto
    FileManager fm;

    //TODO : rimuovere friend
    friend class ContoCorrenteTest_TestOPTransazioni_Test;
    friend class ContoCorrenteTest_TransazioniInesistenti_Test;
    friend class FileManagerTest_TestGestioneFile_Test;
    friend class FileManagerTest_TestConciliazione_Test;
    
};



#endif //CONTOCORRENTE_H
