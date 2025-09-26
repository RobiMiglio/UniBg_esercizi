/*
================================================================================
DOMANDA 13 – Gestione dinamica e ordinamento
================================================================================

Devi scrivere un programma che gestisca un elenco dinamico di temperature
giornaliere (float), permettendo:

1. Inserimento di valori fino a quando l’utente digita un numero negativo.
2. Stampa di tutte le temperature inserite.
3. Calcolo della media.
4. Ordinamento crescente dei valori (usa bubble sort o algoritmo semplice).

📌 Vincoli:
- Non puoi usare std::sort o librerie esterne.
- Devi gestire la memoria dinamicamente (simile a malloc/realloc in C).
- Usa la sintassi C++ ma “stile C”.

--------------------------------------------------------------------------------
Domanda teorica:
- Spiega la differenza tra allocazione automatica, statica e dinamica in C/C++.
- Cosa succede se dimentichi di liberare la memoria allocata dinamicamente?
================================================================================
*/

#include <iostream>

using namespace std;

int main()
{
    int capienza = 2;
    float *temperature = new float[capienza];
    int totaleValori = 0;
    float temp = 0;

    do
    {
        cout << "inserisci temperatura (numero negativo per terminare): ";
        cin >> temp;
        if(temp >= 0)
        {
            if(totaleValori == capienza) 
            {
                capienza *= 2;
                float *nuovo = new float[capienza];
                for(int i=0; i<totaleValori; i++)
                {
                    nuovo[i] = temperature[i];
                }
                delete[] temperature;
                temperature = nuovo;
            }
        
            temperature[totaleValori++] = temp;
        }
    } while (temp >= 0);
    
    //stampa di tutte le temperature e calcolo media valori
    float media = 0;
    for(int i=0; i<totaleValori; i++)
    {
        cout << i+1 << "° temperatura: " << temperature[i] << endl;
        media += temperature[i];
    }
    media /= totaleValori;
    
    //stampa media
    cout << "la media è: " << media << endl;

    //stampare in ordine crescente le temperature
    for(int i = 0; i < totaleValori - 1; i++)
    {
        for(int j = 0; j < totaleValori - i - 1; j++)
        {
            if(temperature[j] > temperature[j + 1])
            {
                float trash = temperature[j];
                temperature[j] = temperature[j + 1];
                temperature[j + 1] = trash;
            }
        }
    }

    cout << "stampa in ordine crescente: " << endl;
    for(int i=0; i<totaleValori; i++)
    {
        cout << i+1 << "° temperatura: " << temperature[i] << endl;
    }

    delete[] temperature;

    return 0;
}