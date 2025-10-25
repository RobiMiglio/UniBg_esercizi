/*

UNIVERSITA` DI BERGAMO
ESAME DI
INFORMATICA 12 CFU – Modulo di Programmazione
(ING. INFORMATICA)
Prof. G. PSAILA
APPELLO DEL 31/01/2018
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
Si scriva la funzione denominata QualeElenco che riceve come parametri due liste di buoni,
denominate rispettivamente lista1 e lista2, un vettore di date di scadenza (puntatori a
carattere) denominato datescadenza e un numero intero size (che indica gli elementi nel
vettore datescadenza) . La funzione calcola il valore conta1, che indica quanti buoni in
lista1 hanno come data di scadenza una delle date riportate nel vettore dateScadenza, ed il
valore conta2, che indica quanti buoni in lista2 hanno come data di scadenza una delle date
riportate nel vettore dateScadenza. La funzione restituisce 1 se conta1 è maggiore di
conta2, restituisce 2 se conta2 è maggiore di conta1, restituisce 0 se conta1 e conta2
sono uguali. Non sono previste condizioni di errore.
N.B. Si eviti la duplicazione del codice.

Domanda Teoria (6 punti)
Si descriva, in non più di una pagina, la legge matematica che consente di rappresentare i numeri
negativi in complemento a 2, usando come esempio il numero -10 da rappresentare in
complemento a 2 su 5 bit.

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

int contaBuoniScadenza(NODO *lista, char *datescadenza[], int size)
{
	if(lista == NULL)
	{
		return 0;
	}
	
	int count = 0;
	for(NODO *n=lista; n!=NULL; n=n->next)
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
	return count;
}

int QualeElenco(NODO *lista1, NODO *lista2, char *datescadenza[], int size)
{
	int conta1 = contaBuoniScadenza(lista1, datescadenza, size);
	int conta2 = contaBuoniScadenza(lista2, datescadenza, size);
		
	if(conta1>conta2)
	{
		return 1;
	}
	else if(conta2>conta1)
	{
		return 2;
	}
	else
	{
		return 0;
	}
}

/*
domanda teoria

il complemento a 2 è la legge matematica che consente ai pc di gestire i numeri
negativi.
Permette alla cpu di gestire le operazioni con i numeri negativi sempre e solo
con l'operazione di somma.
i passi del complemento a 2 sono questi:
-convertire il numero in valore assoluto
-convertirlo in valore binario
-adeguare il valore sulla base di bit richiesta
-invertire tutti i bit (da 0 a 1 e viceversa)
-aggiungere 1 al valore 

ora il bit più significativo è da considerarsi negativo, quindi 
se si calcola il valore otterremo appunto il valore negatico del valore iniziale

esemprio con -10 in decimale

-10 in valore assoluto
-1010 in binario
-01010 adeguato su base 5 bit come chiesto da esercizio
-10101 inversione bit
-10110 aggiunta di 1

ora quindi -16+4+2 = -10

*/