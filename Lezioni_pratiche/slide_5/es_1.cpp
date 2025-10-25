
/*
Esercizio 1 (SLIDE 5 MOD PROGRAMMAZIONE - ESERCITAZIONI)

Scrivere un sotto-programma in linguaggio C++ che ricevuta una
matrice quadrata come parametro restituisca al
chiamante un valore booleano indicante se la matrice è simmetrica
oppure no.
Scrivere quindi un programma principale minimale che acquisisca una
matrice quadrata di numeri reali dallo
standard input e testi la funzionalità del sotto-programma precedente.
Se la matrice non è simmetrica occorre annullare
le sue diagonali principali riportare su standard-output il risultato
ottenuto.

*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define RIGHE 3
#define COLONNE 3

bool isMatriceSimmetrica(int arr[][COLONNE], int righe, int colonne)
{
    if (righe != colonne) return false; // sicurezza

    for (int i = 0; i < righe; i++) {
        for (int k = i + 1; k < colonne; k++) {
            if (arr[i][k] != arr[k][i]) {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int matrice[RIGHE][COLONNE];
    srand(time(NULL));

    cout << "Matrice originale:" << endl;
    for (int i = 0; i < RIGHE; i++) {
        for (int k = 0; k < COLONNE; k++) {
            matrice[i][k] = (rand() % 21) - 10; // valori tra -10 e +10
            cout << matrice[i][k] << " ";
        }
        cout << endl;
    }

    cout << endl;

    if (isMatriceSimmetrica(matrice, RIGHE, COLONNE)) {
        cout << "La matrice è simmetrica." << endl;
    } else {
        cout << "La matrice NON è simmetrica." << endl;
        cout << "Annullamento della diagonale principale..." << endl;

        for (int i = 0; i < RIGHE; i++)
            matrice[i][i] = 0;

        cout << "\nMatrice modificata:" << endl;
        for (int i = 0; i < RIGHE; i++) {
            for (int k = 0; k < COLONNE; k++) {
                cout << matrice[i][k] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
