
/*
esercizio 4

Facendo uso dei comandi messi a disposizione dalla libreria standard del
C++ definiti in <cstring>, risolvere il seguente problema.
Leggere due stringhe str1, str2 dallo standard input, stampare a video
lunghezza di str1 e str2, stampare il risultato della concatenazione delle due
stringhe: str1 concatenata str2, confrontare le due stringhe e stamparle in
ordine alfabetico.

*/

#include <iostream>
#include <cstring>

using namespace std;

#define LUNGHEZZA_MASSIMA 21


void stampaInOrdineAlfabetico(char *arr)
{
	int lunghezzaParola = strlen(arr);
	char stringaTemp[lunghezzaParola+1];
	
	//riempimento array temporaneo
	strcpy(stringaTemp, arr);
	
	//ordinamento in ordine alfabetico usando sitema bubblesort
	int limite = lunghezzaParola-1;
	bool scambioEffettuato = 1;
	int indiceUltimoScambio  = 0;
	do  
	{
		scambioEffettuato = 0;
        indiceUltimoScambio  = 0;
		
        for(int i=0; i<limite; i++)
        {
		    //togliere l'offset se lettera è minuscola, così da valutarle tutte con lo stesso valore sia che siano maiuscole che minuscole
		    char posizioneCorrente = (stringaTemp[i] >= 97 && stringaTemp[i]<= 122) ? (stringaTemp[i]-32) : stringaTemp[i];
		    char posizioneSuccessiva = (stringaTemp[i+1] >= 97 && stringaTemp[i+1]<= 122) ? (stringaTemp[i+1]-32) : stringaTemp[i+1];
            
		    if(posizioneCorrente > posizioneSuccessiva)
		    {
		    	int temp = stringaTemp[i];
		    	stringaTemp[i] = stringaTemp[i+1];
		    	stringaTemp[i+1] = temp;
		    	scambioEffettuato = 1;
		    	indiceUltimoScambio = i;
		    }
        }   
		limite = indiceUltimoScambio;
	}while(scambioEffettuato && limite>0);

	cout << stringaTemp;
}


int main()
{
	char s1[LUNGHEZZA_MASSIMA];
	char s2[LUNGHEZZA_MASSIMA];
	
	cout << "inserisci la prima parola di massimo " << LUNGHEZZA_MASSIMA-1 << " lettere e poi premi invio: ";
	cin.getline(s1, LUNGHEZZA_MASSIMA, '\n');
	cout << endl;

	cout << "inserisci la seconda parola di massimo " << LUNGHEZZA_MASSIMA-1 << " lettere e poi premi invio: ";
	cin.getline(s2, LUNGHEZZA_MASSIMA, '\n');
	cout << endl;
	
	//stampa lunghezza stringhe
	cout << "lungezza prima parola: " << strlen(s1) << endl;
	cout << "lungezza seconda parola: " << strlen(s2) << endl;
	
	//stampa concatenazione di s1 in s2
	char s1PlusS2[(strlen(s1)+strlen(s2)+1)];
    strcpy(s1PlusS2, s1);
    strcat(s1PlusS2, s2);
	cout << "concatenazione di s1 su s2: " << s1PlusS2 << endl;
	
	//stampa se sono uguali
	if(strcmp(s1, s2) ==0)
	{
		cout << "le stringhe sono uguali" << endl;
	}
	else
	{
		cout << "le stringhe non sono uguali" << endl;
	}
	
    //stampa parola che viene prima in base alle sue lettere (in ordine alfabetico)
    if (strcmp(s1, s2) < 0)
    {
        cout << s1 << " " << s2;
    }
    else
    {
        cout << s2 << " " << s1;
    }
    cout << endl;
    
	//stampa stringhe in ordine alfabetico
	cout << "la prima stringa stampata in ordine alfabetico è: ";
    stampaInOrdineAlfabetico(s1);
    cout << endl;
	cout << "la seconda stringa stampata in ordine alfabetico è: ";
    stampaInOrdineAlfabetico(s2);
    cout << endl;

	return 0;
}