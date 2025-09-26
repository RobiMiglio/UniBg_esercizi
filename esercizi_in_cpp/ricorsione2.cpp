/*
===========================================================
   MEGA TEST FINALE — DOMANDA 4 (versione universitaria reale)
   Argomenti: ricorsione, stack frame, passaggio per riferimento
===========================================================

Progettare un programma che calcoli la somma di tutti gli
elementi di un array di interi utilizzando un approccio
**completamente ricorsivo**.

Il programma deve:
 - accettare un array di dimensione variabile (puoi definirlo nel main);
 - utilizzare una funzione ricorsiva che riceva:
      • il puntatore all’array
      • la dimensione corrente
      • un contatore interno per la posizione
 - restituire la somma totale.

⚙️ Vincoli:
 - Non utilizzare cicli iterativi (for, while, do-while);
 - Il passaggio del contatore deve avvenire per riferimento;
 - L’approccio deve evidenziare il comportamento dello stack
   (chiamate annidate e ritorni progressivi).

Esempio indicativo di output:
Array: 3 5 2 8 1  
Somma totale: 19

===========================================================
Scrivi qui sotto il tuo codice 👇
===========================================================
*/

/*
-----------------------------------------------------------
💭 Domande teoriche:
-----------------------------------------------------------

1️⃣ Descrivi come viene gestito lo stack frame durante
    una chiamata ricorsiva: cosa accade a ogni “attivazione”
    della funzione?

2️⃣ Cosa cambia tra passare il contatore per valore
    e passarlo per riferimento in questo contesto?
===========================================================
*/

#include <iostream>

using namespace std;

int sommaRicorsiva(int *arr, int size, int &index)
{
    if(index == size)
    {
        return 0;
    }
    return arr[index++] + sommaRicorsiva(arr, size, index);

}

int main()
{
    int contatore = 0;
    int array[3] = {1,2,3};
    cout << "totale somma: " << sommaRicorsiva(array, 3, contatore);

    return 0;
}


/*
-----------------------------------------------------------
💭 Domande teoriche — DOMANDA 4
-----------------------------------------------------------

1️⃣ Come viene gestito lo stack frame durante
    una chiamata ricorsiva?

Ogni volta che una funzione ricorsiva viene chiamata,
il sistema crea un nuovo **stack frame** (record di attivazione),
che contiene:
 - i parametri passati alla funzione (arr, size, index)
 - le variabili locali (se presenti)
 - l’indirizzo di ritorno (cioè dove proseguire nel codice
   quando la funzione termina)

Durante la **discesa ricorsiva**, ogni chiamata rimane sospesa
in attesa del risultato della chiamata successiva.
Quando si raggiunge il **caso base**, la funzione restituisce
un valore e gli stack frame vengono progressivamente distrutti
man mano che la ricorsione risale.

ESEMPIO (array = {1, 2, 3}):

Chiamata iniziale:
→ sommaRicorsiva(arr, 3, index=0)

1. index = 0 → ritorna arr[0] + sommaRicorsiva(..., index=1)
   = 1 + sommaRicorsiva(...)

2. index = 1 → ritorna arr[1] + sommaRicorsiva(..., index=2)
   = 2 + sommaRicorsiva(...)

3. index = 2 → ritorna arr[2] + sommaRicorsiva(..., index=3)
   = 3 + sommaRicorsiva(...)

4. index = 3 → CASO BASE → ritorna 0

Risalendo lo stack:
→ 3 + 0 = 3
→ 2 + 3 = 5
→ 1 + 5 = 6   ← risultato finale

⚙️ Ogni chiamata rimane “in sospeso” finché la successiva non restituisce
il suo risultato. Lo stack si comporta come una pila (ultimo che entra,
primo che esce).

-----------------------------------------------------------

2️⃣ Differenza tra passaggio per valore e per riferimento

• **Per valore:**
  Viene passata una copia della variabile.
  Ogni funzione lavora su una propria copia locale,
  quindi le modifiche non si riflettono sull’esterno.

• **Per riferimento:**
  Viene passato l’indirizzo in memoria della variabile.
  Tutte le funzioni operano sulla *stessa istanza*,
  e le modifiche sono visibili anche al livello chiamante.

Nel nostro programma, se passassimo `index` per valore,
ogni chiamata avrebbe una copia di `index` e non vedrebbe
l’incremento fatto dalle altre chiamate.
Risultato: la funzione sommerebbe sempre arr[0].

Passandolo invece **per riferimento**, tutte le chiamate
condividono la stessa variabile `index`, che viene aggiornata
a ogni passo della ricorsione.
-----------------------------------------------------------
*/
