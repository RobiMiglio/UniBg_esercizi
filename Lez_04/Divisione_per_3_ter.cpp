#include <iostream>

using namespace std;

int main()
{
   int v;

   while( 1 )
   {
      cout << "inserisci un valore" << endl;
      cin >> v;
      if( v % 3 == 0 )
      {
      	cout << "OK" << endl;
      	break;
	  }
   }
   
   return 0;
}

