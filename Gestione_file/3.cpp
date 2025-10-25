/*
Aprire il file "nomi.txt" in lettura.
Leggere tutti i nomi (uno per riga) nel vettore:
char lista[100][50];
Stampare tutti i nomi letti.
In caso di errore apertura file, terminare il programma.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    ifstream fin("nomi.txt");
    if(fin.fail())
    {
        cout << "Errore apertura file" << endl;
        exit(1);
    }

    char lista[100][50];
    int i = 0;

    while(i < 100 && fin.getline(lista[i], 50))
    {
        i++;
    }

    for(int j = 0; j < i; j++)
    {
        cout << lista[j] << endl;
    }

    fin.close();
    return 0;
}
