/*
te20240702

UNIVERSITA` DI BERGAMO

ESAME DI
INFORMATICA 12 CFU – Modulo di Programmazione
(ING. INFORMATICA)
Prof. G. PSAILA

APPELLO DEL 02/07/2024

Per consegnare, si svolgano entrambi gli esercizi.
Durata: 90 minuti.
Punteggio complessivo: 16 punti. Sufficienza: 9 punti.

Esercizio (10 punti)

Si consideri un programma per gestire le prenotazioni di una catena di alberghi.
Una prenotazione è descritta da un tipo strutturato denominato PRENOTAZIONE,
i cui campi sono un codice di 18 caratteri (che identifica univocamente la
prenotazione), la data di emissione (stringa nel formato internazionale
aaaa-mm-gg), la data di inizio del periodo prenotato (stringa di 10 caratteri),
la data di fine del periodo prenotato (stringa di 10 caratteri), il codice
dell’albergo (stringa di 10 caratteri), il numero della camera (numero intero),
la categoria della camera (numero intero), il prezzo della prenotazione
(numero in virgola mobile) e lo stato della prenotazione (numero intero,
dove 1 indica che la prenotazione è attiva, 2 indica che il soggiorno è
avvenuto, 3 indica che la prenotazione è stata annullata).

Si definisca quindi la struttura dati per una lista dinamica dove il campo
informativo del nodo è a sua volta basato sul tipo PRENOTAZIONE.

Si scriva la funzione denominata PrenotazioniAlbergoMaxDueMesi, che riceve
come parametri una lista di prenotazioni denominata listaIn, un vettore di
stringhe (vettore di puntatori a carattere) denominato alberghi e un numero
intero denominato size, che indica il numero di elementi nel vettore alberghi.
Il vettore alberghi contiene un elenco di codici di albergo.

La funzione restituisce una nuova lista di prenotazioni, così ottenuta:
(1) per ciascun albergo riportato nel vettore alberghi, la funzione conta il
numero di prenotazioni il cui soggiorno termina nello stesso anno in cui è
iniziato, ma nel mese successivo (per esempio, se la prenotazione è iniziata
nel mese 09, deve terminare nel mese 10 dello stesso anno);
(2) trovato l’albergo con il massimo di prenotazioni con le caratteristiche
cercate, la funzione crea una nuova lista (gestita internamente con la
variabile listaOut) che contiene una copia di tutte le prenotazioni cercate
(cioè quelle che finiscono nel mese successivo al mese di inizio, ma nello
stesso anno) per quell’albergo.

La funzione restituisce il valore di listaOut, oppure, in caso di errore,
la funzione restituisce il valore NULL.

N.B. Si risolva il problema in modo da fare esattamente DUE scansioni della
lista puntata dal parametro listaIn, lavorando direttamente su di essa e
senza creare copie temporanee (sia totali che parziali).

N.B. Si eviti la duplicazione di parti del codice del programma.

Domanda Teoria (6 punti)

Si consideri l’encoding dei caratteri in UTF-8. Dati i due byte DE 95
(in base 16) che descrivono un carattere in UTF-8, si estragga il codice
binario e si riporti il corrispondente valore in base 10 del carattere
corrispondente.
*/


#include <iostream>
#include <cstring>

using namespace std;

struct PRENOTAZIONE
{
	char codice[19];
	char dataEmissione[13];
	char dataInizioPeriodoPrenotato[11];
	char dataFinePeriodoPrenotato[11];
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

bool dataTerminePrenotazioneOk(PRENOTAZIONE p)
{
	int meseInizioPrenotazione = ((p.dataInizioPeriodoPrenotato[5] - '0')*10) + (p.dataInizioPeriodoPrenotato[6] - '0');
	
	int meseFinePrenotazione = ((p.dataFinePeriodoPrenotato[5] - '0')*10) + (p.dataFinePeriodoPrenotato[6] - '0');
	
	int quantitaMesiSoggiornati = meseFinePrenotazione - meseInizioPrenotazione;
	
	if(strncmp(p.dataFinePeriodoPrenotato, p.dataInizioPeriodoPrenotato, 4)==0 && quantitaMesiSoggiornati==1)
	{
		return 1;
	}
	
	return 0;
}

void contaPrenotazioni(PRENOTAZIONE p, const char *alberghi[], int size, int contatori[])
{
	for(int i=0; i<size; i++)
	{
		if(strcmp(p.codiceAlbergo, alberghi[i])==0 && dataTerminePrenotazioneOk(p))
		{
			contatori[i]++;
		}
	}
}

const char* cercaAlbergoMAxPrenotazioni(NODO *lista, const char *alberghi[], int size)
{
	const char *albergoDesiderato = NULL;
	
	int contatori[size];
	for(int i=0; i<size; i++)
	{
		contatori[i] = 0;
	}
	
	while(lista!=NULL)
	{
		contaPrenotazioni(lista->info, alberghi, size, contatori);		
		lista = lista->next;
	}
	
	int max = 0;
	int pos = 0;
	for(int i=0; i<size; i++)
	{
		if(contatori[i]>max)
		{
			pos = i;
			max = contatori[i];
		}
	}
	if(max==0)
	{
		return NULL;
	}
	albergoDesiderato = alberghi[pos];
	return albergoDesiderato;
}


int inserisciInTesta(NODO *&lista, PRENOTAZIONE p)
{
	NODO *nuovoNodo = new NODO;
	if(nuovoNodo==NULL)
	{
		return -1;
	}
	
	nuovoNodo->info = p;
	nuovoNodo->next = lista;
	lista = nuovoNodo;
	return 0;
}

NODO* PrenotazioniAlbergoMaxDueMesi(NODO *listaIn, const char *alberghi[], int size)
{
	if(listaIn==NULL || size<1)
	{
		return NULL;
	}
	
	NODO *listaOut = NULL;
	
	const char *codiceAlbergoDesiderato = cercaAlbergoMAxPrenotazioni(listaIn, alberghi, size);
	if(codiceAlbergoDesiderato == NULL)
	{
		return NULL;
	}
	
	while(listaIn!=NULL)
	{
		if(strcmp(listaIn->info.codiceAlbergo, codiceAlbergoDesiderato)==0 && dataTerminePrenotazioneOk(listaIn->info))
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

conversione in binario (da base 16) tenendo template UTF-8
DE = 13*16^1 + 14*16^0 = 222 che in binario è 11011110
95 = 9*16^1 + 5*16^0 = 149 che in binario è 10010101

eliminazione prefissi UTF-8 e unificazione
11110010101

in decimale è 1941

*/