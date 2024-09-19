//
// Created by Riccardo fantechi on 19/09/24.
//

#ifndef TRANSAZIONE_H
#define TRANSAZIONE_H
//IDEA: classe che permette di operare sul conto corrente entrata e uscita

class Transazione {

public:
    Transazione(int Valore, bool in);

    int getValore();
    bool getIn();
private:
    int Valore;
    bool in; //True se l'operazione è in entrata, False altrimenti
};
#endif //TRANSAZIONE_H
