#include <iostream>
#include "Transazione.h"
#include "ContoCorrente.h"
#include "FileManager.h"
#include <fstream>
#include <sstream>



using namespace std;

int main() {
    ContoCorrente c1 = ContoCorrente("Riccardo",4000);
    FileManager fm = FileManager();
    /*Transazione t1 = Transazione(500,true,"11-02-24");
    Transazione t2 = Transazione(600,true,"16-02-24");
    Transazione t3 = Transazione(200,false,"19-02-24");

    c1.EseguiTransazione(t1);
    cout <<"Saldo dopo la prima transazione"<<c1.getSaldo()<<endl;
    c1.EseguiTransazione(t2);
    cout <<"Saldo dopo la seconda transazione"<<c1.getSaldo()<<endl;
    c1.EseguiTransazione(t3);
    cout <<"Saldo dopo la terza transazione"<<c1.getSaldo()<<endl;*/

    /*ofstream fout("/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/Estratto.txt"); //ios::app permentte di non sovrascrivere il file
    fout << t3.getInfo();
    fout.close();


    char c;
    ifstream fin("/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/Estratto.txt");
    while(fin.get(c)){
        cout << c;
    }

    fin.close();*/

    /*ifstream fin("/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/Estratto.txt"); //apertura del file
    std::string input;
   while( std::getline(fin,input)) {
       //vado a prendere la linea e con il ciclo while posso prenderne una ad una ed inserirla nella variabile input

       istringstream iss(input); //prendo input
       int x;
       std::string In;
       std::string data;

       if (iss >> x >> In >> data) {
           // con l'operatore >> posso estrarre l'input (divisi da spazi) e salvarlo nelle variabili
           std::cout << "Importo: " << x << std::endl;
           std::cout << "In: " << In << std::endl;
           std::cout << "Data: " << data << std::endl;

       } else {
           std::cerr << "Errore nella lettura dei dati." << std::endl;
       }
   }
    fin.close();*/

    fm.ReadExtractFile("/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/Transazioni.txt",c1);



}

