/*

dichiaro variabile a,c,b, (int)
prendo in input a,b,c
if a<b >>>>> a,b,c a,c,b c,a,b
    if c<a
       stampo c,a,b
    else if c<b
       stampo a,c,b
    else
       stampo a,b,c
else >>>>> c,b,a    b,a,c     b,c,a
    if a<c
        stampo b,a,c
    else if b<c
        stampo b,c,a
    else
        stampo c,b,a
*/

#include <iostream>

using namespace std;

int main(void)
{
    int a;
    int b;
    int c;

    cout << "inerisci primo numero: " << endl;
    cin >> a;
    cout << "inerisci secondo numero: " << endl;
    cin >> b;
    cout << "inerisci terzo numero: " << endl;
    cin >> c;
    
    if(a<b)
    {
        if(c<a)
        {
            cout << "l'ordine crescente è: " << c << a << b << endl;
        }
        else if(c<b)
        {
            cout << "l'ordine crescente è: " << a << c << b << endl;
        }
        else
        {
            cout << "l'ordine crescente è: " << a << b << c << endl;
        }
    }
    else
    {
        if(a<c)
        {
            cout << "l'ordine crescente è: " << b << a << c << endl;
        }
        else if(b<c)
        {
            cout << "l'ordine crescente è: " << b << c << a << endl;
        }
        else
        {
            cout << "l'ordine crescente è: " << c << b << a << endl;
        }  
    }

    return 0;
}



