/*

Pagina 1 di 5
Esercizio 1
Scrivere un programma che riceve in ingresso il contenuto di una matrice quadrata
di interi con N2 elementi.
Il programma calcola e visualizza i massimi locali della matrice.
Il massimo locale e' definito come un elemento della matrice i cui adiacenti sono
tutti minori o uguali ad esso.
Esempio: data la matrice M[5][5] (i cui massimi locali sono rappresentati in
grassetto):
il programma dovra' stampare a video:
Nota: attenzione al calcolo dei massimi lungo i bordi della matrice.
*/


#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{

    int base = 0;

    do
    {
        cout << "Inserire un numero positivo che sarà la base da moltiplicare per la potenza di 2 e formerà la nostra matrice: ";
        cin >> base;
        if (base <= 0)
        {
            cout << "Valore non corretto - riprovare" << endl;
        }
    } while (base <= 0);

	int matrice[base][base];
	
	srand(time(NULL));
	
	//valorizzazione e stampa valori matrice
	for(int i=0; i<base; i++)
	{
		for(int k=0; k<base; k++)
		{
			matrice[i][k] = rand()%100;
			cout << matrice[i][k] << "  ";
		}
		cout << endl;
	}
	
	cout << endl;
	
	//stampa massimi locali
	for(int i=0; i<base; i++)
	{
		for(int k=0; k<base; k++)
		{
			//angolo in alto a sinistra
			if((i==0)&&(k==0))
			{
				if((matrice[i][k] > matrice[i+1][k]) &&
				   (matrice[i][k] > matrice[i][k+1]) &&
				   (matrice[i][k] > matrice[i+1][k+1]))
				{
					cout << "Matrice [" << i << " , " << k << "] = " << matrice[i][k] << endl;
				}
			}
			//angolo in basso a sinistra
			else if((i==(base-1))&&(k==0))
			{
				if((matrice[i][k] > matrice[i-1][k]) &&
				   (matrice[i][k] > matrice[i][k+1]) &&
				   (matrice[i][k] > matrice[i-1][k+1]))
				{
					cout << "Matrice [" << i << " , " << k << "] = " << matrice[i][k] << endl;
				}
			}
			//angolo in basso a destra
			else if((i==(base-1))&&(k==(base-1)))
			{
				if((matrice[i][k] > matrice[i-1][k-1]) &&
				   (matrice[i][k] > matrice[i-1][k]) &&
				   (matrice[i][k] > matrice[i-1][k-1]))
				{
					cout << "Matrice [" << i << " , " << k << "] = " << matrice[i][k] << endl;
				}
			}
			//angolo in alto a destra
			else if((i==0)&&(k==(base-1)))
			{
				if((matrice[i][k] > matrice[i][k-1]) &&
				   (matrice[i][k] > matrice[i+1][k]) &&
				   (matrice[i][k] > matrice[i-1][k-1]))
				{
					cout << "Matrice [" << i << " , " << k << "] = " << matrice[i][k] << endl;
				}
			}
			//parete sinistra
			else if((i>0)&&(i<(base-2))&&(k==0))
			{
				if((matrice[i][k] > matrice[i-1][k]) &&
				   (matrice[i][k] > matrice[i+1][k]) &&
				   (matrice[i][k] > matrice[i-1][k+1]) &&
				   (matrice[i][k] > matrice[i][k+1]) &&
				   (matrice[i][k] > matrice[i+1][k+1]))
				{
					cout << "Matrice [" << i << " , " << k << "] = " << matrice[i][k] << endl;
				}
			}
			//parete destra
			else if((i>0)&&(i<(base-2))&&(k==(base-1)))
			{
				if((matrice[i][k] > matrice[i-1][k]) &&
				   (matrice[i][k] > matrice[i+1][k]) &&
				   (matrice[i][k] > matrice[i-1][k-1]) &&
				   (matrice[i][k] > matrice[i][k-1]) &&
				   (matrice[i][k] > matrice[i+1][k-1]))
				{
					cout << "Matrice [" << i << " , " << k << "] = " << matrice[i][k] << endl;
				}
			}
			//parete alta
			else if((k>0)&&(k<(base-2))&&(i==0))
			{
				if((matrice[i][k] > matrice[i][k-1]) &&
				   (matrice[i][k] > matrice[i][k+1]) &&
				   (matrice[i][k] > matrice[i+1][k-1]) &&
				   (matrice[i][k] > matrice[i+1][k]) &&
				   (matrice[i][k] > matrice[i+1][k+1]))
				{
					cout << "Matrice [" << i << " , " << k << "] = " << matrice[i][k] << endl;
				}
			}
			//parete bassa
			else if((k>0)&&(k<(base-2))&&(i==(base-1)))
			{
				if((matrice[i][k] > matrice[i][k-1]) &&
				   (matrice[i][k] > matrice[i][k+1]) &&
				   (matrice[i][k] > matrice[i-1][k-1]) &&
				   (matrice[i][k] > matrice[i-1][k]) &&
				   (matrice[i][k] > matrice[i-1][k+1]))
				{
					cout << "Matrice [" << i << " , " << k << "] = " << matrice[i][k] << endl;
				}
			}
			//tutti gli altri valori all'interno della matrice
			else
			{
				if((matrice[i][k] > matrice[i-1][k-1]) &&
				   (matrice[i][k] > matrice[i-1][k]) &&
				   (matrice[i][k] > matrice[i-1][k+1]) &&
				   (matrice[i][k] > matrice[i+1][k-1]) &&
				   (matrice[i][k] > matrice[i+1][k]) &&
				   (matrice[i][k] > matrice[i+1][k+1]) &&
				   (matrice[i][k] > matrice[i][k-1]) &&
				   (matrice[i][k] > matrice[i][k+1]))
				{
					cout << "Matrice [" << i << " , " << k << "] = " << matrice[i][k] << endl;
				}
			}
		}
		cout << endl;
	}
	

	return 0;
}
