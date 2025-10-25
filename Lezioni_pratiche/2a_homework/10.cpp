/*

Esercizio 10
Date le coordinate x e y di 3 punti (P1, P2, P3), verificare se i punti P2 e P3 sono
equidistanti dal punto P1 (quindi se i punti P2 e P3 si trovano su una circonferenza con
centro nel punto P1). La verifica viene fatta controllando se i quadrati delle distanze
P1-P2 e P1-P3 sono uguali.
Input: coordinate x ed y dei 3 punti
Output: messaggio che indica se i punti sono equidistanti oppure no
Oss: i tipi di dato float o double sono approssimazioni finite dei numeri reali;
per confrontare due valori float o (double) è consigliabile impostare una verifica di
appartenenza a un intervallo, invece che un semplice test di uguaglianza.
Es:
(distq12-distq13<TOL && distq12-distq13>-TOL)
dove TOL sarà una costante definita all'inizio del file come, es.: #define TOL 0.0001

*/

#include <iostream>
#include <cmath> // per pow() e fabs()

using namespace std;

#define TOL 0.0001

int main()
{
	float coordinateX[3] = {0};
	float coordinateY[3] = {0};
	
	//imput coordinate dei 3 punti
	for(int i=0; i<3; i++)
	{
		do
		{
			cout << "inserire coordinata X per il " << i+1 << "° punto (numero positivo): ";
			cin >> coordinateX[i];
			if(coordinateX[i] <0)
			{
				cout << "valore non valido - riprovare" << endl;
			}
		}while(coordinateX[i] <0);

		do
		{
			cout << "inserire coordinata Y per il " << i+1 << "° punto (numero positivo): ";
			cin >> coordinateY[i];
			if(coordinateY[i] <0)
			{
				cout << "valore non valido - riprovare" << endl;
			}
		}while(coordinateY[i] <0);
	}
	
	//verifica coordinate 
	
    // calcolo dei quadrati delle distanze da P1
    float distq12 = pow(coordinateX[1] - coordinateX[0], 2) + pow(coordinateY[1] - coordinateY[0], 2);
    float distq13 = pow(coordinateX[2] - coordinateX[0], 2) + pow(coordinateY[2] - coordinateY[0], 2);

    // verifica di equidistanza con tolleranza
    if (fabs(distq12 - distq13) < TOL)
    {
        cout << "I punti P2 e P3 sono equidistanti da P1." << endl;
    }
    else
	{
		cout << "I punti P2 e P3 NON sono equidistanti da P1." << endl;
	}
        

	return 0;
}