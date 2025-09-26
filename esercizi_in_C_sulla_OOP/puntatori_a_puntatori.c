/*
================================================================================
DOMANDA 10 – Puntatori a puntatori e array 2D
================================================================================
*/

#include <stdio.h>

void stampaMatrice(int **mat, int righe, int colonne)
{
    for(int i=0; i<righe; i++)
    {
        for(int k=0; k<colonne; k++)
        {
            printf("%d ", mat[i][k]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int righe = 3;
    int colonne = 3;
    int matrice[3][3];

    // inizializza matrice con valori crescenti
    int temp = 1;
    for(int i=0; i<righe; i++)
    {
        for(int k=0; k<colonne; k++)
        {
            matrice[i][k] = temp++;
        }
    }

    // array di puntatori alle righe
    int *arrpunt[3];
    for(int i=0; i<righe; i++)
    {
        arrpunt[i] = matrice[i]; // ogni riga è un array di int, decays in int*
    }

    // passo come int** grazie all’array di puntatori
    stampaMatrice(arrpunt, righe, colonne);

    return 0;
}

/*
================================================================================
Risposte alle domande teoriche
================================================================================

- Differenza tra un puntatore a puntatore e un array multidimensionale in C:
  * Un array multidimensionale (`int m[3][3]`) è un blocco contiguo di memoria
    con dimensioni fisse note a compile time.
  * Un puntatore a puntatore (`int **p`) rappresenta un indirizzo a un array
    di puntatori, che a loro volta puntano a blocchi di memoria (potenzialmente
    non contigui). Serve più flessibilità ma anche più gestione manuale.

- Perché passando un array 2D a una funzione è necessario conoscere almeno
  il numero di colonne?
  * Perché in memoria la matrice è lineare riga per riga: per accedere a
    `m[i][j]`, il compilatore deve sapere quanti elementi ci sono in una riga
    (numero colonne) per calcolare l’offset corretto. Senza questa informazione,
    non può tradurre l’indirizzo in maniera corretta.
*/
