/*

Esercizio 2
Calcolare l’indice di massa corporea (BMI) a partire da altezza (h) e peso (m) immessi
dall’utente, specificando il tipo di situazione (sottopeso, normale, ecc…). Formula: BMI =
m / h2 (m in kg, h in metri).
Si faccia riferimento alla seguente tabella:


Suggerimenti:
• Chiedere all’utente altezza e peso con cout << + cin >> con variabili float
• Usare una sequenza di IF per determinare la classe in base al BMI
• Fare attenzione a gestire un input errato da parte dell’utente
(altezza e/o peso uguali a zero o negativi)

*/

#include <iostream>

using namespace std;


int main()
{

	float altezza = 0;
	float peso = 0;
	float bmi = 0;
	
	cout << "calcolo indice di massa corporea (BMI)" << endl;
	
	do
	{
		cout <<"inserire l'altezza: ";
		cin >> altezza;
		if(altezza<=0)
		{
			cout << "valore non corretto, deve essere >= 0" << endl;
		}
	}while(altezza<=0);
	
		do
	{
		cout <<"inserire il peso: ";
		cin >> peso;
		if(peso<=0)
		{
			cout << "valore non corretto, deve essere >= 0" << endl;
		}
	}while(peso<=0);

	bmi = peso / (altezza * altezza);
	cout << "valore di bmi: " << bmi << " --> ";
	if(bmi < 18.5)
	{
		cout << "sottopeso" << endl;
	}
	else if ((bmi>=18.5) && (bmi<25))
	{
		cout << "normale" << endl;
	}
	else if ((bmi>=25) && (bmi<30))
	{
		cout << "sovrappeso" << endl;
	}
	else if ((bmi>=30) && (bmi<40))
	{
		cout << "obeso" << endl;
	}
	else if (bmi>40)
	{
		cout << "obeso grave" << endl;
	}	

	return 0;
}