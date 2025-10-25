/*
Scrivere il codice necessario per:

1. dichiarare un ofstream
2. aprire un file chiamato "dati.txt" in modalità append
3. verificare che l’apertura non sia fallita
4. se fallisce, stampare "Errore apertura file"
5. altrimenti scrivere la parola "ciao" nel file
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    ofstream fout;

    fout.open("dati.txt", ios::app);
    if(fout.fail())
    {
        cout << "Errore apertura file" << endl;
        exit(1);
    }

    fout << "ciao" << endl;

    fout.close();

    return 0;
}
