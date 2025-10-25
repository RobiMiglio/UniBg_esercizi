
/*

Esercizio 3
Si chieda all’utente di inserire due numeri interi (a e b), tali che:
a > b > 0. Se ne calcoli la “strana somma” secondo la formula:
strana somma = a + (b) + (b – 1) + (b – 2) + … + 0
Si visualizzi a schermo il risultato dell’operazione.
Suggerimenti:
• Chiedere all’utente di inserire i due numeri usando cout <<, cin >>
• Fare attenzione a gestire l’input (vincoli sui numeri a e b)
• Usare un ciclo WHILE per calcolare la “strana somma”, decrementando
  opportunamente b
  
*/

#include <iostream>

using namespace std;

int main()
{

	int a = 0;
	int b = 0;
	int somma = 0;

	do
	{
		cout << "inserire il valore di b: ";
		cin >> b;
		if(b<=0)
		{
			cout << "non valido - inserire valore > 0" << endl;
		}
	}while(b<=0);
	
	do
	{
		cout << "inserire il valore di a: ";
		cin >> a;
		if(a<=b)
		{
			cout << "non valido - inserire valore > b" << endl;
		}
	}while(a<=b);

	somma = a;
	while(b>0)
	{
		somma += b;
		b--;
	}
	
	cout << "strana somma: " << somma << endl;
	
	return 0;
}

