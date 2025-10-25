
/*
Esercizio 8

Data una sequenza di numeri interi, positivi e negativi, in valore assoluto minori di MAX_NUM,
si vuole sapere qual è la porzione di sequenza (fatta di elementi consecutivi) che rende massima la
somma dei suoi elementi.
Scrivere un sotto-programma che restituisca le posizioni d'inizio e di fine della porzione di sequenza
individuata e restituisca anche il valore della somma degli interi nella sottosequenza

*/

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

#define MAX_NUM 11
#define SIZE 6


void stampaPorzioneMax(int *arr, int size)
{
	int max = arr[0];
	int indiceSinistro = 0;
	int indiceDestro = 0;
	int temp = 0;
	for(int i=0; i<size; i++)
	{
		for(int j=i; j<size; j++)
		{
			temp += arr[j];
			if(temp > max)
			{
				max = temp;
				indiceSinistro = i;
				indiceDestro = j;
			}
		}
        temp = 0;
	}
	
	cout << "la porzione di sequenza con il risultato maggiore si trova tra: " << endl;
	cout << "indice sinistro: " << indiceSinistro+1 <<"a" << endl;
	cout << "indice destro: " << indiceDestro+1 <<"a" << endl;
	cout << "max: " << max << endl;
}

/*Funzione più performante
void stampaPorzioneMassima(int *array, int dimensione)
{
    int sommaCorrente = array[0];     // somma della sottosequenza che stiamo considerando ora
    int sommaMassima = array[0];      // somma massima trovata finora
    int inizioMax = 0;                // indice di inizio della sottosequenza migliore
    int fineMax = 0;                  // indice di fine della sottosequenza migliore
    int inizioTemp = 0;               // possibile nuovo inizio (quando ricominciamo da zero)

    // Scorriamo l'array partendo dal secondo elemento
    for (int i = 1; i < dimensione; i++)
    {
        // Se il numero attuale è migliore da solo che sommato a quello precedente,
        // allora conviene ripartire una nuova sottosequenza da qui
        if (array[i] > sommaCorrente + array[i])
        {
            sommaCorrente = array[i];
            inizioTemp = i;
        }
        else
        {
            // altrimenti continuiamo ad aggiungerlo alla somma corrente
            sommaCorrente += array[i];
        }

        // Se la nuova somma è la più alta trovata finora, aggiorniamo i dati
        if (sommaCorrente > sommaMassima)
        {
            sommaMassima = sommaCorrente;
            inizioMax = inizioTemp;
            fineMax = i;
        }
    }

    cout << "La porzione di sequenza con la somma massima e':" << endl;
    cout << "Indice sinistro: " << inizioMax + 1 << endl;
    cout << "Indice destro: " << fineMax + 1 << endl;
    cout << "Somma massima: " << sommaMassima << endl;
}
*/

int main()
{
	srand(time(NULL));
	
	int sequenza[SIZE];
	
    cout << "sequenza: ";
	for(int i=0; i<SIZE; i++)
	{
		sequenza[i] = (rand()%21)-10; //numeri che vanno da -10 a 10 (questo rispetta il limite di MAX_NUM)
        cout << sequenza[i] << " ";
	}
    cout << endl;
	
	stampaPorzioneMax(sequenza, SIZE);

	return 0;
}