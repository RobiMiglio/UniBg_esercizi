/*
Scrivere un programma che legge da tastiera un nome
di file e un numero intero che indica quanti nominativi
leggere;
Leggere i nominativi nel numero indicato
precedentemente;
Salvarli sul file il cui nome ± stato inserito all'inizio
(un nominativo per riga) in ordine alfabetico.
*/
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

#define LUNGH_MAX_NOMINATIVI 30
#define DIM_MAX 1000

void riordinaPerAlfabeto(char arr[][LUNGH_MAX_NOMINATIVI], int size)
{
    bool scambiato;
    int limite = size - 1;
    int indice = 0;

    do
    {
        scambiato = false;
        indice = 0;
        for(int i=0; i<limite; i++)
        {
            if(strcmp(arr[i], arr[i+1]) > 0)
            {
                char temp[LUNGH_MAX_NOMINATIVI];
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[i+1]);
                strcpy(arr[i+1], temp);

                scambiato = true;
                indice = i;
            }
        }
        limite = indice;
    }
    while(scambiato && limite > 0);
}

int main()
{
    char nomeFile[DIM_MAX];
    int qtNominativi = 0;

    cout << "Inserire il nome del file: ";
    cin.getline(nomeFile, DIM_MAX);

    cout << "Inserisci il numero di nominativi: ";
    cin >> qtNominativi;
    cin.ignore(); // per pulire il buffer

    char arrayNominativi[qtNominativi][LUNGH_MAX_NOMINATIVI];

    // Lettura dei nominativi da tastiera
    cout << "Inserisci i " << qtNominativi << " nominativi:" << endl;
    for(int i=0; i<qtNominativi; i++)
    {
        cin.getline(arrayNominativi[i], LUNGH_MAX_NOMINATIVI);
    }

    // Ordinamento alfabetico
    riordinaPerAlfabeto(arrayNominativi, qtNominativi);

    // Scrittura su file
    ofstream fileOut;
    fileOut.open(nomeFile, ios::app);
    if(fileOut.fail())
    {
        cout << "Errore nell'apertura del file." << endl;
        return 1;
    }

    for(int i=0; i<qtNominativi; i++)
    {
        fileOut << arrayNominativi[i] << endl;
    }

    fileOut.close();

    cout << "Dati salvati correttamente nel file." << endl;

    return 0;
}
