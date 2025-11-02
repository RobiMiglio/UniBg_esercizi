#include <iostream>
 
using namespace std;




/* versione base 

#define DIM 10

int main() {
	int V[DIM];
	int app;
	for(int i = 0; i < DIM; i++) {
		cin >> V[i];
	}
	for (int j = 0; j < DIM - 1; j++) {
		for (int i = 0; i < DIM - 1 - j; i++) {
			if (V[i] > V[i+1]) {
				app = V[i];
				V[i] = V[i+1];
				V[i+1] = app;
			}
		}
	}

	for(int i = 0; i < DIM; i++) {
		cout << V[i] << " ";
	}
}

*/





/* versione più efficente */

#include <iostream>
using namespace std;

/*
    Funzione che ordina un array di interi con l'algoritmo di Bubble Sort ottimizzato.

    Ottimizzazioni applicate:
    1️⃣ Interrompe il ciclo se l'array è già ordinato (flag scambiato = false)
    2️⃣ Tiene traccia dell’ultima posizione di scambio per ridurre i confronti
    3️⃣ Riduce il limite di iterazione a ogni passaggio (gli ultimi elementi sono già in ordine)
*/

void bubbleSort(int V[], int n) {
    int limite = n - 1;        // ultimo indice da controllare
    bool scambiato = true;     // flag per sapere se sono avvenuti scambi

    while (scambiato && limite > 0) {
        scambiato = false;     // all'inizio di ogni passaggio supponiamo che sia ordinato
        int ultimoScambio = 0; // memorizza l'ultimo indice dove avviene uno scambio

        // Ciclo principale di confronto
        for (int i = 0; i < limite; i++) {
            if (V[i] > V[i + 1]) {
                // Scambio dei due elementi adiacenti
                int temp = V[i];
                V[i] = V[i + 1];
                V[i + 1] = temp;

                scambiato = true;
                ultimoScambio = i; // aggiorno la posizione dell'ultimo scambio
            }
        }

        // Riduzione del limite al punto dell’ultimo scambio
        // perché dopo quella posizione gli elementi sono già ordinati
        limite = ultimoScambio;
    }
}

int main() {
    int n;

    // INPUT: numero di elementi
    cout << "Inserisci quanti numeri vuoi ordinare: ";
    cin >> n;

    // Controllo sull'input
    if (n <= 0) {
        cout << "Numero di elementi non valido!" << endl;
        return 1;
    }

    int V[n];

    // INPUT: valori dell'array
    cout << "Inserisci i " << n << " numeri da ordinare: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> V[i];
    }

    // ORDINAMENTO
    bubbleSort(V, n);

    // OUTPUT: stampa array ordinato
    cout << "\nArray ordinato: ";
    for (int i = 0; i < n; i++) {
        cout << V[i] << " ";
    }
    cout << endl;

    return 0;
}


