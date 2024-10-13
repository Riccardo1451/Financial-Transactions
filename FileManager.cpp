#include "ContoCorrente.h"
#include "FileManager.h"
#include "Transazione.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>


using namespace std;

void FileManager::CaricaTransazioniDaFile(std::string nomeFile, vector<Transazione> &transazioni, ContoCorrente& cc) {

    // il file deve essere scritto secondo il formato ID: int int stringa stringa stringa

    ifstream fin (nomeFile); //apro il file
    std::string input; //dove mantengo la riga temporaneamente

    while (getline(fin,input)) {
        istringstream iss(input); //riga nel file

        int id, importo;
        string in,data,conciliata;

        string id_label; //isolare ID:
        iss >> id_label >> id;

        iss >> importo >> in >> data;
        getline(iss,conciliata); //ci sono degli spazi

        //creo la transazione e la inserisco nel vettore

        bool opt = in == "Entrata" ? true:false;
        bool conc = conciliata == " Conciliata" ? true:false;

        Transazione temp = Transazione(importo,opt,data,conc);
        cc.addTransazione(temp,"");
        ScriviTransazioniSuFile("/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/Transazioni.txt",transazioni);

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
                    ScriviTransazioniSuFile("/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/Transazioni.txt", transazioni);
                    return;
                    }
            }
            }
    }

    cerr << "La transazione non è ancora conciliata" << endl;
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

    ScriviTransazioniSuFile("/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/Transazioni.txt", transazioni);
}



