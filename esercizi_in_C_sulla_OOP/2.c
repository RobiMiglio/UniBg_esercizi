/*
================================================================================
ESERCIZIO 2 – Incapsulamento (getter/setter in C)
================================================================================

Spiegazione:
- In C non esistono modificatori di accesso (public/private).
- Possiamo simulare l'incapsulamento separando interfaccia e implementazione.
- I dati “privati” sono nascosti nella struct, e l'accesso avviene tramite funzioni pubbliche (getter/setter).

Requisiti:
1. Crea una struct Auto con campo privato velocita.
2. Implementa le funzioni pubbliche:
   - void setVelocita(Auto* a, int v);
   - int getVelocita(Auto* a);
   - void accelera(Auto* a) che aumenta velocita di 10.
3. Nel main():
   - Crea un oggetto Auto.
   - Imposta la velocità a 0.
   - Chiama accelera().
   - Stampa la velocità usando getVelocita().

--------------------------------------------------------------------------------
Domande concettuali:
1. Perché in C dobbiamo usare funzioni per leggere o modificare i dati “privati”?
2. Come sarebbe diverso in C++ usando private/public?
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "2.h"

struct Auto {
    int velocita;  // campo “privato”
};

void setVelocita(Auto *a, int v) {
    a->velocita = v;
}

int getVelocita(Auto *a) {
    return a->velocita;
}

void accelera(Auto *a) {
    a->velocita += 10;
}

int main() {
    Auto a;               // oggetto automatico, non dinamico
    setVelocita(&a, 0);   // inizializza velocità
    accelera(&a);         

    printf("Velocita: %d\n", getVelocita(&a));

    return 0;
}

/*
ESERCIZIO 2 – Incapsulamento
-------------------------------------------------
1. Perché in C dobbiamo usare funzioni per leggere o modificare i dati “privati”?
   → Perché in C non esistono modificatori di accesso (`private`, `public`).
     L’unico modo per simulare l’incapsulamento è nascondere la struct
     nell’implementazione (.c) e fornire getter/setter pubblici nel .h.

2. Come sarebbe diverso in C++ usando private/public?
   → In C++ basta dichiarare gli attributi `private` e scrivere `public` getter/setter.
     Il compilatore impedisce direttamente l’accesso ai campi privati dall’esterno.
*/
