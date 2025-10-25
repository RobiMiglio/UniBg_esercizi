/*

UNIVERSITA` DI BERGAMO
ESAME DI
INFORMATICA 12 CFU – Modulo di Programmazione
(ING. INFORMATICA)
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

Si scriva la funzione denominata UnisciListini che riceve come parametri due liste di
prodotti. La funzione crea uno nuova lista ottenuta fondendo i prodotti presenti nelle due liste nel
modo seguente:
• se un codice di prodotto è presente in una sola delle due liste, viene riportato così com’è
nella nuova lista;
• se un codice di prodotto è presente in entrambe le liste, viene riportata nella nuova lista la
versione con il prezzo più basso.

La funzione restituisce l’indirizzo della testa della nuova lista; in caso di problemi, restituisce il
valore NULL.

N.B. Si eviti la duplicazione del codice.

Domanda Teoria (6 punti)
Si descriva (in non più di una pagina) la codifica UTF-8; quindi, si consideri il codice 130 (in base
10) e lo si codifichi in UTF-8.

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

void inserisciInCoda(NODO *&lista, PRODOTTO p)
{
	NODO *nuovoNodo = new NODO;
	if(nuovoNodo == NULL)
	{
		cout << "memoria terminata" << endl;
		return;
	}
	
	nuovoNodo->info = p;
	nuovoNodo->next = NULL;
	
	if(lista == NULL)
	{
		lista = nuovoNodo;
	}
	else
	{
		NODO *temp = lista;
		
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = nuovoNodo;
	}
}

NODO* cerca(NODO *lista, const char codice[])
{
	if(lista == NULL)
	{
		return NULL;
	}
	
	while(lista != NULL)
	{
		if(strcmp(lista->info.codice, codice) == 0)
		{
			return lista;
		}
		lista = lista->next;
	}
	return NULL;
}

NODO* UnisciListini(NODO *lista1, NODO *lista2)
{
	if(lista1==NULL && lista2==NULL)
	{
		return NULL;
	}
	
	NODO *nuovaLista = NULL;
	
	for(NODO *n=lista1; n!=NULL; n=n->next)
	{
		inserisciInCoda(nuovaLista, n->info);
	}
	
	for(NODO *n=lista2; n!=NULL; n=n->next)
	{
		NODO *trovato = cerca(nuovaLista, n->info.codice);
		
		if(trovato == NULL)
		{
			inserisciInCoda(nuovaLista, n->info);
		}
		else
		{
			if(n->info.prezzo < trovato->info.prezzo)
			{
				trovato->info = n->info;
			}
		}
	}
	return nuovaLista;
}
	

/*

UTF-8 è una codifica variabile dei caratteri Unicode che utilizza da 1 a 4 byte per rappresentare ogni carattere. 
Per i valori 0–127 utilizza esattamente lo stesso byte dell’ASCII, garantendo la retro-compatibilità. I caratteri con valore 
maggiore sono codificati in più byte, con un formato che consente alla CPU o al software di riconoscere sempre l’inizio di un 
carattere (codifica auto-sincronizzante).

La struttura dei byte è:
1 byte: 0xxxxxxx (caratteri 0–127)
2 byte: 110xxxxx 10xxxxxx (caratteri 128–2047)
3 byte: 1110xxxx 10xxxxxx 10xxxxxx
4 byte: 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

Per codificare il valore 130:
130 in binario = 10000010
Appartiene al range 128–2047 → servono 2 byte.
Espando a 11 bit: 00010000010
Inserisco nei template:
    Primo byte: 11000010
    Secondo byte: 10000010

✔ Codifica UTF-8 di 130: 11000010 10000010 (esadecimale C2 82)

*/