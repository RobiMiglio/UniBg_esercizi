/*
================================================================================
ESERCIZIO OOP 2 – Gestione dispositivi multimediali (ereditarietà multipla)
================================================================================

Specifiche:
- Devi modellare diversi dispositivi multimediali che possono:
  - Riprodurre audio
  - Riprodurre video
- Alcuni dispositivi supportano solo audio, altri solo video, altri entrambi.
- Tutti i dispositivi devono esporre un’interfaccia comune con una funzione
  `riproduci()`.

Requisiti:
1. Definisci una struttura base `Dispositivo` con:
   - un puntatore a funzione `riproduci(struct Dispositivo*)`.

2. Crea due "interfacce" simulate:
   - AudioDevice (contiene volume + funzione per alzare/abbassare volume)
   - VideoDevice (contiene luminosità + funzione per regolare luminosità)

3. Crea dispositivi concreti:
   - Radio (solo audio)
   - Televisore (solo video)
   - Smartphone (audio + video)

4. Implementa le funzioni di comportamento:
   - La radio riproduce sempre "Musica".
   - Il televisore riproduce sempre "Film".
   - Lo smartphone sceglie se riprodurre audio o video a seconda di un flag.

5. Nel main():
   - Crea un array di `Dispositivo*` con diversi tipi di dispositivi.
   - Itera sull’array e chiama `riproduci()` senza sapere il tipo concreto.

--------------------------------------------------------------------------------
Domande concettuali:
1. Come hai simulato l’ereditarietà multipla in C?
2. Perché è utile separare interfaccia comune (Dispositivo) e parti specifiche
   (AudioDevice/VideoDevice)?
3. Come cambia la gestione del polimorfismo se invece fossimo in C++?
================================================================================
*/

#include <stdio.h>
#include "gestioneDispositivi.h"
#include "gestioneDispositivi.def"

typedef enum
{
    #define X(tipo, ...) tipo,
        DISPOSITIVI_X
    #undef X
    enumTipiDispositiviMax
}enumTipiDispositivi;

const char *nomiDispositivi[] = 
{
    #define X(tipo, ...) #tipo,
        DISPOSITIVI_X
    #undef X    
};


typedef struct DispositivoGenerico
{
    Dispositivo base;
    enumTipiDispositivi tipo;
    int anno;
    enumFunzionalitaDevice enumfunzionalita;
    int funzionalita;
    void (*regolaFunzionalita)(struct DispositivoGenerico *r);
    enumFlagFunzionalita enumFlag;
    int flagFunzionalita;
}DispositivoGenerico;

void regolaVolume(DispositivoGenerico *d)
{
    d->funzionalita += 10;
}

void regolaLuminosita(DispositivoGenerico *d)
{
    d->funzionalita += 20;
}

void regolaVolumeOLuminosita(DispositivoGenerico *d)
{
    if(d->flagFunzionalita & AUDIO)
    {
        d->funzionalita += 10;
    }
    if (d->flagFunzionalita & VIDEO)
    {
        d->funzionalita += 20;
    }
}

void riproduciMusica(Dispositivo *d)
{
    DispositivoGenerico *dg = (DispositivoGenerico *)d;
    printf("[%s] --> riproduzione di musica dell'anno: %d\n", nomiDispositivi[dg->tipo], dg->anno);

}

void riproduciFilm(Dispositivo *d)
{
    DispositivoGenerico *dg = (DispositivoGenerico *)d;
    printf("[%s] --> riproduzione di film dell'anno: %d\n", nomiDispositivi[dg->tipo], dg->anno);
}

void riproduciMusicaOFilm(Dispositivo *d)
{
    DispositivoGenerico *dg = (DispositivoGenerico *)d;
    if(dg->flagFunzionalita & AUDIO)
    {
        printf("[%s] --> riproduzione di musica dell'anno: %d\n", nomiDispositivi[dg->tipo], dg->anno);
    }
    if (dg->flagFunzionalita & VIDEO)
    {
        printf("[%s] --> riproduzione di film dell'anno: %d\n", nomiDispositivi[dg->tipo], dg->anno);
    }
}

//creazione dispositivi usando X macro
DispositivoGenerico dispositivi[] =
{
    #define X(tipo, annoDiLancio, funzioneRiproduci, funzioneRegolaFunzionalita, tipoFunzionalita, valoreInizialeFunzionalita, flagFunzionalita, valoreFlagFunzionalita) {{annoDiLancio, funzioneRiproduci}, tipo, annoDiLancio, tipoFunzionalita, valoreInizialeFunzionalita, funzioneRegolaFunzionalita, flagFunzionalita, valoreFlagFunzionalita},
        DISPOSITIVI_X
    #undef X
};


int main()
{
    for(int i=0; i<enumTipiDispositiviMax; i++)
    {
        Dispositivo *d = (Dispositivo *)&dispositivi[i];
        DispositivoGenerico *dg = &dispositivi[i];

        d->riproduci(d);
        dg->regolaFunzionalita(dg);
    }

    return 0;
}
