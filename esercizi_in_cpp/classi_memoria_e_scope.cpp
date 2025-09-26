// 🧠 DOMANDA 9 – Classi di memoria e scope
// 1️⃣ Scrivi un programma che mostri la differenza tra:
//     - variabile automatica (auto)
//     - variabile statica (static)
//     - variabile globale
// 2️⃣ Fai in modo che la funzione `test()` venga chiamata più volte
//     e mostri il comportamento diverso delle variabili.
// 3️⃣ Spiega cosa significa "scope" e "lifetime" di una variabile.


#include <iostream>

using namespace std;

int variabileGlobale = 0;

void test()
{
    static int variabileStatica = 0;

    int variabileAutomatica = 0;

    variabileStatica++;
    variabileAutomatica++;
    variabileGlobale++;
    cout << "variabile globale: " << variabileGlobale << endl;
    cout << "variabile statica: " << variabileStatica << endl;
    cout << "variabile automatica: " << variabileAutomatica << endl;
}

int main()
{
    for(int i=0; i<4; i++)
    {
        test();
    }
    variabileGlobale++;
    cout << "variabile globale: " << variabileGlobale << endl;

    return 0;
}

/*
🔸 Scope (campo d’azione)

Lo scope di una variabile è la parte di codice in cui il nome della variabile è visibile e accessibile.

Le variabili locali hanno scope limitato al blocco {} in cui sono dichiarate.

Le globali hanno scope esteso a tutto il file (o al programma, se dichiarate extern).


🔸 Lifetime (durata)

Indica quanto tempo la variabile rimane allocata in memoria:

Automatica → creata all’ingresso della funzione, distrutta all’uscita.

Statica → creata una volta sola, rimane fino alla fine del programma.

Globale → creata all’avvio del programma, distrutta alla chiusura.

*/