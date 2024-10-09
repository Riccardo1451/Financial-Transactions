//
// Created by Riccardo fantechi on 20/09/24.
//

#include "Transazione.h"
#include <iostream>
using namespace std;

int Transazione::UltimoID = 0;

Transazione::Transazione(int Importo, bool in, std::string data, bool conciliata)
: Importo(Importo),In(in), data(data), Conciliata(conciliata) {
    ID = ++UltimoID; //Assegno l'ID univoco alla transazione e vado ad incrementare il valore dell'UltimoID
}

void Transazione::setImporto(int valore) {
    if (valore >= 0)
        this->Importo = valore;
    else cerr<<"L'importo non può essere negativo"<<endl;
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

std::string Transazione::getData() {
    return data;
}

void Transazione::setData(std::string data) {
    this->data = data;
}

int Transazione::getID() const {
    return ID;
}

bool Transazione::getConciliata() {
    return Conciliata;
}

void Transazione::setConciliata(bool opt) {
    Conciliata=opt;
}


std::string Transazione::getInfo() {
    //Andiamo a creare una stringa per ogni transazione in modo che possiamo scriverla su un file
    std::string IO = In ? "Entrata" : "Uscita";
    std::string Conc = Conciliata ? "Conciliata" : "Non Conciliata";

    return "ID: "+std::to_string(ID)+" "+std::to_string(Importo)+" "+IO+" "+data+" "+Conc;
}




