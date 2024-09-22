//
// Created by Riccardo fantechi on 20/09/24.
//

#ifndef CONTOCORRENTE_H
#define CONTOCORRENTE_H
#include "Transazione.h"
#include <string>
#include <vector>


class ContoCorrente {

public:
    ContoCorrente(std::string Intestatario, int Saldo);

    int getSaldo() const;
    void setSaldo(int valore);

    void EseguiTransazione(Transazione& Transazione);
    //l'intestatario deve essere unico e non può variare una volta che il conto viene creato

    std::vector<Transazione> getStoricoTransazioni();

private:
    std::string Intestatario;
    int Saldo;

    std::vector <Transazione> StoricoTransazioni; //TODO:si può anche rimuovere visto che il CC scrivere direttamente la transazione sul file
};



#endif //CONTOCORRENTE_H
