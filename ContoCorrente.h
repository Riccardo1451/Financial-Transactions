//
// Created by Riccardo fantechi on 20/09/24.
//

#ifndef CONTOCORRENTE_H
#define CONTOCORRENTE_H
#include "Transazione.h"
#include <string>
#include <vector>

#include "FileManager.h"


class ContoCorrente {

public:
    ContoCorrente(std::string Nome, int budget);

    int getBudget() const;
    void setBudget(int valore);

    std::string getNome() const;

    void addTransazione(Transazione &Transazione);

    void modTransazione(int ID, int nuovoImporto, bool nuovoIn, std::string nuovaData);

    void deleteTransazione(int ID);

private:
    std::string Intestatario;
    int Budget;

    std::vector<Transazione> Transazioni; //vettore di transazioni dell relativo conto
    FileManager fm;
};



#endif //CONTOCORRENTE_H
