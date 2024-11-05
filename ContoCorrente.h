
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

    void addTransazione(Transazione & Transazione, std::string Percorso);

    void modTransazione(int ID, int nuovoImporto, bool nuovoIn, std::string nuovaData); //TODO: ID->mappa

    void deleteTransazione(int ID);

    void loadTransazioni(std::string nomeFile);

    Transazione searchTransazione() const;
    //TODO: cercare transazioni


    void WriteTransactionOnFile(std::string fileName, std::vector<Transazione> &transazioni);
    void LoadTransactionFromFile(std::string fileName, std::vector<Transazione> &transazioni);
    void ConciliaTransaction(Transazione &transazione, const std::string& estrattoConto, std::vector<Transazione> &transazioni);
    void ConciliaAllTransactions(std::string estrattoConto, std::vector<Transazione> &transazioni);
    std::vector<Transazione> getTransazioni() const;


private:
    std::string Intestatario;
    int Budget;

    int IDcontatore;

    std::vector<Transazione> Transazioni; //vettore di transazioni dell relativo conto
};



#endif //CONTOCORRENTE_H
