/*
Leggere da "input.txt" tutte le righe
e copiarle in "output.txt".
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    if(fin.fail())
    {
        cout << "Errore apertura file input" << endl;
        exit(1);
    }

    ofstream fout("output.txt");
    if(fout.fail())
    {
        cout << "Errore apertura file output" << endl;
        exit(1);
    }

    char riga[200];

    while(fin.getline(riga, 200))
    {
        fout << riga << endl;
    }

    fin.close();
    fout.close();

    return 0;
}
