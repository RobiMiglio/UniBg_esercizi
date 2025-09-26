/*
===========================================================
   MEGA TEST FINALE — DOMANDA 3 (versione universitaria reale)
   Argomenti: OOP in C, array dinamici, lookup table, X-macro
===========================================================

Progettare e realizzare un programma modulare che gestisca
un insieme di dispositivi in grado di eseguire diverse
operazioni matematiche di base (addizione, sottrazione,
moltiplicazione e divisione) su due valori numerici.

Il programma deve:
 - creare dinamicamente un insieme di dispositivi;
 - assegnare a ciascun dispositivo una diversa operazione;
 - eseguire tutte le operazioni e visualizzare i risultati
   in modo chiaro e leggibile.

Si richiede:
 - approccio astratto in stile “OOP in C” (uso di struct e puntatori a funzione);
 - eliminare completamente l’uso di istruzioni condizionali (if/switch);
 - utilizzare un meccanismo di lookup o macro per associare operazioni e nomi.

L’output deve mostrare per ogni dispositivo il nome
dell’operazione e il relativo risultato.

Esempio indicativo:
Operazione ADD → 8.00
Operazione SUB → 2.00
Operazione MUL → 15.00
Operazione DIV → 1.67
===========================================================
Scrivi qui sotto il tuo codice 👇
===========================================================
*/
#include <iostream>

using namespace std;

#define OPS_X \
X(ADD, a+b) \
X(SUB, a-b) \
X(MUL, a*b) \
X(DIV, a/b)

typedef enum {
    #define X(tipo, ...) tipo,
        OPS_X
    #undef X
    enumOpsMax
} enumOps;

const char *arrNomiOps[] = {
    #define X(tipo, ...) #tipo,
        OPS_X
    #undef X
};

typedef struct Operazione {
    enumOps tipo;
    float (*ops)(float a, float b);
} Operazione;

#define X(tipo, formula) float op_##tipo(float a, float b) { return formula; }
OPS_X
#undef X

Operazione arrOps[] = {
    #define X(tipo, formula) {tipo, op_##tipo},
        OPS_X
    #undef X
};

float calcola(Operazione *o, float a, float b)
{
    return o->ops(a, b);
}

void stampaDispositivo(Operazione *o, float a, float b)
{
    cout << "Operazione " << arrNomiOps[o->tipo] << " --> " 
         << calcola(o, a, b) << endl;
}

int main()
{
    int numOps = enumOpsMax;
    Operazione *dispositivi = new Operazione[numOps];

    // Copia sicura da arrOps
    for(int i = 0; i < numOps; i++)
        dispositivi[i] = arrOps[i];

    for(int i = 0; i < numOps; i++)
        stampaDispositivo(&dispositivi[i], 4, 3);

    delete[] dispositivi;
    return 0;
}
