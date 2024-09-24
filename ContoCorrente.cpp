//
// Created by Riccardo fantechi on 20/09/24.
//

#include "ContoCorrente.h"
#include <fstream>
#include <iostream>

int ContoCorrente::getSaldo() const {
    return Saldo;
}
void ContoCorrente::setSaldo(int valore) {
    this->Saldo = valore;
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
    std::ofstream fout("/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/Estratto.txt", std::ios::app); //ios::app permentte di non sovrascrivere il file
    fout << Transazione.getInfo()+"\n";
    fout.close();
    //Vado a scrivere sul file estratto ogni operazione
}
