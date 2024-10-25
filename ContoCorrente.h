
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

    void loadTransazioni(std::string nomeFile);
    //TODO: cercare transazioni

    void checkTransazione(Transazione &transazione,std::string estrattoConto);
    void checkAllTransazioni(std::string estrattoConto);

    std::vector<Transazione> getTransazioni() const;


private:
    std::string Intestatario;
    int Budget;

    int IDcontatore;

    std::vector<Transazione> Transazioni; //vettore di transazioni dell relativo conto
    FileManager fm;
};



#endif //CONTOCORRENTE_H
