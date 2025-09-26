/*
===========================================================
   MEGA TEST FINALE — DOMANDA 2 (versione universitaria)
   Argomenti: OOP in C, memoria dinamica, astrazione
===========================================================

Scrivere un programma che simuli un sistema di sensori.

Ogni sensore deve:
 - leggere un valore casuale compreso tra 0 e 100,
 - elaborare il valore calcolando la metà,
 - mantenere il proprio stato indipendente dagli altri.

Il programma deve:
 - creare dinamicamente due sensori,
 - per ciascuno leggere, elaborare e stampare i risultati,
 - rilasciare correttamente la memoria.

⚙️ Il codice deve essere strutturato in modo astratto e modulare,
simulando la programmazione a oggetti in C
(utilizzare struct e puntatori a funzione).

Esempio di output (indicativo):
Sensor 1 -> valore letto: 73.42
Sensor 1 -> valore elaborato: 36.71
Sensor 2 -> valore letto: 15.08
Sensor 2 -> valore elaborato: 7.54
===========================================================
Scrivi qui sotto il tuo codice 👇
===========================================================
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

typedef struct Sensore
{
    int (*letturaValoreSensore)(void);
    float (*calcoloMeta)(float value);
}Sensore;

int letturaValoreSensore(void)
{
    int n = rand() % 100;  // Restituisce numero tra 0 e 100
    return n;
}

float calcolaMeta(float value)
{
    return (float)value/2;
}

int main()
{
    // Inizializza il generatore di numeri casuali
    srand(time(NULL));  

    Sensore *sensoreA = new Sensore;
    Sensore *sensoreB = new Sensore;

    sensoreA->letturaValoreSensore = letturaValoreSensore;
    sensoreA->calcoloMeta = calcolaMeta;

    sensoreB->letturaValoreSensore = letturaValoreSensore;
    sensoreB->calcoloMeta = calcolaMeta;

    float letturaA = sensoreA->letturaValoreSensore();
    cout << "valore letto sensore A: " << letturaA << endl;
    cout << "valore elaborato sensore A: " << sensoreA->calcoloMeta(letturaA) << endl;

    float letturaB = sensoreB->letturaValoreSensore();
    cout << "valore letto sensore B: " << letturaB << endl;
    cout << "valore elaborato sensore B: " << sensoreB->calcoloMeta(letturaB) << endl;

    delete sensoreA;
    delete sensoreB;

    return 0;
}