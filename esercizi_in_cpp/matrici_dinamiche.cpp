/*
===========================================================
   MEGA TEST FINALE — DOMANDA MATRICE DINAMICA
===========================================================

Scrivi un programma in C++ che:

1) Chieda all’utente il numero di righe e colonne di una matrice.
2) Allochi dinamicamente una matrice 2D di interi usando puntatori a puntatori (int**).
3) Riempi la matrice con numeri casuali da 1 a 9.
4) Stampi la matrice utilizzando sia la notazione mat[i][j] sia la doppia dereferenziazione *(*(mat + i) + j).
5) Calcoli e stampi la somma totale di tutti gli elementi.
6) Libera correttamente tutta la memoria allocata (prima le righe, poi l’array di puntatori).

Vincoli:
- Non usare array statici né std::vector.
- Dimensione completamente dinamica.
- Mostrare esplicitamente l’uso di *(*(mat + i) + j).

Domande teoriche associate (da rispondere a parte):
- Descrivi cosa succede in memoria durante l’allocazione e deallocazione.
- Spiega la differenza tra mat[i][j] e *(*(mat+i)+j).
- Perché è importante liberare prima le righe e poi l’array di puntatori.
*/

/*
===========================================================
   MEGA TEST FINALE — DOMANDA MATRICE DINAMICA (CORRETTA)
   Argomenti: memoria dinamica 2D, puntatori a puntatori,
              aritmetica dei puntatori, gestione memoria
===========================================================

Scrivi un programma in C++ che:

1️⃣ Chieda all’utente il numero di righe e colonne di una matrice.
2️⃣ Allochi dinamicamente una matrice 2D di interi usando int**.
3️⃣ Riempia la matrice con numeri casuali (1..9).
4️⃣ Stampi la matrice in due modi:
      - usando la notazione mat[i][j]
      - usando la notazione *(*(mat + i) + j)
5️⃣ Calcoli la somma totale di tutti gli elementi.
6️⃣ Libera correttamente la memoria (prima le righe, poi l’array principale).

Vincoli:
- Nessun array statico o std::vector.
- Dimensione completamente dinamica.
- Mostrare esplicitamente *(*(mat+i)+j).

===========================================================
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    int righe = 0, colonne = 0;

    cout << "Inserisci numero righe: ";
    cin >> righe;
    cout << "Inserisci numero colonne: ";
    cin >> colonne;

    if (righe <= 0 || colonne <= 0)
    {
        cout << "Dimensioni non valide. Uscita.\n";
        return 1;
    }

    // 🔹 Allocazione dinamica della matrice (array di puntatori a int)
    int **matrice = new int *[righe];

    // 🔹 Allocazione delle singole righe
    for (int i = 0; i < righe; i++)
    {
        matrice[i] = new int[colonne];
    }

    // 🔹 Riempimento con numeri casuali 1..9
    for (int i = 0; i < righe; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            matrice[i][j] = (rand() % 9) + 1;
        }
    }

    // 🔹 Stampa con notazione matrice[i][j]
    cout << "\nStampa con notazione matrice[i][j]:\n";
    for (int i = 0; i < righe; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            cout << matrice[i][j] << " ";
        }
        cout << endl;
    }

    // 🔹 Stampa con notazione *(*(matrice + i) + j)
    cout << "\nStampa con notazione *(*(matrice + i) + j):\n";
    for (int i = 0; i < righe; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            cout << *(*(matrice + i) + j) << " ";
        }
        cout << endl;
    }

    // 🔹 Calcolo somma totale
    int somma = 0;
    for (int i = 0; i < righe; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            somma += matrice[i][j];
        }
    }

    cout << "\nSomma totale: " << somma << endl;

    // 🔹 Deallocazione (prima righe, poi matrice principale)
    for (int i = 0; i < righe; i++)
    {
        delete[] matrice[i];
    }
    delete[] matrice;

    return 0;
}

/*
-----------------------------------------------------------
💭 Domande teoriche (risposte commentate)
-----------------------------------------------------------

1️⃣ COSA SUCCEDE IN MEMORIA DURANTE L’ALLOCAZIONE / DEALLOCAZIONE

a) new int*[righe]:
   ➤ viene allocato un array di N puntatori (uno per riga)
   ➤ ogni elemento del vettore è un “int *”, inizialmente non ancora associato

b) new int[colonne]:
   ➤ per ciascun puntatore (cioè per ogni riga),
     viene allocato un blocco contiguo di ‘colonne’ interi

In totale si crea una **tabella a due livelli di indirizzi**:
  - livello 1 → vettore di puntatori (righe)
  - livello 2 → vettori di int (colonne per ciascuna riga)

La deallocazione è l’operazione inversa:
  prima si cancellano i blocchi interni (le righe),
  poi l’array principale dei puntatori.


2️⃣ DIFFERENZA TRA mat[i][j] E *(*(mat + i) + j)

- mat[i][j]:
   ➤ sintassi più leggibile, ma equivalente alla seconda
   ➤ il compilatore la traduce in: *(*(mat + i) + j)

- *(*(mat + i) + j):
   ➤ aritmetica esplicita:
        (mat + i) → sposta il puntatore alla riga i-esima
        *(mat + i) → dereferenzia, ottenendo il puntatore alla riga
        + j → sposta il puntatore di j colonne
        * → dereferenzia ottenendo il valore dell’elemento


3️⃣ PERCHÉ SI DEVONO LIBERARE PRIMA LE RIGHE

Se liberassimo subito `delete[] matrice;`
→ perderemmo tutti i riferimenti alle righe allocate
   e non potremmo più deallocarle ⇒ MEMORY LEAK.

Ordine corretto:
   1. delete[] matrice[i];   (per ogni riga)
   2. delete[] matrice;      (array principale di puntatori)

-----------------------------------------------------------
✅ NOTE PROFESSORALI:
-----------------------------------------------------------
✔️ Codice formalmente corretto e sicuro.  
✔️ Aritmetica dei puntatori mostrata esplicitamente.  
✔️ Ottimo uso di srand e controllo dimensioni.  
✔️ Complessità O(righe × colonne).  
-----------------------------------------------------------
*/
