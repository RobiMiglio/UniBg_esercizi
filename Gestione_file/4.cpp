/*
Leggere dal file "dati.txt" tutti i numeri interi presenti.
Salvarli nell’array int valori[200].
Calcolare e stampare la somma di tutti i numeri letti.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    ifstream fin("dati.txt");
    if(fin.fail())
    {
        cout << "Errore apertura file" << endl;
        exit(1);
    }

    int valori[200];
    int i = 0;

    while(i < 200 && fin >> valori[i])
    {
        i++;
    }

    int somma = 0;
    for(int j = 0; j < i; j++)
    {
        somma += valori[j];
    }

    cout << "Somma = " << somma << endl;

    fin.close();
    return 0;
}
