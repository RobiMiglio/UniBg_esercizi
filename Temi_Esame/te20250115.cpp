/*

UNIVERSITA` DI BERGAMO
ESAME DI
INFORMATICA 12 CFU – Modulo di Programmazione (ING. INFORMATICA)
Prof. G. PSAILA
APPELLO DEL 15/01/2025
Per consegnare, si svolgano entrambi gli esercizi.
Durata: 90 minuti.
Punteggio complessivo: 16 punti. Sufficienza: 9 punti.
Esercizio (10 punti)
Si consideri un programma per gestire le verbalizzazioni di esami universitari.
Un verbale è descritto da un tipo strutturato denominato VRRBALE, i cui campi sono un codice di 15 caratteri (che identifica univocamente il verbale), la data di verbalizzazione (stringa nel formato internazionale aaaa-mm-gg), la data dell’appello d’esame (stringa di 10 caratteri), la data di superamento dell’esame (stringa di 10 caratteri), il codice dell’insegnamento (stringa di 10 caratteri), il nome del docente (stringa di 50 caratteri), la matricola dello studente (Stringa di 7 caratteri), il voto (numero intero, dove 31 indica 30 e lode).
Si definisca quindi la struttura dati per una lista dinamica dove il campo informativo del nodo è a sua volta basato sul tipo VERBALE.
Si scriva la funzione denominata VerbaliMeseDiverso, che riceve come parametri una lista di verbali denominata listaIn, un vettore di stringhe (vettore di puntatori a carattere) denominato insegnamenti ed un numero intero denominato size, che indica il numero di elementi nel vettore insegnamenti. Il vettore insegnamenti contiene un elenco di codici di insegnamento.
La funzione restituisce una nuova lista di verbali, così ottenuta: (1) per ciascun insegnamento riportato nel vettore insegnamenti, la funzione conta il numero di verbali che sono stati creati nello stesso mese (anno e numero del mese) della data dell’appello; (2) trova l’insegnamento con il minor numero di verbali con le caratteristiche del punto 1, purché vi siano dei verbali con quelle caratteristiche; (3) la funzione crea una nuova lista (gestita internamente con la variabile listaOut) che contiene una copia di tutti i verbali dell’insegnamento trovato al punto 2 che sono stati creati nello stesso anno della data dell’appello ma in mesi successivi.
La funzione restituisce il valore di listaOut, oppure, in caso di errore, la funzione restituisce il valore NULL.
N.B. Si risolva il problema in modo da fare esattamente DUE scansioni della lista puntata dal parametro listaIn, lavorando direttamente su di essa e senza creare copie temporanee (sia totali che parziali).
N.B. Si eviti la duplicazione di parti del codice del programma.
Domanda Teoria (6 punti)
Si consideri l’encoding dei caratteri in UTF-8. Dati i due Byte C9 81 (in base 16) che descrivono un carattere in UTF-8, si estragga il codice binario del carattere e si riporti il codice del carattere in base 10.

*/

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

struct VERBALE
{
	char codice[16];
	char dataVerbalizzazione[13];
	char dataAppelloEsame[11];
	char dataSuperamentoEsame[11];
	char codiceInsegnamento[11];
	char nomeDocente[51];
	char matricolaStudente[8];
	int voto;
};

struct NODO
{
	VERBALE info;
	NODO *next;
};

bool stessoMeseAnno(VERBALE v)
{
	if(strncmp(v.dataVerbalizzazione, v.dataAppelloEsame, 7)==0)
	{
		return 1;
	}
	return 0;
}

int contaVerbali(NODO *lista, char insegnamento[])
{
	int count = 0;
	while(lista != NULL)
	{
		if(strcmp(lista->info.codiceInsegnamento, insegnamento)==0 && stessoMeseAnno(lista->info))
		{
			count++;
		}
		lista = lista->next;
	}
	return count;
}	

const char* trovaInsegnamento(NODO *lista, char *insegnamenti[], int size)
{
	const char *insegnamento = NULL;
	
	int numeroVerbali = 0;
	int numeroVerbaliMin = 65535;
	for(int i=0; i<size; i++)
	{
		numeroVerbali = contaVerbali(lista, insegnamenti[i]);
		if(numeroVerbali>0 && numeroVerbali<numeroVerbaliMin)
		{
			insegnamento = insegnamenti[i];
			numeroVerbaliMin = numeroVerbali;
		}
	}
	return insegnamento;
}

bool isCreatiMesiSucc(const char dataCreazione[], const char dataAppello[])
{
	char arrDataCreazione[3];
	
	strncpy(arrDataCreazione, dataCreazione+5, 2);
	arrDataCreazione[2] = '\0';
	int meseDataCreazione = atoi(arrDataCreazione);
	
	char arrDataAppello[3];
	
	strncpy(arrDataAppello, dataAppello+5, 2);
	arrDataAppello[2] = '\0';
	int meseDataAppello = atoi(arrDataAppello);
	
	if(meseDataCreazione>meseDataAppello)
	{
		return 1;
	}
	return 0;
}

bool stessoAnnoMesiSucc(VERBALE v)
{
	if(strncmp(v.dataVerbalizzazione, v.dataAppelloEsame, 4)==0 && isCreatiMesiSucc(v.dataVerbalizzazione, v.dataAppelloEsame))
	{
		return 1;
	}
	return 0;
}

int inserisciInTesta(NODO *&lista, VERBALE v)
{
	NODO *nuovoNodo = new NODO;
	if(nuovoNodo == NULL)
	{
		cout << "memoria terminata" << endl;
		return -1;
	}
	nuovoNodo->info = v;
	nuovoNodo->next = lista;
	lista = nuovoNodo;
	return 0;
}

NODO* VerbaliMeseDiverso(NODO *listaIn, char *insegnamenti[], int size)
{
	NODO *listaOut = NULL;
	const char *insegnamento = trovaInsegnamento(listaIn, insegnamenti, size);
	
	while(listaIn!=NULL)
	{
		if(strcmp(listaIn->info.codiceInsegnamento, insegnamento)==0 && stessoAnnoMesiSucc(listaIn->info))
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

C9 in binario è 11001001
81 in binario è 10000001

ora eliminiamo il templete della codifica UTF-8 di questi valori (110xxxxx 10xxxxxx)
quindi diventa 01001 000001
eliminiamo lo 0 che non serve --> 1001000001
in base 10 è = 512+64+1 = 577

*/