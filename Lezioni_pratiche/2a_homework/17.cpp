/*

Esercizio 17 (Privo di Quadrati)
Un numero intero positivo è privo di quadrati se non esiste un quadrato perfetto che lo
divide (equivalentemente, se non esiste un quadrato di primo che lo divide). Scrivete un
programma che legga un numero in input e determini se è privo di quadrati.

*/


#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Inserisci un numero intero positivo: ";
    cin >> n;

    if (n <= 0) {
        cout << "Il numero deve essere positivo." << endl;
        return 0;
    }

    bool privo_di_quadrati = true;

    for (int p = 2; p * p <= n; p++) {
        int contatore = 0;
        while (n % p == 0) {
            n /= p;
            contatore++;
        }
        if (contatore >= 2) {  // se un fattore primo compare due volte o più
            privo_di_quadrati = false;
            break;
        }
    }

    if (privo_di_quadrati)
        cout << "Il numero è privo di quadrati" << endl;
    else
        cout << "Il numero NON è privo di quadrati" << endl;

    return 0;
}
