// ⚙️ DOMANDA 14 – Puntatori a funzione e puntatori a puntatori
//
// Scrivi un programma che:
//
// 1️⃣ Definisca tre funzioni:
//        - `quadrato(int x)`
//        - `cubo(int x)`
//        - `doppio(int x)`
//     ognuna restituisce un int con l’operazione indicata.
// 2️⃣ Crea un array di puntatori a funzione che contenga questi 3 operatori.
// 3️⃣ Implementa una funzione `applicaOperazioni()` che riceve:
//        - un puntatore a puntatore a funzione (così può accedere/modificare)
//        - la dimensione dell’array
//        - un numero `n`
//     e applichi ciascuna funzione a `n` stampando i risultati.
// 4️⃣ Nel main() dimostra che funziona.
//
// 🔍 DOMANDA TEORICA:
// - Perché i **puntatori a funzione** sono utili per simulare “metodi virtuali” in C?
// - Cos’è un **puntatore a puntatore a funzione** e quando serve?
//
// BONUS 💡: estendi l’esercizio permettendo all’utente di scegliere dinamicamente
//           quante funzioni inserire nell’array e quali eseguire.


#include <iostream>

using namespace std;

int quadrato(int x)
{
    return x*x;
}

int cubo(int x)
{
    return x*x*x;
}

int doppio(int x)
{
    return x*2;
}

typedef int (*Funzione)(int);

void applicaOperazioni(Funzione *p, int size, int numero)
{
    for(int i=0; i<size; i++)
    {
        cout << "risultato: " << p[i](numero) << endl;
    }
}

int main()
{
    int (*arrayFunzioni[3])(int a) = 
    {
        quadrato, cubo, doppio
    };

    applicaOperazioni(arrayFunzioni, 3, 2);

    return 0;
}

/*

Spiegazione teorica (come in un orale)

Un puntatore a funzione è una variabile che contiene l’indirizzo di una funzione, come i puntatori normali contengono indirizzi di variabili.

Serve per:
passare funzioni come argomento (callback, strategie)
simulare metodi virtuali in C (es. vtable manuale)

Un puntatore a puntatore a funzione (int (**p)(int)) serve quando devi passare un array di funzioni o modificare i puntatori stessi.

*/