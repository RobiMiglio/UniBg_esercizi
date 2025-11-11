#include <iostream>

using namespace std;

struct PUNTO
{
	float x;
	float y;
};

void stampa_punto(PUNTO pt)
{
	cout << "(" << pt.x << ","
	     << pt.y << ")";
}

int main()
{
	PUNTO p1, p2;

	cout << "Inserire x: ";
	cin >> p1.x;
	cout << "Inserire y: ";
	cin >> p1.y;	
	stampa_punto(p1); cout << endl;
	
	p2.x = p1.y;
	p2.y = p1.x;
	stampa_punto(p2); cout << endl;


	p1 = p2;
	stampa_punto(p1); cout << endl;

   return 0;
}

