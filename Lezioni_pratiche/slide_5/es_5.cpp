/*
esercizio 5

Scrivere un programma in linguaggio C++ che conti il numero di parole contenute in una frase inserita
dall’utente.
Considerare qualsiasi carattere non alfanumerico come un
possibile separatore di parola.
Strutturare il programma prevedendo la definizione e l’utilizzo
di un sottoprogramma con il seguente prototipo
bool alfanum(char c)
che restituisce true nel caso il carattere passato come parametro sia alfanumerico
([‘A'...'Z', 'a'...'z', '0'...'9']), false in caso contrario.
Esempi:
"Oggi piove" : 2 parole
"Oggi c'e' il sole" : 5 parole

*/

#include <iostream>
#include <cstring>

using namespace std;

#define LUNGHEZZA_MAX 41


bool alfanum(char c)
{
	if(((c>='A')&&(c<='Z')) || ((c>='a')&&(c<='z')) || ((c>='0')&&(c<='9')))
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
	char frase[LUNGHEZZA_MAX];
	
	cout << "inserire una frase di massimo " << LUNGHEZZA_MAX-1 << " lettere e poi premi invio per confermare: ";
	cin.getline(frase, LUNGHEZZA_MAX, '\n');
	cout << endl;

	int lunghezzaFrase = strlen(frase);
	int sommaParole = 0;
	bool parolaIniziata = 0;
	for(int i=0; i<lunghezzaFrase+1; i++)
	{
		if(alfanum(frase[i]) && (parolaIniziata==0))
		{
			parolaIniziata = 1;
		}
		else if(!alfanum(frase[i]) && (parolaIniziata==1))
		{
			parolaIniziata = 0;
			sommaParole += 1;
		}
	}
	
	cout << "questa frase contiene: " << sommaParole << " parole" << endl;
		

	return 0;
}