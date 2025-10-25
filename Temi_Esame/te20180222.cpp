/*
UNIVERSITA` DI BERGAMO
ESAME DI
INFORMATICA 12 CFU – Modulo di Programmazione
(ING. INFORMATICA)
Prof. G. PSAILA
APPELLO DEL 22/02/2018
Per consegnare, si svolgano entrambi gli esercizi. Durata: 90 minuti.
Punteggio complessivo: 16 punti. Sufficienza: 9 punti

Esercizio (10 punti)
Si consideri un programma per gestire la raccolta delle informazioni relative ai buoni sconto offerti
da un sito di prenotazione alberghi ai propri clienti. Un buono sconto è descritto da un tipo
strutturato denominato BUONO, i cui campi sono un codice di 10 cifre (che identifica univocamente
un buono), la data di emissione (stringa nel formato internazionale aaaa-mm-gg ), l’indirizzo email
del cliente al quale viene proposto (stringa di 250 caratteri), il valore del buono in Euro, la data di
scadenza, lo stato del buono (numero intero, dove 1 indica che il buono non è stato ancora
utilizzato, 2 indica che è stato utilizzato e 3 indica che è scaduto).
Si definisca quindi la struttura dati per una lista dinamica dove il campo informativo del nodo è a
sua volta basato sul tipo BUONO.
Si scriva la funzione denominata QuantiNonComuni che riceve come parametri due liste di
buoni, denominate rispettivamente lista1 e lista2, un vettore di date di scadenza (vettore di
puntatori a carattere) denominato datescadenza e un numero intero size (che indica gli
elementi nel vettore datescadenza). La funzione calcola e restituisce il numero di buoni
presenti in una sola delle due lista (in base al loro codice) la cui data di scadenza è una delle date
riportate nel vettore dateScadenza. Non sono previste condizioni di errore.
N.B. Si eviti la duplicazione del codice.

Domanda Teoria (6 punti)
Si consideri un sistema dove per gli indirizzi di memoria vengono usati 24 bit e la memoria viene
gestita con il sistema della paginazione con pagine da 1Kbyte e indirizzi logici. Si consideri il
seguente indirizzo logico l=000000000100110000011101.
Se nella tabella delle pagine abbiamo le corrispondenze pl→pf (in base 10) 17→11, 18→35,
19→55, 20→16, qual è l’indirizzo fisico f su 24 bit corrispondente all’indirizzo logico l ?
*/

#include <iostream>
#include <cstring>

using namespace std;

struct BUONO
{
	char codice[11];
	char dataEmissione[11];
	char emailCliente[251];
	int valore;
	char dataScadenza[11];
	int stato;
};

struct NODO
{
	BUONO info;
	NODO *next;
};

int contaBuoniScadenza(NODO *listaControllo, NODO *listaDaConfrontare, char *datescadenza[], int size)
{
	int count = 0;
	bool presente = 0;
	for(NODO *n=listaControllo; n!=NULL; n=n->next)
	{
		for(NODO *k=listaDaConfrontare; k!=NULL; k=k->next)
		{
			if(strcmp(n->info.codice, k->info.codice) == 0)
			{
				presente = 1;
				break;
			}
		}
		if(!presente)
		{
			for(int i=0; i<size; i++)
			{
				if(strcmp(n->info.dataScadenza, datescadenza[i]) ==0)
				{
					count++;
					break;
				}
			}
		}
		presente = 0;
	}
	return count;
}

int QuantiNonComuni(NODO *lista1, NODO *lista2, char *datescadenza[], int size)
{
	if(lista1==NULL && lista2==NULL)
	{
		return 0;
	}
	
	int conta1 = contaBuoniScadenza(lista1, lista2, datescadenza, size);
	int conta2 = contaBuoniScadenza(lista2, lista1, datescadenza, size);
	
	return conta1+conta2;		
}

/*
domanda teoria
Nel sistema di paginazione un indirizzo logico è suddiviso in due parti:
• il numero di pagina logica (PL),
• l’offset all’interno della pagina.

La dimensione della pagina determina quanti bit devono essere riservati
all’offset; tutti i bit rimanenti dell’indirizzo logico rappresentano invece
il numero di pagina logica.

Poiché la pagina è da 1 KB = 2^10 byte, l’offset è composto da 10 bit. Con
indirizzi logici di 24 bit, i restanti 14 bit identificano quindi la pagina
logica (PL).

───────────────────────────────────────────────
APPLICAZIONE ALL’INDIRIZZO FORNITO
───────────────────────────────────────────────

Indirizzo logico:
l = 0000000001001100000011101 (24 bit)

Separazione:
• PL  = 00000000010011   (14 bit)
• Offset = 00000011101   (10 bit)

Conversione della pagina logica:
00000000010011₂ = 19₁₀

Dalla tabella delle pagine:
19 → 55 (frame fisico PF)

Conversione in binario:
55₁₀ = 110111₂

Estensione a 14 bit:
PF = 00000000110111

Composizione dell’indirizzo fisico (PF seguito dall’offset):

f = 00000000110111 00000011101



*/