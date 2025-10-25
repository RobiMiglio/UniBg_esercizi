
/*

UNIVERSITA` DI BERGAMO


ESAME DI

INFORMATICA 12 CFU – Modulo di Programmazione (ING. INFORMATICA)

Prof. G. PSAILA


APPELLO DEL 19/02/2025


Per consegnare, si svolgano entrambi gli esercizi.

Durata: 90 minuti.

Punteggio complessivo: 16 punti. Sufficienza: 9 punti.


Esercizio (10 punti)

Si consideri un programma per gestire le verbalizzazioni di esami universitari.

Un verbale è descritto da un tipo strutturato denominato VERBALE, i cui campi sono un codice di 15 caratteri (che identifica univocamente il verbale), la data di verbalizzazione (stringa nel formato internazionale aaaa-mm-gg), la data dell’appello d’esame (stringa di 10 caratteri), la data di superamento dell’esame (stringa di 10 caratteri), il codice dell’insegnamento (stringa di 10 caratteri), il nome del docente (stringa di 50 caratteri), la matricola dello studente (Stringa di 7 caratteri), il voto (numero intero, dove 31 indica 30 e lode).

Si definisca quindi la struttura dati per una lista dinamica dove il campo informativo del nodo è a sua volta basato sul tipo VERBALE.

Si scriva la funzione denominata VerbaliVotiAlti, che riceve come parametri una lista di verbali denominata listaIn, un vettore di stringhe (vettore di puntatori a carattere) denominato insegnamenti ed un numero intero denominato size, che indica il numero di elementi nel vettore insegnamenti. Il vettore insegnamenti contiene un elenco di codici di insegnamento.

La funzione restituisce una nuova lista di verbali, così ottenuta: (1) per ciascun insegnamento riportato nel vettore insegnamenti, la funzione calcola la media dei voti dei verbali che sono stati creati nello stesso mese (anno e numero del mese) della data dell’appello; (2) trova l’insegnamento con la media calcolata al punto 1 più alta; (3) la funzione crea una nuova lista (gestita internamente con la variabile listaOut) che contiene una copia di tutti i verbali dell’insegnamento trovato al punto 2 il cui voto è maggiore della media calcolata al punto 1 per l’insegnamento identificato al punto2, se esiste..

La funzione restituisce il valore di listaOut, oppure, in caso di errore, la funzione restituisce il valore NULL.

N.B. Si risolva il problema in modo da fare esattamente DUE scansioni della lista puntata dal parametro listaIn, lavorando direttamente su di essa e senza creare copie temporanee (sia totali che parziali).

N.B. Si eviti la duplicazione di parti del codice del programma.


Domanda Teoria (6 punti)

Si consideri un sistema in cui per gli indirizzi di memoria vengono usati 20 bit e la memoria viene gestita con il sistema della paginazione con pagine da 1Kbyte e indirizzi logici. Si consideri il seguente indirizzo logico l=00000100110000100110.

Se nella tabella delle pagine abbiamo le corrispondenze pl→pf (in base 10) 29→128, 32→6, 18→129, 19→38, qual è l’indirizzo fisico f su 24 bit corrispondente all’indirizzo logico l ?

*/




/*
Domanda teoria

Sistema di paginazione:
- Indirizzi logici: 20 bit
- Dimensione pagina: 1 KByte = 1024 byte = 2^10
⇒ Offset = 10 bit
⇒ Numero di pagina logica = 20 - 10 = 10 bit

L’indirizzo logico è quindi:
[ pagina logica (10 bit) | offset (10 bit) ]

pagina logica = 0000010011
offset = 0000100110

pagina logica in decimale è 19 che sulla tabella delle pagine
corrisponde a 38 che in binario è 100110

Dato che l’indirizzo fisico è di 24 bit:
⇒ Numero di pagina fisica = 24 - 10 = 14 bit

quindi adattiamo la pagina fisica su 14 bit = 00000000100110

indirizzo fisico ottenuto accostandoci offset:
000000001001100000100110

*/


#include <iostream>
#include <cstring>
using namespace std;

struct VERBALE
{
    char codice[16];
    char dataVerbalizzazione[11];
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
    NODO* next;
};


bool isDataOk(VERBALE v)
{
	return (strncmp(v.dataVerbalizzazione, v.dataAppello, 7)==0);
}

int ins_testa(NODO *&head, VERBALE v)
{
	NODO *nuovoNodo = new NODO;
	if(nuovoNodo == NULL)
	{
		return -1;
	}
	
	nuovoNodo->info = v;
	nuovoNodo->next = head;
	head = nuovoNodo;
	return 0;
}

void contaVoti(VERBALE v, const char *insegnamenti[], int size, float contatoriVoti[], int contatoriInsegnamenti[])
{
	for(int i=0; i<size; i++)
	{
		if(strcmp(v.codiceInsegnamento, insegnamenti[i])==0)
		{
			contatoriVoti[i] += v.voto;
			contatoriInsegnamenti[i]++;
		}
	}
}

void calcolaMedie(NODO *lista, const char *insegnamenti[], int size, float contatoriVoti[], int contatoriInsegnamenti[])
{
	while(lista != NULL)
	{
		if(isDataOk(lista->info))
		{
			contaVoti(lista->info, insegnamenti, size, contatoriVoti, contatoriInsegnamenti);
		}
		lista = lista->next;
	}
}

NODO* VerbaliVotiAlti(NODO *listaIn, const char *insegnamenti[], int size)
{
	if(size<1 || listaIn==NULL)
	{
		return NULL;
	}
	
	float contatoriVoti[size];
	int contatoriInsegnamenti[size];
	for(int i=0; i<size; i++)
	{
		contatoriVoti[i]=0;
		contatoriInsegnamenti[i]=0;
	}
	
	calcolaMedie(listaIn, insegnamenti, size, contatoriVoti, contatoriInsegnamenti);
	
	float mediaMax = -1;
	int pos = 0;
	
	for(int i=0; i<size; i++)
	{
		if(contatoriInsegnamenti[i]>0)
		{
			float mediaMaxTemp = contatoriVoti[i] / contatoriInsegnamenti[i];
			if(mediaMaxTemp >mediaMax)
			{
				mediaMax = mediaMaxTemp;
				pos = i;
			}
		}
	}
	
	if(mediaMax<0)
	{
		return NULL;
	}
	
	const char *insegnamentoTrovato = insegnamenti[pos];
	NODO *listaOut = NULL;
	
	while(listaIn != NULL)
	{
		if(isDataOk(listaIn->info) && strcmp(listaIn->info.codiceInsegnamento, insegnamentoTrovato)==0 && listaIn->info.voto > mediaMax)
		{
			if(ins_testa(listaOut, listaIn->info)<0)
			{
				return NULL;
			}
		}
		listaIn = listaIn->next;
	}
	return listaOut;
}