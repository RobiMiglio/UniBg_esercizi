#include <iostream>

using namespace std;

int main()
{
   int v;

   do
   {
      cout << "inserisci un valore" << endl;
      cin >> v;
   } while( v % 3 != 0 );
   cout << "OK" << endl;
   
   return 0;
}

