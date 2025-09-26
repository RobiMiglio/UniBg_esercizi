/*
===========================================================
   MEGA TEST FINALE — DOMANDA 9 (versione semplificata)
   Argomenti: memoria dinamica 1D, aritmetica dei puntatori,
              passaggio di array a funzione
===========================================================

Scrivere un programma che gestisca **dinamicamente un array di interi**.

Il programma deve:
 - chiedere all’utente la dimensione dell’array;
 - allocare dinamicamente l’array;
 - riempirlo con valori casuali (1..100);
 - stampare tutti i valori usando **solo aritmetica dei puntatori**
   (senza usare la notazione `arr[i]`);
 - calcolare e restituire la media dei valori tramite una funzione esterna;
 - deallocare la memoria.

Esempio di output:
Dimensione array: 5  
Array: 42 87 13 9 64  
Media: 43.0

-----------------------------------------------------------
💭 Domande teoriche:
-----------------------------------------------------------

1️⃣ Qual è la differenza tra:
     - `arr[i]`
     - `*(arr + i)`
   A livello di accesso in memoria e di compilazione?

2️⃣ Perché, in una funzione che riceve un array,
    è sufficiente passare un `int *` e non serve indicare la dimensione?

===========================================================
Scrivi qui sotto il tuo codice 👇
===========================================================
*/


/*
===========================================================
   MEGA TEST FINALE — DOMANDA 9 (Soluzione corretta)
   Argomenti: memoria dinamica 1D, aritmetica dei puntatori,
              passaggio di array a funzione
===========================================================
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Funzione che calcola la media usando solo aritmetica dei puntatori
float media(int *arr, int size)
{
    int somma = 0;

    for (int i = 0; i < size; i++)
    {
        // CORRETTO: * (arr + i) dereferenzia l'elemento i-esimo
        somma += *(arr + i);
    }

    return static_cast<float>(somma) / size;
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    int size = 0;
    cout << "Inserisci la dimensione dell'array: ";
    cin >> size;

    // Alloca dinamicamente l’array
    int *array = new int[size];

    // Riempimento con numeri casuali
    for (int i = 0; i < size; i++)
    {
        *(array + i) = (rand() % 100) + 1; // assegna valore random
    }

    // Stampa con aritmetica dei puntatori
    cout << "\nArray:\n";
    for (int i = 0; i < size; i++)
    {
        cout << *(array + i) << " "; // NON *array + i, ma *(array + i)
    }

    cout << "\n";

    // Calcolo e stampa media
    cout << "Media: " << media(array, size) << endl;

    // Deallocazione
    delete[] array;

    return 0;
}

/*

-----------------------------------------------------------
💭 Risposte teoriche
-----------------------------------------------------------

1️⃣ Differenza tra arr[i] e *(arr + i):

✅ arr[i] è semplicemente **una forma sintattica alternativa** di *(arr + i).
   Il compilatore le traduce nello stesso codice macchina.

   arr[i] ≡ *(arr + i)
   *(arr + i) ≡ arr[i]

⚙️ Significato in memoria:
 - `arr` è un puntatore al primo elemento dell’array.
 - `arr + i` sposta l’indirizzo di `arr` di i posizioni (cioè di i * sizeof(int) byte).
 - L’operatore `*` dereferenzia quell’indirizzo, restituendo il valore.

Esempio:
   arr = 0x1000
   arr + 1 = 0x1004  (su architettura a 4 byte per int)
   *(arr + 1) = valore del secondo elemento.

-----------------------------------------------------------

2️⃣ Perché una funzione che riceve un array può dichiararsi come `int *arr`?

✅ Perché in C e C++, quando si passa un array come argomento,
   esso **decade automaticamente in un puntatore** al primo elemento.

   Quindi `int array[]` e `int *array` sono equivalenti come parametri di funzione.

⚠️ Tuttavia:
   - il puntatore NON conserva l’informazione sulla dimensione.
   - per questo, bisogna passare anche la lunghezza come parametro aggiuntivo (`int size`).

-----------------------------------------------------------
💡 Riepilogo visivo:

   [array]
   ↓
   +-----+-----+-----+-----+
   | 42  | 87  | 13  |  9  |
   +-----+-----+-----+-----+
     ↑
     arr (puntatore al primo elemento)

   arr + 2  → indirizzo del terzo elemento
   *(arr+2) → valore del terzo elemento (13)
-----------------------------------------------------------
*/
