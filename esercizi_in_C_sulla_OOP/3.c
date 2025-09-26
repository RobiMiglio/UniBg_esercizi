/*
================================================================================
ESERCIZIO 3 – Ereditarietà simulata in C
================================================================================

Spiegazione:
- In C non esistono classi derivate, ma possiamo simulare ereditarietà includendo
  una struct “base” dentro una struct “derivata”.
- I metodi possono essere simulati con puntatori a funzione, che possono essere
  ridefiniti nella struct derivata.

Requisiti:
1. Crea una struct Auto con:
   - int velocita;
   - void (*accelera)(struct Auto*);

2. Crea una struct AutoElettrica che “eredita” da Auto:
   - Include Auto come primo campo;
   - int batteria;
   - void (*ricarica)(struct AutoElettrica*);

3. Implementa le funzioni:
   - void acceleraAuto(struct Auto* a) { velocita += 10; }
   - void acceleraElettrica(struct Auto* a) { velocita += 20; batteria -= 1; }
   - void ricaricaBatteria(struct AutoElettrica* a) { batteria = 100; }

4. Nel main():
   - Crea un oggetto Auto e uno AutoElettrica;
   - Chiama accelera su entrambi usando i rispettivi puntatori a funzione;
   - Stampa velocità e batteria dell’AutoElettrica.

--------------------------------------------------------------------------------
Domande concettuali:
1. Perché includere la struct base come primo campo della struct derivata?
2. Come possiamo simulare il polimorfismo in C usando i puntatori a funzione?
================================================================================
*/

#include <stdio.h>
#include "3.h"

// Definizione della struct base
struct Auto 
{
    int velocita;
    void (*accelera)(struct Auto *a);
};

// Definizione della struct derivata
struct AutoElettrica 
{
    Auto elettrica;   // eredita attributi e metodi di Auto
    int batteria;
    void (*ricarica)(struct AutoElettrica *ae);
};

// Funzione "normale" di accelerazione
void acceleraAuto(Auto *a) 
{
    a->velocita += 10;
}

// Funzione di accelerazione specializzata per AutoElettrica
void acceleraElettrica(Auto *a) 
{
    AutoElettrica *ae = (AutoElettrica *)a; // cast: trattiamo Auto* come AutoElettrica*
    ae->elettrica.velocita += 20;
    ae->batteria -= 1;
}

// Funzione per ricaricare la batteria
void ricaricaBatteria(AutoElettrica *a) 
{
    a->batteria = 100;
}

int main() 
{
    // Oggetto Auto "normale"
    Auto golf = {0, acceleraAuto};

    // Oggetto AutoElettrica (derivato)
    AutoElettrica polo = {
        {0, acceleraElettrica},  // inizializza la struct Auto dentro
        50,                      // batteria
        ricaricaBatteria         // funzione di ricarica
    };

    // Stato iniziale
    printf("velocita auto: %d\n", golf.velocita);
    printf("velocita auto elettrica: %d\n", polo.elettrica.velocita);
    printf("batteria auto elettrica: %d\n", polo.batteria);

    // Azioni
    golf.accelera(&golf);
    polo.elettrica.accelera((Auto *)&polo);  // cast per simulare polimorfismo
    polo.ricarica(&polo);

    // Stato finale
    printf("velocita auto: %d\n", golf.velocita);
    printf("velocita auto elettrica: %d\n", polo.elettrica.velocita);
    printf("batteria auto elettrica: %d\n", polo.batteria);

    return 0;
}

/*
ESERCIZIO 3 – Ereditarietà simulata
-------------------------------------------------
1. Perché includere la struct base come primo campo della struct derivata?
   → Così un puntatore alla struct derivata può essere convertito a puntatore
     alla struct base senza rompere la memoria. Questo imita l’ereditarietà
     del C++.

2. Come simulare il polimorfismo in C con i puntatori a funzione?
   → Nella struct base si mette un puntatore a funzione (es. `accelera`).
     La struct derivata può sostituire quel puntatore con un’altra funzione,
     ottenendo comportamenti diversi a runtime.
*/
