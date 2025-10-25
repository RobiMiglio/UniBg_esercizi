/*

UNIVERSITA` DI BERGAMO
ESAME DI
INFORMATICA 12 CFU – Modulo di Programmazione
(ING. GESTIONALE)
Prof. G. PSAILA
APPELLO DEL 24/02/2017
Per consegnare, si svolgano entrambi gli esercizi. Durata: 90 minuti.
Punteggio complessivo: 16 punti. Sufficienza: 9 punti

Esercizio (10 punti)
Si consideri un programma per gestire la raccolta delle informazioni relative ad un listino prezzi di
prodotti da vendere, organizzato in una lista dinamica. Un prodotto è definito da un tipo strutturato
denominato PRODOTTO, i cui campi sono il codice (stringa di 12 caratteri) la data di inserimento
nel listino (stringa nel formato internazionale aaaa-mm-gg ), il prezzo (numero in virgola mobile),
la percentuale IVA (numero intero) e una tipologia di prodotto (un numero intero positivo).
Si definisca quindi la struttura dati per una lista dinamica dove il campo informativo del nodo è a
sua volta basato sul tipo PRODOTTO.
Si scriva la funzione denominata ContaProdottiComuni che riceve come parametri due liste
di prodotti. La funzione restituisce il numero di codici di prodotto che sono presenti nelle due liste
con la stessa tipologia.

Domanda Teoria (6 punti)
Si descriva (in non più di una pagina) il ruolo svolto dal protocollo TCP e il suo posizionamento nel
modello ISO-OSI.

*/

#include <iostream>
#include <cstring>

using namespace std;

struct PRODOTTO
{
	char codice[13];
	char dataInserimento[11];
	float prezzo;
	int percentualeIva;
	int tipologia;
};

struct NODO
{
	PRODOTTO info;
	NODO *next;
};


int contaProdottiComuni(NODO *lista1, NODO *lista2)
{
	if(lista1==NULL || lista2==NULL)
	{
		return 0;
	}
	
	int count = 0;
	for(NODO *n=lista1; n!=NULL; n=n->next)
	{
		for(NODO *k=lista2; k!=NULL; k=k->next)
		{
			if((strcmp(n->info.codice, k->info.codice)==0) && (n->info.tipologia == k->info.tipologia))
			{
				count++;
				break;
			}
		}
	}
	return count;
}


/*
domanda teoria

TCP è un protocollo di trasporto che permette a due computer di scambiarsi dati in modo affidabile. Prima di iniziare 
la comunicazione crea una connessione stabile (three-way handshake), poi invia i dati in segmenti numerati e controlla 
che arrivino tutti e nell’ordine giusto. Se qualcosa va perso, richiede la ritrasmissione.

Gestisce anche la velocità di invio per evitare sovraccarichi nella rete o nel ricevente.

Nel modello ISO-OSI, TCP si trova al livello 4 – Trasporto. Sta sopra al livello di rete (IP), che si occupa solo di 
instradare i pacchetti, e fornisce alle applicazioni un servizio di comunicazione sicuro e ordinato.	

*/