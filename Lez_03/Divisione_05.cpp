#include <iostream>

using namespace std;

int main()
{
   int a;
   int b;
   float r;

   cout << "inserisci due valori" << endl;
   cin >> a;
   cin >> b;
   
   if( b != 0)
   {
      r = a / (float)b;
      cout << "r: " << r << endl;
   }
   else
      cout << "ATTENZIONE: DIVISIONE PER ZERO";
   
   return 0;
}
