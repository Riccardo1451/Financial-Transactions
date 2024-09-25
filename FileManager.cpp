#include "ContoCorrente.h"
#include "FileManager.h"
#include <cstdio>
#include <fstream>
#include <string>


using namespace std;

void FileManager::CaricaTransazioniDaFile(std::string nomeFile, std::vector<Transazione> &transazioni) {
    //TODO: da file esterno voglio prendere le transazioni e inserirle nel vettore per poi scriverle sul file
}

void FileManager::ScriviTransazioniSuFile(std::string nomeFile, vector<Transazione> &transazioni) {
    ofstream fout(nomeFile);

    for (auto& transazione : transazioni) {
        fout << transazione.getInfo() << std::endl; // Scrive l'info della transazione
    }

    fout.close(); // Chiudi il file
}

