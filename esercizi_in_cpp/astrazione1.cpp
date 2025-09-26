/*
===========================================================
   MEGA TEST FINALE — DOMANDA 1 (Soluzione ufficiale)
   Argomenti: Array, Puntatori a funzione, OOP in C, Astrazione
===========================================================

📘 consegna:
Scrivi un programma C-like che:

1️⃣ Definisce una `struct Sorter` che rappresenta un “oggetto ordinatore”.
    - Deve contenere:
      • Un puntatore a funzione per confrontare due `int`.
      • Un altro puntatore a funzione per ordinare un array di interi.

2️⃣ Implementa due funzioni di confronto:
      int compareAscending(int a, int b);
      int compareDescending(int a, int b);

3️⃣ Implementa una funzione:
      void bubbleSort(int *array, int n, int (*cmp)(int, int));
    - Deve usare la funzione di confronto passata per decidere l’ordine.

4️⃣ Nel `main()`:
    - Crea un array di interi, es: {4, 2, 9, 1}.
    - Crea due istanze di `Sorter`:
        • una per ordinamento crescente
        • una per ordinamento decrescente
    - Ciascuna deve usare la propria funzione di confronto e ordinare l’array.
    - Stampa il risultato di entrambi gli ordinamenti.

📈 Esempio output atteso:
Array originale: 4 2 9 1
Ordinato crescente: 1 2 4 9
Ordinato decrescente: 9 4 2 1
===========================================================
*/

#include <iostream>
using namespace std;

// Definizione della "classe" in stile C
typedef struct Sorter
{
    bool (*compare)(int a, int b);                              // comportamento di confronto
    void (*sort)(int *array, int size, bool (*cmp)(int, int));  // comportamento di ordinamento
} Sorter;

// Funzioni di confronto
bool compareAscending(int a, int b) { return (a > b); }   // scambia se a > b
bool compareDescending(int a, int b) { return (a < b); }  // scambia se a < b

// Funzione di ordinamento generica
void bubbleSort(int *array, int size, bool (*cmp)(int, int))
{
    int temp;
    for (int j = 0; j < size - 1; j++)
    {
        for (int i = 0; i < size - j - 1; i++)
        {
            if (cmp(array[i], array[i + 1]))
            {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}

// Funzione di stampa array
void printArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

int main()
{
    int size = 4;
    int arrayAsc[4] = {4, 2, 9, 1};
    int arrayDesc[4] = {4, 2, 9, 1};

    // Creazione delle "istanze" Sorter
    Sorter ordinCrescente;
    Sorter ordinDecrescente;

    ordinCrescente.compare = compareAscending;
    ordinCrescente.sort = bubbleSort;

    ordinDecrescente.compare = compareDescending;
    ordinDecrescente.sort = bubbleSort;

    // Output iniziale
    cout << "Array originale: ";
    printArray(arrayAsc, size);

    // Ordinamento crescente
    ordinCrescente.sort(arrayAsc, size, ordinCrescente.compare);
    cout << "Ordinato crescente: ";
    printArray(arrayAsc, size);

    // Ordinamento decrescente
    ordinDecrescente.sort(arrayDesc, size, ordinDecrescente.compare);
    cout << "Ordinato decrescente: ";
    printArray(arrayDesc, size);

    return 0;
}

/*
-----------------------------------------------------------
💭 RISPOSTE TEORICHE
-----------------------------------------------------------

1️⃣ Perché questo approccio è considerato “OOP in C” anche se non usa class né inheritance?
──────────────────────────────────────────────────────────
Perché combina dati (array e funzioni di ordinamento) e comportamenti 
(puntatori a funzione) dentro una singola struttura, simulando 
incapsulamento e polimorfismo tipici dell’OOP.

Ogni `Sorter` rappresenta un "oggetto" con il proprio stato e comportamento:
- incapsula i metodi (`compare`, `sort`)
- può essere istanziato più volte con comportamenti diversi (ascendente o discendente)
- può essere passato e usato come un'entità autonoma.

Quindi, anche senza `class` o `inheritance`, applichiamo i principi base:
👉 astrazione, incapsulamento e modularità.


2️⃣ Differenza tra passare una funzione come parametro e memorizzarla in una struct
──────────────────────────────────────────────────────────
- Quando passo una funzione come parametro, fornisco un comportamento *temporaneo* 
  a una funzione (es. `bubbleSort(..., compareAscending)`).
- Quando la memorizzo in una struct, il comportamento diventa *proprietà* dell’oggetto, 
  parte della sua definizione.  

Quindi:
→ funzione come parametro → comportamento momentaneo  
→ funzione in struct → comportamento permanente e associato all'istanza  

È un passo verso la programmazione a oggetti, in cui ogni oggetto 
definisce da sé come deve comportarsi.
===========================================================
*/
