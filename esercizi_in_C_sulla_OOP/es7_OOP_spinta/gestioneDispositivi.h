#pragma once
#include "gestioneDispositivi.def"

typedef struct Dispositivo
{
    int anno;
    void (*riproduci)(struct Dispositivo *d);
}Dispositivo;


typedef enum
{
    VOLUME,
    LUMINOSITA,
    VOLUME_O_LUMINOSITA,
    enumFunzionalitaDeviceMax
}enumFunzionalitaDevice;

typedef enum
{
    #define X(flag, valore) flag = valore,
        FLAG_FUNZIONALITA_X
    #undef X
    enumFlagFunzionalitaMax
}enumFlagFunzionalita;
