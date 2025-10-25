/*
te20250920

2) Parte Pratica (10 punti)

Si consideri un programma per gestire le verbalizzazioni di esami universitari.


Un verbale è descritto da un tipo strutturato denominato VERBALE, i cui campi sono:

· un codice di 15 caratteri (che identifica univocamente il verbale),

· la data di emissione del verbale

· la data dell’appello d’esame

· la data di superamento dell’esame

· il codice dell’insegnamento (stringa di 10 caratteri),

· il nome del docente (stringa di 50 caratteri),

· la matricola dello studente (Stringa di 7 caratteri),

· il voto (numero intero, dove 31 indica 30 e lode).

I campi data sono stringhe di 10 caratteri in formato internazionale (aaaa-mm-gg).


Si definisca quindi la struttura dati per una lista dinamica dove il campo informativo del nodo è a sua volta basato sul tipo VERBALE.


Si scriva la funzione denominata CopiaAlcuniVerbali, che riceve come parametri due liste di verbali denominate lista1 e lista2, un vettore di stringhe (vettore di puntatori a carattere) denominato dateApplli ed un numero intero denominato size, che indica il numero di elementi nel vettore dateAppelli.

La funzione restituisce una nuova lista di verbali, così ottenuta:

(1) per ciascuna data nel vettore dateAppelli, la funzione conta il numero di verbali in lista1 e in lista2 (facendo un unico conteggio) emessi per appelli in quella data;

(2) la funzione calcola la data dataMax con il maggior numero di verbali (se esiste);

(3) la funzione copia in listaOut tutti e soli i verbali presenti in lista1 o in lista2 emessi per un appello in dataMax.

La funzione restituisce il valore di listaOut, oppure, in caso di errore, la funzione restituisce il valore NULL.


N.B. Si risolva il problema in modo da fare esattamente DUE scansioni di lista1 e DUE scansioni di lista2, lavorando direttamente su queste liste, senza modificarle e senza creare copie temporanee (sia totali che parziali).

*/



#include <iostream>
#include <cstring>

using namespace std;

struct VERBALE
{
    char codice[16];
    char dataEmissione[11];        // aaaa-mm-gg
    char dataAppello[11];
    char dataSuperamento[11];
    char codiceInsegnamento[11];
    char nomeDocente[51];
    char matricolaStudente[8];
    int voto;
};

struct NODO
{
    VERBALE info;
    NODO *next;
};

int insTesta(NODO *&lista, VERBALE v)
{
	NODO *nuovo = new NODO;
	if(nuovo==NULL)
	{
		return -1;
	}
	
	nuovo->info = v;
	nuovo->next = lista;
	lista = nuovo;
	return 0;
}

int cercaData(const char data[], const char *dateAppelli[], int size)
{
	for(int i=0; i<size; i++)
	{
		if(strcmp(data, dateAppelli[i])==0)
		{
			return i;
		}
	}
	return -1;
}

void contaConteggi(NODO *lista, const char *dateAppelli[], int size, int conteggi[])
{
	while(lista != NULL)
	{
		int posData = cercaData(lista->info.dataAppello, dateAppelli, size);
		if(posData>=0)
		{
			conteggi[posData]++;
		}
		lista = lista->next;
	}
}

int trovaPosDataMax(int conteggi[], int size)
{
	int max = -1;
	int pos = 0;
	for(int i=0; i<size; i++)
	{
		if(conteggi[i]>0 && conteggi[i]>max)
		{
			max = conteggi[i];
			pos = i;
		}
	}
	
	if(max!= -1)
	{
		return pos;
	}
	return -1;
}

int insInLista(NODO *&listaOut, NODO *lista, const char dataMax[])
{
	while(lista != NULL)
	{
		if(strcmp(lista->info.dataAppello, dataMax)==0)
		{
			if(insTesta(listaOut, lista->info)<0)
			{
				return -1;
			}
		}
		lista = lista->next;
	}
	return 0;
}

NODO* CopiaAlcuniVerbali(NODO *lista1, NODO *lista2, const char *dateAppelli[], int size)
{
	if(size<1)
	{
		return NULL;
	}
	
	int conteggi[size];
	for(int i=0; i<size; i++)
	{
		conteggi[i]=0;
	}
	
	//prima scansione di lista1
	contaConteggi(lista1, dateAppelli, size, conteggi);
	
	//prima scansione di lista2
	contaConteggi(lista2, dateAppelli, size, conteggi);
	
	int posDataMax = trovaPosDataMax(conteggi, size);
	//se non c'è nessun verbale che rispetta le condizioni ritorna NULL
	if(posDataMax < 0)
	{
		return NULL;
	}
	
	const char *dataMax = dateAppelli[posDataMax];
	NODO *listaOut = NULL;
	
	//seconda scansione di lista1
	if(insInLista(listaOut, lista1, dataMax)<0)
	{
		return NULL;
	}
	
	//seconda scansione di lista2
	if(insInLista(listaOut, lista2, dataMax)<0)
	{
		return NULL;
	}
	
	return listaOut;
}