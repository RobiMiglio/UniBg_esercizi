#pragma once
#include "gestioneVeicoli.def"

// Enum dei veicoli
typedef enum {
    #define X(nome, ...) nome,
        VEICOLI_X
    #undef X
    enumNomiVeicoliMax
} enumNomiVeicoli;

// Enum risorse
typedef enum {
    CARBURANTE,
    BATTERIA
} TipoRisorsa;

// Struct base Veicolo (interfaccia pubblica)
typedef struct Veicolo {
    int velocita;
    void (*accelera)(struct Veicolo *v);
    void (*stampaStato)(struct Veicolo *v);
} Veicolo;

// Prototipi funzioni pubbliche
void AcceleraBenzina(Veicolo *v);
void AcceleraElettrica(Veicolo *v);
void stampaStatoBenzina(Veicolo *v);
void stampaStatoElettrica(Veicolo *v);
