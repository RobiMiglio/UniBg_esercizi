
// Esegue e visualizza a video il risultato del massimo tra 2 numeri inseriti da un utente

#include <iostream>

using namespace std;

int main()
{
    int a;
    int b;

    cout << "insrisci due numeri interi: " << endl;
    cin >> a;
    cin >> b;

    cout << "il numero più grande che hai inserito è: " << ((a > b) ? a : b) << endl;
    
    return 0;
}
