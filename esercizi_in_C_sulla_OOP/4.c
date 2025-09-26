/*
================================================================================
ESERCIZIO 4 – Polimorfismo simulato in C
================================================================================

Spiegazione:
- In C++ il polimorfismo consente di chiamare lo stesso metodo su oggetti diversi
  e ottenere comportamenti diversi.
- In C simuliamo questa cosa usando **puntatori a funzione nella struct base**.
- Le struct derivate ridefiniscono i puntatori a funzione, quindi la chiamata
  "virtuale" viene eseguita con comportamenti diversi a seconda dell'oggetto.

Requisiti:
1. Crea una struct Forma con:
   - void (*disegna)(struct Forma*);

2. Crea due "classi derivate":
   - Cerchio: include Forma come primo campo + int raggio.
   - Rettangolo: include Forma come primo campo + int base, altezza.

3. Implementa le funzioni:
   - void disegnaCerchio(Forma* f) → stampa "Disegno un cerchio di raggio X".
   - void disegnaRettangolo(Forma* f) → stampa "Disegno un rettangolo base X altezza Y".

4. Nel main():
   - Crea un array di puntatori a Forma (2 elementi).
   - Inserisci un Cerchio e un Rettangolo.
   - Itera sull’array e chiama `disegna` per ciascun oggetto.

--------------------------------------------------------------------------------
Domande concettuali:
1. Perché serve il cast (da Forma* a Cerchio* o Rettangolo*) nelle funzioni di disegno?
2. Qual è la differenza tra polimorfismo “statico” (overloading) e “dinamico” (override)?
================================================================================
*/

#include <stdio.h>
#include "4.h"

// Definizioni
typedef struct Forma Forma;
typedef struct Cerchio Cerchio;
typedef struct Rettangolo Rettangolo;

struct Forma 
{
    void (*disegna)(Forma *f);
};

struct Cerchio 
{
    Forma formaBase;  // eredita Forma
    int raggio;
};

struct Rettangolo 
{
    Forma formaBase;  // eredita Forma
    int base;
    int altezza;
};

// Funzioni
void disegnaCerchio(Forma *f) 
{
    Cerchio *c = (Cerchio *)f;  // cast a tipo derivato
    printf("Disegno un cerchio di raggio: %d\n", c->raggio);
}

void disegnaRettangolo(Forma *f) 
{
    Rettangolo *r = (Rettangolo *)f;  // cast a tipo derivato
    printf("Disegno un rettangolo base %d altezza %d\n", r->base, r->altezza);
}

int main() 
{
    // Creo un cerchio e un rettangolo
    Cerchio c = {{disegnaCerchio}, 4};         // formaBase con funzione + raggio
    Rettangolo r = {{disegnaRettangolo}, 3, 6}; // formaBase con funzione + base e altezza

    // Array di puntatori alla base
    Forma *forme[2];
    forme[0] = (Forma *)&c;
    forme[1] = (Forma *)&r;

    // Polimorfismo simulato
    for (int i = 0; i < 2; i++) 
    {
        forme[i]->disegna(forme[i]);
    }

    return 0;
}

/*
ESERCIZIO 4 – Polimorfismo simulato
-------------------------------------------------
1. Perché serve il cast (da Forma* a Cerchio* o Rettangolo*)?
   → Perché la funzione di disegno riceve solo un puntatore alla struct base
     (`Forma*`). Per accedere ai campi specifici (raggio, base, altezza) dobbiamo
     castare al tipo corretto.

2. Differenza tra polimorfismo statico e dinamico?
   → Polimorfismo statico: deciso a compile-time (es. overloading di funzioni).
   → Polimorfismo dinamico: deciso a runtime (es. override di metodi virtuali,
     oppure simulato in C con i puntatori a funzione).
*/
