//
// Created by Riccardo fantechi on 20/09/24.
//

#include "ContoCorrente.h"

#include <iostream>

int ContoCorrente::getSaldo() const {
    return Saldo;
}
void ContoCorrente::setSaldo(int valore) {
    this->Saldo = valore;
}

std::vector<Transazione> ContoCorrente::getStoricoTransazioni() {
    return StoricoTransazioni;
}

ContoCorrente::ContoCorrente(std::string Intestatario, int Saldo) : Intestatario(Intestatario), Saldo(Saldo){ }

void ContoCorrente::EseguiTransazione(Transazione &Transazione) {
    //gestione della transazione
    if(Transazione.getIn()) { //il valore è un bool -> True se l'operazione è in entrata sul conto False altrimenti
        Saldo+=Transazione.getImporto();
    }
    else if(!Transazione.getIn()){
        if(Saldo >= Transazione.getImporto()){
            //verifico che il saldo sia disponibile
            Saldo-=Transazione.getImporto();
        }else {
            //Gestione di saldo non disponibile
            std::cout <<"Il saldo è insufficiente per eseguire la transazione"<<std::endl;
            return;
        }
    }
    StoricoTransazioni.push_back(Transazione);
}
