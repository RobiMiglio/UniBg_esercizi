/*
================================================================================
DOMANDA 6 – Passaggio di argomenti
================================================================================

1. Scrivi due funzioni:
   - `void incrementaByVal(int x)` che incrementa la variabile ricevuta (ma
     non deve modificare il chiamante).
   - `void incrementaByRef(int *x)` che incrementa la variabile ricevuta
     modificando anche il chiamante.

2. Nel `main()`:
   - Crea una variabile `int a = 5`.
   - Chiama entrambe le funzioni su `a` e stampa il valore di `a` prima e dopo
     ciascuna chiamata.

--------------------------------------------------------------------------------
Domanda teorica:
- Spiega in poche righe la differenza tra passaggio per valore e passaggio per
  riferimento in C, e fai un esempio pratico di quando useresti l’uno o l’altro.
================================================================================
*/

#include <stdio.h>

void incrementaByVal(int x)
{
    x +=1;
}

void incrementaByRef(int *x)
{
    *x +=1;
}

int main()
{
    int a = 5;
    printf("valore di a: %d\n", a);
    incrementaByVal(a);
    printf("valore di a: %d\n", a);
    incrementaByRef(&a);
    printf("valore di a: %d\n", a);
}


/*
domanda teorica
la differenza è:
-passaggio per valore = passiamo il valore della variabile alla funzione che poi ne fa quello che vuole senza modificare la variabile passata
-passaggio per riferimento = passiamo l'indirizzo della variabile alla funzione --> quindi se viene incrementata anche la var passata si incrementa

passaggio per valore è utile quando per esempio dobbiamo trovare la somma di due numeri e passiamo quindi il valore di due variabili 

passaggio per riferimento è utile quando es dobbiamo incrementare la var solo in determinati casi e questi casi li mettiamo tutti in una funzione..

*/

