
#ifndef CONTOCORRENTE_H
#define CONTOCORRENTE_H
#include "Transazione.h"
#include <string>
#include <vector>

#include "FileManager.h"


class ContoCorrente {

public:
    ContoCorrente(std::string Nome, int Budget = 0);

    std::string getNome() const;

    void addTransazione(Transazione & Transazione, std::string Percorso);

    void modTransazione(int ID, int nuovoImporto, bool nuovoIn, std::string nuovaData);

    void deleteTransazione(int ID);

    Transazione searchTransazione() const;
    //TODO: cercare transazioni
    void WriteTransactionOnFile(std::string fileName, std::vector<Transazione> &transazioni);

    void LoadTransactionFromFile(const std::string& fileName);

    void ConciliaTransaction(Transazione &transazione, const std::string& estrattoConto);

    void ConciliaAllTransactions(const std::string& estrattoConto);

    std::vector<Transazione> getTransazioni() const;
    int getBudget() const;

private:
    std::string Intestatario;
    int Budget;

    int IDcontatore;

    std::vector<Transazione> Transazioni; //vettore di transazioni dell relativo conto
};



#endif //CONTOCORRENTE_H
