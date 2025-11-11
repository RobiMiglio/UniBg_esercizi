#include <iostream>

using namespace std;

void Lettura(int *v, int size);
void Stampa(int v[], int size);


int main()
{
    const int SIZE=5;
    int elenco[SIZE];

    Lettura( elenco, SIZE);
    Stampa( elenco, SIZE );
   
   return 0;
}

void Lettura(int *v, int size)
{
	int i;
	
	for(i=0; i < size; i++)
	{
		cout << "INserire valore " 
		    << (i+1) << ": ";
		cin >> v[i];
	}
}

void Stampa(int v[], int size)
{
	int i;
	
	for(i=0; i < size; i++)
	{
		cout << "Valore " 
		    << (i+1) << ": "
		    << v[i] << endl;
	}
}


