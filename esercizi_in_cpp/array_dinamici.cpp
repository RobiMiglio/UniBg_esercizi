// ⚙️ DOMANDA 11 – Array dinamici (new e delete)
// Scrivi un programma che:
//   1️⃣ Chieda all’utente quanti elementi vuole inserire.
//   2️⃣ Allochi dinamicamente un array di interi di quella dimensione con `new`.
//   3️⃣ Permetta all’utente di inserire i valori dell’array.
//   4️⃣ Calcoli e stampi la media dei valori.
//   5️⃣ Libera la memoria con `delete[]`.
//
// 🔍 DOMANDA TEORICA:
// Spiega la differenza tra array statici, automatici e dinamici in termini di:
//   - allocazione (stack, heap, data segment)
//   - tempo di vita
//   - gestione della memoria (chi la alloca e chi la libera)
//
// BONUS: Perché `new` e `delete` sono utili quando non conosciamo la dimensione
//         dell’array a tempo di compilazione?


#include <iostream>

using namespace std;

int main()
{
    int size = 0;
    cout << "quanti elementi vuoi inserire? ";
    cin >> size;
    if (size <= 0) 
    {
        cout << "Dimensione non valida." << endl;
        return 0;
    }

    int *arraydinamico = new int[size];

    float media = 0;
    for(int i=0; i<size; i++)
    {
        cout << "inserisci il " << i+1 << "° elemento dell'array: ";
        cin >> arraydinamico[i];
        media += arraydinamico[i];
    }

    media /= size;
    cout << "\nla media dei valori è: " << media << endl;

    delete[] arraydinamico;

    return 0;
}


/*

// 🔍 DOMANDA TEORICA:
// Spiega la differenza tra array statici, automatici e dinamici in termini di:
//   - allocazione (stack, heap, data segment)
//   - tempo di vita
//   - gestione della memoria (chi la alloca e chi la libera)
//
// BONUS: Perché `new` e `delete` sono utili quando non conosciamo la dimensione
//         dell’array a tempo di compilazione?

domande:

-array statici:
    *allocati nella data segment perchè devono continueare ad esistere e conservare il valore anche alla fine della funzione in cui sono usati
    *tempo di vita = fino alla fine del programma
    *vengono allocati e liberati direttamente dal sistema/compilatore --> noi sviluppatore non ce ne preoccupiamo
-array automatici:
    *allocati nello stack perchè alla fine della funzione dove sono creati e usati vengono distrutti
    *tempo di vita = alla funzione
    *vengono allocati e liberati direttamente dal sistema/compilatore/funzione --> noi sviluppatore non ce ne preoccupiamo
-array dinamici:
    *allocati nell'heap
    *fino a quando viene chiamata la delete su quell'array
    *vengono allocati specificatamente da noi sviluppatori con new e delete

BONUS:
perchè permettono di creare un array senza sapere di preciso la dimensione ma verrà saputa solo a run time e non a compile time

| Tipo array     | Memoria        | Vita                             | Inizializzazione | Note                               |
| -------------- | -------------- | -------------------------------- | ---------------- | ---------------------------------- |
| **Statico**    | *Data segment* | Tutta la durata del programma    | Solo una volta   | Mantiene stato tra chiamate        |
| **Automatico** | *Stack*        | Solo finché la funzione è attiva | Ad ogni chiamata | Più veloce, ma spazio limitato     |
| **Dinamico**   | *Heap*         | Finché non chiami `delete[]`     | Gestita da `new` | Flessibile ma più costoso in tempo |


*/