/*
===========================================================
   MEGA TEST FINALE — DOMANDA 7
   Argomenti: puntatori a puntatori, memoria dinamica, array di stringhe
===========================================================

Progettare un programma che gestisca dinamicamente un piccolo
elenco di parole (array di stringhe), utilizzando **puntatori a puntatori**.

Il programma deve:
 - dichiarare un `char **lista` che rappresenta un array di stringhe;
 - allocare dinamicamente memoria per N parole (es. 3);
 - per ogni parola, allocare spazio dinamico e copiare il contenuto
   (es. "Ciao", "Mondo", "C++");
 - stampare l’elenco completo tramite doppia dereferenziazione;
 - deallocare correttamente tutta la memoria allocata (prima
   ogni stringa, poi l’array di puntatori).

⚙️ Vincoli:
 - non usare `std::string` (solo array di `char`);
 - mostrare chiaramente come avviene la dereferenziazione;
 - il programma deve funzionare anche variando N.

Esempio indicativo di output:
Parola 1: Ciao  
Parola 2: Mondo  
Parola 3: C++

-----------------------------------------------------------
💭 Domande teoriche:

1️⃣ Spiega cosa rappresenta un `char **` in memoria.
   (descrivi la struttura dei livelli di indirizzamento)

2️⃣ Cosa accade se si libera solo `delete[] lista`
   senza liberare prima le stringhe interne?
   Perché è un errore?

===========================================================
Scrivi qui sotto il tuo codice 👇
===========================================================

*/
/*
===========================================================
   SOLUZIONE GUIDATA — DOMANDA 7
===========================================================
*/

#include <iostream>
#include <cstring> // per strcpy()

using namespace std;

int main()
{
    int N = 3; // numero di parole
    char **lista = new char*[N]; // 👈 array di puntatori a char (livello 1: l’array)

    // Creiamo manualmente le parole di esempio
    const char *paroleOrig[] = {"Ciao", "Mondo", "C++"};

    for(int i = 0; i < N; i++)
    {
        // 1️⃣ Alloca spazio per la stringa (lunghezza + 1 per il terminatore '\0')
        lista[i] = new char[strlen(paroleOrig[i]) + 1];

        // 2️⃣ Copia il contenuto della parola originale dentro la nuova memoria
        strcpy(lista[i], paroleOrig[i]);
    }

    // 3️⃣ Stampa con doppia dereferenziazione
    cout << "== Elenco parole ==" << endl;
    for(int i = 0; i < N; i++)
    {
        cout << "Parola " << i + 1 << ": " << lista[i] << endl;
    }

    // 4️⃣ Deallocazione corretta
    for(int i = 0; i < N; i++)
    {
        delete[] lista[i]; // 👈 libera ogni stringa
    }
    delete[] lista; // 👈 libera l’array di puntatori

    return 0;
}

/*
-----------------------------------------------------------
💭 RISPOSTE DOMANDE TEORICHE:
-----------------------------------------------------------

1️⃣ `char **` rappresenta un **puntatore a un puntatore di char**,
    cioè un indirizzo che punta a un’area di memoria contenente
    più indirizzi di tipo `char *`.  
    Ogni `char *` a sua volta punta all’inizio di una stringa
    (sequenza di caratteri terminata da '\0').

    Struttura in memoria:
        [lista] → | ptr1 | ptr2 | ptr3 |
                      ↓      ↓      ↓
                    "Ciao" "Mondo" "C++"

2️⃣ Se si fa solo `delete[] lista`, si libera l’array di puntatori,
    ma **non** le stringhe a cui questi puntatori fanno riferimento.  
    Quindi la memoria delle singole stringhe resta allocata → 
    si verifica un **memory leak**, perché non abbiamo più un modo
    per accedere a quelle aree e liberarle.

-----------------------------------------------------------
🧠 RIASSUNTO CONCETTUALE:
-----------------------------------------------------------
- `char *`  → puntatore a una singola stringa (livello 1)
- `char **` → array di più `char *`, cioè tante stringhe (livello 2)
- Ogni livello deve essere allocato e deallocato separatamente.
===========================================================
*/
