/*
================================================================================
DOMANDA 7 – Array e funzioni
================================================================================

1. Scrivi una funzione `void stampaArray(int arr[], int n)` che stampi gli
   elementi di un array di interi.

2. Scrivi una funzione `int sommaArray(int arr[], int n)` che restituisca la
   somma di tutti gli elementi.

3. Nel `main()`:
   - Dichiara un array statico di 5 interi inizializzati a piacere.
   - Calcola `n` usando `sizeof` (senza scrivere a mano 5).
   - Stampa l’array e la sua somma.

--------------------------------------------------------------------------------
Domanda teorica:
- Perché in C, quando passo un array a una funzione, in realtà sto passando un
  puntatore al primo elemento? Cosa implica questo nel calcolo della lunghezza
  dell’array dentro la funzione?
================================================================================
*/

#include <stdio.h>

void stampaArray(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d° dell'array ha valore: %d\n", i+1, arr[i]);
    }
}

int sommaArray(int arr[], int n)
{
    int totale = 0;
    for(int i=0; i<n; i++)
    {
        totale += arr[i];
    }
    return totale;
}


int main()
{
    int arrayInteri[5] = {1,2,3,4,5};
    int n = sizeof(arrayInteri)/sizeof(arrayInteri[0]);
    stampaArray(arrayInteri, n);
    printf("somma dei valori dell'array: %d\n", sommaArray(arrayInteri, n));
}
