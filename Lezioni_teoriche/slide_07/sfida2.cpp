
/*

SFIDA 2
Scrivere un programma che legge da tastiera un
vettore di SIZE=10 elementi. Il vettore viene ordinato
al termine della lettura.
Richiedere un numero da cercare, quindi effettuare la
ricerca chiamando al funzione Ricerca, alla quale
viene passato l'indirizzo del primo elemento del
vettore, il numero di elementi e il valore da cercare; la
funzione restituisce -1 se non trova il valore, altrimenti
restituisce la posizione in cui ha trovato il valore.

Fate due versioni:
- la versione iterativa realizza la ricerca nella funzione
Ricerca in modo iterativo;
- la versione ricorsiva realizza la funzione Ricerca in
modo ricorsivo.

*/

#include <iostream>

using namespace std;

#define SIZE 10

void bubbleSort(int *arr, int size)
{
    bool scambio;
    int limite = size - 1;
    do
    {
        scambio = false;
        for(int i = 0; i < limite; i++)
        {
            if(arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                scambio = true;
            }
        }
        limite--;
    }
    while(scambio);
}

int ricercaIterativa(int *arr, int size, int valoreRicerca)
{
	int low = 0;
	int high = size-1;
	int mid = 0;
	
	while(low<=high)
	{
		mid = (low+high)/2;
		if(valoreRicerca==arr[mid])
		{
			return mid;
		}
		else if(valoreRicerca<arr[mid])
		{
			high = mid-1;
		}
		else if(valoreRicerca>arr[mid])
		{
			low = mid+1;
		}
	}
	
	return -1;
}

int ricercaRicorsiva(int *arr, int low, int high, int valoreRicerca)
{
    if(low>high)
    {
        return -1;
    }

    int mid = (low+high)/2;

    if(valoreRicerca==arr[mid])
	{
		return mid;
	}
	else if(valoreRicerca<arr[mid])
	{
        return ricercaRicorsiva(arr, low, mid-1, valoreRicerca);
	}
	else
	{
		return ricercaRicorsiva(arr, mid+1, high, valoreRicerca);
	}
}


int main()
{
	int vettore[SIZE];

	cout << "inserire 10 numeri" << endl;
	for(int i=0; i<SIZE; i++)
	{
		cout << i+1 << ": ";
		cin >> vettore[i];
	}
	cout << endl;

    bubbleSort(vettore, SIZE);
    //stampa array ordinato
    for(int i=0; i< SIZE; i++)
    {
        cout << i+1 << ": " << vettore[i] << endl;
    }
	
	int valoreDaCercare = 0;
	
	cout << "inserisci il numero che vuoi cercare nell'array: ";
	cin >> valoreDaCercare;
	
    int indiceRicercaIterativa = ricercaIterativa(vettore, SIZE, valoreDaCercare);

    if(indiceRicercaIterativa>=0)
    {
        cout << "con la ricerca iterativa è stato trovato il numero: " << vettore[indiceRicercaIterativa] << " nell' indice: " << indiceRicercaIterativa << endl;
    }
    else
    {
        cout << "con la ricerca iterativa non è stato trovato il valore" << endl;
    }

    int indiceRicercaRicorsiva = ricercaRicorsiva(vettore, 0, SIZE-1, valoreDaCercare);

    if(indiceRicercaRicorsiva>=0)
    {
        cout << "con la ricerca ricorsiva è stato trovato il numero: " << vettore[indiceRicercaRicorsiva] << " nell' indice: " << indiceRicercaRicorsiva << endl;
    }
    else
    {
        cout << "con la ricerca ricorsiva non è stato trovato il valore" << endl;
    }
	

	return 0;
}
	
