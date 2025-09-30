#include <iostream>

using namespace std;

int main()
{
   int x;

   cout << "inserisci un valore" << endl;
   cin >> x;
   
   if( x >= 0 && x <= 10)
      cout << "x=" << x 
	       << " e` in [0, 10]"<< endl;
   else
      cout << "x=" << x 
	       << " non e` in [0, 10]"<< endl;
   
   return 0;
}
