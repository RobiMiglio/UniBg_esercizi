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

   switch( scelta )
   {
   	case 1:
   	   r = a + b;
   	   cout << "Somma = " << r;
   	   break;
   	case 2:
   	   r = a - b;
   	   cout << "Differenza = " << r;
   	   break;
   case 3:
   	   r = a * b;
   	   cout << "Prodotto = " << r;
       break;
    default:
      cout << "Scelta non valida";
      break;
   }
      
   return 0;
}

