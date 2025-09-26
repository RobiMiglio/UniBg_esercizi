/*
================================================================================
DOMANDA 12 – Puntatori a funzione e polimorfismo in C
================================================================================

// Definisci una struct Dispositivo con un puntatore a funzione `void (*accendi)(struct Dispositivo*)`
// Crea due “derivati”: Radio e Televisore, con campi aggiuntivi a piacere
// Implementa due funzioni concrete `accendiRadio` e `accendiTV`
// Nel main():
// - Crea un array di puntatori a Dispositivo contenente Radio e Televisore
// - Chiama accendi() su tutti gli elementi senza conoscere il tipo concreto

// Domanda teorica:
// - Come il puntatore a funzione permette di simulare il polimorfismo in C?
*/

#include <stdio.h>

typedef struct Dispositivo
{
    void(*accendi)(struct Dispositivo *d);
    void(*stampaInfo)(struct Dispositivo *d);
}Dispositivo;

typedef struct 
{
    Dispositivo base;
    float costo;
}Radio;

typedef struct 
{
    Dispositivo base;
    int pollici;
}Tv;


void accendiRadio(Dispositivo *d)
{
    puts("radio accesa");
}

void accendiTV(Dispositivo *d)
{
    puts("Tv accesa");
}

void stampaInfoRadio(Dispositivo *d)
{
    Radio *r = (Radio *)d;
    printf("costo: %.2f\n", r->costo);
}

void stampaInfoTv(Dispositivo *d)
{
    Tv *t = (Tv *)d;
    printf("pollici: %d\n", t->pollici);
}

int main()
{
    Radio r = {{accendiRadio, stampaInfoRadio}, 40.5};
    Tv t = {{accendiTV, stampaInfoTv}, 400};
    Dispositivo *dispositivi[2];

    dispositivi[0] = (Dispositivo *)&r;
    dispositivi[1] = (Dispositivo *)&t;

    int n = sizeof(dispositivi) / sizeof(dispositivi[0]);
    for(int i=0; i<n; i++)
    {
        dispositivi[i]->accendi(dispositivi[i]);
        dispositivi[i]->stampaInfo(dispositivi[i]);
    }
}

/*
RISPOSTA TEORICA
- I puntatori a funzione permettono di simulare il polimorfismo in C perché:
  * ogni struct può avere un campo che punta a una funzione specifica.
  * più "tipi derivati" possono riempire quel campo con implementazioni diverse.
  * quando chiamo `dispositivo->accendi(...)`, il programma non deve sapere
    se è una Radio o una TV: esegue la funzione collegata a quell’oggetto.
- È un modo manuale per ottenere lo stesso concetto di "metodo virtuale"
  che esiste nei linguaggi orientati agli oggetti.
*/
