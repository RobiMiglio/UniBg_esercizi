/*
Esegue il massimo di più numeri con terminatore zero (quando l'utente
inserisce la cifra 0 "zero" il programma termina e restituisce all'utente il
valore massimo inserito)
*/

#include <iostream>

using namespace std;

int main()
{
    int number;
    int valoreMassimo = 0;

    do
    {
        cout << "inserisci un numero (0 per terminare e stampare il valore massimo): " << endl;
        cin >> number;
        if (number > valoreMassimo)
        {
            valoreMassimo = number;
        }
    } while (number != 0);

    cout << "il valore massimo è: " << valoreMassimo << endl;
    
}