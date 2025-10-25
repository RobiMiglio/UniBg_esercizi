
/*

Scrivere un programma in linguaggio C che lette dallo standard input
due sequenze vettoriali ordinate di interi V1[n], V2[m] ne crei una terza
V3[n+m] anch’essa ordinata, che contenga tutti gli elementi di V1 e di
V2.
Esempio: V1 = < 1, 2, 5, 6 >; V2 = < 3, 4, 5, 7, 9 >; allora V3 =
<1, 2, 3, 4, 5, 5, 6, 7, 9 >

*/

#include <iostream>

using namespace std;

#define N 3
#define M 4

void stampa(int *vettore, int size)
{
	for(int i=0; i<size; i++)
	{
		cout << vettore[i] << " ";
	}
	cout << endl;
}


int main()
{
	int V1[N];
	int V2[M];
	int V3[N+M];
	
	int nonValido = 0;
	
	cout << "inserire i numeri in ordine crescente dei vettori V1 e V2" << endl;
	
	for(int i=0; i<N; i++)
	{
		do
		{
			nonValido = 0;
			cout << "inserire il " << i+1 << "° elemento dell'array V1: ";
			cin >> V1[i];
			if(i>0 && V1[i] < V1[i-1])
			{
				nonValido = 1;
				cout << "numero inferiore al precedente - non valido" << endl;
			}
		}while(nonValido);		
	}

	for(int i=0; i<M; i++)
	{
		do
		{
			nonValido = 0;
			cout << "inserire il " << i+1 << "° elemento dell'array V2: ";
			cin >> V2[i];
			if(i>0 && V2[i] < V2[i-1])
			{
				nonValido = 1;
				cout << "numero inferiore al precedente - non valido" << endl;
			}
		}while(nonValido);		
	}
	
	int indiceV1 = 0;
    int indiceV2 = 0;
	
	for(int i=0; i<(N+M); i++)
	{
		if((indiceV1<N)&&(indiceV2<M))
		{
			if(V1[indiceV1] < V2[indiceV2])
			{
				V3[i] = V1[indiceV1];
                indiceV1++;
			}
			else
			{
				V3[i] = V2[indiceV2];
                indiceV2++;
			}
		}
		else if((indiceV1>=N) && (indiceV2<M))
		{
			V3[i] = V2[indiceV2];
            indiceV2++;
		}
		else if((indiceV1<N) && (indiceV2>=M))
		{
			V3[i] = V1[indiceV1];
            indiceV1++;
		}		
	}
	
	cout << "sequenza di V1: ";
	stampa(V1, N);

	cout << "sequenza di V2: ";
	stampa(V2, M);
	
	cout << "sequenza di V3: ";
	stampa(V3, (N+M));

	return 0;
}