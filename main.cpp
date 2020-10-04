#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <math.h>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void leer();
void participante();

int main(int argc, char** argv) {

    leer();
    participante();
    return EXIT_SUCCESS;
}

void leer() {
    string nombre;
    ifstream infile("products_taller.csv");
    string line = "   ";
    vector<string> datos_csv;
    while (getline(infile, line))
    {
        stringstream strstr(line);
        string word="  ";
        while(getline(strstr,word,';'))
        {
            datos_csv.push_back(word);
        }
    }
    //--------------------------------------
    string nombre2;
    ifstream infile2("trx_taller.csv");
    string line2 = "   ";
    vector<string> datos_csv2;
    while (getline(infile2, line2))
    {
        stringstream strstr2(line2);
        string word2="  ";
        while(getline(strstr2,word2,';'))
        {
            datos_csv2.push_back(word2);
        }
    }



    cout << datos_csv.size() << endl;
    string codigo;
    int cantidad,aux;
    string aux2;
    int *aux4;
    int val= datos_csv.size();
    int val2= datos_csv2.size();
    for(int i=0; i< val; i=i+3)
    {
        //.at para obtener el dato en este caso en la posicion i
        cantidad=0;
        codigo= datos_csv.at(i);
        for (int j=0; j<val2; j=j+3)
        {
            //"buscando para codigo: "<<datos_csv.at(i)<< endl;
            if (codigo==datos_csv2.at(j))
            {

                aux2=(datos_csv2.at(j+1));
                //cout<<aux2<<endl;
                //std::istringstream (aux2)>>aux;
                //aux=std::stoi
                //if(sscanf(aux2.c_str(), "%d", &aux4) != 1)
                //aux4=aux;

                cantidad++;
                //cout<<"aux4 ="<<*aux4<<endl;
                //cout<<"aux2="<<aux2<<endl;
                //cout<<"catidad="<<cantidad<<endl;
            }
        }
        cout<< "La cantidad de:"<<datos_csv.at(i+1)<<" es de: "<<cantidad<<endl;
    }


    system("pause");
}

void participante() {
    std::cout << std::endl << "=== TALLER ===" << std::endl;
    std::cout << std::endl << "Sion-Jei Mamani León" << std::endl;
    std::cout << std::endl << "Javier Silva Gómez"<< std::endl;
}
