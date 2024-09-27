#include "ContoCorrente.h"
#include "FileManager.h"
#include "Transazione.h"
#include <fstream>
#include <string>
#include <sstream>


using namespace std;

void FileManager::CaricaTransazioniDaFile(std::string nomeFile, ContoCorrente& CC) {

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
        bool conc = conciliata == "Conciliata" ? true:false;

        Transazione temp = Transazione(importo,opt,data,conc);

        CC.addTransazione(temp);

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

