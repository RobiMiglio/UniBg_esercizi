#include <iostream>

using namespace std;

int main()
{
   int x;
   int r;

   cout << "inserisci un valore" << endl;
   cin >> x;
   
   r = !(x >= 0 && x <= 10);
   cout << "Confronto: " << r << endl;
   if( r )
      cout << "x=" << x 
	       << " non e` in [0, 10]"<< endl;
   else
      cout << "x=" << x 
	       << " e` in [0, 10]"<< endl;
   
   return 0;
}
