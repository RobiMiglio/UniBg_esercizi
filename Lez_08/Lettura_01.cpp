#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;


int main()
{
	int size, v, i;
	char nomefile[1000];
	ifstream fin;

	cout << "Nome del file: ";
	cin.getline(nomefile, 10000);

	fin.open(nomefile);
	if(fin.fail())
	{
		cout << "Errore Apertura File";
		exit(1);
	}

	fin >> size;

	for(i=0; i < size; i++)
	{
		fin >> v;
		cout << v << endl;
	}
	
	fin.close();
   
    return 0;
}




