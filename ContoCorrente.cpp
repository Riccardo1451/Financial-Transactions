//
// Created by Riccardo fantechi on 20/09/24.
//

#include "ContoCorrente.h"
#include <fstream>
#include <iostream>

int ContoCorrente::getImporto() const {
    return Importo;
}
void ContoCorrente::setImporto(int valore) {
    this->Importo = valore;
}


ContoCorrente::ContoCorrente(std::string Intestatario, int Importo) : Intestatario(Intestatario), Importo(Importo){ }

void ContoCorrente::EseguiTransazione(Transazione &Transazione) {
    //gestione della transazione
    if(Transazione.getIn()) { //il valore è un bool -> True se l'operazione è in entrata sul conto False altrimenti
        Importo+=Transazione.getSaldo();
    }
    else if(!Transazione.getIn()){
        if(Importo >= Transazione.getSaldo()){
            //verifico che il saldo sia disponibile
            Importo-=Transazione.getSaldo();
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
