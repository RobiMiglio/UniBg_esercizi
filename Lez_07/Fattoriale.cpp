#include <iostream>

using namespace std;

int fatt(int n)
{
	int r;
	
	if( n == 0 )
		r = 1;
	else
		r = n * fatt( n-1);
	
	return r;
}

int fattoriale(int n)
{
	int r;
	
	if(n < 0)
		r = -1;
	else
		r = fatt( n );
	return r;
}

int main()
{
	int v;
	int ris;

	cout << "Inserire un intero: ";
	cin >> v;
	
	ris = fattoriale( v );
	if( ris < 0 )
		cout << "Fattoriale non definito";
	else
		cout << "Risultato: " << ris;
   
   return 0;
}




