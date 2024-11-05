//
// Created by Riccardo fantechi on 20/09/24.
//

#include "ContoCorrente.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

std::string ViewTransaction ="/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/FileTesto/VisualizzaTransazioni.txt";

std::string ContoCorrente::getNome() const {
    return Intestatario;
}


ContoCorrente::ContoCorrente(std::string Nome, int Budget) : Intestatario(Nome),IDcontatore(1) {}



void ContoCorrente::addTransazione(Transazione &Transazione, std::string Percorso) {
    //Viene passata una transazione da inserire nel file delle transazioni
    Transazione.setID(IDcontatore++);
    Transazioni.push_back(Transazione);
    WriteTransactionOnFile(Percorso,Transazioni);
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
            WriteTransactionOnFile(ViewTransaction,Transazioni);
            return;
        }
    }
    cerr <<"Transazione con ID: "<<ID<<" non trovata."<<endl;//TODO:lanciare eccezione
}

void ContoCorrente::deleteTransazione(int ID) {
    //Tramite ID vado a rimuovere la transazioni dal file e dal vettore
    auto it = std::remove_if(Transazioni.begin(), Transazioni.end(), [ID](const Transazione& t) {
       return t.getID() == ID; // Ritorna true se l'ID corrisponde
   });

    if (it != Transazioni.end()) {
        Transazioni.erase(it, Transazioni.end()); // Rimuovi le transazioni trovate
        WriteTransactionOnFile(ViewTransaction,Transazioni);
    } else {
        cerr << "Transazione con ID " << ID << " non trovata." << std::endl; //TODO:lanciare eccezione// Messaggio di errore se non trovata
    }
}
Transazione ContoCorrente::searchTransazione()const{
}
void ContoCorrente::WriteTransactionOnFile(std::string fileName, std::vector<Transazione> &transazioni) {
    ofstream fout(fileName);
    int count = 0; //tenere di conto del numero di transazioni

    for (auto& transazione : transazioni) {
        fout << transazione.getInfo() << std::endl; // Scrive l'info della transazione

        count++;
    }

    fout << "Numero di transazioni eseguite : "<< count << endl;

    //Oppure contando gli elementi nell vettore

    fout.close(); // Chiudi il file
}
void ContoCorrente::LoadTransactionFromFile(std::string fileName, std::vector<Transazione> &transazioni) {
    ifstream fin(fileName);
    std::string input;

    while (getline(fin, input)) {
        istringstream iss(input);

        int id, importo;
        std::string in, data, conciliata, id_label;

        // Estrai la riga
        if (!(iss >> id_label >> id >> importo >> in >> data)) {
            std::cerr << "Errore: Formato della transazione non valido."<<std::endl; //TODO: lanciare eccezione
            continue;
        }


        getline(iss, conciliata);


        bool opt;
        if (in == "Entrata") {
            opt = true;
        } else if (in == "Uscita") {
            opt = false;
        } else {
            std::cerr << "Errore: Formato 'Entrata/Uscita' non valido nella transazione.";
            continue;
        }


        bool conc = (conciliata == " Conciliata");


        Transazione temp = Transazione(importo, opt, data, conc);
        addTransazione(temp, "");


        WriteTransactionOnFile(ViewTransaction, transazioni);
    }
}


void ContoCorrente::ConciliaTransaction(Transazione &transazione, const std::string& estrattoConto, std::vector<Transazione> &transazioni) {
    ifstream fin(estrattoConto);  // Apro l'estratto conto
    std::string input;

    while (getline(fin, input)) {

        std::istringstream iss(input);
        int id,importo;
        std::string idLabel, tipo, data, statoConciliazione;

        iss >> idLabel >> id >> importo >> tipo >> data;
        getline(iss, statoConciliazione);

        bool tipoIn = (tipo == "Entrata");

        if (transazione.getImporto() == importo &&
            transazione.getIn() == tipoIn &&
            transazione.getData() == data) {
            //Cerca corrispondenze
            for (auto &trans : transazioni) {
                if (trans.getImporto() == importo &&
                    trans.getIn() == tipoIn &&
                    trans.getData() == data) {
                    transazione.setConciliata(true);
                    trans.setConciliata(true);
                    WriteTransactionOnFile(ViewTransaction, transazioni);
                    return;
                    }
            }
            }
    }

    cerr << "La transazione ID: "+std::to_string(transazione.getID())+" non è ancora conciliata" << endl; //TODO: lanciare eccezione

}

void ContoCorrente::ConciliaAllTransactions(std::string estrattoConto, std::vector<Transazione> &transazioni) {
    ifstream fin(estrattoConto);
    std::string input;

    while (getline(fin, input)) {
        std::istringstream iss(input);
        std::string idLabel, tipo, data, statoConciliazione;
        int id, importo;

        iss >> idLabel >> id >> importo >> tipo >> data;
        getline(iss, statoConciliazione);

        bool tipoIn = (tipo == "Entrata");

        for (auto &transazione : transazioni) {
            if (transazione.getImporto() == importo &&
                transazione.getIn() == tipoIn &&
                transazione.getData() == data) {
                transazione.setConciliata(true);
                }
        }
    }
    //Check di tutte le transazioni che siano conciliate -> Altrimenti notifica
    for(auto &transazione : transazioni){
        //verifica che siano conciliate
        if(!transazione.getConciliata()){
            std::cerr << "Ci sono alcune transazioni non conciliate, verifica l'estratto conto\n"; //TODO: lanciare eccezione
        }
    }
    WriteTransactionOnFile(ViewTransaction, transazioni);
}


std::vector<Transazione> ContoCorrente::getTransazioni() const {
    return Transazioni;
}









