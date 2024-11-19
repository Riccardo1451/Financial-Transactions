
#include "ContoCorrente.h"
#include "ObjectNotFound.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#include "ObjectNotReady.h"

using namespace std;

std::string ViewTransaction ="/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/FileTesto/VisualizzaTransazioni.txt";

ContoCorrente::ContoCorrente(std::string Nome, int Budget) : Intestatario(Nome),IDcontatore(1){}

std::string ContoCorrente::getNome() const {
    return Intestatario;
}
void ContoCorrente::addTransazione(Transazione& transazione, std::string Percorso) {
    //Gestione budget
    if (transazione.getIn())
        Budget += transazione.getImporto();
    else
        Budget -= transazione.getImporto();

    //Viene passata una transazione da inserire nel file delle transazioni
    transazione.setID(IDcontatore++);
    Transazioni[transazione.getID()] = transazione;

    WriteTransactionOnFile(Percorso,Transazioni);
    //Vado a scrivere sul file estratto ogni operazione
}

void ContoCorrente::modTransazione(int ID, int nuovoImporto, bool nuovoIn, std::string nuovaData) {
    //Con una struttura map utilizziamo find(ID) per cercare direttamente la relativa transazione eliminando il ciclo for
    auto it = Transazioni.find(ID);

    if (it != Transazioni.end()){ //se la transazione esiste
        Transazione& transazione = it->second; //recupero la transazione

        //Gestione dell'attributo Budget
        if (transazione.getIn()) {
            //controllo se la transazione da modificare era in ingresso o uscita
            Budget -= transazione.getImporto();
            if (nuovoIn) //se la nuova transazione è in ingresso sommo altrimento sottraggo
                Budget += nuovoImporto;
            else
                Budget -= nuovoImporto;
        } else {
            Budget += transazione.getImporto();
            if (nuovoIn)
                Budget += nuovoImporto;
            else
                Budget -= nuovoImporto;
        }
        //modifico la transazione che è un riferimento all'oggetto
            transazione.setImporto(nuovoImporto);
            transazione.setIn(nuovoIn);
            transazione.setData(nuovaData);
            cout<<"Transazione con ID: "+std::to_string(transazione.getID())+" modificata correttamente"<<std::endl;
            WriteTransactionOnFile(ViewTransaction,Transazioni);
        }
    else throw ObjectNotFound("Transazione "+to_string(ID)+" non trovata");
}

void ContoCorrente::deleteTransazione(int ID) {
    //Tramite il metodo find cerco la transazione e la elimino
    auto it = Transazioni.find(ID);

    if(it != Transazioni.end()) {
        if(it->second.getIn())
            Budget -= it->second.getImporto();
        else
            Budget += it->second.getImporto();


        Transazioni.erase(it); // Rimuovi le transazioni trovate
        WriteTransactionOnFile(ViewTransaction,Transazioni);
    } else {
        throw ObjectNotFound("La transazione con ID: "+to_string(ID)+" non è stata trovata");
    }
}

std::map<int,Transazione> ContoCorrente::searchTransazione(Transazione transazione)const{
    std::map <int,Transazione> result;
    auto it = Transazioni.find(transazione.getID());

    if(it != Transazioni.end()) {
        result[it->first] = it->second;
    }
    return result; //altrimente ritorna una map vuota
}

void ContoCorrente::WriteTransactionOnFile(std::string fileName, std::map<int, Transazione> &transazioni) {
    ofstream fout(fileName);

    /*if(!fout.is_open()) {
        throw runtime_error("Errore: impossibile aprire il file di testo");
    }*/

    for (const auto& [id,transazione] : transazioni) {
        fout << transazioni[id].getInfo() << std::endl; // Scrive l'info della transazione
    }

    fout << "Numero di transazioni eseguite : "<< transazioni.size() << endl;

    //Sappiamo direttamente la size della map

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
    fin.close();
}


void ContoCorrente::ConciliaTransaction(Transazione &transazione, const std::string& estrattoConto) {
    ifstream fin(estrattoConto);// Apro l'estratto conto
    if(!fin.is_open()) {
        throw runtime_error("Errore: impossibile aprire il file di testo");
    }

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
            //Troviamo la transazione con il metodo find
            auto it = Transazioni.find(transazione.getID());
            if (it != Transazioni.end()) {
                transazione.setConciliata(true);
                it->second.setConciliata(true);

                WriteTransactionOnFile(ViewTransaction, Transazioni);
                return;
            }
        }
    }
    throw ObjectNotReady("La transazione ID: "+to_string(transazione.getID())+" non è ancora conciliata");

}

void ContoCorrente::ConciliaAllTransactions(const std::string& estrattoConto) {
    ifstream fin(estrattoConto);
    if(!fin.is_open()) {
        throw runtime_error("Errore: impossibile aprire il file di testo");
    }
    std::string input;

    while (getline(fin, input)) {
        std::istringstream iss(input);
        std::string idLabel, tipo, data, statoConciliazione;
        int id, importo;

        iss >> idLabel >> id >> importo >> tipo >> data;
        getline(iss, statoConciliazione);

        bool tipoIn = (tipo == "Entrata");

        for (auto &transazione : Transazioni) {
            if (transazione.second.getImporto() == importo &&
                transazione.second.getIn() == tipoIn &&
                transazione.second.getData() == data) {
                transazione.second.setConciliata(true);
                }
        }
    }
    //Check di tutte le transazioni che siano conciliate -> Altrimenti notifica
    for(auto& transazione : Transazioni){
        //verifica che siano conciliate
        if(!transazione.second.getConciliata()){
            throw ObjectNotReady("Ci sono alcune transazioni non ancora conciliate, verifica l'estratto conto");
        }
    }
    WriteTransactionOnFile(ViewTransaction, Transazioni);
}


std::map<int, Transazione> &ContoCorrente::getTransazioni(){
    return Transazioni;
}

int ContoCorrente::getBudget() const {
    return Budget;
}









