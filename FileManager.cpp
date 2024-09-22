//
// Created by Riccardo fantechi on 20/09/24.
//

#include "FileManager.h"
#include "Transazione.h"
#include "ContoCorrente.h"
#include <fstream>
#include <sstream>

using namespace std;

void FileManager::ReadExtractFile(std::string pos, ContoCorrente &cc) {
    //pos è la stringa della posizione del file da leggere
    //Ciclo while che prende riga per riga le transazioni e ne crea di nuove
    std::ifstream fin(pos);
    std::string input;

    while(std::getline(fin,input)) {
        //prendo la seingola linea dal file aperto e la salvo come stringa su input

        istringstream iss (input);
        int x;
        string opt;
        string data;
        bool In;

        if(iss >> x >> opt >> data) {
            //salvo nelle variabili i valori delle transazioni e vado a crearne una nuova
            if(opt == "Entrata") {
                In = true;
            }else In = false;

            Transazione t1 = Transazione(x,In,data);

            cc.EseguiTransazione(t1);

        }
    }


}
