/*

Esercizio 7
Disegnare sullo schermo un rettangolo, utilizzando un carattere a piacere (ad es. ‘#’), dopo
averne chiesto all’utente altezza (h) e lunghezza (l).
Ad esempio, per h = 4 e l = 6, ci si aspetta il seguente output:
******
******
******
******
Suggerimenti:
• Chiedere all’utente altezza e lunghezza
• Fare attenzione a gestire l’input (altezza e/o lunghezza negativi)
• Per il disegno, usare due cicli WHILE annidati, uno esterno che scandisce le
righe, uno interno che scandisce le colonne (o viceversa)

*/


#include <iostream>

using namespace std;

int main()
{
	int altezza = 0;
	int lunghezza = 0;
	
	do
	{
		cout << "inserire valore positivo per l'altezza: ";
		cin >> altezza;
		if(altezza<=0)
		{
			cout << "valore non corretto" << endl;
		}
	}while(altezza<=0);
	
	do
	{
		cout << "inserire valore positivo per la lunghezza: ";
		cin >> lunghezza;
		if(lunghezza<=0)
		{
			cout << "valore non corretto" << endl;
		}
	}while(lunghezza<=0);
		
	int contatoreRighe = 0;
	int contatoreColonne = 0;
	
	while(contatoreRighe<altezza)
	{
		while(contatoreColonne<lunghezza)
		{
			cout << "# ";
            contatoreColonne++;
		}
		cout << endl;
        contatoreColonne =0;
        contatoreRighe++;
	}

	return 0;
}