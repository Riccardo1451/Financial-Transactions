//
// Created by Riccardo fantechi on 20/09/24.
//

#include "Transazione.h"

Transazione::Transazione(int Saldo, bool in, std::string data) : Saldo(Saldo),In(in), data(data){ }

void Transazione::setSaldo(int valore) {
    this->Saldo = valore;
}
void Transazione::setIn(bool opzione) {
    this->In = opzione;
}

int  Transazione::getSaldo() const{
    return Saldo;
}

bool Transazione::getIn() const{
    return In;
}

std::string Transazione::getData() {
    return data;
}

void Transazione::setData(std::string data) {
    this->data = data;
}

std::string Transazione::getInfo() {
    //Andiamo a creare una stringa per ogni transazione in modo che possiamo scriverla su un file
    std::string opt;
    if(In) {
        opt = "Entrata";
    }else opt="Uscita";

    return std::to_string(Saldo)+" "+opt+" "+data;
}



