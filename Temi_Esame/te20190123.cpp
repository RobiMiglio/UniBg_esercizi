/*
UNIVERSITA` DI BERGAMO
ESAME DI
INFORMATICA 12 CFU – Modulo di Programmazione
(ING. INFORMATICA)
Prof. G. PSAILA
APPELLO DEL 23/01/2019
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
Si scriva la funzione denominata FondiNonDuplicatiInDate che riceve come parametri due
liste di coupon, denominate rispettivamente lista1 e lista2. La funzione accoda a lista2
tutti i coupon in lista1 che non sono precedentemente presenti in lista2 (si usi il codice del
coupon per fare la verifica). La funzione restituisce il numero di coupon accodati a lista2,
mentre restituisce -1 in caso di errore.
N.B. Si eviti la duplicazione del codice.
N.B. si noti che lista2 potrebbe essere vuota all’inizio.

Domanda Teoria (6 punti)
Si riportino le 4 configurazioni della rappresentazione UTF-8 dei caratteri, quindi si rappresenti in
UTF-8 il carattere 153.

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

int inserimentoInCoda(NODO *&lista, COUPON c)
{
	NODO *nuovoNodo = new NODO;
	if(nuovoNodo == (NODO*)NULL)
	{
		cout << "memoria terminata" << endl;
		return -1;
	}
	nuovoNodo->info = c;
	nuovoNodo->next = NULL;
	
	//se lista è vuota
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

bool cerca(NODO *lista, COUPON c)
{
	if(lista == NULL)
	{
		return 0;
	}
	
	while(lista != NULL)
	{
		if(strcmp(lista->info.codice, c.codice) == 0)
		{
			return 1;
		}
		lista = lista->next;
	}
	return 0;
}

int FondiNonDuplicatiInDate(NODO *lista1, NODO *&lista2)
{
	if(lista1 == NULL)
	{
		return 0;
	}
	
	int count = 0;
	bool trovato = 0;
	int risultatoInserimentoInCoda = 0;
	while(lista1 != NULL)
	{
		trovato = cerca(lista2, lista1->info);
		if(!trovato)
		{
			risultatoInserimentoInCoda = inserimentoInCoda(lista2, lista1->info);
			if(risultatoInserimentoInCoda <0)
			{
				return risultatoInserimentoInCoda;
			}
			count++;
		}
		lista1 = lista1->next;
	}
	
	return count;
}

/*
domanda teoria

le 4 configurazioni sono:
-valori 0-127 --> 0xxxxxxx
-valori 128-2047 --> 110xxxxx 10xxxxxx
-valori 2048-65535 --> 1110xxxx 10xxxxxx 10xxxxxx
-valori > 65535 --> 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

153 in utf-8 è 

-in binario = 10011001
-config --> 110xxxxx 10xxxxxx
- adattamento --> 00010011001
-risultato finale --> 11000010 10011001
	
	
*/