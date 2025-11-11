#include <iostream>

using namespace std;

void confronto(float x, float y, 
			   float min, float max)
{
	if(x > y)
	{
		min = y;
		max = x;
	}
	else
	{
		min = x;
		max = y;
	}
	return;
}

int main()
{
	float v1, v2;
	float min=0, max=0;

	cout << "Inserire valore 1: ";
	cin >> v1;
	cout << "Inserire valore 1: ";
	cin >> v2;
	
	confronto(v1, v2, min, max);

	cout << "min: " << min 
	     << " max: " << max;
   
   return 0;
}

