#include <iostream>

using namespace std;

int main()
{
   const int SIZE = 10;
   int vett[10];
   int i;

   for(i=0; i < SIZE; i++)
   {
   	   cout << "Inserire un valore: ";
   	   cin >> vett[i];
   }
   
   cout << endl;
   for(i=0; i < SIZE; i++)
      cout << "Posizione " << (i+1) 
           << " valore: " << vett[i] << endl;
   
   return 0;
}

