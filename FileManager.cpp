#include "ContoCorrente.h"
#include "FileManager.h"
#include "Transazione.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>


using namespace std;
std::string VisualizzaTransazioni = "/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/FileTesto/VisualizzaTransazioni.txt";

void FileManager::CaricaTransazioniDaFile(std::string nomeFile, vector<Transazione> &transazioni, ContoCorrente& cc) {
    ifstream fin(nomeFile);
    std::string input;

    while (getline(fin, input)) {
        istringstream iss(input);

        int id, importo;
        std::string in, data, conciliata, id_label;

        // Estrai la riga
        if (!(iss >> id_label >> id >> importo >> in >> data)) {
            std::cerr << "Errore: Formato della transazione non valido."<<std::endl;
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
        cc.addTransazione(temp, "");


        ScriviTransazioniSuFile(VisualizzaTransazioni, transazioni);
    }
}


void FileManager::ScriviTransazioniSuFile(std::string nomeFile, vector<Transazione> &transazioni) {
    ofstream fout(nomeFile);
    int count = 0; //tenere di conto del numero di transazioni

    for (auto& transazione : transazioni) {
        fout << transazione.getInfo() << std::endl; // Scrive l'info della transazione

        count++;
    }

    fout << "Numero di transazioni eseguite : "<< count << endl;

    //Oppure contando gli elementi nell vettore

    fout.close(); // Chiudi il file
}
void FileManager::ConciliaTransazione(Transazione &transazione, std::string estrattoConto, std::vector<Transazione> &transazioni) {
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
                    ScriviTransazioniSuFile(VisualizzaTransazioni, transazioni);
                    return;
                    }
            }
            }
    }

    cerr << "La transazione ID: "+std::to_string(transazione.getID())+" non è ancora conciliata" << endl;
}


void FileManager::ConciliaAllTransazioni(std::string estrattoConto, std::vector<Transazione> &transazioni) {
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
        std::cerr << "Ci sono alcune transazioni non conciliate, verifica l'estratto conto\n";
      }
    }
    ScriviTransazioniSuFile(VisualizzaTransazioni, transazioni);
}



