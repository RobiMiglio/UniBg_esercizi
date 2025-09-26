#pragma once
#include "GestioneCatalogo.def"

typedef enum
{
   #define X(tipo, titolo, anno, tipoProfessionista, nomeDelProfessionista, ...) nomeDelProfessionista,
     CATALOGO_X
   #undef X
   enumNomiProfessionistaMax
}enumNomiProfessionista;

const char *nomiProfessionista[] = 
{
   #define X(tipo, titolo, anno, tipoProfessionista, nomeDelProfessionista, ...) #nomeDelProfessionista,
     CATALOGO_X
   #undef X
};

typedef enum
{
   #define X(tipo, titolo, anno, tipoProfessionista, ...) tipoProfessionista,
     CATALOGO_X
   #undef X
   enumTipoProfessionistaMax
}enumTipoProfessionista;

const char *nomiTipoProfessionista[] = 
{
   #define X(tipo, titolo, anno, tipoProfessionista, ...) #tipoProfessionista,
     CATALOGO_X
   #undef X
};

typedef enum
{
   #define X(tipo, titolo, ...) titolo,
     CATALOGO_X
   #undef X
   enumTitoloMediaMax
}enumTitoloMedia;

const char *nomiTitoloMedia[] = 
{
   #define X(tipo, titolo, ...) #titolo,
     CATALOGO_X
   #undef X
};

//classe
typedef struct ElementoMultimediale
{
    enumNomiProfessionista nomeProf;
    enumTipoProfessionista tipoProf;
    enumTitoloMedia nomeTitolo;
    int Anno;
    void (*mostraInfo)(struct ElementoMultimediale *c);
}ElementoMultimediale;

void stampaInformazioniLibro(ElementoMultimediale *e);
void stampaInformazioniFilm(ElementoMultimediale *e);
void stampaInformazioniAlbumMusicale(ElementoMultimediale *e);