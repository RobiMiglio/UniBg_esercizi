/*
Esegue la somma di più numeri con terminatore zero (quando l'utente
inserisce la cifra 0 "zero" il programma termina e restituisce all'utente la
somma)
*/

#include <iostream>

using namespace std;

int main()
{
    int number;
    int sommaTotale = 0;

    do
    {
        cout << "inserisci un numero (0 per terminare e calcolare la somma): " << endl;
        cin >> number;
        sommaTotale += number;

    } while (number != 0);
    cout << "la somma totale dei numeri inseriti è: " << sommaTotale << endl;

    return 0;
}
