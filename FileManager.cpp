#include "ContoCorrente.h"
#include "FileManager.h"
#include <cstdio>
#include <fstream>
#include <string>


using namespace std;

void FileManager::CaricaTransazioniDaFile(std::string nomeFile, std::vector<Transazione> &transazioni) {

}

void FileManager::ScriviTransazioniSuFile(std::string nomeFile, vector<Transazione> &transazioni) {
    ofstream fout(nomeFile);

    for (auto& transazione : transazioni) {
        fout << transazione.getInfo() << std::endl; // Scrive l'info della transazione
    }

    fout.close(); // Chiudi il file
}

