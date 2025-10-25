/*
Esercizio 1 – Massimi locali (versione con allocazione dinamica)
Autore: studente
Note: non usa <vector>, solo new[] e delete[].
*/

#include <iostream>
#include <cstdlib>  // rand(), srand()
#include <ctime>    // time()
using namespace std;

int main() {
    int N = 0;

    // INPUT CON CONTROLLO
    do {
        cout << "Inserire la dimensione N della matrice quadrata: ";
        cin >> N;
        if (N <= 0)
            cout << "Valore non valido - riprovare" << endl;
    } while (N <= 0);

    // ✅ ALLOCAZIONE DINAMICA DELLA MATRICE NxN
    int** M = new int*[N];     // puntatore a righe
    for (int i = 0; i < N; i++)
        M[i] = new int[N];     // ogni riga ha N colonne

    srand(time(NULL)); // inizializza generatore casuale

    // RIEMPIMENTO E STAMPA MATRICE
    cout << "\nMatrice generata (" << N << "x" << N << "):\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            M[i][j] = rand() % 100; // numeri da 0 a 99
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nMassimi locali trovati:\n";

    // CONTROLLO DI TUTTI GLI ELEMENTI
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            bool eMassimo = true;

            // Controlla tutti i vicini (anche diagonali)
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {

                    if (di == 0 && dj == 0)
                        continue; // salta se è la cella stessa

                    int ni = i + di; // riga vicina
                    int nj = j + dj; // colonna vicina

                    // Controllo dei limiti della matrice
                    if (ni >= 0 && ni < N && nj >= 0 && nj < N) {
                        if (M[ni][nj] > M[i][j])
                            eMassimo = false;
                    }
                }
            }

            if (eMassimo)
                cout << "M[" << i << "," << j << "] = " << M[i][j] << endl;
        }
    }

    // ✅ DEALLOCAZIONE DELLA MATRICE
    for (int i = 0; i < N; i++)
        delete[] M[i];
    delete[] M;

    return 0;
}
