// 📝 DOMANDA 8 – Ricorsione e pila delle chiamate
// Scrivi una funzione ricorsiva che calcoli il fattoriale di un numero n.
// Poi spiega brevemente cosa succede nello stack (pila) delle chiamate
// quando calcoli, ad esempio, fattoriale(4).
//
// BONUS: riscrivi la stessa funzione in modo iterativo e confronta
// la differenza in termini di uso della memoria.


#include <iostream>

using namespace std;


int fattoriale(int n)
{
    if(n==0)
    {
        return 1;
    }
    return n*fattoriale(n-1);
}

int fattorialeIterativo(int n)
{
    int risultato = 1;
    while (n > 1)
    {
        risultato *= n;
        n--;
    }
    return risultato;
}


int main()
{
    int a = 4;

    cout << "fattoriale di a: " << fattoriale(a) << endl;
    cout << "fattoriale simulato iterativo di a: " << fattorialeIterativo(a) << endl;

    return 0;
}


/*

🧠 Spiegazione – Pila delle chiamate (fattoriale(4))

Ogni chiamata crea un nuovo record di attivazione nello stack con:

il parametro n

lo spazio per il valore di ritorno

l’indirizzo di ritorno (dove riprendere l’esecuzione)

Ecco come cresce e poi si svuota la pila:

Chiamata	Stack top	Operazione
fattoriale(4)	n=4	chiama fattoriale(3)
fattoriale(3)	n=3	chiama fattoriale(2)
fattoriale(2)	n=2	chiama fattoriale(1)
fattoriale(1)	n=1	chiama fattoriale(0)
fattoriale(0)	n=0	ritorna 1

Poi si risale:

fattoriale(1) = 1 * 1 = 1
fattoriale(2) = 2 * 1 = 2
fattoriale(3) = 3 * 2 = 6
fattoriale(4) = 4 * 6 = 24


➡️ Quindi ogni chiamata rimane sospesa in attesa del risultato della successiva, consumando memoria nello stack.

⚙️ Differenza tra versione ricorsiva e iterativa
Aspetto	Ricorsiva	Iterativa
Memoria	O(n) (una chiamata per livello)	O(1) (solo variabili locali)
Velocità	Più lenta (overhead chiamate)	Più veloce
Chiarezza	Più leggibile per problemi ricorsivi	Più efficiente


*/