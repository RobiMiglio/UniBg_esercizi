/*

UNIVERSITA` DI BERGAMO


ESAME DI

INFORMATICA 12 CFU – Modulo di Programmazione (ING. INFORMATICA)

Prof. G. PSAILA


APPELLO DEL 26/06/2025


Per consegnare, si svolgano entrambi gli esercizi.

Durata: 90 minuti.

Punteggio complessivo: 16 punti. Sufficienza: 9 punti.


ATTENZIONE

Il compito non viene valutato se i punti seguenti non sono rispettati.

· Entrambe le parti devono essere svolte.

· Le specifiche relative alla struttura dati e all’interfaccia della funzione devono essere rispettate nel dettaglio.

· Il codice deve essere completo, cioè non sono ammesse parti delle funzioni mancanti o funzioni richiamate ma mancanti (se non sono funzioni di libreria);

· Non devono essere presenti errori grossolani che mettono in evidenza mancanza di adeguata preparazione (per esempio, invertire gli assegnamenti o confondere tipi di dato e variabili).

Se il compito viene etichettato “NV” (Non Valutabile) non verrà consentito di partecipare all’appello successivo. Quindi, si consiglia fortemente di consegnare il compito per la valutazione SOLO se ritenete di aver evitato i vincoli sopra riportati.



1) Parte Teoria (6 punti)

Si consideri un sistema in cui per gli indirizzi di memoria vengono usati 20 bit e la memoria viene gestita con il sistema della paginazione con pagine da 1 Kbyte e indirizzi logici.

Si consideri il seguente indirizzo logico l=0000010010 0000010011.

Se nella tabella delle pagine abbiamo le corrispondenze pl→pf (in base 10) 29→128, 32→6, 18→36, 19→38, qual è l’indirizzo fisico f su 24 bit corrispondente all’indirizzo logico l ?



(segue la parte pratica sul retro).


2) Parte Pratica (10 punti)

Si consideri un programma per gestire le verbalizzazioni di esami universitari.

Un verbale è descritto da un tipo strutturato denominato VERBALE, i cui campi sono un codice di 15 caratteri (che identifica univocamente il verbale), la data di verbalizzazione (stringa nel formato internazionale aaaa-mm-gg), la data dell’appello d’esame (stringa di 10 caratteri), la data di superamento dell’esame (stringa di 10 caratteri), il codice dell’insegnamento (stringa di 10 caratteri), il nome del docente (stringa di 50 caratteri), la matricola dello studente (Stringa di 7 caratteri), il voto (numero intero, dove 31 indica 30 e lode).

Si definisca quindi la struttura dati per una lista dinamica dove il campo informativo del nodo è a sua volta basato sul tipo VERBALE.

Si scriva la funzione denominata VerbaliVotiAlti, che riceve come parametri due liste di verbali denominate lista1 e lista2, un vettore di stringhe (vettore di puntatori a carattere) denominato dateAppelli ed un numero intero denominato size, che indica il numero di elementi nel vettore dateAppelli.

La funzione restituisce una nuova lista di verbali, così ottenuta:

(1) per ciascuna data nel vettore dateAppelli, la funzione conta il numero di verbali in lista1 emessi per appelli di esame in quella data; analogamente, la funzione fa lo stesso conteggio per i verbali nella lista2;

(2) la funzione identifica in quali date il numero di verbali in lista1 è maggiore dei verbali in lista2;

(3) la funzione copia in listaOut tutti i verbali in lista1 emessi per appelli nelle date identificate al punto 2, se esistono.

La funzione restituisce il valore di listaOut, oppure, in caso di errore, la funzione restituisce il valore NULL.

N.B. Si risolva il problema in modo da fare esattamente DUE scansioni di lista1 e UNA scansione di lista2, lavorando direttamente su queste liste e senza creare copie temporanee (sia totali che parziali).

N.B. Si eviti la duplicazione di parti del codice del programma

*/

#include <iostream>
#include <cstring>

using namespace std;

struct VERBALE
{
    char codice[16];
    char dataVerbalizzazione[11];   // aaaa-mm-gg
    char dataAppello[11];           // aaaa-mm-gg
    char dataSuperamento[11];       // aaaa-mm-gg
    char codiceInsegnamento[11];
    char nomeDocente[51];
    char matricolaStudente[8];
    int voto;                       // 31 = 30 e lode
};

struct NODO
{
    VERBALE info;
    NODO *next;
};

/* Inserimento in testa */
int ins_testa(NODO *&lista, VERBALE v)
{
    NODO *nuovoNodo = new NODO;
    if (nuovoNodo == NULL)
        return -1;

    nuovoNodo->info = v;
    nuovoNodo->next = lista;
    lista = nuovoNodo;
    return 0;
}

/* Incrementa il contatore associato alla data dell'appello */
void incrementaContatori(VERBALE v, const char *dateAppelli[], int size, int contatori[])
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(v.dataAppello, dateAppelli[i]) == 0)
        {
            contatori[i]++;
        }
    }
}

/* Conta i verbali per ciascuna data */
void contaVerbali(NODO *lista, const char *dateAppelli[], int size, int contatori[])
{
    while (lista != NULL)
    {
        incrementaContatori(lista->info, dateAppelli, size, contatori);
        lista = lista->next;
    }
}

/* Verifica se per una data lista1 ha più verbali di lista2 */
bool isDataOk(const char data[], const char *dateAppelli[], int size,
              int contatoriLista1[], int contatoriLista2[])
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(data, dateAppelli[i]) == 0)
        {
            if (contatoriLista1[i] > contatoriLista2[i])
                return true;
        }
    }
    return false;
}

/* Funzione principale richiesta */
NODO* VerbaliVotiAlti(NODO *lista1, NODO *lista2,
                      const char *dateAppelli[], int size)
{
    if (lista1 == NULL || size < 1)
        return NULL;

    int contatoriLista1[size];
    int contatoriLista2[size];

    for (int i = 0; i < size; i++)
    {
        contatoriLista1[i] = 0;
        contatoriLista2[i] = 0;
    }

    /* Prima scansione di lista1 e lista2 */
    contaVerbali(lista1, dateAppelli, size, contatoriLista1);
    contaVerbali(lista2, dateAppelli, size, contatoriLista2);

    /* Seconda scansione di lista1 */
    NODO *listaOut = NULL;
    while (lista1 != NULL)
    {
        if (isDataOk(lista1->info.dataAppello,
                     dateAppelli, size,
                     contatoriLista1, contatoriLista2))
        {
            if (ins_testa(listaOut, lista1->info) < 0)
                return NULL;
        }
        lista1 = lista1->next;
    }

    return listaOut;
}
