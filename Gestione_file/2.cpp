/*
Aprire il file "input.txt".
Se l’apertura fallisce, stampare un messaggio.
Leggere una parola dal file in un array char parola[50].
Stampare la parola letta.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    ifstream fin;

    fin.open("input.txt");
    if(fin.fail())
    {
        cout << "Errore apertura file" << endl;
        exit(1);
    }

    char parola[50];

    fin.getline(parola, 50);

    cout << "parola letta: " << parola << endl;

    fin.close();

    return 0;
}
