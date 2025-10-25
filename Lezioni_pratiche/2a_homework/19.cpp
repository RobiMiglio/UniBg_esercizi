/*
Esercizio 19 (Primi Gemelli)
Due numeri primi p e q sono gemelli se p = q + 2.
Scrivere un programma che stampi i primi gemelli minori di un intero fornito dall'utente.
*/

#include <iostream>
using namespace std;

int main()
{
    int numero = 0;

    // Input con controllo
    do
    {
        cout << "Inserire un numero positivo: ";
        cin >> numero;
        if (numero <= 0)
        {
            cout << "Valore non corretto - riprovare" << endl;
        }
    } while (numero <= 0);

    cout << endl;
    cout << "I numeri primi gemelli minori di " << numero << " sono:" << endl;

    bool almenoUnaCoppia = false;
    int ultimoPrimo = 0;

    // Ciclo su tutti i numeri minori del limite
    for (int i = 2; i < numero; i++)
    {
        bool ePrimo = true;

        // Controllo se i è primo
        for (int k = 2; k * k <= i && ePrimo; k++)
        {
            if (i % k == 0)
                ePrimo = false;
        }

        // Se è primo, verifica se forma una coppia gemella con l’ultimo primo
        if (ePrimo)
        {
            if (ultimoPrimo != 0 && i - ultimoPrimo == 2)
            {
                cout << "( " << ultimoPrimo << " , " << i << " )" << endl;
                almenoUnaCoppia = true;
            }
            ultimoPrimo = i; // aggiorna l'ultimo primo trovato
        }
    }

    if (!almenoUnaCoppia)
        cout << "Nessuna coppia di primi gemelli trovata." << endl;

    return 0;
}
