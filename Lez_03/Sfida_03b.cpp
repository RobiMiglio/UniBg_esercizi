/*
SFIDA 2

Scrivere un programma (di nome Sfida_03b.cpp) che:
- legge da tastiera tre numeri che corrispondono ad una data, quindi giorno, mese e anno
- si deve controllare se la data è valida.

Una data è valida se:
- l'anno non è minore del 1800;
- il mese è compreso tra 1 e 12;
- il giorno è compreso tra 1 e il massimo giorno di ogni mese;
- nel caso di Febbraio, se l'anno è bisestile, i giorni sono 29, altrimenti 28.

Quando un anno è bisestile?
- se è multiplo di 400
- se è multiplo di 4 ma non è multiplo di 100
*/

#include <iostream>

using namespace std;

int main()
{
    int giorno = 0;
    int mese = 0;
    int anno = 0;
  
    cout << "inserisci il giorno: " << endl;
    cin >> giorno;

    cout << "inserisci il mese: " << endl;
    cin >> mese;

    cout << "inserisci il anno: " << endl;
    cin >> anno;

    bool isBisestibile = ((anno%400 ==0)&&(anno%4 ==0)&&(anno%100 != 0));
    bool dataValida = 0;

    if(anno > 1800 && (mese >= 1 && mese <= 12))
    {
        switch(mese)
        {
            case 1: 
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
               if (giorno >= 1 && giorno <= 31)
               {
                   dataValida = 1;
               }
               break;   
            case 4: 
            case 6:
            case 9:
            case 11:
               if (giorno >= 1 && giorno <= 30)
               {
                   dataValida = 1;
               }
               break; 
            case 2:   
               if(isBisestibile)
               {
                    if((giorno >= 1 && giorno <= 29))
                    {
                        dataValida = 1;
                    }
               }
               else
               {
                    if((giorno >= 1 && giorno <= 28))
                    {
                        dataValida = 1;
                    }
               }
               break;
        }
        if (dataValida)
        {
            cout << "data valida"  << endl;            
        }
        else
        {
            cout << "data non valida"  << endl;
        }
    }
    else
    {
        cout << "data non valida"  << endl;
    }

    return 0;
}