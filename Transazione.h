//
// Created by Riccardo fantechi on 19/09/24.
//

#ifndef TRANSAZIONE_H
#define TRANSAZIONE_H
#include <string>

//IDEA: classe che permette di operare sul conto corrente entrata e uscita

class Transazione {

public:
    Transazione(int Saldo, bool in, std::string data);

    int getSaldo() const;
    void setSaldo(int valore);

    bool getIn() const;
    void setIn(bool opzione);

    std::string getData();
    void setData(std::string data);

    std::string getInfo();


private:
    int Saldo;
    bool In; //True se l'operazione è in entrata, False altrimenti
    std::string data;
    //TODO: Aggiungere attributo conciliato -> Controllano l'estratto conto (verificano)
};
#endif //TRANSAZIONE_H
