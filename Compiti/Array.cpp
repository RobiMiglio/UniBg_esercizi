/* ===============================================================
   Esercizio: Array
   Scadenza: 6 gennaio 2026 - 22:59

   Istruzioni:
   Scrivere un programma per gestire un array di numeri interi.

   In particolare, il problema si occupa di generare un array di 
   50 numeri casuali compresi fra 1 e 100 e offrire a menu le seguenti scelte:

   1. Calcolare la media
   2. Visualizzare il massimo
   3. Visualizzare il minimo
   4. Rigenerare l’array
   5. Visualizzare i valori che distano meno di 4 dalla media
   6. Calcolare la moda
   7. Uscire dal programma
   =============================================================== */


#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define SIZE 50

double calcolaMedia(int *array, int size)
{
    int somma = 0;
    for (int i = 0; i < size; i++)
        somma += array[i];
    return (double)somma / size;
}

int calcolaValoreMassimo(int *array, int size)
{
   int valoreMassimo = array[0];
   for(int i=1; i<size; i++)
   {
      if(array[i] > valoreMassimo)
      {
         valoreMassimo = array[i];
      }
   }
   return valoreMassimo;
}

int calcolaValoreMinimo(int *array, int size)
{
   int valoreMinimo = array[0];
   for(int i=1; i<size; i++)
   {
      if(array[i] < valoreMinimo)
      {
         valoreMinimo = array[i];
      }
   }
   return valoreMinimo;
}

void rigeneraArray(int *array, int size)
{
   for(int i=0; i<size; i++)
   {
      array[i] = (rand()%100)+1;
   }
}

void stampaValoriDistantiDaMedia(int *array, int size, int distanza)
{
   double media = calcolaMedia(array, size);
   bool isAlmenoUnValore = 0;
   int distanzaDaMedia = 0;
   cout << "i valori che distano meno di " << distanza << " dalla media (che è: " << media << ") sono: ";
   for(int i=0; i<size; i++)
   {
      if(array[i]>=media)
      {
         distanzaDaMedia = array[i]-media;
      }
      else
      {
         distanzaDaMedia = media-array[i];
      }
      if(distanzaDaMedia<4)
      {
         cout << array[i] << " ";
         isAlmenoUnValore = 1;
      }
   }
   if(isAlmenoUnValore==0)
   {
      cout << "nessun valore trovato";
   }
   cout << endl;
}

void stampaModa(int *array, int size)
{
    int maxFrequenza = 0;

    // Trova la frequenza massima
    for (int i = 0; i < size; i++) 
    {
        int conta = 0;
        for (int j = 0; j < size; j++) 
        {
            if (array[i] == array[j])
            {
               conta++;
            }
        }
        if (conta > maxFrequenza)
        {
         maxFrequenza = conta;
        }
    }

    cout << "Valori con frequenza massima (" << maxFrequenza << "): ";

    // Stampa tutte le mode
    for (int i = 0; i < size; i++) 
    {
        int conta = 0;
        for (int j = 0; j < size; j++) 
        {
            if (array[i] == array[j])
            {
               conta++;
            }
        }

        if (conta == maxFrequenza) 
        {
            bool giaStampato = false;
            for (int k = 0; k < i; k++) 
            {
                if (array[k] == array[i])
                {
                  giaStampato = true;
                }
            }
            if (!giaStampato)
            {
               cout << array[i] << " ";
            }
        }
    }
    cout << endl;
}

void stampaArray(int *array, int size)
{
   for(int i=0; i<size; i++)
   {
      cout << array[i] << " ";
   }
   cout << endl;
}

int main()
{
   int arrayNumeriCasuali[SIZE];
   srand(time(NULL));
   //inizializzazione array con numeri casuali
   rigeneraArray(arrayNumeriCasuali, SIZE);

   cout << "valori array: ";
   stampaArray(arrayNumeriCasuali, SIZE);

   int scelta = 0;
   bool uscireProgramma = 0;
   do
   {
      cout << "\nMenu: " << endl
           << "1. Calcolare la media" << endl
           << "2. Visualizzare il massimo" << endl
           << "3. Visualizzare il minimo" << endl
           << "4. Rigenerare l'array" << endl
           << "5. Visualizzare i valori che distano meno di 4 dalla media" << endl
           << "6. Calcolare la moda" << endl
           << "7. Uscire dal programma" << endl
           << "inserire il valore corrispondente all'azione che si vuole intraprendere: ";
      cin >> scelta;
      switch(scelta)
      {
         case 1: 
            cout << "Media: " << calcolaMedia(arrayNumeriCasuali, SIZE) << endl;
            break;
         case 2: 
            cout << "Valore massimo: " << calcolaValoreMassimo(arrayNumeriCasuali, SIZE) << endl;
            break;
         case 3: 
            cout << "Valore minimo: " << calcolaValoreMinimo(arrayNumeriCasuali, SIZE) << endl;
            break;
         case 4: 
            rigeneraArray(arrayNumeriCasuali, SIZE);
            cout << "valori array dopo rigenerazione con numeri casuali: ";
            stampaArray(arrayNumeriCasuali, SIZE);
            break;
         case 5: 
            stampaValoriDistantiDaMedia(arrayNumeriCasuali, SIZE, 4);
            break;
         case 6: 
            stampaModa(arrayNumeriCasuali, SIZE);
            break;
         case 7: 
            uscireProgramma = 1;
            cout << "exit" << endl << endl;
            break;
         default: 
            cout << "valore non valido - inserire un valore presente nel menu" << endl;
            break;
      }
   }while(!uscireProgramma);

   return 0;
}