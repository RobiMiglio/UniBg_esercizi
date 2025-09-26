/*
================================================================================
ESERCIZIO OOP 3 – Gestione catalogo media
================================================================================

Scenario:
- Devi gestire una collezione di elementi multimediali (es. libri, film, album).
- Ogni elemento ha delle informazioni comuni (nomeTitolo, Anno).
- Ogni tipo di media ha dettagli specifici (es. autore, regista, artista).
- Devi poter trattare tutti i media in maniera uniforme, ma stampare anche
  informazioni specifiche a seconda del tipo.

Requisiti minimi (vincolanti):
1. Definisci una struct base `Media` con:
   - nomeTitolo (stringa)
   - Anno (int)
   - puntatore a funzione `mostraInfo(struct Media*)`

2. Implementa almeno 2 tipi concreti (derivati da Media), a tua scelta
   (es. Libro, Film, Album musicale...).

3. Implementa le funzioni necessarie per mostrare le informazioni.
   - Devono stampare sia i campi base (nomeTitolo, Anno) sia i campi specifici.

4. Nel main():
   - Crea un array di puntatori a Media contenente elementi di tipi diversi.
   - Itera e chiama `mostraInfo()` senza sapere il tipo concreto.

--------------------------------------------------------------------------------
Domande concettuali:
1. Come hai deciso quali campi lasciare nella struct base e quali nei derivati?
2. In C++ avresti potuto usare ereditarietà e metodi virtuali: cosa cambia
   rispetto alla simulazione in C?
3. Se volessi aggiungere un nuovo tipo di media (es. Podcast), quali modifiche
   minime dovresti fare al codice?
================================================================================
*/

#include <stdio.h>
#include "GestioneCatalogo.h"
#include "GestioneCatalogo.def"

typedef enum
{
   #define X(tipo, ...) tipo,
     CATALOGO_X
   #undef X
   enumTipoMediaMax
}enumTipoMedia;

const char *nomiTipoMedia[] = 
{
   #define X(tipo, ...) #tipo,
     CATALOGO_X
   #undef X   
};

typedef enum
{
   #define X(tipo, titolo, anno, tipoProfessionista, nomeDelProfessionista, tipoDettaglio, ...) tipoDettaglio,
     CATALOGO_X
   #undef X
   enumTipoDettaglioMax
}enumTipoDettaglio;

const char *nomiTipoDettaglio[] = 
{
   #define X(tipo, titolo, anno, tipoProfessionista, nomeDelProfessionista, tipoDettaglio, ...) #tipoDettaglio,
     CATALOGO_X
   #undef X 
};

//classe derivata generica per tutti gli elementi multimediali
typedef struct ElementoMultimedialeGenerico
{
   ElementoMultimediale base;
   enumTipoMedia tipoMedia;
   enumTipoDettaglio tipoDettaglio;
   float dettaglio;
}ElementoMultimedialeGenerico;




void stampaInformazioniLibro(ElementoMultimediale *e)
{
   ElementoMultimedialeGenerico *em = (ElementoMultimedialeGenerico *)e;
   printf("[%s] che è un %s ha scritto il %s dal titolo: %s --> Anno: %d e %s: %.2f\n", nomiProfessionista[em->base.nomeProf], nomiTipoProfessionista[em->base.tipoProf], nomiTipoMedia[em->tipoMedia], nomiTitoloMedia[em->base.nomeTitolo], em->base.Anno, nomiTipoDettaglio[em->tipoDettaglio], em->dettaglio);
}

void stampaInformazioniFilm(ElementoMultimediale *e)
{
   ElementoMultimedialeGenerico *em = (ElementoMultimedialeGenerico *)e;
   printf("[%s] che è un %s ha diretto il %s dal titolo: %s --> Anno: %d e %s: %.2f\n", nomiProfessionista[em->base.nomeProf], nomiTipoProfessionista[em->base.tipoProf], nomiTipoMedia[em->tipoMedia], nomiTitoloMedia[em->base.nomeTitolo], em->base.Anno, nomiTipoDettaglio[em->tipoDettaglio], em->dettaglio);
}

void stampaInformazioniAlbumMusicale(ElementoMultimediale *e)
{
   ElementoMultimedialeGenerico *em = (ElementoMultimedialeGenerico *)e;
   printf("[%s] che è un %s ha inciso l'%s dal titolo: %s --> Anno: %d e %s: %.2f\n", nomiProfessionista[em->base.nomeProf], nomiTipoProfessionista[em->base.tipoProf], nomiTipoMedia[em->tipoMedia], nomiTitoloMedia[em->base.nomeTitolo], em->base.Anno, nomiTipoDettaglio[em->tipoDettaglio], em->dettaglio);
}

ElementoMultimedialeGenerico elementi[] = 
{
   #define X(tipo, titolo, anno, tipoProfessionista, nomeDelProfessionista, tipoDettaglio, dettaglio, funzioneStampaInfo) \
   {{nomeDelProfessionista, tipoProfessionista, titolo, anno, funzioneStampaInfo}, tipo, tipoDettaglio, dettaglio},
     CATALOGO_X
   #undef X
};


int main()
{
   int nElementi = sizeof(elementi)/sizeof(elementi[0]);
   for(int i=0; i<nElementi; i++)
   {
       ElementoMultimediale *d = (ElementoMultimediale *)&elementi[i];
       d->mostraInfo(d);
   }

   /*
      for(int i=0; i<enumTipoMediaMax; i++)
   {
       ElementoMultimediale *d = (ElementoMultimediale *)&elementi[i];
       d->mostraInfo(d);
   }
   */

   return 0;
}