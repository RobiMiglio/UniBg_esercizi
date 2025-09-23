#include <iostream>

using namespace std;

int main()
{
   int a;
   int b;
   float r;

   cout << "inserisci due valori" << endl;
   cin >> a;
   cin >> b;
   
   r = (float)a / b;
   cout << "r: " << r << endl;
   
   return 0;
}
