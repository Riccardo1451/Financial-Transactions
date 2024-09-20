#include <iostream>
#include "Transazione.h"
#include "ContoCorrente.h"


using namespace std;

int main() {
    ContoCorrente c1 = ContoCorrente("Riccardo",4000);
    Transazione t1 = Transazione(500,true,"11-02-24");
    Transazione t2 = Transazione(600,true,"16-02-24");
    Transazione t3 = Transazione(200,false,"19-02-24");

    c1.EseguiTransazione(t1);
    cout <<"Saldo dopo la prima transazione"<<c1.getSaldo()<<endl;
    c1.EseguiTransazione(t2);
    cout <<"Saldo dopo la seconda transazione"<<c1.getSaldo()<<endl;
    c1.EseguiTransazione(t3);
    cout <<"Saldo dopo la terza transazione"<<c1.getSaldo()<<endl;
}

