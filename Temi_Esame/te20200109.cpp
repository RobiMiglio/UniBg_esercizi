/*
UNIVERSITA` DI BERGAMO
ESAME DI
INFORMATICA 12 CFU – Modulo di Programmazione
(ING. INFORMATICA)
Prof. G. PSAILA
PRE-APPELLO DEL 09/01/2020
Per consegnare, si svolgano entrambi gli esercizi. Durata: 90 minuti.
Punteggio complessivo: 16 punti. Sufficienza: 9 punti.

Esercizio (10 punti)
Si consideri un programma per gestire la raccolta delle informazioni relative agli abbonamenti ad un
parcheggio. Un abbonamento è descritto da un tipo strutturato denominato ABBONAMENTO, i cui
campi sono un codice di 10 caratteri (che identifica univocamente l’abbonamento), la data di
emissione (stringa nel formato internazionale aaaa-mm-gg ), la data di scadenza, il numero di targa
(stringa di 10 caratteri), l’importo residuo (numero in virgola mobile), il valore dell’ultimo addebito
e la data dell’ultimo addebito..
Si definisca quindi la struttura dati per una lista dinamica dove il campo informativo del nodo è a
sua volta basato sul tipo ABBONAMENTO.
Si scriva la funzione denominata EstraiNonDuplicati che riceve come parametri due liste di
abbonamenti, denominate rispettivamente lista1 e lista2, ed un vettore di caratteri
denominato data_cercata. La funzione restituisce una nuova lista che contiene tutti gli
abbonamenti emessi in data_cercata che non sono presenti in entrambe le liste, ma solo in una
delle due (si usi il codice dell’abbonamento per fare la verifica). In caso di errore, la funzione
restituisce il valore NULL.
N.B. Si eviti la duplicazione del codice.


Vedi Esercizio 2 sul retro
Esercizio 2 (5 + 3 punti)
Si consideri il seguente programma.
void modifica(int *p1, int *p2)
{
int temp;
temp = *p1;
*p1 = *p2;
*p2 = temp; // QUI alla prima attivazione
}
void trasforma(int el[], int size)
{
int i;
for(i=0; i<size-1; i++)
if( (i%3) == 1 )
modifica(el+i, el+(i-1));
}
void stampa(int el[], int size)
{
int i;
for(i=0; i< size; i++)
cout << el[i] << endl;
cout << "***********" << endl;
}
int main()
{
const int SIZE=10;
int elenco[SIZE];
int i;
elenco[0]=1;
elenco[1]=2;
for(i=2; i < SIZE; i++)
elenco[i] = (elenco[i-1] + elenco[i-2])*2;
stampa(elenco, SIZE);
trasforma(elenco, SIZE);
stampa(elenco, SIZE);
return 0;
}
Esercizio 2.a (4 punti)
Si disegnino i record di attivazione delle funzioni nell’istante in cui il flusso di esecuzione
raggiunge il commento // QUI alla prima attivazione della funzione modifica, indicando i
valori numerici delle variabili e usando le frecce per i valori dei puntatori.
Esercizio 2.b (2 punti)
Si riporti sul foglio di protocollo l’output del programma sul dispositivo di uscita (schermo).
*/

#include <iostream>
#include <cstring>

using namespace std;

struct ABBONAMENTO
{
	char codice[11];
	char dataEmissione[11];
	char dataScadenza[11];
	char numeroTarga[11];
	float importoResiduo;
	float valoreUltimoAddebito;
	char dataUltimoAddebito[11];
};

struct NODO
{
	ABBONAMENTO info;
	NODO *next;
};

int inserisciInCoda(NODO *&lista, ABBONAMENTO a)
{
	NODO *nuovoNodo = new NODO;
	if(nuovoNodo == (NODO*)NULL)
	{
		cout << "memoria terminata" << endl;
		return -1;
	}
	nuovoNodo->info = a;
	nuovoNodo->next = NULL;
	
	if(lista == NULL)
	{
		lista = nuovoNodo;
		return 0;
	}
	
	NODO *temp = lista;
	while(temp->next !=NULL)
	{
		temp = temp->next;
	}
	temp->next = nuovoNodo;
	return 0;
}

bool IndagineCriteriNuovaLista(NODO *lista, ABBONAMENTO a, const char data[])
{
	if(lista == NULL)
	{
		return 0;
	}

	if(strcmp(a.dataEmissione, data)!=0)
	{
		return 0;
	}
	
	while(lista != NULL)
	{
		if(strcmp(lista->info.codice, a.codice) == 0)
		{
			return 0;
		}			
		lista = lista->next;
	}
	return 1;
}

NODO* EstraiNonDuplicati(NODO *&lista1, NODO *&lista2, char data_cercata[])
{
	if(lista1==NULL && lista2==NULL)
	{
		return NULL;
	}
	
	NODO *nuovaLista = NULL;
	
	NODO *temp = lista1;
	
	int valoreRestituito = 0;
	
	while(temp != NULL)
	{
		if(IndagineCriteriNuovaLista(lista2, temp->info, data_cercata))
		{
			valoreRestituito = inserisciInCoda(nuovaLista, temp->info);
			if(valoreRestituito<0)
			{
				return NULL;
			}
		}
		temp = temp->next;
	}
	
	temp = lista2;

	while(temp != NULL)
	{
		if(IndagineCriteriNuovaLista(lista1, temp->info, data_cercata))
		{
			inserisciInCoda(nuovaLista, temp->info);
			if(valoreRestituito<0)
			{
				return NULL;
			}
		}
		temp = temp->next;
	}	
	return nuovaLista;
}

/*
============================================================
Esercizio 2.a — Record di attivazione al punto // QUI
(prima attivazione della funzione modifica)
============================================================

La prima chiamata a modifica avviene quando i = 1, quindi:

    modifica(el + 1, el + 0);

Prima della chiamata, l’array contiene:
el[0] = 1
el[1] = 2
el[2] = 6
...

Dentro modifica l’esecuzione procede così:
1) temp = *p1 → temp = 2
2) *p1 = *p2 → *p1 = 1

A questo punto el diventa:
el[0] = 1
el[1] = 1

Il flusso ora è esattamente sul commento:
// QUI alla prima attivazione

=================================================================
STACK DELLE ATTIVAZIONI AL PUNTO “// QUI”
=================================================================

┌────────────────────────────────────────────────────────────┐
│                      modifica()                             │
├────────────────────────────────────────────────────────────┤
│ temp = 2                                                   │
│ p1 → el[1] = 1                                             │
│ p2 → el[0] = 1                                             │
└────────────────────────────────────────────────────────────┘
                        ▲ chiamata
                        │
┌────────────────────────────────────────────────────────────┐
│                      trasforma()                           │
├────────────────────────────────────────────────────────────┤
│ el → array elenco[]                                        │
│ size = 10                                                  │
│ i = 1                                                      │
└────────────────────────────────────────────────────────────┘
                        ▲ chiamata
                        │
┌────────────────────────────────────────────────────────────┐
│                        main()                              │
├────────────────────────────────────────────────────────────┤
│ elenco[] = {1, 2, 6, 16, 44, 120, ...}                     │
│ SIZE = 10                                                  │
└────────────────────────────────────────────────────────────┘

=================================================================
FRECCE DEI PUNTATORI
=================================================================

p1 ───► el[1] = 1
p2 ───► el[0] = 1

============================================================

esercizio 2.b

1
2
6
16
44
120
328
1136
2928
8128
***********
2
1
6
44
16
120
1136
328
2928
8128



*/