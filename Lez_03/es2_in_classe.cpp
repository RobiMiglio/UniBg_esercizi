/*

Si scriva un programma in linguaggio C++
che letto un numero intero positivo dallo standard input, visualizzi a
terminale il quadrato del numero stesso facendo uso soltanto di
operazioni di somma.
Si osservi che il quadrato di ogni numero intero positivo N
può essere costruito sommando tra loro i primi N numeri dispari.
Esempio:
N = 5;
N2 = 1 + 3 + 5 + 7 + 9 = 25.

*/


#include <iostream>

using namespace std;

int main()
{
    int numero = 0;


    do
    {
        cout << "inserisci numero intero positivo: ";
        cin >> numero;
        if(numero<0)
        {
            cout << "\nnumero non valido" << endl;
        }
    } while (numero<0);

    
    int quadrato = 0;
    int dispari = 1; // primo numero dispari

    for (int i = 0; i < numero; i++) 
    {
        quadrato += dispari;
        dispari += 2; // passa al dispari successivo
    }

    cout << "Il quadrato di " << numero << " è: " << quadrato << endl;
    




    return 0;
}