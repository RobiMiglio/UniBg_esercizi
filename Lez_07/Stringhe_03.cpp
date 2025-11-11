#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char nome[51];
	char cognome[51];
	char nominativo[102];

	cin.getline(nome, 51);
	cin.getline(cognome, 51);
	strcpy(nominativo, nome);
	strcat(nominativo, " ");
	strcat(nominativo, cognome);
	cout << nominativo << endl;

	cout << "Lungheza del nome: " << strlen(nome);
	cout << endl;	
	cout << "Lungheza del cognome: " << strlen(cognome);
	cout << endl;
	
	if(strcmp(nome, cognome)==0)
		cout << "Nome e Cognome coincidono" << endl;
	if(strcmp(nome, cognome)<0)
		cout << "Il Nome precede il Cognome" << endl;
	if(strcmp(nome, cognome)>0)
		cout << "Il Nome Segue il Cognome" << endl;

   return 0;
}

