#include <iostream>

using namespace std;

int main()
{
   int a=1;
   int *p;
   
   cout << "Valore di a: " << a << endl;
   p = &a;
   *p = 3;
   
   cout << "Valore di a: " << a << endl;
   
   return 0;
}

