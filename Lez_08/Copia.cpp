#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;


int main(int argc, char*argv[])
{
	ifstream fin;
	ofstream fout;
	char c;

	if(argc != 3)
	{
		cout << "Argomenti Errati";
		return 1;
	}
	
	fin.open(argv[1]);
	if(fin.fail())
	{
		cout << "Errore Apertura File" << argv[1];
		exit(1);
	}
	fout.open(argv[2], ios::out);
	if(fout.fail())
	{
		cout << "Errore Apertura File" << argv[2];
		exit(1);
	}

	while(fin.get(c))
	{
		fout << c;
	}
	
	fin.close();
	fout.close();
   
    return 0;
}




