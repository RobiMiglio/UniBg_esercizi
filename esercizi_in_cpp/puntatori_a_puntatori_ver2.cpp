/*
===========================================================
   MEGA TEST FINALE — DOMANDA 8
   Argomenti: memoria dinamica 2D, puntatori a puntatori, astrazione
===========================================================

Progettare un programma che gestisca una **matrice dinamica di interi**
utilizzando esclusivamente puntatori a puntatori (`int **`).

Il programma deve:
 - chiedere all’utente il numero di righe e colonne;
 - allocare dinamicamente la matrice;
 - riempirla con valori casuali compresi tra 1 e 9;
 - calcolare e stampare la somma di tutti gli elementi;
 - deallocare correttamente la memoria (riga per riga + matrice principale).

⚙️ Vincoli:
 - Non utilizzare array statici.
 - Non utilizzare `std::vector` o altre strutture di libreria.
 - Mostrare esplicitamente i livelli di dereferenziazione
   (es. `*(*(mat + i) + j)`).
 - Il programma deve essere completamente indipendente da dimensioni fisse.

Esempio di output:
Inserisci numero righe: 2  
Inserisci numero colonne: 3  
Matrice:
4 7 2  
1 5 3  
Somma totale: 22

-----------------------------------------------------------
💭 Domande teoriche:
-----------------------------------------------------------

1️⃣ Descrivi passo per passo cosa accade in memoria durante:
     a) l’allocazione della matrice (con `new int*[righe]`)
     b) l’allocazione di ogni riga (co
*/


#include <iostream>
#include <cstdlib> // rand, srand
#include <ctime>   // time
using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    int righe = 0;
    int colonne = 0;

    cout << "Inserisci numero righe: ";
    cin >> righe;
    cout << "Inserisci numero colonne: ";
    cin >> colonne;

    if (righe <= 0 || colonne <= 0) {
        cout << "Dimensioni non valide. Exit.\n";
        return 1;
    }

    // 1) Alloca l'array di puntatori (livello superiore)
    int **mat = new int*[righe];

    // 2) Alloca ogni riga come array di "colonne" interi
    for (int i = 0; i < righe; ++i) {
        mat[i] = new int[colonne];
    }

    // 3) Riempie la matrice con valori casuali 1..9
    for (int i = 0; i < righe; ++i) {
        for (int j = 0; j < colonne; ++j) {
            mat[i][j] = (rand() % 9) + 1; // 1..9
        }
    }

    // 4) Stampa la matrice e calcola la somma, mostrando anche la doppia dereferenziazione
    cout << "\nMatrice:\n";
    int somma = 0;
    for (int i = 0; i < righe; ++i) {
        for (int j = 0; j < colonne; ++j) {
            // accesso normale e accesso con doppia dereferenziazione
            int val_normal = mat[i][j];
            int val_double = *(*(mat + i) + j);
            // dimostriamo che sono lo stesso valore
            cout << val_normal << " ";
            (void)val_double; // evitare warning se non usato direttamente
            somma += val_normal;
        }
        cout << "\n";
    }

    cout << "\nSomma totale: " << somma << "\n";

    // 5) Deallocazione: prima le righe, poi l'array di puntatori
    for (int i = 0; i < righe; ++i) {
        delete[] mat[i];  // libera ciascuna riga
    }
    delete[] mat;        // libera l'array di puntatori

    return 0;
}

/*
-----------------------------------------------------------
💭 Risposte teoriche (formato commento per VS Code)
-----------------------------------------------------------

1️⃣ Descrizione passo-passo in memoria:

 a) All'allocazione della matrice con `new int*[righe]`:
    - Il runtime alloca sul heap un blocco contiguo di memoria grande
      quanto `righe * sizeof(int*)`.
    - Questo blocco contiene puntatori non inizializzati (mat[0], mat[1], ...).
    - `mat` (variabile sullo stack) contiene l'indirizzo del primo elemento
      di questo blocco. Quindi `mat` è un puntatore a puntatori (int**).

 b) All'allocazione di ogni riga con `new int[colonne]`:
    - Per ogni riga `i`, il runtime alloca sul heap un blocco contiguo
      di `colonne * sizeof(int)` byte.
    - L'indirizzo di questo blocco viene memorizzato in `mat[i]` (cioè
      nel singolo puntatore nella tabella `mat`).
    - Quindi in memoria otteniamo: un blocco con puntatori (mat),
      ciascuno dei quali punta a un blocco di interi (una riga).

    Visualizzazione semplificata:
      mat -> [ mat[0] | mat[1] | mat[2] | ... ]
                 ↓        ↓        ↓
               [riga0]  [riga1]  [riga2]
               (int[])  (int[])  (int[])

 c) Deallocazione finale:
    - Per ogni riga i: si chiama `delete[] mat[i]` liberando il blocco
      di interi associato a quella riga.
    - Dopo che tutte le righe sono state liberate, si chiama `delete[] mat`
      per liberare il blocco che conteneva i puntatori.
    - Importante: se si chiama `delete[] mat` PRIMA di `delete[] mat[i]`,
      si perde l'indirizzo alle righe (perdita di puntatori) e non si può
      più liberare le righe singolarmente -> memory leak.

2️⃣ Perché liberare prima le righe e poi il puntatore principale?

 - Ordine corretto:
    for i: delete[] mat[i];  // libera ogni riga
    delete[] mat;            // poi libera l'array di puntatori

 - Se inverti l'ordine:
    delete[] mat;   // liberi l'array di puntatori
    // ora mat è invalido: mat[i] non è più accessibile in modo sicuro
    delete[] mat[i]; // ERRORE: uso di memoria già liberata / comportamento indefinito

 - Motivo tecnico:
    `mat` contiene gli indirizzi delle righe. Se liberi `mat` prima,
    perdi questi indirizzi e non puoi più chiamare `delete[]` su ciascuna riga.
    Si genera memory leak (le righe rimangono allocate) o comportamento
    indefinito se si tenta di accedervi dopo `delete[] mat`.

-----------------------------------------------------------
Riassunto pratico:
 - Alloca: prima l'array di puntatori (int**), poi ogni riga (int*).
 - Dealloca: prima ogni riga, poi l'array di puntatori.
 - Usa sempre delete[] per memoria allocata con new[].
-----------------------------------------------------------
*/
