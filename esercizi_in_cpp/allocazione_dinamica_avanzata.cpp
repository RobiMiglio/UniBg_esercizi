// ⚙️ DOMANDA 12 – Allocazione dinamica avanzata (matrice dinamica)
//
// Scrivi un programma che:
//
//   1️⃣ Chieda all’utente il numero di righe e colonne di una matrice di int.
//   2️⃣ Allochi dinamicamente la matrice (array di puntatori a riga, con `new`).
//   3️⃣ Permetta all’utente di inserire i valori della matrice.
//   4️⃣ Calcoli e stampi la somma di tutti gli elementi.
//   5️⃣ Libera tutta la memoria correttamente usando `delete[]`.
//
// 🔍 DOMANDA TEORICA:
//   - Differenza tra array dinamico monodimensionale e bidimensionale in memoria.
//   - Cosa significa “allocazione contigua”? 
//   - Perché è necessario chiamare `delete[]` per ogni riga di una matrice dinamica?
//
// 💡 BONUS:
//   - Come potresti allocare la stessa matrice in un unico blocco contiguo di memoria?
//
// ✏️ Istruzioni:
//   - Usa solo `new` e `delete[]` (nessun vector o malloc).
//   - Mantieni stile “C-like” anche se scrivi in C++.
//   - Inserisci un commento finale con la tua risposta teorica.
//

#include <iostream>

using namespace std;

int main()
{
    int sizeRighe = 0;
    int sizeColonne = 0;
    cout << "inseri il numero di righe della matrice: ";
    cin >> sizeRighe;
    cout << "inseri il numero di colonne della matrice: ";
    cin >> sizeColonne;

    int **matriceDinamica = new int *[sizeRighe];

    for(int i=0; i<sizeRighe; i++)
    {
        matriceDinamica[i] = new int[sizeColonne];
    }

    // 🔸 Inserimento valori
    for (int i = 0; i < sizeRighe; i++) {
        for (int j = 0; j < sizeColonne; j++) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> matriceDinamica[i][j];
        }
    }

    // 🔹 Calcolo somma
    int somma = 0;
    for (int i = 0; i < sizeRighe; i++) 
    {
        for (int j = 0; j < sizeColonne; j++) 
        {
            somma += matriceDinamica[i][j];
        }
    }

    cout << "\nSomma totale = " << somma << endl;

    // 🔸 Libero memoria
    for (int i = 0; i < sizeRighe; i++) 
    {
        delete[] matriceDinamica[i];  // libera ogni riga
    }
    delete[] matriceDinamica;          // libera l’array di puntatori


    return 0;
}

/*
🧠 SPIEGAZIONE TEORICA

👉 Array dinamico monodimensionale:
- È un blocco contiguo di memoria nello heap (es. new int[n]).
- Accesso molto veloce, località spaziale ottimale.

👉 Matrice dinamica (doppio puntatore):
- È un array di puntatori a righe, ognuna con il proprio blocco nello heap.
- I blocchi NON sono contigui: le righe possono essere sparse in memoria.
- Serve un ciclo `delete[]` per ogni riga, altrimenti memory leak.

👉 Allocazione contigua:
- Significa che tutti i dati sono in un’unica area di memoria sequenziale.
  Esempio:
  ```cpp
  int *mat = new int[righe * colonne];
  mat[i * colonne + j] = valore;
  delete[] mat;

*/