#include <iostream>

using namespace std;

void BubbleSort( int v[], int size)
{
	int i, continua;
	int t;
	
	do
	{
		continua = 0;
	    for(i = 0; i < size-1; i++)
	    {
	   	    if( v[i] > v[i+1])
	   	    {
	   	    	t = v[i];
	   	     	v[i] = v[i+1];
		   	   v[i+1] = t;
		   	   continua = 1;
			}
	    }
	} while( continua );
}

void Lettura(int *&v, int &size)
{
	int i;
	
	cout << "ELementi? ";
	cin >> size;
	
	v = new int[size];
	if( v == NULL)
	{
		cout << "Memoria Esaurita";
		exit(1);
	}
	
	for(i=0; i < size; i++)
	{
		cout << "Inserire valore " 
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
    int SIZE;
    int *elenco;

    Lettura( elenco, SIZE);
    BubbleSort( elenco, SIZE );
    Stampa( elenco, SIZE );
    delete elenco;
   
   return 0;
}



