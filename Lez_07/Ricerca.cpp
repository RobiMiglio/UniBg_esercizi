#include <iostream>

using namespace std;

int cerca(int vett[], int len, int v)
{
	int pos=-1;
	
	if( len> 0 )
		if( vett[0] == v)
		   pos = 0;
		else
		{
			pos = cerca(vett+1, len-1, v);
			if(pos >= 0)
				pos++;
		}
	
	return pos;
}

int main()
{
	const int SIZE=5;
	int v, pos;
	int elenco[SIZE] = {1, 4, 2, 5, 10};

	cout << "Inserire un intero: ";
	cin >> v;
	
	pos = cerca(elenco, SIZE, v);
	if( pos < 0 )
		cout << "Valore non trovato";
	else
		cout << "Posizione: " << pos;
   
   return 0;
}

