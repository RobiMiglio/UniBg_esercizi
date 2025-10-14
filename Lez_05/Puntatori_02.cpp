#include <iostream>

using namespace std;

int main()
{
   const int SIZE=5;
   int vett[SIZE];
   int i;
   int *p;
   
   p = vett;

   for(i=0; i < SIZE; i++)
   {
   	   cout << "Inserire un valore: ";
   	   cin >> *(p + i);
   }
   
   cout << endl;
   for(i=0; i < SIZE; i++)
      cout << "Posizione " << (i+1) 
           << " valore: " << p[i] << endl;
   
   return 0;
}

