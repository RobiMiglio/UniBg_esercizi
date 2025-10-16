/*

Esercizio 4
(soluzione omessa per esercizio individuale)

Uno studente deve sostenere una prova pratica e una prova teorica
per superare un esame.
A ogni prova è assegnato un punteggio tra 0 e 30.
Il voto finale è dato dalla media dei due.
Anche se il voto finale è maggiore o uguale a 18, lo studente risulterà
promosso solo se entrambe le prove sono sufficienti,
altrimenti dovrà risostenere la prova che è risultata insufficiente.
Scrivere un programma che acquisisca i voti delle due prove e
riporti a video un messaggio che descrive le sorti dello studente


*/

#include <iostream>

using namespace std;

int main()
{
    int voto1 = 0;
    int voto2 = 0;
    float media = 0;

    do
    {
        cout << "inserire voto 1: ";
        cin >> voto1;
        if((voto1<0) || (voto1>30))
        {
            cout << "\nvoto errato" << endl;
        }
    } while ((voto1<0) || (voto1>30));
    
    do
    {
        cout << "inserire voto 2: ";
        cin >> voto2;
        if((voto2<0) || (voto2>30))
        {
            cout << "\nvoto errato" << endl;
        }
    } while ((voto2<0) || (voto2>30));

    if((voto1>=18) && (voto2>=18))
    {
        cout << "promosso" << endl;
        media = ((float)voto1 + voto2)/2;
        cout << "media: " << media << endl;
    }
    else
    {
        cout << "non promosso" << endl;
    }

    return 0;
}