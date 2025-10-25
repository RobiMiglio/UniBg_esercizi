/*

Esercizio 12
Scrivere un programma che calcoli il massimo comun divisore (MCD) tra due numeri n1≥0
e n2≥0, usando l'algoritmo di Euclide.
Il principio di funzionamento dell'algoritmo è il seguente:
MCD(n1, 0) = n1, MCD(0, n2) = n2;
MCD(n1, n2) = n1, se n1 = n2;
MCD(n1, n2) = MCD(n1-n2, n2) se n1>n2;
MCD(n1, n2) = MCD(n1, n2-n1) se n2>n1
Input: numeri di cui calcolare il MCD
Output: MCD dei numeri.

*/

#include <iostream>

using namespace std;

int main()
{
	int n1 = 0;
	int n2 = 0;
	
	do
	{
		cout << "inserire un valore positivo per n1: ";
		cin >> n1;
		if(n1<0)
		{
			cout << "valore non idoneao - riprovare" << endl;
		}
	}while(n1<0);

	do
	{
		cout << "inserire un valore positivo per n2: ";
		cin >> n2;
		if(n2<0)
		{
			cout << "valore non idoneao - riprovare" << endl;
		}
	}while(n2<0);
	
	int mcd = 0;
	
    if(n1 == 0)
    {
        mcd = n2;
    }
    else if(n2 == 0)
    {
        mcd = n1;
    }
    else
    {
        // algoritmo di Euclide (versione a sottrazioni)
        while(n1 != n2)
        {
            if(n1 > n2)
                n1 -= n2;
            else
                n2 -= n1;
        }
        mcd = n1;  // quando n1 == n2, questo è il MCD
    }

	cout << "risultato: " << mcd << endl;


	return 0;
}