
/*
sfida 1

Scrivere un programma che legge da tastiera una
sequenza di noni;
l'inserimento termina quando l'utente inserisce il nome
"ESCI";
terminata la lettura, il programma stampa il nome
alfabeticamente piò grande.
Facoltativo: dopo aver letto un nome, convertire tutte
le sue lettere in maiuscolo, scrivendo e chiamando la
funzione
void maiuscolo(char s[]);

*/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N_NOMI 10
#define MAX_LUNGHEZZA_NOME 15

void maiuscolo(char s[])
{
    for(int i = 0; s[i] != '\0'; i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
            s[i] -= 32;   // minuscolo -> MAIUSCOLO
    }
}

int main()
{
    char nomi[MAX_N_NOMI][MAX_LUNGHEZZA_NOME];
    int n = 0;

    while (n < MAX_N_NOMI)
    {
        cout << "Inserisci un nome (oppure ESCI per terminare): ";
        cin.getline(nomi[n], MAX_LUNGHEZZA_NOME);

        maiuscolo(nomi[n]);

        if (strcmp(nomi[n], "ESCI") == 0)
            break;

        n++;
    }

    if (n == 0)
    {
        cout << "Nessun nome inserito." << endl;
        return 0;
    }

    // Trova il più grande alfabeticamente
    int indiceMax = 0;
    for (int i = 1; i < n; i++)
    {
        if (strcmp(nomi[i], nomi[indiceMax]) > 0)
            indiceMax = i;
    }

    cout << "\nIl nome alfabeticamente più grande è: " 
         << nomi[indiceMax] << endl;

    return 0;
}
