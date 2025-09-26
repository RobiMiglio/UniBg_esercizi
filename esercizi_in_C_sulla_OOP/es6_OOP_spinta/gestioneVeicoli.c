/*
================================================================================
ESERCIZIO OOP 1 – Gestione veicoli (polimorfismo e incapsulamento con X-Macro)
================================================================================

Specifiche:
- Devi gestire diversi tipi di veicoli che condividono alcune operazioni comuni.
- Ogni veicolo deve poter accelerare e mostrare il proprio stato.
- Alcuni veicoli hanno risorse aggiuntive (es. carburante o batteria) che
  devono essere aggiornate quando accelera.
- Devi poter trattare tutti i veicoli in modo uniforme senza conoscere
  il tipo concreto.

Requisiti:
1. Implementa le strutture necessarie per rappresentare i veicoli.
2. Implementa le funzioni necessarie per:
   - Accelerare ogni veicolo secondo le proprie regole.
   - Stampare lo stato attuale del veicolo (velocita, risorse, ecc.).
3. Gestisci un array di veicoli diversi e chiama le funzioni senza
   conoscere il tipo concreto.

--------------------------------------------------------------------------------
Domande concettuali:
1. Quali scelte di progettazione hai fatto per permettere di trattare tutti i
   veicoli in modo uniforme?
2. Come hai simulato l’ereditarietà e il polimorfismo in C?
3. In quali situazioni è utile nascondere dettagli dei veicoli (incapsulamento)?
================================================================================
*/

#include <stdio.h>
#include "gestioneVeicoli.h"
#include "gestioneVeicoli.def"

// Array dei nomi dei veicoli
const char *nomiVeicoli[] = {
    #define X(nome, ...) #nome,
        VEICOLI_X
    #undef X
};

// Struct concreta interna (incapsulata)
typedef struct AutoGenerica {
    Veicolo base;
    enumNomiVeicoli tipo;
    TipoRisorsa tipoRisorsa;
    int risorsa;
} AutoGenerica;

// Implementazione funzioni comportamentali
void AcceleraBenzina(Veicolo *v) {
    AutoGenerica *ag = (AutoGenerica *)v;
    ag->base.velocita += 20;
    ag->risorsa -= 2; // sappiamo che è carburante
}

void AcceleraElettrica(Veicolo *v) {
    AutoGenerica *ag = (AutoGenerica *)v;
    ag->base.velocita += 40;
    ag->risorsa -= 5; // sappiamo che è batteria
}

void stampaStatoBenzina(Veicolo *v) {
    AutoGenerica *ag = (AutoGenerica *)v;
    printf("[%s] velocita: %d km/h - carburante: %d%%\n", nomiVeicoli[ag->tipo], ag->base.velocita, ag->risorsa);
}

void stampaStatoElettrica(Veicolo *v) {
    AutoGenerica *ag = (AutoGenerica *)v;
    printf("[%s] velocita: %d km/h - batteria: %d%%\n", nomiVeicoli[ag->tipo], ag->base.velocita, ag->risorsa);
}

// Creazione veicoli usando X-Macro
AutoGenerica veicoli[] = {
    #define X(nome, tipoRes, accel, stampa, val) { {0, accel, stampa}, nome, tipoRes, val },
      VEICOLI_X
    #undef X
};

// Main di test
int main() {
    for (int i = 0; i < enumNomiVeicoliMax; i++) {
        Veicolo *v = (Veicolo *)&veicoli[i];
        v->stampaStato(v);
        v->accelera(v);
        v->stampaStato(v);
    }
    return 0;
}



/*
================================================================================
DOMANDE CONCETTUALI – RISPOSTE
--------------------------------------------------------------------------------
1. Ho creato una struttura base Veicolo con velocità e metodi comuni, poi ho
   generato i vari tipi concreti con le X-Macro. Così ogni veicolo è un tipo
   specifico ma può essere trattato come Veicolo*.
2. L’ereditarietà è simulata includendo la struct base come primo campo;
   il polimorfismo è simulato con i puntatori a funzione.
3. L’incapsulamento è utile per nascondere i dettagli interni (es. gestione
   carburante/batteria) e permettere di usare i veicoli solo tramite interfaccia
   comune (accelera, stampaStato).
================================================================================
*/

