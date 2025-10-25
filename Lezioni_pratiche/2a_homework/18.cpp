/*

Esercizio 18 (Numeri perfetti)
Un numero è perfetto se è uguale alla somma dei suoi divisori propri.
Per esempio, 6 = 1+2+3 è perfetto.
Scrivete un programma che, dato un intero in input, scriva i numeri perfetti minori
dell’intero dato.

*/


#include <iostream>

using namespace std;

int main()
{

    int numero = 0;

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
	
	int somma = 0;
	
    cout << "i numeri perfetti minori di " << numero << " sono: ";
	for(int i=1; i<numero; i++)
	{
        somma = 0;
        for(int k=1; k<i; k++)
        {
            if(i%k == 0)
            {
                somma += k;
            }
        }
        if(somma == i)
        {
            cout << i << " ";
        }
	}

    cout << endl;
	
	return 0;
}