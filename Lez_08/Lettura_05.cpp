#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

struct PUNTO
{
	float x;
	float y;
};

PUNTO estraiPunto(char r[])
{
	int virgola=-1;
	int i, l;
	char buffer[50];
	PUNTO p={0,0};
	
	for(i=0; r[i]!= '\0' && virgola < 0; i++)
	{
		if(r[i]==',')
			virgola=i;
	}
	if(virgola >=0)
	{
		l = strlen(r);
		strncpy(buffer, r, virgola);
		buffer[virgola]='\0';
		p.x = atof(buffer);
		strncpy(buffer, r+virgola+1, l-virgola-1);
		buffer[l-virgola-1]='\0';
		p.y = atof(buffer);
	}
	return p;
}

void stampa_Punto(PUNTO p)
{
	cout << "(" << p.x << "," << p.y << ")";
}

int main()
{
	int v, i, letti;
	char nomefile[1000];
	ifstream fin;
	char riga[50];
	PUNTO p;

	cout << "Nome del file: ";
	cin.getline(nomefile, 10000);

	fin.open(nomefile);
	if(fin.fail())
	{
		cout << "Errore Apertura File";
		exit(1);
	}

	fin.getline(riga, 50);
	letti = strlen(riga);
	while(!fin.fail() && letti>0)
	{
		p = estraiPunto(riga);
		stampa_Punto(p);
		cout << endl;
		fin.getline(riga, 50);
		letti = strlen(riga);	
	}
	
	fin.close();
   
    return 0;
}




