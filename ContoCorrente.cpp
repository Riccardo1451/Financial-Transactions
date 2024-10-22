//
// Created by Riccardo fantechi on 20/09/24.
//

#include "ContoCorrente.h"
#include <fstream>
#include <iostream>
using namespace std;

std::string VisualizzaTransaizoni ="/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/FileTesto/VisualizzaTransazioni.txt";

std::string ContoCorrente::getNome() const {
    return Intestatario;
}


ContoCorrente::ContoCorrente(std::string Nome, int Budget) : Intestatario(Nome),IDcontatore(1) {}



void ContoCorrente::addTransazione(Transazione &Transazione, std::string Percorso) {
    //Viene passata una transazione da inserire nel file delle transazioni
    Transazione.setID(IDcontatore++);
    Transazioni.push_back(Transazione);
    fm.ScriviTransazioniSuFile(Percorso,Transazioni);
    //Vado a scrivere sul file estratto ogni operazione
}

void ContoCorrente::modTransazione(int ID, int nuovoImporto, bool nuovoIn, std::string nuovaData) {
    //Tramite ID posso prendere la transazioni relativa e modificarla
    for(auto& transazione : Transazioni) {
        if(transazione.getID() == ID) {
            transazione.setImporto(nuovoImporto);
            transazione.setIn(nuovoIn);
            transazione.setData(nuovaData);
            cout<<"Transazione con ID: "+std::to_string(transazione.getID())+" modificata correttamente"<<std::endl;
            fm.ScriviTransazioniSuFile(VisualizzaTransaizoni,Transazioni);
            return;
        }
    }
    cerr <<"Transazione con ID: "<<ID<<" non trovata."<<endl;
}

void ContoCorrente::deleteTransazione(int ID) {
    //Tramite ID vado a rimuovere la transazioni dal file e dal vettore
    auto it = std::remove_if(Transazioni.begin(), Transazioni.end(), [ID](const Transazione& t) {
       return t.getID() == ID; // Ritorna true se l'ID corrisponde
   });

    if (it != Transazioni.end()) {
        Transazioni.erase(it, Transazioni.end()); // Rimuovi le transazioni trovate
        fm.ScriviTransazioniSuFile(VisualizzaTransaizoni,Transazioni);
    } else {
        cerr << "Transazione con ID " << ID << " non trovata." << std::endl; // Messaggio di errore se non trovata
    }
}

void ContoCorrente::uploadTransazioni(std::string nomeFile) {
    fm.CaricaTransazioniDaFile(nomeFile,Transazioni,*this);
}

void ContoCorrente::checkTransazione(Transazione &transazione, std::string estrattoConto) {
    fm.ConciliaTransazione(transazione,estrattoConto,Transazioni);
}
void ContoCorrente::checkAllTransaizoni(std::string estrattoConto) {
    fm.ConciliaAllTransazioni(estrattoConto,Transazioni);
}







