//sfida lezione_02 (ultima pagina slide lezione_02 teorica)
/*
Scrivere un programma che svolge il seguente lavoro.
Leggere due numeri interi tramite le variabile v1 e v2.
Calcolare e stampare la somma di v1 e v2.
Raddoppiare e stampare il valore di v1.
Calcolare e stampare la differenza di v1 e v2.
Sottrarre a v2 il valore della differenza
precedentemente calcolata e stampare il nuovo valore.
Calcolare il quoziente intero e il resto di v1 diviso v2.
Calcolare e stampare il risultato esatto di v1 diviso v2.
*/

#include <iostream>

using namespace std;

int main()
{
    int v1 = 0;
    int v2 = 0;
    int risultato = 0;
    cout << "inserisci due numeri interi" << endl;
    cin >> v1;
    cin >> v2;

    //calcola somma
    risultato = v1 + v2;
    cout << "somma: " << risultato << endl;

    //raddoppiare valore v1
    v1 *= 2;
    cout << "raddoppio di v1: " << v1 << endl;

    //differenza di v1 e v2
    risultato = 0;
    risultato = v1-v2;
    cout << "differenza di v1 e v2: " << risultato << endl;

    //sottrarre a v2 il valore della differenza precedentemente calcolata e stampare valore
    v2 -= risultato;
    cout << "risultato: " << v2 << endl;

    //calcolare quozioente intero e il resto di v1 diviso v2
    risultato = v1/v2;
    cout << "quoziente di v1 e v2: " << risultato << endl;

    risultato = v1%v2;
    cout << "resto di v1 e v2: " << risultato << endl;

//Calcolare e stampare il risultato esatto di v1 diviso v2
    float risultatoEsatto = (float)v1/v2;
    cout << "resto di v1 e v2: " << risultatoEsatto << endl;

    return 0;
}