/*

Esercizio 16
Scrivere un programma che prenda in input un numero in base 10, e lo converta in una
base scelta dall'utente (la nuova base deve essere compresa tra 2 e 9).

*/
#include <iostream>
using namespace std;

// Funzione per convertire un numero in base 10 in una base tra 2 e 9
int convertiDato(int value, int base)
{
    int risultatoDivisione = value;
    int resto = 0;
    int valoreDaRitornare = 0;
    int moltiplicatore = 1;

    // Finché il numero non diventa 0
    while (risultatoDivisione > 0)
    {
        // Calcolo il resto della divisione (una cifra della nuova base)
        resto = risultatoDivisione % base;

        // Aggiorno il quoziente
        risultatoDivisione /= base;

        // Costruisco il nuovo numero mettendo la cifra più "a sinistra"
        valoreDaRitornare += resto * moltiplicatore;

        // Aumento la posizione (le cifre si leggono da destra a sinistra)
        moltiplicatore *= 10;
    }

    return valoreDaRitornare;
}

int main()
{
    int numero = 0;
    char tipologiaBase = 0;

    // Input: numero decimale
    do
    {
        cout << "Inserire un numero positivo in base 10: ";
        cin >> numero;
        if (numero <= 0)
        {
            cout << "Valore non corretto - riprovare" << endl;
        }
    } while (numero <= 0);

    cout << endl;

    // Scelta della base di conversione
    do
    {
        cout << "In che base vuoi convertire? " << endl
             << "a - binaria (base 2)" << endl
             << "b - base 3" << endl
             << "c - base 4" << endl
             << "d - ottale (base 8)" << endl
             << "e - base 9" << endl;
        cin >> tipologiaBase;
    } while (!((tipologiaBase == 'a') || (tipologiaBase == 'b') ||
               (tipologiaBase == 'c') || (tipologiaBase == 'd') ||
               (tipologiaBase == 'e')));

    cout << endl;

    int base = 0;
    switch (tipologiaBase)
    {
    case 'a':
        base = 2;
        break;
    case 'b':
        base = 3;
        break;
    case 'c':
        base = 4;
        break;
    case 'd':
        base = 8;
        break;
    case 'e':
        base = 9;
        break;
    }

    int valoreConvertito = convertiDato(numero, base);
    cout << "Conversione del numero " << numero << " in base " << base
         << " = " << valoreConvertito << endl;

    return 0;
}
