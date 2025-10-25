/*

Esercizio 8
Estendere l’esercizio precedente in modo da supportare i seguenti tipi di figura (l’utente
seleziona il tipo ed immette i parametri della figura all’avvio del programma)
Quadrato (parametro: lato)
***
***
***
Rettangolo (parametri: base, altezza)
****
****
****
Triangolo Rettangolo (parametri: base, altezza)
********
******
****
**
Suggerimenti: Attenzione al triangolo!
Usare una variabile di tipo float per mantenere la lunghezza della riga corrente e
decrementarla di (float)(base/altezza) a ogni riga.
*/


#include <iostream>

using namespace std;

int main()
{
	int altezza = 0;
	int base = 0;
	int lato = 0;
	int scelta = 0;
	
    do 
    {
	    cout << "selezionare 1 per il quadrato, 2 per il rettangolo e 3 per il triangolo rettangolo: ";
	    cin >> scelta;
    
	    if(scelta == 1)
	    {
	    	do
	    	{
	    		cout << "inserire valore positivo per il lato: ";
	    		cin >> lato;
	    		if(lato<=0)
	    		{
	    			cout << "valore non corretto" << endl;
	    		}
	    	}while(lato<=0);
        }
	    else if((scelta == 2) || (scelta == 3))
	    {
	    	do
	    	{
	    		cout << "inserire valore positivo per l'altezza: ";
	    		cin >> altezza;
	    		if(altezza<=0)
	    		{
	    			cout << "valore non corretto" << endl;
	    		}
	    	}while(altezza<=0);
        
	    	do
	    	{
	    		cout << "inserire valore positivo per la base: ";
	    		cin >> base;
	    		if(base<=0)
	    		{
	    			cout << "valore non corretto" << endl;
	    		}
	    	}while(base<=0);
	    }
        else
        {
            cout << "valore non corretto - riprovare" << endl;
        }
    }while((scelta<1) || (scelta>3));
		
	int contatoreRighe = 0;
	int contatoreColonne = 0;
	float rigaCorrente = base;
	
	if(scelta ==1)
	{
		while(contatoreRighe<lato)
		{
			while(contatoreColonne<lato)
			{
				cout << "# ";
				contatoreColonne++;
			}
			cout << endl;
			contatoreColonne =0;
			contatoreRighe++;
		}
	}
	else if(scelta == 2)
	{
		while(contatoreRighe<altezza)
		{
			while(contatoreColonne<base)
			{
				cout << "# ";
				contatoreColonne++;
			}
			cout << endl;
			contatoreColonne =0;
			contatoreRighe++;
		}
	}
	else if(scelta == 3)
	{
		while(contatoreRighe<altezza)
		{
			while(contatoreColonne<rigaCorrente)
			{
				cout << "# ";
                contatoreColonne++;
			}
			cout << endl;
			contatoreColonne =0;
            rigaCorrente -= (float)base/altezza;
			contatoreRighe++;
		}
	}

	return 0;
}