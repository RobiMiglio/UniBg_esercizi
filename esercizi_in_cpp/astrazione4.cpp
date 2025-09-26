/*
===========================================================
   MEGA TEST FINALE — DOMANDA 10
   Argomenti: OOP in C (astrazione con struct e function pointer),
              static, const, inline, ambito e incapsulamento
===========================================================

Progettare un programma che simuli un piccolo sistema
di **figure geometriche** (es. cerchio e rettangolo).

Il programma deve:
 - rappresentare ogni figura come un "oggetto" con:
      • un nome (stringa costante)
      • un metodo per calcolare l’area (funzione)
 - non usare classi né ereditarietà, ma solo `struct` e
   puntatori a funzione (approccio OOP in C);
 - tutte le figure devono essere allocate staticamente
   (niente memoria dinamica);
 - il programma deve stampare per ciascuna figura:
      → nome e area calcolata;
 - la funzione di stampa deve essere `inline` e
   ricevere un `const` puntatore alla figura.

⚙️ Vincoli:
 - Nessun uso di `new`, `delete`, `malloc` o `free`.
 - Usare `static` per incapsulare funzioni non esportabili
   (visibili solo nel file corrente).
 - Usare almeno una costante simbolica (`const` o `constexpr`).

Esempio di output (indicativo):
Figura: Cerchio  → Area: 78.50  
Figura: Rettangolo → Area: 24.00

-----------------------------------------------------------
💭 Domande teoriche:
-----------------------------------------------------------

1️⃣ Cosa significa dichiarare una funzione `static` in un file `.cpp`?
    Qual è la differenza rispetto a una funzione globale “normale”?

2️⃣ In che modo l’uso di `const` su un puntatore o su una variabile
    migliora la sicurezza e la leggibilità del codice?

3️⃣ Cosa accade a livello di compilazione quando una funzione è
    dichiarata `inline`?

===========================================================
Scrivi qui sotto il tuo codice 👇
===========================================================
*/

#include <iostream>
#include <cstring>

using namespace std;

#define PI_GRECO 3.14

typedef struct Figura
{
    char nome[30];
    float (*calcolaArea)(float a, float b);
    void (*stampaArea)(const Figura *f);
}Figura;

typedef struct Cerchio
{
    Figura Figurabase;
    int raggio;
}Cerchio;

typedef struct Rettangolo
{
    Figura Figurabase;
    int base;
    int altezza;
}Rettangolo;

float areaCerchio(float raggio, float b)
{
    (void)b; //unused
    return (raggio * raggio)*PI_GRECO;
}

float areaRettangolo(float base, float altezza)
{
    return (base * altezza);
}

static inline void stampaAreaCerchio(const Figura *f)
{
    Cerchio *c = (Cerchio*)f;
    cout << "Figura: " << c->Figurabase.nome << " --> Area: " << c->Figurabase.calcolaArea(c->raggio, 0) << endl;
}

static inline void stampaAreaRettangolo(const Figura *f)
{
    Rettangolo *c = (Rettangolo*)f;
    cout << "Figura: " << c->Figurabase.nome << " --> Area: " << c->Figurabase.calcolaArea(c->base, c->altezza) << endl;
}


int main()
{
    Cerchio c;
    Rettangolo r;

    strcpy(c.Figurabase.nome, "Cerchio");
    c.raggio = 20;
    c.Figurabase.calcolaArea = areaCerchio;
    c.Figurabase.stampaArea = stampaAreaCerchio;


    strcpy(r.Figurabase.nome, "Rettangolo");
    r.base = 20;
    r.altezza = 2;
    r.Figurabase.calcolaArea = areaRettangolo;
    r.Figurabase.stampaArea = stampaAreaRettangolo;

    c.Figurabase.stampaArea((Figura*)&c);
    r.Figurabase.stampaArea((Figura*)&r);


    return 0;
}

/*
domande teoriche

1.
significa che è visibile solo all'interno di quel .cpp e non quindi anche all'esterno come invece è con una funzione normale

2.
migliora la sicurezza perchè viene assicurato che quel dato o quell'indirizzo è fissato e non può essere modificato

3.
il compilatore sostituisce l'intero codice della funzione nei punti in cui essa viene chiamata 
quindi diciamo che elimina la chiamata alla funzione --> perchè ci copia tutto il codice
riduce quindi overhead di chiamate
va bene solo per funzioni piccole e che non sono chiamate 1000 volte in giro per il programma...


*/