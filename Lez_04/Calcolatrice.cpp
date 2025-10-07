#include <iostream>

using namespace std;

int main()
{
   int a;
   int b;
   int r;
   int scelta;

   cout << "inserisci due valori" << endl;
   cin >> a;
   cin >> b;
   
   cout << "1 - Somma" << endl;
   cout << "2 - Differenza" << endl;
   cout << "3 - Prodotto" << endl;
   cout << "Scelta: ";
   cin >> scelta;

   if( scelta == 1 )   
   {
   	   r = a + b;
   	   cout << "Somma = " << r;
   }
   if( scelta == 2 )   
   {
   	   r = a - b;
   	   cout << "Differenza = " << r;
   }
   if( scelta == 3 )   
   {
   	   r = a * b;
   	   cout << "Prodotto = " << r;
   }
   if( scelta < 1 || scelta > 3)
      cout << "Scelta non valida";
   
   return 0;
}

