/*
esercizio 2

Si considerino due matrici di interi A e B, di uguali dimensioni (R e C, costanti, che indicano il
numero di righe e colonne).
Diciamo che A domina B se, confrontando i valori in posizioni corrispondenti, risulta che il numero
dei valori in A maggiori dei corrispondenti valori in B è più grande del numero di quelli di B maggiori
dei corrispondenti in A e inoltre gli elementi corrispondenti non sono mai uguali (se due elementi
corrispondenti sono uguali la dominanza non è definita).
Si proponga un prototipo per la funzione domina(...) che riceve le matrici come parametri e
restituisce 1 se la prima domina la seconda, -1 se la seconda domina la prima, 0 altrimenti.
Si dia una descrizione breve ma precisa di un algoritmo per implementare la funzione.
Si codifichi la funzione in C.

*/

int confrontoMatrici(int matriceA[R][C], int matriceB[R][C])
{
	int dominaA = 0;
	int dominaB = 0;
	
	for(int i=0; i<R; i++)
	{
		for(int k=0; k<C; k++)
		{
            if(matriceA[i][k] == matriceB[i][k])
            {
                return 0;
            }
			else if(matriceA[i][k] > matriceB[i][k])
			{
				dominaA += 1;
			}
			else if(matriceB[i][k] > matriceA[i][k])
			{
				dominaB += 1;
			}
		}
	}
	
	if(dominaA > dominaB)
	{
		return 1;
	}
	else if(dominaB > dominaA)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}


/*
breve descrizione algoritmo funzione
-si creano due variabili che tengono la somma delle volte in cui un dato valore in una data posizone nella matrice domina sul rispettivo dell'altra matrice
-con un ciclo for scorriamo tutte le posizioni della matrice e in ogni posizione controlliamo i valori nelle due matrici, confrontandoli e aggionrando quindi le variabili 
 appena create
-alla fine confrontiamo le due variabili e ritorniamo il valore come da specifica
*/