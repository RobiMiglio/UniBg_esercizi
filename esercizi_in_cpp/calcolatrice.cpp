/*
===========================================================
   ESERCIZIO 1 — CALCOLATRICE AVANZATA (C-STYLE IN C++)
   Argomenti: input/output, operatori aritmetici, switch,
              funzioni, puntatori, const, preprocessore
===========================================================

Progettare un programma che simuli una **calcolatrice**.
La calcolatrice deve:
 - Leggere due numeri interi dall'utente
 - Chiedere quale operazione effettuare: somma, sottrazione,
   moltiplicazione, divisione, resto modulo
 - Usare una `switch` per selezionare l'operazione
 - Usare puntatori per passare i numeri alle funzioni
 - Tutte le funzioni devono ricevere i parametri come `const`
 - Usare almeno una costante simbolica `#define`

⚙️ Specifiche:
 - Numeri interi (int)
 - Gestire la divisione per zero
 - Creare funzioni separate per ogni operazione

📤 Output atteso (esempio):
Inserisci il primo numero: 10
Inserisci il secondo numero: 3
Seleziona operazione (+ - * / %): *
Risultato: 30

-----------------------------------------------------------
💭 Domande teoriche:
-----------------------------------------------------------

1️⃣ Qual è la differenza tra passaggio per valore e per riferimento?

2️⃣ Perché conviene dichiarare i parametri delle funzioni `const`?

3️⃣ In quali situazioni un `switch` è preferibile a una serie di `if-else`?

===========================================================
Scrivi qui sotto il tuo codice 👇
===========================================================
*/

#include <iostream>

using namespace std;


#define OPERAZIONI_X \
X(SOMMA, '+', a+b) \
X(SOTTRAZIONE, '-', a-b) \
X(MOLTIPLICAZIONE, '*', a*b) \
X(DIVISIONE, '/', a/b) \
//X(RESTO_MODULO, '%', a%b)


typedef enum
{
    #define X(tipo, ...) tipo,
        OPERAZIONI_X
    #undef X
    enumOpsMax
}enumOps;

const char *arrNomiOps[] = 
{
    #define X(tipo, ...) #tipo,
        OPERAZIONI_X
    #undef X
};

typedef struct Operazione
{
    enumOps tipo;
    char simbolo;
    float (*operazione)(float a, float b);
}Operazione;

//generatore di funzioni
#define X(tipo, simbolo, formula) float op_##tipo(float a, float b) {return formula;}
    OPERAZIONI_X
#undef X

Operazione arrOps[] = 
{
    #define X(tipo, simbolo, formula) { tipo, simbolo, op_##tipo },
    OPERAZIONI_X
    #undef X
};

int main()
{
    float a = 0;
    float b = 0;
    char c = 0;
    cout << "CALCOLATRICE" << endl;
    cout << "inserisci il ptimo numero: ";
    cin >> a;
    cout << "\n inserisci il secondo numero: ";
    cin >> b;
    cout << "\nSeleziona operazione (+ - * / %): ";
    cin >> c;

    for(int i=0; i<enumOpsMax; i++)
    {
        if(c == arrOps[i].simbolo)
        {
            cout << "\nRisultato: " << arrOps[i].operazione(a, b) << endl;
            break;
        }
    }


    return 0;
}


/*
domande teoriche

1.
passaggio per valore = passo alla funzione il valore di una variabile e la funzione crea una copia di questa variabile
passaggio per riferimento = passa alla funzione l'indirizzo in memoria di questa variabile

2.
perchè non devono essere modificati ma solo letti per calcolarne il risultato

3.
quando ci sono svariati casi


*/