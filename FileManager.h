//
// Created by Riccardo fantechi on 20/09/24.
//

#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <cstdio>
#include <string>
#include "ContoCorrente.h"


class FileManager {
    //Classe per gestire lettura e scrittura
public:
    void ReadExtractFile(std::string pos, ContoCorrente &cc ); //IDEA: legge le transazioni da eseguire da un file, le crea e le esegue
    void WriteExtractFile(); //TODO:implementare possibile far scrivere al FM le transazioni ?

private:
};



#endif //FILEMANAGER_H
