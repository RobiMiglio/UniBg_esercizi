/**************************************************************
 *  UNIVERSITÀ DI BERGAMO
 *  ESAME DI INFORMATICA 12 CFU – Modulo di Programmazione
 *  (ING. INFORMATICA)
 *  Prof. G. Psaila
 *
 *  APPELLO DEL 10/07/2025
 *
 *  Durata: 90 minuti
 *  Punteggio complessivo: 16 punti
 *  Sufficienza: 9 punti
 **************************************************************/

/**************************************************************
 *  SPECIFICHE ESAME – PARTE PRATICA (10 punti)
 *
 *  Un verbale è descritto dal tipo strutturato VERBALE, con:
 *   - codice (15 caratteri)
 *   - data di emissione (aaaa-mm-gg)
 *   - data dell’appello (10 caratteri)
 *   - data di superamento (10 caratteri)
 *   - codice insegnamento (10 caratteri)
 *   - nome docente (50 caratteri)
 *   - matricola studente (7 caratteri)
 *   - voto (intero, 31 = 30 e lode)
 *
 *  Si definisca una lista dinamica di verbali.
 *
 *  Si scriva la funzione CopiaAlcuniVerbali che:
 *   (1) per ciascuna data nel vettore dateEmissione conta
 *       i verbali in lista1 e lista2 emessi in quella data
 *       (conteggio unico);
 *   (2) calcola la media m dei conteggi ottenuti;
 *   (3) copia in listaOut tutti e soli i verbali presenti
 *       in lista1 o lista2 con data il cui conteggio è
 *       maggiore della media m.
 *
 *  Vincoli:
 *   - esattamente DUE scansioni di lista1
 *   - esattamente DUE scansioni di lista2
 *   - nessuna copia temporanea di liste
 *   - evitare duplicazione di codice
 **************************************************************/

/**************************************************************
 *  PARTE TEORIA (6 punti) – SOLUZIONE DA 10/10
 *
 *  Dati i due byte FF C0 (esadecimale), stabilire se
 *  rappresentano un codice UTF-8 valido.
 *
 *  FF = 255 = 11111111₂
 *  C0 = 192 = 11000000₂
 *
 *  In UTF-8 sono ammessi solo i seguenti formati:
 *   - 1 byte  : 0xxxxxxx
 *   - 2 byte  : 110xxxxx 10xxxxxx
 *   - 3 byte  : 1110xxxx 10xxxxxx 10xxxxxx
 *   - 4 byte  : 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
 *
 *  Il byte FF (11111111) non è ammesso in nessun formato UTF-8.
 *  Inoltre C0 come byte iniziale è proibito perché genera
 *  un overlong encoding.
 *
 *  CONCLUSIONE:
 *   La sequenza FF C0 NON rappresenta un codice UTF-8 valido.
 **************************************************************/

#include <iostream>
#include <cstring>

using namespace std;

/**************************************************************
 *  STRUTTURE DATI
 **************************************************************/

struct VERBALE
{
    char codice[16];
    char dataEmissione[11];        // aaaa-mm-gg
    char dataAppello[11];
    char dataSuperamento[11];
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

/**************************************************************
 *  INSERIMENTO IN TESTA
 **************************************************************/

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

/**************************************************************
 *  CONTEGGIO VERBALI PER DATA
 **************************************************************/

void contaConteggi(NODO *lista, const char *dateEmissione[],
                   int size, int conteggi[])
{
    while (lista != NULL)
    {
        for (int i = 0; i < size; i++)
        {
            if (strcmp(lista->info.dataEmissione, dateEmissione[i]) == 0)
            {
                conteggi[i]++;
            }
        }
        lista = lista->next;
    }
}

/**************************************************************
 *  CALCOLO MEDIA DEI CONTEGGI
 **************************************************************/

float calcolaMedia(int conteggi[], int size)
{
    float somma = 0;
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        somma += conteggi[i];
        count++;
    }

    if (count > 0)
        return somma / count;

    return 0;
}

/**************************************************************
 *  VERIFICA SE UNA DATA SUPERA LA MEDIA
 **************************************************************/

bool isDataOk(const char data[], const char *dateEmissione[],
              int size, int conteggi[], float media)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(data, dateEmissione[i]) == 0)
        {
            if (conteggi[i] > media)
                return true;
        }
    }
    return false;
}

/**************************************************************
 *  COPIA VERBALI DA UNA LISTA A LISTAOUT
 **************************************************************/

int copiaDaLista(NODO *lista, NODO *&listaOut,
                 const char *dateEmissione[],
                 int size, int conteggi[], float media)
{
    while (lista != NULL)
    {
        if (isDataOk(lista->info.dataEmissione,
                     dateEmissione, size, conteggi, media))
        {
            if (ins_testa(listaOut, lista->info) < 0)
                return -1;
        }
        lista = lista->next;
    }
    return 0;
}

/**************************************************************
 *  FUNZIONE RICHIESTA DALL'ESAME
 **************************************************************/

NODO* CopiaAlcuniVerbali(NODO *lista1, NODO *lista2,
                         const char *dateEmissione[], int size)
{
    if (size < 1)
        return NULL;

    int conteggi[size];
    for (int i = 0; i < size; i++)
        conteggi[i] = 0;

    /* Prima scansione lista1 e lista2 */
    contaConteggi(lista1, dateEmissione, size, conteggi);
    contaConteggi(lista2, dateEmissione, size, conteggi);

    /* Calcolo media */
    float media = calcolaMedia(conteggi, size);
    if (media == 0)
        return NULL;

    /* Seconda scansione lista1 e lista2 */
    NODO *listaOut = NULL;

    if (copiaDaLista(lista1, listaOut, dateEmissione, size,
                     conteggi, media) < 0)
        return NULL;

    if (copiaDaLista(lista2, listaOut, dateEmissione, size,
                     conteggi, media) < 0)
        return NULL;

    return listaOut;
}
