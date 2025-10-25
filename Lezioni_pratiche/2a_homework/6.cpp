/*

Esercizio 6
Scrivete un programma che, dopo aver richiesto in input un numero intero positivo n,
stampi la corrispondente tabellina, moltiplicando n
per i numeri interi da 1 a 10, come indicato nel seguente esempio di esecuzione.

*/

#include <iostream>

using namespace std;

int main()
{
    int n = 0;
	do
	{
		cout << "inserisci un numero intero positivo: ";
		cin >> n;
		if(n<=0)
		{
			cout << "non valido - riprovare" << endl;
		}
	}while(n<=0);
	
	cout << "ecco la tabellina del " << n << ":" << endl;
	for(int i=1; i<11; i++)
	{
		cout << i << " x " << n << " = " << i*n << endl;
	}
	
	return 0;
}