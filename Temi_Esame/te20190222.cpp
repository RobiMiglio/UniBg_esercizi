/*

UNIVERSITA` DI BERGAMO
ESAME DI
INFORMATICA 12 CFU – Modulo di Programmazione
(ING. INFORMATICA)
Prof. G. PSAILA
APPELLO DEL 22/02/2019
Per consegnare, si svolgano entrambi gli esercizi. Durata: 90 minuti.
Punteggio complessivo: 16 punti. Sufficienza: 9 punti.

Esercizio (10 punti)
Si consideri un programma per gestire la raccolta delle informazioni relative ai coupon per acquisto
di servizi, venduti da un sito di vendita di questi coupon. Un coupon è descritto da un tipo
strutturato denominato COUPON, i cui campi sono un codice di 10 caratteri (che identifica
univocamente un coupon), la data di emissione (stringa nel formato internazionale aaaa-mm-gg ),
la data di scadenza, il codice dell’esercente (stringa di 10 caratteri), l’indirizzo email dell’acquirente
(stringa di 250 caratteri), il valore del coupon in Euro, lo stato del coupon (numero intero, dove 1
indica che il coupon non è stato ancora utilizzato, 2 indica che è stato utilizzato).
Si definisca quindi la struttura dati per una lista dinamica dove il campo informativo del nodo è a
sua volta basato sul tipo COUPON.
Si scriva la funzione denominata EstraiCouponDuplicatiUsati che riceve come parametri
due liste di coupon, denominate rispettivamente lista1 e lista2. La funzione restituisce
l’indirizzo della testa di una nuova lista ottenuta inserendo i coupon presenti in lista1 con lo
stato non utilizzato e in lista2 con lo stato utilizzato (nella nuova lista, vanno inseriti con
quest’ultimo stato). La funzione restituisce NULL in caso di errore o in cui non ci siano coupon con
le caratteristiche desiderate.
N.B. Si eviti la duplicazione del codice.
N.B. Si usi il codice per stabilire se un coupon è presente in entrambe le liste.

Domanda Teoria (6 punti)
Si consideri un sistema dove per gli indirizzi di memoria vengono usati 24 bit e la memoria viene
gestita con il sistema della paginazione con pagine da 1Kbyte e indirizzi logici. Si consideri il
seguente indirizzo logico l=00000000010100 0000101101.
Se nella tabella delle pagine abbiamo le corrispondenze pl→pf (in base 10) 17→11, 18→35,
19→55, 20→106, qual è l’indirizzo fisico f su 24 bit corrispondente all’indirizzo logico l ?

*/

#include <iostream>
#include <cstring>

using namespace std;

struct COUPON
{
	char codice[11];
	char dataEmissione[11];
	char dataScadenza[11];
	char codiceEsercente[11];
	char emailAcquirente[251];
	int valore;
	int stato;
};

struct NODO
{
	COUPON info;
	NODO *next;
};

NODO* cerca(NODO *lista, COUPON c)
{
	if(lista==NULL)
	{
		return NULL;
	}
	
	while(lista != NULL)
	{
		if((strcmp(lista->info.codice, c.codice)==0) && lista->info.stato==2 && c.stato==1)
		{
			return lista;
		}
		lista = lista->next;
	}
	return NULL;
}

int inserisciInCoda(NODO *&lista, COUPON c)
{
	NODO *nuovoNodo = new NODO;
	if(nuovoNodo == (NODO*)NULL)
	{
		cout << "memoria terminata" << endl;
		return -1;
	}
	nuovoNodo->info = c;
	nuovoNodo->next = NULL;
	
	//lista vuota
	if(lista == NULL)
	{
		lista = nuovoNodo;
		return 0;
	}
	
	NODO *temp = lista;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = nuovoNodo;
	return 0;
}
	

NODO* EstraiCouponDuplicatiUsati(NODO *lista1, NODO *lista2)
{
	if(lista1 == NULL || lista2 == NULL)
	{	
		return NULL;
	}
	
	NODO *nuovaLista = NULL;
	
	int statoInserimento = 0;
	while(lista1 != NULL)
	{
		NODO *trovato = cerca(lista2, lista1->info);
		
		if(trovato!=NULL)
		{
			statoInserimento = inserisciInCoda(nuovaLista, trovato->info);
			if(statoInserimento <0)
			{
				return NULL;
			}
		}	
		
		lista1 = lista1->next;
	}
	return nuovaLista;
}

/*
domanda teoria

gli indirizzi di memoria si dividono in due parti
-pagina logica
-offset di pagina

La dimensione della pagina stabilisce l'offset.
I restanti bit sono a tutti gli effetti l'indice, della tabella delle pagine, 
a cui è associato il frame fisico (pagina fisica).

trovato il valore della pagina fisica:
-lo si converte in binario
-lo si adatta ai bit riservati per la pagina logica
-lo si unisce ai bit dell'offset di pagina ed ecco che abbiamo ottenuto il 
 corrispondente indirizzo fisico
 
esempio pratico richiesto

-offset --> 1Kbyte -> 1024byte --> 2^10 --> 10 bit per offset
-quindi visto che per indirizzo usiamo 24 bit --> 24-10 = 14 bit per la pagina logica

ora quindi l'indirizzo logico lo spezziamo così:
-pagina logica = 00000000010100
-offset = 0000101101

il valore in decimale di 00000000010100 è 20 quindi la tabella ci dice che 
il frame fisico è 106 che tradotto in binario è 1101010
Adattato ai 14 bit diventa 00000001101010

quindi indirizzo fisico è 000000011010100000101101

*/