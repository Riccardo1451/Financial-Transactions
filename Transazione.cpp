//
// Created by Riccardo fantechi on 20/09/24.
//

#include "Transazione.h"

Transazione::Transazione(int Importo, bool in, std::string& data) : Importo(Importo),In(in), data(data){ }

void Transazione::setImporto(int valore) {
    this->Importo = valore;
}
void Transazione::setIn(bool opzione) {
    this->In = opzione;
}

int  Transazione::getImporto() const{
    return Importo;
}

bool Transazione::getIn() const{
    return In;
}

std::string Transazione::getData() const {
    return data;
}

void Transazione::setData(std::string data) {
    this->data = data;
}




