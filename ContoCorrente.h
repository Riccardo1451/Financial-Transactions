//
// Created by Riccardo fantechi on 20/09/24.
//

#ifndef CONTOCORRENTE_H
#define CONTOCORRENTE_H
#include <string>


class ContoCorrente {

public:
    ContoCorrente(std::string Intestatario, int Saldo);


private:
    std::string Intestatario;
    int Saldo;
};



#endif //CONTOCORRENTE_H
