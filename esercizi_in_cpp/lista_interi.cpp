/*

Devi gestire una lista di interi (senza sapere prima quanti saranno).
Serve un algoritmo che:

Permetta di inserire nuovi numeri in sequenza.

Permetta di stamparli tutti.

Permetta di calcolare la somma dei valori nella lista.

📌 Suggerimento: usa una struttura dinamica che ti consenta di aggiungere elementi senza dover sapere la dimensione in anticipo.

*/


#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> numeri;  // vettore dinamico di interi
    int x;

    cout << "Inserisci numeri (0 per terminare): ";
    while (true)
    {
        cin >> x;
        if (x == 0)
            break;
        numeri.push_back(x);  // aggiunge alla fine
    }

    cout << "\nHai inserito " << numeri.size() << " numeri.\n";

    int somma = 0;
       for (int i = 0; i < (int)numeri.size(); i++)
    {
        cout << "Elemento " << i + 1 << ": " << numeri[i] << endl;
        somma += numeri[i];
    }

    cout << "\nSomma totale: " << somma << endl;

    return 0;
}



