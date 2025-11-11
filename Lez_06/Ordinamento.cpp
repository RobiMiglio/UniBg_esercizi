#include <iostream>

using namespace std;

void Sort( int v[], int size)
{
	int i, j;
	int t;
	
	for( i=0; i < size-1; i++)
	   for(j = i+1; j < size; j++)
	   {
	   	    if( v[i] > v[j])
	   	    {
	   	    	t = v[i];
	   	     	v[i] = v[j];
		   	   v[j] = t;
			}
	   }
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


int main()
{
    const int SIZE=5;
    int elenco[SIZE];

    Lettura( elenco, SIZE);
    Sort( elenco, SIZE );
    Stampa( elenco, SIZE );
   
   return 0;
}



