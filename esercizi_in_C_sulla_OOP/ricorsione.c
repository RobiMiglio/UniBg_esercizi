/*
================================================================================
DOMANDA 9 – Ricorsione e pila delle chiamate
================================================================================

1. Scrivi una funzione ricorsiva `int fattoriale(int n)` che calcoli il fattoriale di `n`.
   - Caso base: `fattoriale(0) = 1`.
   - Caso ricorsivo: `fattoriale(n) = n * fattoriale(n-1)`.

2. Nel `main()`:
   - Chiedi all’utente un numero intero.
   - Calcola e stampa il fattoriale usando la funzione ricorsiva.

--------------------------------------------------------------------------------
Domanda teorica:
- Spiega cosa succede nella pila delle chiamate (call stack) durante una
  funzione ricorsiva. Cosa rappresenta un *record di attivazione*?
================================================================================
*/

#include <stdio.h>

int fattoriale(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n*fattoriale(n-1);
    }
}

int main()
{
    int c = 0;
    puts("inserisci un intero: ");
    scanf("%d", &c);
    printf("fattoriale: %d\n", fattoriale(c));
}


/*
================================================================================
RISPOSTA TEORICA DOMANDA 9 – Pila delle chiamate e record di attivazione
================================================================================

- Durante l’esecuzione di una funzione ricorsiva, ogni chiamata viene memorizzata
  nella **pila delle chiamate (call stack)** come un *record di attivazione*.
  
- Un **record di attivazione** contiene:
  - valori dei parametri della funzione,
  - variabili locali,
  - indirizzo di ritorno (dove continuare al termine della funzione),
  - eventuali altre informazioni necessarie all’esecuzione della funzione.

- Quando la funzione raggiunge il caso base, il record di attivazione viene rimosso
  dalla pila e si torna alla chiamata precedente, continuando il calcolo.

Esempio:
fattoriale(3):
- Chiamate sulla pila: fattoriale(3), fattoriale(2), fattoriale(1)
- Si calcola fattoriale(1) → rimozione record → ritorno a fattoriale(2)
- Si calcola fattoriale(2) → rimozione record → ritorno a fattoriale(3)
- Si calcola fattoriale(3) → rimozione record → fine

================================================================================
*/
