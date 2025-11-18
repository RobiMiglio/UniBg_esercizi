#include <iostream>
#include <cstdlib>

using namespace std;


int main()
{
	int i;
	int *elenco;
	int size;

	cout << "Quanti Valori? ";
	cin >> size;
	
	elenco = new int[size];
	if(elenco == NULL)
	{
		cout << "Memoria Esaurita";
		exit(1);
	}

	for(i=0; i < size; i++)
	{
		cout << "Valore " << (i+1) << ": ";
		cin >> elenco[i];
	}
	
	for(i=0; i < size; i++)
		cout << "Valore " << (i+1) << ": "
		     << elenco[i] << endl;
   
   delete elenco;
   
   return 0;
}




