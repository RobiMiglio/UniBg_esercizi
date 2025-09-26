/*
===========================================================
   MEGA TEST FINALE — DOMANDA 7
   Argomenti: array multidimensionali, for annidati,
              break, continue, operatori logici
===========================================================

Scrivere un programma che:

1️⃣ Dichiari una matrice 3x3 di interi.
2️⃣ Chieda all'utente di inserire i valori.
3️⃣ Durante l'inserimento:
    - se l'utente inserisce un valore negativo, ignorarlo (usa continue)
    - se l'utente inserisce 999, interrompere l'inserimento (usa break)
4️⃣ Stampi la matrice inserita.
5️⃣ Calcoli e stampi:
    - la somma di tutti gli elementi
    - la somma della diagonale principale
    - il massimo elemento della matrice

⚙️ Obiettivo:
- Mostrare la gestione di array multidimensionali
- Usare for annidati
- Usare break e continue
- Usare operatori logici

-----------------------------------------------------------
💭 Domande teoriche:

1️⃣ Spiega la differenza tra break e continue in un ciclo.
2️⃣ Cos'è la diagonale principale di una matrice quadrata?
3️⃣ Perché è importante controllare l'interruzione dei cicli quando si usano array e input utente?
===========================================================
*/

#include <iostream>

using namespace std;

int main()
{
    int matrice[3][3] = {0};
    int temp = 0;

    cout << "inserisci valori >=0 e <999 nella matrice";
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout << "\nvalore " << i+1 << "° riga e " << j+1 << "° colonna:";
            cin >> temp;
            if (temp <0)
            {
                cout << "valore < 0 --> non valido, passiamo al prossimo inserimento";
                continue;
            }
            if (temp>=999)
            {
                cout << "valore >= 999 --> inserimento valori terminato";
                break;
            }
            matrice[i][j] = temp;
        }
        if (temp>=999)
        {
            cout << "valore >= 999 --> inserimento valori terminato";
            break;
        }
    }

    int sommaTotale = 0;
    int sommaDiagPrincipale = 0;
    int massimoValoreMatrice = matrice[0][0];
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout << "\nvalore " << i+1 << "° riga e " << j+1 << "° colonna: " << matrice[i][j];
            sommaTotale += matrice[i][j];

            if(i==j)
            {
                sommaDiagPrincipale += matrice[i][j];
            }

            if(matrice[i][j] > massimoValoreMatrice)
            {
                massimoValoreMatrice = matrice[i][j];
            }
        }
    }
    cout << "\nsomma totale: " << sommaTotale << endl;
    cout << "somma diagonale principale: " << sommaDiagPrincipale << endl;
    cout << "massimo val nella matrice: " << massimoValoreMatrice << endl;

    return 0;
}

/*
domande teoriche

1.
con continue = passiamo alla prossima iterazione
con break = terminiamo il ciclo e riprendiamo l'esecuzoine del programma dopo il ciclo

2.
riguarda quegli indici che hanno come riga e colonna lo stesso indice

3.
per avere un rage utile di valori in base allo scopo della matrice..


*/