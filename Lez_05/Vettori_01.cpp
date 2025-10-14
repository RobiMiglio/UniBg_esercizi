#include <iostream>

using namespace std;

int main()
{
   int vett[5];
   int i;

   for(i=0; i < 5; i++)
   {
   	   cout << "Inserire un valore: ";
   	   cin >> vett[i];
   }
   
   cout << endl;
   for(i=0; i < 5; i++)
      cout << "Posizione " << (i+1) 
           << " valore: " << vett[i] << endl;
   
   return 0;
}

