/*

UNIVERSITA` DI BERGAMO
ESAME DI
INFORMATICA 12 CFU – Modulo di Programmazione
(ING. INFORMATICA)
Prof. G. PSAILA
PROVA IN ITINERE DEL 27/01/2017
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

Si scriva la funzione denominata ProdottiTipologiaTop che riceve come parametro la lista
dei prodotti. La funzione calcola la media dei prezzi media, quindi cerca il prodotto con il prezzo
più alto (in caso di più prodotti con lo stesso prezzo, considera il primo trovato) e ne estrae la
tipologia tipMax.

Fatto questo, la funzione deve produrre un vettore di PRODOTTO (restituisce l’indirizzo del primo
elemento) che contiene tutti i prodotti di tipologia tipMax aventi prezzo maggiore o uguale a
media.

Il vettore deve contenere un elemento in più, con il codice impostato come stringa vuota, che serve
per indicare al chiamante che il vettore è finito. Nel caso in cui non vi siano prodotti nella lista,
ovvero si verifichi qualche errore, la funzione restituisce il valore NULL.
N.B. Si eviti la duplicazione del codice.
Domanda Teoria (6 punti)
Si descriva (in non più di una pagina) il ruolo del registro CIR (Current Instruction Registry) nella
CPU e si descriva la fase di fetch dell’istruzione, indicando quando viene aggiornato il registro CIR.

*/

#include <iostream>
#include <cstring>

using namespace std;

typedef struct PRODOTTO {
    char codice[13];
    char dataInserimento[11];
    float prezzo;
    int percentualeIva;
    int tipologiaProdotto;
} PRODOTTO;

typedef struct Nodo {
    PRODOTTO info;
    struct Nodo* next;
} Nodo;

typedef Nodo* Lista;


// ----------------------------------------------------
// FUNZIONE RICHIESTA DALL’ESAME
// ----------------------------------------------------
PRODOTTO* ProdottiTipologiaTop(Lista L)
{
    if (L == NULL)
        return NULL;

    float somma = 0;
    int count = 0;
    float prezzoMax = L->info.prezzo;
    int tipMax = L->info.tipologiaProdotto;

    for (Nodo* p = L; p != NULL; p = p->next)
    {
        somma += p->info.prezzo;
        count++;

        if (p->info.prezzo > prezzoMax)
        {
            prezzoMax = p->info.prezzo;
            tipMax = p->info.tipologiaProdotto;
        }
    }

    float media = somma / count;

    int tot = 0;
    for (Nodo* p = L; p != NULL; p = p->next)
        if (p->info.tipologiaProdotto == tipMax && p->info.prezzo >= media)
            tot++;

    PRODOTTO* vett = new PRODOTTO[tot + 1];
    int k = 0;

    for (Nodo* p = L; p != NULL; p = p->next)
        if (p->info.tipologiaProdotto == tipMax && p->info.prezzo >= media)
            vett[k++] = p->info;

    vett[k].codice[0] = '\0';   // elemento sentinella

    return vett;
}


// ----------------------------------------------------
// MAIN SENZA ERRORI
// ----------------------------------------------------
int main()
{
    Lista L = NULL;

    // Nodo 1
    Nodo* n1 = new Nodo;
    strcpy(n1->info.codice, "ABC123");
    strcpy(n1->info.dataInserimento, "2020-01-01");
    n1->info.prezzo = 10.0;
    n1->info.percentualeIva = 22;
    n1->info.tipologiaProdotto = 1;

    // Nodo 2
    Nodo* n2 = new Nodo;
    strcpy(n2->info.codice, "XYZ999");
    strcpy(n2->info.dataInserimento, "2020-01-02");
    n2->info.prezzo = 30.0;
    n2->info.percentualeIva = 22;
    n2->info.tipologiaProdotto = 2;

    // Nodo 3
    Nodo* n3 = new Nodo;
    strcpy(n3->info.codice, "TTT111");
    strcpy(n3->info.dataInserimento, "2020-01-03");
    n3->info.prezzo = 25.0;
    n3->info.percentualeIva = 22;
    n3->info.tipologiaProdotto = 2;

    // Collegamento lista
    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;
    L = n1;

    // Chiamata funzione
    PRODOTTO* risultato = ProdottiTipologiaTop(L);

    if (risultato == NULL) {
        cout << "Errore o lista vuota.\n";
        return 0;
    }

    cout << "Prodotti selezionati:\n";

    for (int i = 0; risultato[i].codice[0] != '\0'; i++) {
        cout << risultato[i].codice << " | "
             << risultato[i].prezzo << " | "
             << risultato[i].tipologiaProdotto << endl;
    }

    delete[] risultato;

    delete n3;
    delete n2;
    delete n1;

    return 0;
}



/*

Il registro CIR (Current Instruction Register) contiene l’istruzione in corso di esecuzione, non il suo indirizzo.
È fondamentale perché la CPU può eseguire solo ciò che si trova nei suoi registri.

Fase di fetch

Il Program Counter (PC) contiene l’indirizzo della prossima istruzione.

Il PC copia l’indirizzo nel MAR (Memory Address Register).

La memoria legge quell’indirizzo e mette l’istruzione nel MDR (Memory Data Register).

Il contenuto dell’MDR viene copiato nel CIR.

Il PC viene incrementato alla prossima istruzione.

Il CIR viene aggiornato quando l’istruzione è stata letta dalla memoria.

*/