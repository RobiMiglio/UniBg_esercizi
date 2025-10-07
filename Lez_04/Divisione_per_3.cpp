#include <iostream>

using namespace std;

int main()
{
   int procedi=1;
   int v;

   while( procedi )
   {
      cout << "inserisci un valore" << endl;
      cin >> v;
      if( v % 3 == 0 )
      {
      	cout << "OK" << endl;
      	procedi = 0;
	  }
   }
   
   return 0;
}
