#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;


int main()
{
	int size, v, i;
	char nomefile[1000];
	ofstream fout;

	cout << "Nome del file: ";
	cin.getline(nomefile, 10000);
	cout << "Quanti Valori? ";
	cin >> size;
	
	fout.open(nomefile, ios::out);
	if(fout.fail())
	{
		cout << "Errore Apertura File";
		exit(1);
	}

	fout << size << endl;

	for(i=0; i < size; i++)
	{
		cout << "Valore " << (i+1) << ": ";
		cin >> v;
		fout << v << endl;
	}
	
	fout.close();
   
    return 0;
}




