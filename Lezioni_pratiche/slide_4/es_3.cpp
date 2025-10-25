
/*
Es_3

Scrivere una funzione per definire se un numero è primo e un programma
principale minimale che ne testa la funzionalità.

*/

#include <iostream>

using namespace std;

bool isNumeroPrimo(int n)
{
    if (n < 2) return false;        // 0 e 1 non sono primi
    for (int i = 2; i*i <= n; i++)  // basta arrivare alla radice quadrata
    {
        if (n % i == 0)
            return false;            // ha un divisore, quindi non è primo
    }
    return true;                     // nessun divisore trovato → è primo
}


int main()
{
	int numero = 0;
	
	do
	{
		cout << "inserisci un numero positivo ";
		cin >> numero;
		if(numero<=0)
		{
			cout << "incorretto" << endl;
		}
	}while(numero<=0);
	
	if(isNumeroPrimo(numero))
	{
		cout << numero << " è un numero primo" << endl;
	}
	else
	{
		cout << numero << " non è un numero primo" << endl;
	}	

	return 0;
}