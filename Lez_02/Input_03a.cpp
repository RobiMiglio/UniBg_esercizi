#include <iostream>

using namespace std;

int main()
{
   int a;
   int b;
   
   cin >> a;
   b = a++ * 2;
   cout << "a: " << a << endl;
   cout << "b: " << b << endl;
   
   return 0;
}
