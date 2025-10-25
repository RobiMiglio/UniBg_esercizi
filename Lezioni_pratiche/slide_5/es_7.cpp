/*
esercizio 7

Definiamo la "somiglianza" S fra due stringhe come il rapporto tra il doppio del numero di
"triplette di caratteri consecutivi" comuni ad entrambe le stringhe e la somma delle
"triplette di caratteri consecutivi" in ciascuna stringa.
Nel caso in cui almeno una delle due stringhe sia composta da meno di 3 caratteri, la
somiglianza è nulla (S = 0.0).
Scrivere un programma C++, che acquisisca due stringhe da tastiera (standard input) e
riporti sullo schermo (standard output) la loro "somiglianza", secondo la definizione
precedente.
S = ( 2 × N_comuni ) / ( N1 + N2 )

*/

#include <iostream>
#include <cstring>

using namespace std;

#define LUNGHEZZA_MAX 22

double somiglianza(char *par1, char *par2)
{
	int lunghezzaParola1 = strlen(par1);
	int lunghezzaParola2 = strlen(par2);
	
	if((lunghezzaParola1<3) || (lunghezzaParola2<3))
	{
		return 0;
	}
	
	int numeroTriplettePar1 = lunghezzaParola1-2;
	int numeroTriplettePar2 = lunghezzaParola2-2;
		
	char arrayTripletteParola1[numeroTriplettePar1][4];
	char arrayTripletteParola2[numeroTriplettePar2][4];
	
	for(int i=0; i<numeroTriplettePar1; i++)
	{
		for(int k=0; k<3; k++)
		{
			arrayTripletteParola1[i][k] = par1[k+i];
		}
        arrayTripletteParola1[i][3] = '\0';
	}

	for(int i=0; i<numeroTriplettePar2; i++)
	{
		for(int k=0; k<3; k++)
		{
			arrayTripletteParola2[i][k] = par2[k+i];
		}
        arrayTripletteParola2[i][3] = '\0';
	}
	
	int numeroTriplCondivise = 0;
	for(int i=0; i<numeroTriplettePar1; i++)
	{
		for(int k=0; k<numeroTriplettePar2; k++)
		{
			if(strcmp(arrayTripletteParola1[i], arrayTripletteParola2[k]) == 0)
			{
				numeroTriplCondivise += 1;
                break;
			}
		}
	}
	
	return (2.0 * numeroTriplCondivise) / (numeroTriplettePar1 + numeroTriplettePar2);
}
	
	

int main()
{

	char parola1[LUNGHEZZA_MAX];
	char parola2[LUNGHEZZA_MAX];
	
	cout << "inserire la prima parola di massimo " << LUNGHEZZA_MAX-1 << " lettere e poi premi invio per confermare: ";
	cin.getline(parola1, LUNGHEZZA_MAX, '\n');
	cout << endl;

	cout << "inserire la seconda parola di massimo " << LUNGHEZZA_MAX-1 << " lettere e poi premi invio per confermare: ";
	cin.getline(parola2, LUNGHEZZA_MAX, '\n');
	cout << endl;

	cout << "la somiglianza tra le due parole è: " << somiglianza(parola1, parola2) << endl;

	return 0;
}
