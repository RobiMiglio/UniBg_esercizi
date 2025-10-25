/*
Leggere da tastiera:
- il nome di un file
- il numero di nomi da inserire

Leggere i nomi da tastiera, ordinarli in ordine alfabetico
e salvarli, uno per riga, nel file.
*/

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

#define MAX_NOMI 200
#define MAX_LEN 50

void ordina(char arr[][MAX_LEN], int n)
{
    bool ok = true;
    while(ok)
    {
        ok = false;
        for(int i=0; i<n-1; i++)
        {
            if(strcmp(arr[i], arr[i+1]) > 0)
            {
                char tmp[MAX_LEN];
                strcpy(tmp, arr[i]);
                strcpy(arr[i], arr[i+1]);
                strcpy(arr[i+1], tmp);
                ok = true;
            }
        }
    }
}

int main()
{
    char nomeFile[100];
    int n;

    cout << "Nome file: ";
    cin.getline(nomeFile, 100);

    cout << "Quanti nomi? ";
    cin >> n;
    cin.ignore();

    char nomi[MAX_NOMI][MAX_LEN];

    cout << "Inserisci i nomi:\n";
    for(int i=0; i<n; i++)
        cin.getline(nomi[i], MAX_LEN);

    ordina(nomi, n);

    ofstream fout(nomeFile);
    if(fout.fail())
    {
        cout << "Errore apertura file\n";
        return 1;
    }

    for(int i=0; i<n; i++)
        fout << nomi[i] << endl;

    fout.close();
    return 0;
}
