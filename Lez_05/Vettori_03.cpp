#include <iostream>

using namespace std;

#define SIZE 10

int main()
{
   int vett[SIZE];
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

