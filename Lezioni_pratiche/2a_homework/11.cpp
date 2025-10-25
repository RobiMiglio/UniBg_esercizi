/*

Esercizio 11
Data una base ed un esponente, calcolare “base elevato ad esponente”. Sia la base che
l'esponente sono valori interi. Utilizzare la struttura di controllo "for"
Input: base, esponente
Output: base elevato ad esponente

*/

#include <iostream>

using namespace std;

int main()
{
	int base = 0;
	int esponente = 0;
	
	do
	{
		cout << "inserire un valore positivo per la base: ";
		cin >> base;
		if(base<=0)
		{
			cout << "valore non idoneao - riprovare" << endl;
		}
	}while(base<=0);

	do
	{
		cout << "inserire un valore positivo per l'esponente: ";
		cin >> esponente;
		if(esponente<0)
		{
			cout << "valore non idoneao - riprovare" << endl;
		}
	}while(esponente<0);
	
    int risultato = 1;
    for (int i = 0; i < esponente; i++)
    {
        risultato *= base;
    }


	cout << "risultato: " << risultato << endl;


	return 0;
}