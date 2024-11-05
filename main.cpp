#include <iostream>
#include "Transazione.h"
#include "ContoCorrente.h"
#include <fstream>

//Non serve includere il File Manager, viene usato implicitamente dal conto corrente


using namespace std;

int main() {
    //Indirizzi dei file.txt
    std::string ListaTransazioni = "/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/FileTesto/VisualizzaTransazioni.txt";
    std::string Estratto = "/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/FileTesto/Estratto.txt";
    std::string ListaUpload = "/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/FileTesto/ListaTransazioni.txt";

    //Creazione di un conto corrente
    ContoCorrente c1 = ContoCorrente("Riccardo");

    //Creazione transazioni, non hanno ancora un ID associato
    Transazione t1 = Transazione(700, false, "12-03-2007");
    Transazione t2 = Transazione(400, false, "10-09-2007");
    Transazione t3 = Transazione(100, true, "16-05-2010");


    //Aggiunte al conto corrente ricevono un ID univoco
    c1.addTransazione(t1, ListaTransazioni);
    c1.addTransazione(t2, ListaTransazioni);
    c1.addTransazione(t3, ListaTransazioni);

    //Funzione di modifica
    c1.modTransazione(2,300,false,"12-03-2000");

    c1.modTransazione(3,1000,true,"14-01-2003");

    //Funzione di cancellazione
    c1.deleteTransazione(1);


    Transazione t4 = Transazione(20, false, "16-07-2030");


    c1.addTransazione(t4, ListaTransazioni);

    //Funzione di aggiunta di transazioni da file
    c1.LoadTransactionFromFile(ListaUpload);

    c1.deleteTransazione(6);

    Transazione t5 = Transazione(5,false,"15-02-1994");

    c1.addTransazione(t5, ListaTransazioni);

    //Funzione di controllo della conciliazione
    c1.ConciliaTransaction(t5,Estratto);

    //Test di conciliazione di tutte le transazioni
    //c1.checkAllTransaizoni(Estratto);

}

