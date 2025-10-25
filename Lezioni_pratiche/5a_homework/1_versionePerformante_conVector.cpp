/*
Esercizio 1 – Massimi locali in una matrice quadrata

Un elemento M[i][j] è un "massimo locale" se tutti gli elementi adiacenti
(inclusi quelli in diagonale) sono minori o uguali a lui.

L’obiettivo è:
- Leggere la dimensione N della matrice
- Generare casualmente i valori
- Trovare e stampare le celle M[i][j] che sono massimi locali

Versione ottimizzata:
→ Niente lunghi blocchi di if per i bordi
→ Usiamo due cicli per analizzare automaticamente i vicini
→ Evitiamo di uscire dai limiti della matrice
*/

#include <iostream>
#include <vector>
#include <cstdlib>  // per rand() e srand()
#include <ctime>    // per time()

using namespace std;

int main()
{
    int N = 0;

    // ✅ Input controllato
    do
    {
        cout << "Inserire la dimensione N della matrice quadrata: ";
        cin >> N;
        if (N <= 0)
        {
            cout << "Valore non valido - riprovare" << endl;
        }
    } while (N <= 0);

    // ✅ Creiamo una matrice NxN usando vector (standard C++)
    vector<vector<int>> M(N, vector<int>(N));

    srand(time(NULL)); // inizializza generatore casuale

    // ✅ Riempimento e stampa della matrice
    cout << "\nMatrice generata (" << N << "x" << N << "):\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            M[i][j] = rand() % 100; // valori tra 0 e 99
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nMassimi locali trovati:\n";

    // ✅ Scorriamo tutti gli elementi della matrice
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            bool eMassimoLocale = true; // ipotizziamo che sia un massimo

            // 🔁 Analizziamo tutti gli 8 vicini intorno a (i, j)
            for (int di = -1; di <= 1; di++) // spostamento di riga
            {
                for (int dj = -1; dj <= 1; dj++) // spostamento di colonna
                {
                    // Salta se stiamo controllando la cella stessa
                    if (di == 0 && dj == 0)
                        continue;

                    // Calcoliamo le coordinate del vicino
                    int ni = i + di;
                    int nj = j + dj;

                    // ✅ Controlliamo che il vicino sia dentro la matrice
                    if (ni >= 0 && ni < N && nj >= 0 && nj < N)
                    {
                        // Se un vicino è più grande → non è massimo locale
                        if (M[ni][nj] > M[i][j])
                        {
                            eMassimoLocale = false;
                        }
                    }
                }
            }

            // ✅ Se è rimasto vero → è un massimo locale
            if (eMassimoLocale)
            {
                cout << "M[" << i << "," << j << "] = " << M[i][j] << endl;
            }
        }
    }

    return 0;
}
