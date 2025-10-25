/*

Esercizio 1
Si modifichi il classico programma Hello World:
#include <cstdlib>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
cout << "Hello World !" << endl;
system("PAUSE");
return EXIT_SUCCESS;
}
in modo che il programma stampi N ripetizioni della stringa “HelloWorld” (su righe diverse),
con N inserito dall’utente.
Suggerimenti:
• Usare cin >> per acquisire N.
• Usare un ciclo WHILE con una variabile contatore per gestire le ripetizioni.
• Attenzione a usare cout << con “\n” oppure endl per il ritorno a capo.

*/


#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	int count = 0;
	cout << "quante volte vuoi stampare Hello world??";
	cin >> n;
	
	while(count < n)
	{
		cout << "Hello World !" << endl;
		count++;
	}
	
	return EXIT_SUCCESS;
}