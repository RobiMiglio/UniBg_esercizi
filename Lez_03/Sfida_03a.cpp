/*

SFIDA 1
Scrivere un programma (di nome Sfida_03a.cpp) che
legge da tastiera due numeri interi a e b
se b ± diverso da 0
calcola il quoziente q e il resto r della divisione
- se q ± minore di r, scrive in output il valore della
differenza r - q
- altrimenti scrive in output il valore del prodotto di q
per r

*/

#include <iostream>

using namespace std;

int main()
{
    int a = 0;
    int b = 0;
    float q = 0;
    float r = 0;
    
    cout << "inserisci due numeri interi:" << endl;
    cin >> a;
    cin >> b;
    
    if(b!= 0)
    {
        q = (float)a/b;
        r = a%b;
        if(q<r)
        {
            cout << "r-q = " << r-q << endl;
        }
        else
        {
            cout << "q*r = " << q*r << endl;
        }    
    }
    else
    {
        cout << "errore: divisione pe zero" << endl;
    }
    
    return 0;
}  