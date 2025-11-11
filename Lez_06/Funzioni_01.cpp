#include <iostream>

using namespace std;

float f(float x)
{
	float r;
	
	r = x*x + 2*x + 3;
	
	return r;
}

int main()
{
	float v;
	float ris;

	cout << "Inserire un valore: ";
	cin >> v;
	
	ris = f( v );
	cout << "Risultato: " << ris;
   
   return 0;
}

