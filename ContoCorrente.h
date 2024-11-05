
#ifndef CONTOCORRENTE_H
#define CONTOCORRENTE_H
#include "Transazione.h"
#include <string>
#include <map>



class ContoCorrente {

public:
    ContoCorrente(std::string Nome, int Budget = 0);

    std::string getNome() const;

    void addTransazione(Transazione &transazione, std::string Percorso);

    void modTransazione(int ID, int nuovoImporto, bool nuovoIn, std::string nuovaData);

    void deleteTransazione(int ID);

    std::map <int,Transazione> searchTransazione(Transazione transazione) const;
    void WriteTransactionOnFile(std::string fileName, std::map<int, Transazione> &transazioni);

    void LoadTransactionFromFile(const std::string& fileName);

    void ConciliaTransaction(Transazione &transazione, const std::string& estrattoConto);

    void ConciliaAllTransactions(const std::string& estrattoConto);

    std::map<int, Transazione> getTransazioni() const;
    int getBudget() const;

private:
    std::string Intestatario;
    int Budget;

    int IDcontatore;

    //std::vector<Transazione> Transazioni; //vettore di transazioni dell relativo conto
    std::map <int, Transazione> Transazioni;
};



#endif //CONTOCORRENTE_H
