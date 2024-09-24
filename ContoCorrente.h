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


private:
    std::string Intestatario;
    int Saldo; //TODO: il saldo non si può impostare ma deriva dallo storico il conto può avere un importo di partenza da sommare poi al saldo delle transazioni

};



#endif //CONTOCORRENTE_H
