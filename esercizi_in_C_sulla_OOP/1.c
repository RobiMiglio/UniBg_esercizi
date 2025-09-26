/*
================================================================================
ESERCIZIO 1 – Classe e Oggetto (simulazione in C)
================================================================================

Spiegazione:
- Simuliamo una classe con una struct.
- Gli attributi della classe diventano campi della struct.
- I metodi diventano puntatori a funzione dentro la struct.
- Creiamo oggetti come variabili di tipo struct.

Requisiti:
1. Crea una struct `Auto` con:
   - int velocita
   - un puntatore a funzione: void (*accelera)(struct Auto*)

2. Implementa la funzione `acceleraFunc` che aumenta `velocita` di 10.

3. Nel main():
   - Crea due oggetti `a1` e `a2` con velocità iniziali 0 e 50.
   - Chiama `accelera` su entrambi.
   - Stampa la velocità finale di ciascun oggetto.

--------------------------------------------------------------------------------
Domande concettuali:
1. Qual è la differenza tra struct con puntatori a funzione e una classe C++?
2. Perché in C dobbiamo passare &a1 alla funzione accelera, mentre in C++ basta a1.accelera()?
================================================================================
*/



#include <stdio.h>

typedef struct Auto Auto;

struct Auto {
    int velocita;
    void (*accelera)(struct Auto*);
};

void acceleraFunc(Auto *a) {
    a->velocita += 10;
}

int main() {
    Auto a[2] = {
        {0, acceleraFunc},
        {50, acceleraFunc}
    };

    // Usare il puntatore a funzione della struct
    a[0].accelera(&a[0]);
    a[1].accelera(&a[1]);

    printf("Velocita a1: %d\n", a[0].velocita);
    printf("Velocita a2: %d\n", a[1].velocita);

    return 0;
}

/*
ESERCIZIO 1 – Classe e Oggetto (simulazione in C)
-------------------------------------------------
1. Differenza tra struct con puntatori a funzione e classe C++?
   → In C++ le classi hanno costruttori, distruttori, ereditarietà e gestione
     automatica dei metodi. In C dobbiamo simulare manualmente i "metodi"
     inserendo puntatori a funzione dentro la struct.

2. Perché in C serve passare &a1, mentre in C++ basta a1.accelera()?
   → In C le funzioni non sono legate agli oggetti: dobbiamo passare esplicitamente
     il puntatore all'oggetto. In C++ invece i metodi hanno un parametro implicito
     chiamato `this`.
*/
