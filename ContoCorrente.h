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
    ContoCorrente(std::string Intestatario, int Importo);

    int getImporto() const;
    void setImporto(int valore);

    void EseguiTransazione(Transazione& Transazione);
    //l'intestatario deve essere unico e non può variare una volta che il conto viene creato


private:
    std::string Intestatario;
    int Importo;

};



#endif //CONTOCORRENTE_H
