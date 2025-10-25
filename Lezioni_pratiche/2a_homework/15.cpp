/*

Esercizio 15
Scrivere un programma che dati 2 “insiemi” di numeri interi, calcoli l'intersezione di questi
due insiemi. Gli insiemi sono memorizzati negli array 'ins1' (di lunghezza N) e 'ins2' (di
lunghezza M), mentre l'insieme intersezione è contenuto nell'array 'ins_int'.

*/
#include <iostream>
using namespace std;

#define N 6
#define M 4

int main() {
    int ins1[N] = {1,2,3,4,5,1};
    int ins2[M] = {1,2,3,1};

    // Rimuovi duplicati da ins1
    int nuovoArray1[N];
    int size1 = 0;
    for (int i = 0; i < N; i++)
    {
        bool giaPresente = false;
        for (int j = 0; j < size1; j++) 
        {
            if (ins1[i] == nuovoArray1[j]) 
            {
                giaPresente = true;
                break;
            }
        }
        if (!giaPresente) nuovoArray1[size1++] = ins1[i];
    }

    // Rimuovi duplicati da ins2
    int nuovoArray2[M];
    int size2 = 0;
    for (int i = 0; i < M; i++) 
    {
        bool giaPresente = false;
        for (int j = 0; j < size2; j++) 
        {
            if (ins2[i] == nuovoArray2[j]) 
            {
                giaPresente = true;
                break;
            }
        }
        if (!giaPresente) nuovoArray2[size2++] = ins2[i];
    }

    // Trova intersezione
    int ins_int[N < M ? N : M];
    int cont = 0;
    for (int i = 0; i < size1; i++) 
    {
        for (int j = 0; j < size2; j++) 
        {
            if (nuovoArray1[i] == nuovoArray2[j]) 
            {
                ins_int[cont++] = nuovoArray1[i];
                break;
            }
        }
    }

    // Stampa risultato
    cout << "Intersezione: ";
    for (int i = 0; i < cont; i++) 
    {
        cout << ins_int[i] << " ";
    }
    cout << endl;

    return 0;
}
