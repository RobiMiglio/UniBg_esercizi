/*
te20240618

UNIVERSITA` DI BERGAMO

ESAME DI
INFORMATICA 12 CFU – Modulo di Programmazione
(ING. INFORMATICA)
Prof. G. PSAILA

APPELLO DEL 18/06/2024

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

Si scriva la funzione denominata PrenotazioniAlbergoMaxDurataMedia, che riceve
come parametri una lista di prenotazioni denominata listaIn, un vettore di
caratteri denominato dataInizio (che descrive una data in formato
internazionale), un vettore di stringhe (vettore di puntatori a carattere)
denominato alberghi ed un numero intero denominato size, che indica il numero
di elementi nel vettore alberghi. Il vettore alberghi contiene un elenco di
codici di albergo.

La funzione restituisce una nuova lista di prenotazioni, così ottenuta:
(1) per ciascun albergo riportato nel vettore alberghi, la funzione calcola la
durata media dei soggiorni (descritti dalle prenotazioni per quell’albergo)
che iniziano nella data dataInizio;
(2) trovato l’albergo con il massimo valore per la durata media dei soggiorni
di interesse, la funzione crea una nuova lista (gestita internamente con la
variabile listaOut) che contiene una copia di tutte le prenotazioni per
quell’albergo e relative a soggiorni che iniziano in data dataInizio (cioè,
i soggiorni di interesse usati per calcolare la durata media al punto 1).

La funzione restituisce il valore di listaOut, oppure, in caso di errore,
la funzione restituisce il valore NULL.

N.B. Si risolva il problema in modo da fare esattamente DUE scansioni della
lista puntata dal parametro listaIn, lavorando direttamente su di essa e
senza creare copie temporanee (sia totali che parziali).

N.B. Si eviti la duplicazione di parti del codice del programma.

Domanda Teoria (6 punti)

Si consideri un sistema in cui per gli indirizzi di memoria vengono usati
24 bit e la memoria viene gestita con il sistema della paginazione con
pagine da 1Kbyte e indirizzi logici. Si consideri il seguente indirizzo
logico l = 000000000010100000001011.

Se nella tabella delle pagine abbiamo le corrispondenze pl -> pf (in base 10)
29 -> 18, 32 -> 127, 18 -> 19, 20 -> 13, qual è l’indirizzo fisico f su 24 bit
corrispondente all’indirizzo logico l?
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


bool isInizioSoggiornoInDataInizio(PRENOTAZIONE p, const char dataInizio[])
{
	if(strcmp(p.dataInizioPeriodoPrenotato, dataInizio)==0)
	{
		return 1;
	}
	return 0;
}

int giorniDaOrigine(int anno, int mese, int giorno)
{
    int giorniMese[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int tot = 0;

    tot += anno * 365;

    for (int m = 1; m < mese; m++)
        tot += giorniMese[m-1];

    tot += giorno;

    return tot;
}

int durataSoggiorno(PRENOTAZIONE p)
{
    int aI = atoi(p.dataInizioPeriodoPrenotato);
    int mI = atoi(p.dataInizioPeriodoPrenotato + 5);
    int gI = atoi(p.dataInizioPeriodoPrenotato + 8);

    int aF = atoi(p.dataFinePeriodoPrenotato);
    int mF = atoi(p.dataFinePeriodoPrenotato + 5);
    int gF = atoi(p.dataFinePeriodoPrenotato + 8);

    int inizio = giorniDaOrigine(aI, mI, gI);
    int fine   = giorniDaOrigine(aF, mF, gF);

    return fine - inizio;
}

const char* trovaAlberghoMaxMedia(NODO *lista, const char dataInizio[], const char *alberghi[], int size)
{
	float mediaMax = 0;
	int posCodALbergo = 0;
	const char *albergo = NULL;
	
	float contatoriMedie[size];
	for(int i=0;i<size;i++)
	{
		contatoriMedie[i] = 0;
	}
	
	int contatoriNumeroSoggiorni[size];
	for(int i=0;i<size;i++)
	{
		contatoriNumeroSoggiorni[i] = 0;
	}
	
	while(lista != NULL)
	{
		for(int i=0; i<size; i++)
		{
			if(strcmp(lista->info.codiceAlbergo, alberghi[i])==0 && isInizioSoggiornoInDataInizio(lista->info, dataInizio))
			{
				contatoriMedie[i] += durataSoggiorno(lista->info);
				contatoriNumeroSoggiorni[i] += 1;
			}
		}
		lista = lista->next;
	}
	
	for(int i=0; i<size; i++)
	{
		if(contatoriNumeroSoggiorni[i]>0)
		{
			contatoriMedie[i] /= contatoriNumeroSoggiorni[i];
			if(contatoriMedie[i] > mediaMax)
			{
				mediaMax = contatoriMedie[i];
				posCodALbergo = i;
			}
		}
	}
	
	if(mediaMax==0)
	{
		return NULL;
	}
	albergo = alberghi[posCodALbergo];
	return albergo;
}

int inserisciInTesta(NODO *&lista, PRENOTAZIONE p)
{
	NODO *nuovoNodo = new NODO;
	if(nuovoNodo == NULL)
	{
		return -1;
	}
	
	nuovoNodo->info = p;
	nuovoNodo->next = lista;
	lista = nuovoNodo;
	return 0;
}


NODO* PrenotazioniAlbergoMaxDurataMedia(NODO *listaIn, const char dataInizio[], const char *alberghi[], int size)
{
	if(listaIn==NULL || size<1)
	{
		return NULL;
	}
	
	NODO *listaOut = NULL;
	
	const char *codALbergoMaxMediaSogg = trovaAlberghoMaxMedia(listaIn, dataInizio, alberghi, size);
	if(codALbergoMaxMediaSogg == NULL)
	{
		return NULL;
	}
	
	while(listaIn != NULL)
	{
		if(strcmp(listaIn->info.codiceAlbergo, codALbergoMaxMediaSogg)==0 && isInizioSoggiornoInDataInizio(listaIn->info, dataInizio))
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

pagine da 1Kbyte = 1024byte = 2^10
quindi si riserva per ogni pagina 10 bit

quindi dei 24 bit totali
-pagina logica = 14 bit
-offset di pagina = 10 bit

quindi dividiamo indirizzo logico 000000000010100000001011 in 
-pagina logica = 00000000001010
-offset di pagina = 0000001011

in decimale la pagina logica = 10 
Poiché la pagina logica non è presente nella tabella delle pagine, si verifica un page fault

*/