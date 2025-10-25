/*

UNIVERSITA` DI BERGAMO
ESAME DI
INFORMATICA 12 CFU – Modulo di Programmazione (ING. INFORMATICA)
Prof. G. PSAILA
APPELLO DEL 17/01/2024
Per consegnare, si svolgano entrambi gli esercizi.
Durata: 90 minuti.
Punteggio complessivo: 16 punti. Sufficienza: 9 punti.
Esercizio (10 punti)
Si consideri un programma per gestire le prenotazioni di una catena di alberghi.
Una prenotazione è descritta da un tipo strutturato denominato PRENOTAZIONE, i cui campi sono un codice di 18 caratteri (che identifica univocamente la prenotazione), la data di emissione (stringa nel formato internazionale aaaa-mm-gg), la data di inizio del periodo prenotato (stringa di 10 caratteri), il numero di giorni (numero intero), il codice dell’albergo (stringa di 10 caratteri), il numero della camera (numero intero), la categoria della camera (numero intero), il prezzo della prenotazione (numero in virgola mobile) e lo stato della prenotazione (numero intero, dove 1 indica che la prenotazione è attiva, 2 indica che il soggiorno è avvenuto, 3 indica che la prenotazione è stata annullata).
Si definisca quindi la struttura dati per una lista dinamica dove il campo informativo del nodo è a sua volta basato sul tipo PRENOTAZIONE.
Si scriva la funzione denominata PrenotazioniAlbergoAffollato, che riceve come parametri una lista di prenotazioni denominata listaIn, un vettore di caratteri denominato dataSoggiorno (indicante una data), un vettore di stringhe (vettore di puntatori a carattere) denominato alberghi e un numero intero denominato size, che indica il numero di elementi nel vettore alberghi. Il vettore alberghi contiene un elenco di codici di albergo.
La funzione restituisce una nuova lista di prenotazioni (gestita internamente con la variabile listaOut) che contiene tutte e sole le prenotazioni per un soggiorno che inizia nella data indicata da dataSoggiorno dell’albergo (tra quelli indicati nel vettore alberghi) che ha il maggior numero di prenotazioni per soggiorni che iniziano nella data dataSoggiorno.
La funzione restituisce NULL in caso di errore o di lista vuota.
N.B. si eviti la duplicazione di parti del codice del programma.
Domanda Teoria (6 punti)
Si consideri il sistema di encoding dei caratteri in UTF-8.
Dati i Byte 11100001 10101000 10000011 si estragga il codice binario del carattere, lo si converta in base 10 e si dica se è incluso o meno nella tabella ASCII.

*/

#include <iostream>
#include <cstring>

using namespace std;

struct PRENOTAZIONE
{
	char codice[19];
	char dataEmissione[13];
	char dataInizioPeriodoPrenotato[11];
	int numeroGiorni;
	char codiceAlbergo[11];
	int numeroCamera;
	int categoriaCamera;
	float prezzo;
	int statoPrenotazione;
};

struct NODO
{
	PRENOTAZIONE info;
	NODO *next;
};

int contaPrenotazioni(NODO *lista, char dataSoggiorno[], char codiceAlbergo[])
{
	int somma = 0;
	while(lista!=NULL)
	{
		if(strcmp(lista->info.codiceAlbergo, codiceAlbergo)==0 && strcmp(lista->info.dataInizioPeriodoPrenotato, dataSoggiorno)==0)
		{
			somma++;
		}
		lista = lista->next;
	}
	return somma;
}

const char* ricercaAlbergoMaxPrenotazioni(NODO *lista, char dataSoggiorno[], char *codiciAlberghi[], int size)
{
	const char *codiceALbergoMax = NULL;
	int sommaPrenotazioni = 0;
	int sommaPrenotazioniMax = 0;
	for(int i=0; i<size; i++)
	{
		sommaPrenotazioni = contaPrenotazioni(lista, dataSoggiorno, codiciAlberghi[i]);
		if(sommaPrenotazioni>sommaPrenotazioniMax)
		{
			codiceALbergoMax = codiciAlberghi[i];
			sommaPrenotazioniMax = sommaPrenotazioni;
		}
	}
	return codiceALbergoMax;
}
		
int inserisciInTesta(NODO *&lista, PRENOTAZIONE p)
{
	NODO *nuovoNodo = new NODO;
	if(nuovoNodo == NULL)
	{
		cout << "memoria terminata" << endl;
		return -1;
	}
	nuovoNodo->info = p;
	nuovoNodo->next = lista;
	lista = nuovoNodo;
	return 0;
}

NODO* PrenotazioniAlbergoAffollato(NODO *listaIn, char dataSoggiorno[], char *codiciAlberghi[], int size)
{
	if(listaIn==NULL || size==0)
	{
		return NULL;
	}
	
	NODO *listaOut = NULL;
	const char *codiceAlbergoMaxPrenotazioni = ricercaAlbergoMaxPrenotazioni(listaIn, dataSoggiorno, codiciAlberghi, size);
	if(codiceAlbergoMaxPrenotazioni==NULL)
	{
		return NULL;
	}
	
	while(listaIn!=NULL)
	{
		if(strcmp(listaIn->info.codiceAlbergo, codiceAlbergoMaxPrenotazioni)==0 && strcmp(listaIn->info.dataInizioPeriodoPrenotato, dataSoggiorno) == 0)
		{
			if(inserisciInTesta(listaOut, listaIn->info)<0)
			{
				return NULL;
			}
		}
		listaIn = listaIn->next;
	}
	return listaOut;
}

/*
domanda teoria

dobbiamo fare decoding da UTF-8 quindi estrapoliamo il codice binario escludendo
il template UTF-8
0001 101000 000011

eliminiamo i bit superflui
1101000000011 che in decimale è = 4096+2048+512+2+1 = 6659

non è quindi incluso nella tabella ASCII dove i valori sono 0-127

*/

