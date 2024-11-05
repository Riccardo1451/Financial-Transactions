//
// Created by Riccardo fantechi on 20/09/24.
//

#include "ContoCorrente.h"
#include "ObjectNotFound.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#include "ObjectNotReady.h"

using namespace std;

std::string ViewTransaction ="/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/FileTesto/VisualizzaTransazioni.txt";

std::string ContoCorrente::getNome() const {
    return Intestatario;
}


ContoCorrente::ContoCorrente(std::string Nome, int Budget) : Intestatario(Nome),IDcontatore(1) {}



void ContoCorrente::addTransazione(Transazione &Transazione, std::string Percorso) {
    //Gestione budget
    if (Transazione.getIn())
        Budget += Transazione.getImporto();
    else
        Budget -= Transazione.getImporto();

    //Viene passata una transazione da inserire nel file delle transazioni
    Transazione.setID(IDcontatore++);
    Transazioni.push_back(Transazione);
    WriteTransactionOnFile(Percorso,Transazioni);
    //Vado a scrivere sul file estratto ogni operazione
}

void ContoCorrente::modTransazione(int ID, int nuovoImporto, bool nuovoIn, std::string nuovaData) {
    //Tramite ID posso prendere la transazioni relativa e modificarla
    for(auto& transazione : Transazioni) {
        if(transazione.getID() == ID) { //Gestione dell'attributo Budget
            if (transazione.getIn()){ //controllo se la transazione da modificare era in ingresso o uscita
                Budget -= transazione.getImporto();
                if(nuovoIn) //se la nuova transazione è in ingresso sommo altrimento sottraggo
                    Budget += nuovoImporto;
                else
                    Budget -= nuovoImporto;
            }
            else {
                Budget += transazione.getImporto();
                if (nuovoIn)
                    Budget += nuovoImporto;
                else
                    Budget -= nuovoImporto;
            }
            transazione.setImporto(nuovoImporto);
            transazione.setIn(nuovoIn);
            transazione.setData(nuovaData);
            cout<<"Transazione con ID: "+std::to_string(transazione.getID())+" modificata correttamente"<<std::endl;
            WriteTransactionOnFile(ViewTransaction,Transazioni);
            return;
        }
    }
    throw ObjectNotFound("Transazione "+to_string(ID)+" non trovata");
}

void ContoCorrente::deleteTransazione(int ID) {
    //Tramite ID vado a rimuovere la transazioni dal file e dal vettore
    auto it = std::remove_if(Transazioni.begin(), Transazioni.end(), [ID](const Transazione& t) {return t.getID() == ID;}); // Ritorna true se l'ID corrisponde;

    if (it != Transazioni.end()) {
        if(it->getIn())
            Budget -= it->getImporto();
        else
            Budget += it->getImporto();

        Transazioni.erase(it, Transazioni.end()); // Rimuovi le transazioni trovate
        WriteTransactionOnFile(ViewTransaction,Transazioni);
    } else {
        throw ObjectNotFound("La transazione con ID: "+to_string(ID)+" non è stata trovata");
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
void ContoCorrente::LoadTransactionFromFile(const std::string& fileName) {
    ifstream fin(fileName);
    std::string input;

    while (getline(fin, input)) {
        istringstream iss(input);

        int id, importo;
        std::string in, data, conciliata, id_label;

        // Estrai la riga
        if (!(iss >> id_label >> id >> importo >> in >> data)) {
            throw invalid_argument("Errore: formato della transazione non valido");
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


        WriteTransactionOnFile(ViewTransaction, Transazioni);
    }
}


void ContoCorrente::ConciliaTransaction(Transazione &transazione, const std::string& estrattoConto) {
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
            for (auto &trans : Transazioni) {
                if (trans.getImporto() == importo &&
                    trans.getIn() == tipoIn &&
                    trans.getData() == data) {
                    transazione.setConciliata(true);
                    trans.setConciliata(true);
                    WriteTransactionOnFile(ViewTransaction, Transazioni);
                    return;
                    }
            }
            }
    }
    throw ObjectNotReady("La transazione ID: "+to_string(transazione.getID())+" non è ancora conciliata");

}

void ContoCorrente::ConciliaAllTransactions(const std::string& estrattoConto) {
    ifstream fin(estrattoConto);
    std::string input;

    while (getline(fin, input)) {
        std::istringstream iss(input);
        std::string idLabel, tipo, data, statoConciliazione;
        int id, importo;

        iss >> idLabel >> id >> importo >> tipo >> data;
        getline(iss, statoConciliazione);

        bool tipoIn = (tipo == "Entrata");

        for (auto &transazione : Transazioni) {
            if (transazione.getImporto() == importo &&
                transazione.getIn() == tipoIn &&
                transazione.getData() == data) {
                transazione.setConciliata(true);
                }
        }
    }
    //Check di tutte le transazioni che siano conciliate -> Altrimenti notifica
    for(auto &transazione : Transazioni){
        //verifica che siano conciliate
        if(!transazione.getConciliata()){
            throw ObjectNotReady("Ci sono alcune transazioni non ancora conciliate, verifica l'estratto conto");
        }
    }
    WriteTransactionOnFile(ViewTransaction, Transazioni);
}


std::vector<Transazione> ContoCorrente::getTransazioni() const {
    return Transazioni;
}

int ContoCorrente::getBudget() const {
    return Budget;
}









