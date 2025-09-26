// 📝 DOMANDA 7 – Strutture con unioni anonime e campi di bit
// Crea una struct chiamata Sensore che contenga:
//   - un campo di bit per rappresentare 8 sensori ON/OFF (8 bit in totale).
//   - un’unione anonima che può contenere alternativamente un int32_t rawValue
//     oppure un float valoreConvertito.
// Poi:
//   - In main() crea un Sensore.
//   - Imposta manualmente alcuni bit dei sensori (ad esempio il sensore 3 ON).
//   - Carica nell’unione sia un valore int che uno float e mostra come leggere
//     entrambi i campi.
// BONUS: Spiega perché usare una union con bitfield è utile in sistemi embedded.


#include <iostream>

#define SENSORE_1_ON 1<<0
#define SENSORE_2_ON 1<<1
#define SENSORE_3_ON 1<<2
#define SENSORE_4_ON 1<<3
#define SENSORE_5_ON 1<<4
#define SENSORE_6_ON 1<<5
#define SENSORE_7_ON 1<<6
#define SENSORE_8_ON 1<<7

typedef struct Sensore
{
    unsigned int sensorsStato: 8;
    union 
    {
        int32_t rawValue;
        float valoreConvertito;
    };
}Sensore;

int main()
{
    Sensore fotocellula;

    fotocellula.sensorsStato = SENSORE_1_ON | SENSORE_3_ON;
    fotocellula.rawValue = 28900;

    std::cout << "sensori attivi: " << std::endl;
    for(int i=0; i<8; i++)
    {
        if(fotocellula.sensorsStato & 1<<i)
        {
            std::cout << "sensore" << i+1 << std::endl;
        }
    }

    std::cout << "raw valure: " << fotocellula.rawValue << std::endl;

    fotocellula.valoreConvertito = 1450.2;
    std::cout << "valore convertito: " << fotocellula.valoreConvertito << std::endl;



    return 0;
}



/*
risposta domanda teorica

perchè le union occupano meno spazio in memoria visto che pesano tanto quanto il solo valore più pesante invece della somma dei pesi dei vari campi come nelle struct
*/