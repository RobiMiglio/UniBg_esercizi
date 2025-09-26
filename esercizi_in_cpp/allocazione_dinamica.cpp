// ⚙️ DOMANDA 12 – Allocazione dinamica e copia profonda
// Scrivi un programma che:
//
// 1️⃣ Crei dinamicamente un array di interi di dimensione scelta dall’utente.
// 2️⃣ Inizializzi l’array con valori inseriti da tastiera.
// 3️⃣ Implementi una funzione `copiaArray()` che:
//        - Riceve un puntatore e una dimensione,
//        - Alloca un nuovo array della stessa dimensione,
//        - Copia tutti i valori e restituisce il nuovo puntatore.
// 4️⃣ Nel main() mostra che modificare il nuovo array
//     NON influenza quello originale (cioè fa una copia profonda).
// 5️⃣ Libera tutta la memoria.
//
// 🔍 DOMANDA TEORICA:
// - Cos’è una *copia profonda* (deep copy) e in cosa differisce da una *copia superficiale* (shallow copy)?
// - In che situazioni è indispensabile usarla in C o C++ (esempi tipici)?
//
// BONUS 💡: implementa anche una funzione `stampaArray()` per stampare facilmente gli array.

#include <iostream>

using namespace std;

int* copiaArray(int *p, int size)
{
    int *newp = new int[size];
    for(int i=0; i<size; i++)
    {
        newp[i] = p[i];
    }
    return newp;
}

int main()
{
    int sizeArray = 0;
    cout << "inserisci dimensione array: ";
    cin >> sizeArray;

    int *arrayDinamico = new int[sizeArray];

    for(int i=0; i<sizeArray; i++)
    {
        cout << "inserire il " << i+1 << " ° elemento dell'array: " << endl;
        cin >> arrayDinamico[i];
    }

    int *arrayCopiato = copiaArray(arrayDinamico, sizeArray);

    //modifico nuovo array
    for(int i=0; i<sizeArray; i++)
    {
        arrayCopiato[i] += 1;
    }

    //stampo entrambi array così verifico che la modifica al secondo array non inficia su quello originale
    cout << "array originale\t\tarray copiato\n";
    cout << "----------------\t-------------\n";
    for(int i=0; i<sizeArray; i++)
    {
        cout << arrayDinamico[i] << "\t\t\t" << arrayCopiato[i] << endl;
    }

    delete[] arrayDinamico;
    delete[] arrayCopiato;

    return 0;
}


/*
💡 Parte teorica

✅ Definizione corretta:

La copia profonda crea un nuovo spazio in memoria e copia effettivamente i dati.
La copia superficiale invece copia solo il puntatore, perciò entrambi gli oggetti condividono la stessa area di memoria.

✅ Quando serve:

In classi che gestiscono risorse dinamiche (es. array, buffer, file).

Quando implementi un costruttore di copia personalizzato per evitare aliasing tra oggetti.

Tipico esempio: classi che contengono puntatori, tipo

class Stringa { char* testo; ... };

⭐ Concetto chiave da ricordare

Deep copy → 2 blocchi di memoria indipendenti
Shallow copy → 2 puntatori allo stesso blocco
BONUS:
void stampaArray(int *p, int size)
{
   for(int i=0; i<size; i++)
   {
        cout << i+1 << "° elemento dell'array: " << p[i] << endl;
   }
}

*/