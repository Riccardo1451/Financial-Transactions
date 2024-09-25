//
// Created by Riccardo fantechi on 20/09/24.
//

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Transazione.h"


class FileManager {
    //Classe per gestire lettura e scrittura da/su File txt
public:
    void ScriviTransazioniSuFile(std::string nomeFile, std::vector<Transazione> &transazioni);
    void CaricaTransazioniDaFile(std::string nomeFile, std::vector<Transazione> &transazioni);

private:
};



#endif //FILEMANAGER_H
