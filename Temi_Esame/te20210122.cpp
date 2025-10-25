/*
 * te20210122
 *
 * UNIVERSITA' DI BERGAMO
 *
 * ESAME DI
 * INFORMATICA 12 CFU – Modulo di Programmazione
 * (ING. INFORMATICA)
 * Prof. G. PSAILA
 *
 * APPELLO DEL 22/01/2021
 *
 * Per consegnare, si svolgano entrambi gli esercizi.
 * Durata: 90 minuti.
 * Punteggio complessivo: 16 punti.
 * Sufficienza: 9 punti.
 */

/*
 * =====================
 * Esercizio (10 punti)
 * =====================
 *
 * Si consideri un programma per gestire le registrazioni degli esami
 * sostenuti dagli studenti universitari.
 *
 * Una registrazione è descritta da un tipo strutturato denominato
 * REGISTRAZIONE, i cui campi sono:
 * - un codice di 10 caratteri (identifica univocamente la registrazione),
 * - la data della registrazione (stringa in formato internazionale aaaa-mm-gg),
 * - la data dell’appello,
 * - il numero di matricola dello studente (stringa di 10 caratteri),
 * - il codice dell’insegnamento (stringa di 10 caratteri),
 * - il codice del corso di laurea (stringa di 10 caratteri),
 * - il voto ottenuto (numero intero da 0 a 31, dove 31 indica la lode).
 *
 * Si definisca quindi la struttura dati per una lista dinamica dove
 * il campo informativo del nodo è a sua volta basato sul tipo REGISTRAZIONE.
 *
 * Si scriva la funzione denominata MiglioriRipetizioni, che riceve come
 * parametri:
 * - due liste di registrazioni, denominate lista1 e lista2,
 * - un vettore di codici di insegnamento (vettore di stringhe) denominato codiciIns,
 * - un parametro size che indica il numero di elementi nel vettore codiciIns.
 *
 * La funzione restituisce una nuova lista di registrazioni, gestita
 * internamente tramite la variabile listaOut.
 *
 * Una registrazione presente in lista1 viene inserita in listaOut se:
 * - il codice dell’insegnamento è presente in codiciIns
 * - e se vale una delle seguenti situazioni:
 *
 *   a) non esiste in lista2 una registrazione relativa allo stesso studente
 *      e allo stesso insegnamento;
 *
 *   b) esiste in lista2 una registrazione relativa allo stesso studente
 *      e allo stesso insegnamento, ma il voto ottenuto in quest’ultima
 *      è inferiore al voto ottenuto nella registrazione presente in lista1.
 *
 * La funzione restituisce l’indirizzo della testa della nuova lista.
 * La funzione restituisce NULL se non c’è nulla da restituire o in caso di errore.
 *
 * N.B. si eviti la duplicazione di parti del codice del programma.
 */

/*
 * =====================
 * Domanda di Teoria (6 punti)
 * =====================
 *
 * Si consideri il carattere il cui codice UNICODE è 4300_10.
 * Si riporti l’encoding UTF-8 corrispondente, facendo vedere
 * i passaggi effettuati.
 */


#include <iostream>
#include <cstring>

using namespace std;

struct REGISTRAZIONE
{
	char codice[11];
	char dataRegistrazione[11];
	char dataAppello[11];
	char matricola[11];
	char codiceInsegnamento[11];
	char codiceCorso[11];
	int voto;
};

struct NODO
{
	REGISTRAZIONE info;
	NODO *next;
};

bool isPresenteInLista(NODO *lista, REGISTRAZIONE r)
{
	while(lista!=NULL)
	{
		if(strcmp(lista->info.matricola, r.matricola)==0 && strcmp(lista->info.codiceInsegnamento, r.codiceInsegnamento)==0)
		{
			return 1;
		}
		lista = lista->next;
	}
	return 0;
}

bool isPresenteInListaEVerificaVoto(NODO *lista, REGISTRAZIONE r)
{
	while(lista!=NULL)
	{
		if(strcmp(lista->info.matricola, r.matricola)==0 && strcmp(lista->info.codiceInsegnamento, r.codiceInsegnamento)==0 && lista->info.voto<r.voto)
		{
			return 1;
		}
		lista = lista->next;
	}
	return 0;
}


bool isPresenteInListaCodiciIns(char *codici[], int size, REGISTRAZIONE r)
{
	for(int i=0; i<size; i++)
	{
		if(strcmp(r.codiceInsegnamento, codici[i])==0)
		{
			return 1;
		}
	}
	return 0;
}

int inserisciInTesta(NODO *&lista, REGISTRAZIONE r)
{
	NODO *nuovoNodo = new NODO;
	if(nuovoNodo==NULL)
	{
		return -1;
	}
	
	nuovoNodo->info = r;
	nuovoNodo->next = lista;
	lista = nuovoNodo;
	return 0;
}

NODO* MiglioriRipetizioni(NODO *lista1, NODO *lista2, char *codiciIns[], int size)
{
	if(lista1==NULL || size<1)
	{
		return NULL;
	}
	
	NODO *listaOut = NULL;
	
	while(lista1!=NULL)
	{
		if(isPresenteInListaCodiciIns(codiciIns, size, lista1->info) && 
		  (!isPresenteInLista(lista2, lista1->info) || isPresenteInListaEVerificaVoto(lista2, lista1->info)))
		{
			if(inserisciInTesta(listaOut, lista1->info)<0)
			{
				return NULL;
			}
		}
		 
		lista1 = lista1->next;
	}
	return listaOut;
}

/*
domanda teoria

conversione in binario di 4300 = 1000011001100

4300 fa parte del seguente template UTF-8 (3 byte - da 2048 a 65535) = 1110xxxx 10xxxxxx 10xxxxxx

abbiamo a disposizione quindi 16 campi valore da inserire nel template 
quindi aggiungiamo 3 zeri a sinistra per raggiungere il totale di 16 bit
0001000011001100

suddivione nel template = 11100001 10000011 10001100

*/