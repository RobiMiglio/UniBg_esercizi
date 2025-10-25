/*

UNIVERSITA` DI BERGAMO
ESAME DI
INFORMATICA 12 CFU – Modulo di Programmazione (ING. INFORMATICA)
Prof. G. PSAILA
APPELLO DEL 21/01/2022
Per consegnare, si svolgano entrambi gli esercizi. Durata: 90 minuti.
Punteggio complessivo: 16 punti. Sufficienza: 9 punti.
Esercizio (10 punti)
Si consideri un programma per gestire le registrazioni delle vaccinazioni anti-COVID-19 dei cittadini Italiani. Una registrazione è descritta da un tipo strutturato denominato SOMMINISTRAZIONE, i cui campi sono un codice di 10 caratteri (che identifica univocamente la registrazione), la data della somministrazione (stringa nel formato internazionale aaaa-mm-gg), il codice SSN (stringa di 10 caratteri) del cittadino cui la somministrazione è stata effettuata, l’età del cittadino (numero intero) al momento della somministrazione, il tipo di vaccino (stringa di 20 caratteri), la matricola (stringa di 15 caratteri) del medico che ha effettuato la somministrazione; infine, si vuole sapere se il cittadino è o meno in una categoria protetta (un codice numerico indica la specifica categoria; se vale zero, il cittadino non è in una categoria protetta).
Si definisca quindi la struttura dati per una lista dinamica dove il campo informativo del nodo è a sua volta basato sul tipo SOMMINISTRAZIONE.
Si scriva la funzione denominata SoloTerzeDosi, che riceve come parametri due liste di somministrazioni denominate lista1 e lista2.
La funzione crea e restituisce una nuova lista, internamente denominata listaOut, che riporta le somministrazioni di terze dosi riportate in lista2: più precisamente, per ogni registrazione in lista2, questa è copiata in listaOut se è l’unica registrazione presente in lista2 per quel cittadino e se in lista1 vi sono esattamente due registrazioni per lo stesso cittadino.
La funzione restituisce l’indirizzo della testa della nuova lista; in caso di errore, restituisce il valore NULL.
N.B. si eviti la duplicazione di parti del codice del programma.
Domanda Teoria (6 punti)
Si considerino i numeri X=B116 e Y=1016 (rappresentazione esadecimale di due numeri interi in complemento a due). Si calcoli Z=X-Y e si riporti il valore di Z in base 10.

*/

#include <iostream>
#include <cstring>

using namespace std;

struct SOMMINISTRAZIONE
{
	char codice[11];
	char dataSomministrazione[13];
	char codiceSSN[11];
	int etaCittadino;
	char tipoVaccino[21];
	char matricolaMedico[16];
	int tipoCategoriaProtetta;
};

struct NODO
{
	SOMMINISTRAZIONE info;
	NODO *next;
};

int cercaRegistrazioni(NODO *lista, const char codiceSSN[])
{
	if(lista == NULL)
	{
		return 0;
	}
	
	int quantitaRregistrazioniPresenti = 0;
	while(lista != NULL)
	{
		if(strcmp(lista->info.codiceSSN, codiceSSN)==0)
		{
			quantitaRregistrazioniPresenti++;
		}		
		lista = lista->next;
	}
	return quantitaRregistrazioniPresenti;
}

int inserimentoInTesta(NODO *&lista, SOMMINISTRAZIONE s)
{
	NODO *nuovoNodo = new NODO;
	if(nuovoNodo == NULL)
	{
		cout << "memoria terminata" << endl;
		return -1;
	}
	
	nuovoNodo->info = s;
	nuovoNodo->next = lista;
	lista = nuovoNodo;
	return 0;
}

NODO* SoloTerzeDosi(NODO *lista1, NODO *lista2)
{
	NODO *listaOut = NULL;
	
	while(lista2!=NULL)
	{
		if(cercaRegistrazioni(lista2, lista2->info.codiceSSN) == 1)
		{
			if(cercaRegistrazioni(lista1, lista2->info.codiceSSN) == 2)
			{
				if(inserimentoInTesta(listaOut, lista2->info) <0)
				{
					return NULL;
				}
			}
		}
		lista2 = lista2->next;
	}
	return listaOut;
}
		


/*
DOMANDA TEORICA – SOLUZIONE

Si considerino i numeri X = B1₁₆ e Y = 10₁₆, che rappresentano numeri interi 
in complemento a due. Calcolare Z = X − Y e riportare Z in base 10.

1) Convertiamo X e Y in binario (8 bit).

   X = B1₁₆ = 1011 0001₂
   Il MSB è 1 → numero negativo.

   Valore di X:
     Inverti i bit: 0100 1110
     +1 → 0100 1111 = 79₁₀
   → X = -79

   Y = 10₁₆ = 0001 0000₂
   MSB = 0 → positivo
   → Y = 16

2) Calcolo di Z = X − Y
   Z = -79 − 16 = -95

3) Verifica con somma in complemento a due:
      1011 0001   (X)
    + 1111 0000   (−Y)
      ---------
      1010 0001 → interpretazione: negativo
        Inverti: 0101 1110
        +1 → 0101 1111 = 95
      → Z = -95

RISULTATO FINALE:
Z = -95
*/