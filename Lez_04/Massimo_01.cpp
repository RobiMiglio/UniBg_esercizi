// Massimo
#include <iostream>

using namespace std;

int main()
{
   int n, massimo, primo = 1;

   do
   {
   	   cout << "INSERIVE UN VALORE ";
   	   cin >> n;
   	   if( n!=0)
   	   {
   	   	  if( primo )
   	   	  {
   	   	     massimo = n;
			primo = 0;	
		  }
		  else
		  {
		  	if( n > massimo )
		  	   massimo = n;
		  }
	   }
   } while( n != 0);
   
   if( primo )
      cout << "SEQUENZA VUOTA" << endl;
    else
      cout << "Massimo=" << massimo << endl;

   return 0;
}

