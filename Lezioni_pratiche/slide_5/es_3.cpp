
/*
esercizio 3

Scrivere un programma in linguaggio C++ che verifichi se una parola inserita dallo standard input
è palindroma e in caso contrario stampa a video la parola inserita partendo dall’ultimo carattere
sino al primo.
Le parole palindrome sono quelle che possono essere lette indifferentemente da sinistra a destra
e da destra a sinistra.
Esempio:
"anna", "abba", "onorarono", "radar",
"a" (parola di una lettera).

*/


#include <iostream>
#include <cstring>

using namespace std;

#define LUNGHEZZA_MASSIMA 21

int lunghezzaParola(char *arr)
{
	int lunghezza = 0;
	for(int i=0; arr[i] != '\0'; i++)
	{
		lunghezza += 1;
	}
	return lunghezza;
}

bool isParolaPalindroma(char *arr)
{
	int lungezzaPar = (lunghezzaParola(arr));
    char parolaAlContrario[lungezzaPar + 1]; // +1 per il terminatore
    for (int i = 0; i < lungezzaPar; i++) 
    {
        parolaAlContrario[i] = arr[lungezzaPar - 1 - i];
    }
    parolaAlContrario[lungezzaPar] = '\0';

	
	if(strcmp(arr, parolaAlContrario)==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
	

void stampaParolaAlContrario(char *arr)
{
	int lungezzaPar = lunghezzaParola(arr);
	for(int i=lungezzaPar-1; i>=0; i--)
	{
		cout << arr[i];
	}
	cout << " ";
}

int main()
{
	char parola[LUNGHEZZA_MASSIMA];
	
	cout << "inserisci una parola di massimo " << LUNGHEZZA_MASSIMA-1 << "lettere e poi premi invio: ";
	cin.getline(parola, LUNGHEZZA_MASSIMA, '\n');
	cout << endl;
	
	
	if(isParolaPalindroma(parola))
	{
		cout << "la parola: " << parola << " --> è palindroma" << endl;
	}
	else
	{
		cout << "la parola: " << parola << " --> non è palindroma, letta al contrario è: "; 
		stampaParolaAlContrario(parola);
		cout << endl;
	}

	return 0;
}