#include <iostream>

using namespace std;

struct PUNTO
{
	float x;
	float y;
};

void stampa_punto(PUNTO pt)
{
	cout << "(" << pt.x << ","
	     << pt.y << ")";
}

void Leggi_Punti(PUNTO v[], int size)
{
	int i;
	
	for(i=0; i < size; i++)
	{
		cout << "Punto " << (i+1) << ":" << endl;
		cout << "Coord. x: ";
		cin >> v[i].x;
		cout << "Coord. y: ";
		cin >> v[i].y;
	}
}

void Stampa_Punti(PUNTO v[], int size)
{
	int i;
	
	for(i=0; i < size; i++)
	{
		cout << "Punto " << (i+1) << ":";
		stampa_punto(v[i]);
		cout << endl;
	}
}

PUNTO Calcola_Baricentro(PUNTO v[], int size)
{
	int i;
	float somma_x=0, somma_y=0;
	PUNTO b;
	
	for(i=0; i < size; i++)
	{
		somma_x += v[i].x;
		somma_y += v[i].y;
	}
	b.x = somma_x / size;
	b.y = somma_y / size;
	
	return b;
}

int main()
{
	const int SIZE=5;
	PUNTO elenco[SIZE];
	PUNTO bc;

	Leggi_Punti(elenco, SIZE);
	Stampa_Punti(elenco, SIZE);
	bc = Calcola_Baricentro(elenco, SIZE);
	cout << "Baricentro: ";
	stampa_punto(bc);

   return 0;
}

