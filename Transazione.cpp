//
// Created by Riccardo fantechi on 20/09/24.
//

#include "Transazione.h"

Transazione::Transazione(int Valore, bool in) {
    setValore(Valore);
    setIn(in);
}
void Transazione::setValore(int valore) {
    Transazione::Valore = valore;
}
void Transazione::setIn(bool opzione) {
    Transazione::In = opzione;
}


int  Transazione::getValore() const{
    return Valore;
}

bool Transazione::getIn() const{
    return In;
}

