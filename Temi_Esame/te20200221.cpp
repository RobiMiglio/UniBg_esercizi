/*
UNIVERSITA` DI BERGAMO
ESAME DI
INFORMATICA 12 CFU – Modulo di Programmazione (ING. INFORMATICA)
Prof. G. PSAILA
APPELLO DEL 21/02/2020
Per consegnare, si svolgano entrambi gli esercizi. Durata: 90 minuti.
Punteggio complessivo: 16 punti. Sufficienza: 9 punti.

Esercizio (10 punti)
Si consideri un programma per gestire la raccolta delle informazioni relative 
agli abbonamenti ad un parcheggio. 
Un abbonamento è descritto da un tipo strutturato denominato ABBONAMENTO, i cui 
campi sono un codice di 10 caratteri (che identifica univocamente l’abbonamento), 
la data di emissione (stringa nel formato internazionale aaaa-mm-gg ), 
la data di scadenza, il numero di targa (stringa di 10 caratteri), l’importo residuo 
(numero in virgola mobile), il valore dell’ultimo addebito e la data dell’ultimo 
addebito..

Si definisca quindi la struttura dati per una lista dinamica dove il campo 
informativo del nodo è a sua volta basato sul tipo ABBONAMENTO.
Si scriva la funzione denominata SpostaAbbonamenti che riceve come parametri due 
liste di abbonamenti, denominate rispettivamente lista1 e lista2, un vettore di 
stringhe (vettore di puntatori a carattere) denominato elencoCodici, ed un parametro 
size (numero intero) che indica quanti sono gli elementi nel vettore elencoCodici. 
Per ogni codice presente nel vettore elencoCodici, la funzione verifica se il codice 
è presente in lista1: se un abbonamento con il codice cercato non è presente in 
lista1, lo cerca in lista2 e, se lo trova, copia l’abbonamento in questione in lista1.

La funzione restituisce il numero di abbonamenti copiati da lista2 a lista1; in 
caso di errore, la funzione restituisce -1.

Domanda Teoria (6 punti)
Si consideri un sistema in cui per gli indirizzi di memoria vengono usati 24 bit e 
la memoria viene gestita con il sistema della paginazione con pagine da 1Kbyte e 
indirizzi logici. Si consideri il seguente indirizzo logico 
l=000000000011100000101111.
Se nella tabella delle pagine abbiamo le corrispondenze pl→pf (in base 10) 
13→10, 14→7, 17→53, 20→102, qual è l’indirizzo fisico f su 24 bit corrispondente 
all’indirizzo logico l ?
*/

#include <iostream>
#include <cstring>

using namespace std;

struct ABBONAMENTO
{
	char codice[11];
	char dataEmissione[13];
	char dataScadenza[13];
	char numeroTarga[11];
	float importoResiduo;
	float valoreUltimoAddebito;
	char dataUltimoAddebito[13];
};

struct NODO
{
	ABBONAMENTO info;
	NODO *next;
};

NODO* cercaCodiceInLista(NODO *lista, const char codice[])
{
	while(lista!=NULL)
	{
		if(strcmp(lista->info.codice, codice)==0)
		{
			return lista;
		}
		lista = lista->next;
	}
	return NULL;
}

int inserisciInTesta(NODO *&lista,  ABBONAMENTO a)
{
	NODO *nuovoNodo = new NODO;
	if(nuovoNodo == (NODO*)NULL)
	{
		cout << "memoria terminata" << endl;
		return -1;
	}
	nuovoNodo->info = a;
	nuovoNodo->next = lista;
	lista = nuovoNodo;
	return 0;
}

int SpostaAbbonamenti(NODO *&lista1, NODO *&lista2, char *elencoCodici[], int size)
{	
	int sommaCodiciCopiati = 0;
	int risultatoInserimento = 0;
	for(int i=0; i<size; i++)
	{
		NODO *presenteInLista1 = cercaCodiceInLista(lista1, elencoCodici[i]);
		if(presenteInLista1!=NULL)
		{
			continue;
		}
		else
		{
			NODO *presenteInLista2 = cercaCodiceInLista(lista2, elencoCodici[i]);
			if(presenteInLista2!=NULL)
			{
				risultatoInserimento = inserisciInTesta(lista1, presenteInLista2->info);
				if(risultatoInserimento<0)
				{
					return -1;
				}
				else
				{
					sommaCodiciCopiati++;
				}
			}
			else
			{
				continue;
			}
		}
	}
	return sommaCodiciCopiati;
}

/*
domanda teorria

gli indirizzi in memoria sono composti da:
-pagina logica
-offset di pagina

l'offset di pagina è dato dalla grandezza di una pagina che in questo caso
è 1Kbyte = 1024 byte = 2^10 = quindi 10 bit sono riservati per offset.
quindi 24-10 = 14 bit dedicati per pagina logica

quindi scomponiamo l'indirizzo logico:
-pagina logica = 00000000001110
-offset = 0000101111

in decimale pagina logica = 14
sulla tabella delle pagine corrisponde a 7 che in binario è 111
lo adattiamo fino ad arrivare ai 14 bit --> 00000000000111

indirizzo fisico quindi è 000000000001110000101111

*/