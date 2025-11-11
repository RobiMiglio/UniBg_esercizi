#include <iostream>

using namespace std;

int i;

void Da_N_A_Zero(int valore)
{
	for(i=valore; i >= 0; i--)
	   cout << i << " ";
	cout << endl;
}

void Lettura_E_Stampa(int valori)
{
	int v;
	
	for(i=0; i < valori; i++)
	{
		cout << "Inserire valore " << (i+1) << ": ";
		cin >> v;
		if( v >= 0)
			Da_N_A_Zero(v);
		else
			cout << "Valore non valido" << endl;
	}
}

int main()
{
   int valori;
   
   cout << "Quanti valori vuoi gestire ?";
   cin >> valori;
   Lettura_E_Stampa(valori);
   
   return 0;
}

