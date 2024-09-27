//
// Created by Riccardo fantechi on 20/09/24.
//

#include "ContoCorrente.h"
#include <fstream>
#include <iostream>
using namespace std;

int ContoCorrente::getBudget() const {
    return Budget;
}
void ContoCorrente::setBudget(int budget) {
    this->Budget = budget;
}

std::string ContoCorrente::getNome() const {
    return Intestatario;
}


ContoCorrente::ContoCorrente(std::string Nome, int Budget) : Intestatario(Nome), Budget(Budget){ }



void ContoCorrente::addTransazione(Transazione &Transazione) {
    //Viene passata una transazione da inserire nel file delle transazioni
    Transazioni.push_back(Transazione);
    fm.ScriviTransazioniSuFile("/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/Transazioni.txt",Transazioni);
    //Vado a scrivere sul file estratto ogni operazione
}

void ContoCorrente::modTransazione(int ID, int nuovoImporto, bool nuovoIn, std::string nuovaData) {
    //Tramite ID posso prendere la transazioni relativa e modificarla
    for(auto& transazione : Transazioni) {
        if(transazione.getID() == ID) {
            transazione.setImporto(nuovoImporto);
            transazione.setIn(nuovoIn);
            transazione.setData(nuovaData);
            fm.ScriviTransazioniSuFile("/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/Transazioni.txt",Transazioni);
            return;
        }
    }
    cerr <<"Transaizone con ID: "<<ID<<" non trovata"<<endl;
}

void ContoCorrente::deleteTransazione(int ID) {
    //Tramite ID vado a rimuovere la transazioni dal file e dal vettore
    auto it = std::remove_if(Transazioni.begin(), Transazioni.end(), [ID](const Transazione& t) {
       return t.getID() == ID; // Ritorna true se l'ID corrisponde
   });

    if (it != Transazioni.end()) {
        Transazioni.erase(it, Transazioni.end()); // Rimuovi le transazioni trovate
        fm.ScriviTransazioniSuFile("/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/Transazioni.txt",Transazioni);
    } else {
        cerr << "Transazione con ID " << ID << " non trovata." << std::endl; // Messaggio di errore se non trovata
    }
}

void ContoCorrente::uploadTransazioni(std::string nomeFile) {
    fm.CaricaTransazioniDaFile(nomeFile,Transazioni);
}





