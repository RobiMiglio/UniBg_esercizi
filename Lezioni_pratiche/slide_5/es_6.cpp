/*
esercizio 6

Si progetti e codifichi una funzione C++ che riceve come parametri due stringhe che
rappresentano due parole e restituisce un valore intero,
da interpretarsi come valore di verità, che indichi se le due parole sono anagrammi, cioè
se sono ottenibili l’una dall’altra tramite una permutazione
delle lettere che le compongono.
Ad esempio le parole POLENTA e PENTOLA sono anagrammi.
Si presti attenzione al fatto che parole come TAPPO e PATTO non sono anagrammi,
anche se ogni lettera dell’una è contenuta nell’altra.

*/

#include <iostream>
#include <cstring>

using namespace std;

#define LUNGHEZZA_MAX 41

void bubbleSort(char *stringa, int size)
{
    int limite = size-1;
	bool scambioEffettuato = 0;
	int indiceScambioEffettuato = 0;
	do
	{
		scambioEffettuato = 0;
		indiceScambioEffettuato = 0;
		
		for(int i=0; i<limite; i++)
		{
			if(stringa[i] > stringa[i+1])
			{
				int temp = stringa[i];
				stringa[i] = stringa[i+1];
				stringa[i+1] = temp;
				scambioEffettuato = 1;
				indiceScambioEffettuato = i;
			}
		}
		limite = indiceScambioEffettuato;
	}while(scambioEffettuato && limite >0);
}

//funzione che riordina le lettere di ogni stringa in ordine alfabetico e poi le confronta per vedere se sono uguali
//ritorna 1 se sono anagrammi e 0 se non lo sono
bool isAnagrammi(char *par1, char *par2)
{
	int lunghezzaParola1 = strlen(par1);
	int lunghezzaParola2 = strlen(par2);	
	if(lunghezzaParola1 != lunghezzaParola2)
	{
		return 0;
	}
	
	char parola1[lunghezzaParola1+1];
	char parola2[lunghezzaParola2+1];
	strcpy(parola1, par1);
	strcpy(parola2, par2);

    // converto tutto in maiuscolo
    for (int i = 0; i < lunghezzaParola1; i++)
    {
        if (parola1[i] >= 'a' && parola1[i] <= 'z')
        {
            parola1[i] -= 32;
        }
    }            
    for (int i = 0; i < lunghezzaParola2; i++)
    {
        if (parola2[i] >= 'a' && parola2[i] <= 'z')
        {
            parola2[i] -= 32;
        }
    }

	//riordino parola1
	bubbleSort(parola1, lunghezzaParola1);

	//riordino parola2
	bubbleSort(parola2, lunghezzaParola2);

	if(strcmp(parola1, parola2) ==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
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

	if(isAnagrammi(parola1, parola2))
	{
		cout << "queste due parole sono anagrammi " << endl;
	}
	else
	{
		cout << "queste due parole non sono anagrammi " << endl;
	}

	return 0;
}