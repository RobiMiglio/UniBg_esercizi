/*
================================================================================
ESERCIZIO OOP 1 — Gestione dispositivi elettronici (10 punti)
================================================================================

Si consideri un programma in linguaggio C che simula la gestione di dispositivi
elettronici eterogenei (es. Smartphone, Laptop, Smartwatch). Ogni dispositivo 
condivide alcune proprietà comuni, ma differisce per altre.

--------------------------------------------------------------------------------
SPECIFICHE:

1. Definire una struttura base DISPOSITIVO che contenga:
   - un identificativo numerico (int id)
   - un nome del dispositivo (stringa)
   - un livello di batteria (float, in percentuale)
   - due puntatori a funzione:
        → una per “mostrare stato” del dispositivo
        → una per “ricaricare” il dispositivo

2. Definire tre strutture derivate (simulate con campi aggiuntivi):
   - SMARTPHONE (aggiungere campo memoria in GB)
   - LAPTOP (aggiungere campo temperatura CPU in °C)
   - SMARTWATCH (aggiungere campo passi giornalieri)

3. Creare un array contenente dispositivi di diversi tipi, ma gestiti
   tramite la struttura base DISPOSITIVO.

4. Ogni dispositivo deve avere una propria funzione di:
   - visualizzazione stato (che stampi tutti i dati rilevanti)
   - ricarica (che simuli la ricarica in modo differente)
     → es. smartphone +10%, laptop +20%, smartwatch +5%

5. Il programma deve:
   - Inizializzare i dispositivi
   - Stampare lo stato di ciascuno
   - Eseguire una ricarica generica su tutti
   - Stampare di nuovo lo stato dopo la ricarica

--------------------------------------------------------------------------------
ESEMPIO OUTPUT:

[Smartphone] ID: 1, Nome: Pixel7, Batt: 55.0%, Memoria: 128GB  
[Laptop] ID: 2, Nome: ThinkPad, Batt: 20.0%, Temp: 65°C  
[Smartwatch] ID: 3, Nome: FitBand, Batt: 80.0%, Passi: 5600  

--- Dopo ricarica ---
[Smartphone] Batt: 65.0%
[Laptop] Batt: 40.0%
[Smartwatch] Batt: 85.0%

--------------------------------------------------------------------------------
DOMANDA TEORICA (6 punti):

1️⃣ Come si può simulare il concetto di “classe base” e “classe derivata” in C,
    pur non avendo ereditarietà diretta come in C++?

2️⃣ Quali sono i vantaggi e gli svantaggi dell’approccio con “puntatori a funzione”
    per ottenere polimorfismo in C?

================================================================================
*/

#include <iostream>
#include "dispositivi_elettronici.h"
#include "dispositivi_elettronici.def"

using namespace std;

//classe derivata generica
typedef struct DispositivoGenerico
{
   Dispositivo base;
   float dettaglio;
}DispositivoGenerico;

DispositivoGenerico arrDispositivi[] = 
{
   #define X(id, tipo, nome, livelloBatteria, dettaglio, funzioneStato, funzioneRicarica) {{id, tipo, nome, livelloBatteria, funzioneStato, funzioneRicarica}, dettaglio} ,
      DISPOSITIVI_X
   #undef X
};

void statoSmartphone(Dispositivo *d)
{
   DispositivoGenerico *dg = (DispositivoGenerico*)d;
   cout << "\nid dispositivo: " << dg->base.id
        << "\ttipo dispositivo: " << arrNomiTipoDispositivi[dg->base.id]
        << "\tnome dispositivo: " << arrNomiDispositivi[dg->base.id]
        << "\t\tlivello batteria: " << dg->base.livelloBatteria
        << "\tquantita' memoria: " << dg->dettaglio << "GB" << endl;
}

void statoLaptop(Dispositivo *d)
{
   DispositivoGenerico *dg = (DispositivoGenerico*)d;
   cout << "\nid dispositivo: " << dg->base.id
        << "\ttipo dispositivo: " << arrNomiTipoDispositivi[dg->base.id]
        << "\tnome dispositivo: " << arrNomiDispositivi[dg->base.id]
        << "\t\tlivello batteria: " << dg->base.livelloBatteria
        << "\ttemperatura: " << dg->dettaglio << "°C" << endl;
}

void statoSmartwatch(Dispositivo *d)
{
   DispositivoGenerico *dg = (DispositivoGenerico*)d;
   cout << "\nid dispositivo: " << dg->base.id
        << "\ttipo dispositivo: " << arrNomiTipoDispositivi[dg->base.id]
        << "\tnome dispositivo: " << arrNomiDispositivi[dg->base.id]
        << "\tlivello batteria: " << dg->base.livelloBatteria
        << "\tpassi giornalieri: " << dg->dettaglio << endl;
}

void ricaricaSmartphone(Dispositivo *d)
{
   DispositivoGenerico *dg = (DispositivoGenerico*)d;
   dg->base.livelloBatteria += 10;
   cout << "\ntipo dispositivo: " << arrNomiTipoDispositivi[dg->base.id]
        << "\tlivello batteria: " << dg->base.livelloBatteria << endl;
}

void ricaricaLaptop(Dispositivo *d)
{
   DispositivoGenerico *dg = (DispositivoGenerico*)d;
   dg->base.livelloBatteria += 20;
   cout << "\ntipo dispositivo: " << arrNomiTipoDispositivi[dg->base.id]
        << "\tlivello batteria: " << dg->base.livelloBatteria << endl;
}

void ricaricaSmartwatch(Dispositivo *d)
{
   DispositivoGenerico *dg = (DispositivoGenerico*)d;
   dg->base.livelloBatteria += 5;
   cout << "\ntipo dispositivo: " << arrNomiTipoDispositivi[dg->base.id]
        << "\tlivello batteria: " << dg->base.livelloBatteria << endl;
}


int main()
{
   int nDispositivi = sizeof(arrDispositivi)/sizeof(arrDispositivi[0]);
   for(int i=0; i<nDispositivi; i++)
   {
       Dispositivo *d = (Dispositivo *)&arrDispositivi[i];
       d->statoDispositivo(d);
   }

   for(int i=0; i<nDispositivi; i++)
   {
       Dispositivo *d = (Dispositivo *)&arrDispositivi[i];
       d->ricaricaDispositivo(d);
   }

   for(int i=0; i<nDispositivi; i++)
   {
       Dispositivo *d = (Dispositivo *)&arrDispositivi[i];
       d->statoDispositivo(d);
   }

   return 0;
}


/*
domande teoriche

1.
grazie alla creazione di una classe base con attributi e metodi (puntotori a funzione)
poi si creano classi derivate contenenti la classe base più eventualmente anche altre aggiunte

2.
vantaggi --> simuli il polimorfismo --> con lo stesso puntatore a funzione si possono ottenere effetti dfferenti visto che gli si può legare funzioni differenti
svantaggi --> a differenza del C++ dove la OOP è nativa qui dobbiamo costruirla noi, quindi più macchinoso e meno leggibile


*/