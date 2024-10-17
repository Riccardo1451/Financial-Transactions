//
// Created by Riccardo fantechi on 19/09/24.
//

#ifndef TRANSAZIONE_H
#define TRANSAZIONE_H
#include <string>

//IDEA: classe che permette di operare sul conto corrente entrata e uscita

class Transazione {

public:
    Transazione(int Importo, bool in, std::string data, bool conciliata=false);

    int getImporto() const;
    void setImporto(int valore);

    bool getIn() const;
    void setIn(bool opzione);

    bool getConciliata();
    void setConciliata(bool opt);

    std::string getData();
    void setData(std::string data);

    bool validaData(std::string exemp);

    std::string getInfo();

    int getID() const;
    void setID(int value);


private:
    int Importo;
    bool In; //True se l'operazione è in entrata, False altrimenti
    std::string data;

    bool Conciliata;

    int ID; //Attributo UNIVOCO che mi permette di identificare univocamente ogni transazione

    friend class FileManagerTest_TestGestioneFile_Test;

};
#endif //TRANSAZIONE_H
