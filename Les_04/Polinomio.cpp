/*
------------------------------------------------------------
   ESERCIZIO: VALUTAZIONE DI UN POLINOMIO
------------------------------------------------------------

Leggere un polinomio di grado n a coefficienti reali
e valutarlo in un dato punto x.

------------------------------------------------------------
DESCRIZIONE:
Il programma deve:
1. Chiedere all’utente il grado n del polinomio.
2. Leggere i coefficienti reali del polinomio (dal termine di grado n fino a quello costante).
3. Chiedere il valore reale di x.
4. Calcolare e stampare il valore del polinomio in x.
------------------------------------------------------------
*/

#include <iostream>
#include <cmath>  // per pow()

using namespace std;

#define DIM_MAX 10

int main()
{
    int grado = 0;
    
    // Lettura grado del polinomio
    do
    {
        cout << "Inserire il grado del polinomio (maggiore di 0 e <= " << DIM_MAX << "): ";
        cin >> grado;

        if (grado <= 0 || grado > DIM_MAX)
            cout << "Valore non valido - riprovare." << endl;

    } while (grado <= 0 || grado > DIM_MAX);

    double coeff[DIM_MAX + 1];

    // Lettura coefficienti dal grado massimo al termine costante
    cout << "\nInserire i coefficienti del polinomio (dal grado " << grado << " al grado 0):\n";
    for (int i = grado; i >= 0; i--)
    {
        cout << "Coefficiente di grado " << i << ": ";
        cin >> coeff[i];
    }

    double x;
    cout << "\nInserire il valore di x: ";
    cin >> x;

    // Calcolo del valore del polinomio
    double valore = 0;
    for (int i = 0; i <= grado; i++)
    {
        valore += coeff[i] * pow(x, i);
    }

    cout << "\nValore del polinomio P(" << x << ") = " << valore << endl;

    return 0;
}
