#pragma once

#include "dispositivi_elettronici.def"

typedef enum 
{
   #define X(id, tipo, ...) tipo,
      DISPOSITIVI_X
   #undef X
   enumTipoDispositivoMax
}enumTipoDispositivo;

const char *arrNomiTipoDispositivi[] =
{
   #define X(id, tipo, ...) #tipo,
      DISPOSITIVI_X
   #undef X 
};


typedef enum 
{
   #define X(id, tipo, nome, ...) nome,
      DISPOSITIVI_X
   #undef X
   enumNomiDispositivoMax
}enumNomiDispositivo;

const char *arrNomiDispositivi[] =
{
   #define X(id, tipo, nome, ...) #nome,
      DISPOSITIVI_X
   #undef X 
};

//classe dispositivi
typedef struct Dispositivo
{
   //attributi
   int id;
   enumTipoDispositivo tipo;
   enumNomiDispositivo nome;
   float livelloBatteria;
   //metodi
   void (*statoDispositivo)(Dispositivo *d);
   void (*ricaricaDispositivo)(Dispositivo *d);
}Dispositivo;

void statoSmartphone(Dispositivo *d);
void statoLaptop(Dispositivo *d);
void statoSmartwatch(Dispositivo *d);
void ricaricaSmartphone(Dispositivo *d);
void ricaricaLaptop(Dispositivo *d);
void ricaricaSmartwatch(Dispositivo *d);