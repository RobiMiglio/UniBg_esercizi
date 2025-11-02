/*
------------------------------------------------------------
   UNIVERSITÀ — ESERCIZIO: IL MISTERO DEI NUMERI EQUILIBRATI
------------------------------------------------------------

OBIETTIVO:
Scrivere un programma in C++ (stile procedurale) che trovi tutti
i numeri "equilibrati" in un intervallo dato.

DEFINIZIONE:
Un numero si dice "equilibrato" se la somma delle sue cifre pari
è uguale alla somma delle sue cifre dispari.

ESEMPI:
- 242 → (2 + 4) = 6, (cifre dispari: 0) → non equilibrato
- 351 → (3 + 1) = 4, (5) = 5 → non equilibrato
- 1236 → (2 + 6) = 8, (1 + 3) = 4 → non equilibrato
- 1223 → (2 + 2) = 4, (1 + 3) = 4 → equilibrato ✅

------------------------------------------------------------
REQUISITI DEL PROGRAMMA:

1. Il programma deve:
   - chiedere all’utente due numeri interi positivi a e b (con a < b);
   - trovare tutti i numeri equilibrati tra a e b (inclusi);
   - stamparli in ordine crescente.

2. Deve utilizzare:
   - almeno una funzione (es. bool equilibrato(int n));
   - un vettore per memorizzare i numeri trovati;
   - solo cicli "for".

3. È vietato:
   - usare string;
   - usare puntatori;
   - usare funzioni di librerie non standard (cmath, ecc.) 
     tranne se strettamente necessarie.

------------------------------------------------------------
OUTPUT ATTESO:
Elenco dei numeri equilibrati compresi tra a e b (se presenti).

------------------------------------------------------------
SUGGERIMENTO:
Definire una funzione ausiliaria:
    bool equilibrato(int n);
che ritorni true se n è equilibrato, false altrimenti.

*/

#include <iostream>

using namespace std;

#define ORDINAMENTO_CRESCENTE 0
#define ORDINAMENTO_DECRESCENTE 1

bool equilibrato(int n)
{
   int cifra = 0;
   int restante = n;

   int sommaNumeriPari = 0;
   int sommaNumeriDispari = 0;

   for(int i=0; restante>0; i++)
   {
      cifra = restante % 10;  // prendo l'ultima cifra di "restante"
      if(cifra%2==0)
      {
         sommaNumeriPari += cifra;
      }
      else
      {
         sommaNumeriDispari += cifra;
      }
      restante /= 10; // rimuovo l'ultima cifra
   }

   return(sommaNumeriPari==sommaNumeriDispari);
}

void maggiorazioneDimensioneArray(int **arr, int newDim)
{
   // Crea un nuovo array con la nuova dimensione
   int *nuovoArray = new int[newDim];

   // Copia i valori già presenti
   for (int i = 0; i < newDim; i++)
   {
     if((*arr)[i]==0)
     {
        nuovoArray[i] = 0;
     }
     else
     {
        nuovoArray[i] = (*arr)[i];
     }
   }

   // Libera il vecchio array
   delete[] *arr;

   // Aggiorna il puntatore al nuovo array
   *arr = nuovoArray;
}

void stampaDimostrazioneNumeroEquilibrato(int n)
{
   int sizeArrayCifrePari = 0;
   int sizeArrayCifreDispari = 0;
   int *arrayCifrePari = new int[sizeArrayCifrePari];
   int *arrayCifreDispari = new int[sizeArrayCifreDispari];

   int cifra = 0;
   int restante = n;
   int sommaNumeriPari = 0;
   int sommaNumeriDispari = 0;

   for(int i=0; restante>0; i++)
   {
      cifra = restante % 10;  // prendo l'ultima cifra di "restante"
      if(cifra%2==0)
      {
         sizeArrayCifrePari++;
         maggiorazioneDimensioneArray(&arrayCifrePari, sizeArrayCifrePari);
         arrayCifrePari[sizeArrayCifrePari-1] = cifra;
         sommaNumeriPari += cifra;
      }
      else
      {
         sizeArrayCifreDispari++;
         maggiorazioneDimensioneArray(&arrayCifreDispari, sizeArrayCifreDispari);
         arrayCifreDispari[sizeArrayCifreDispari-1] = cifra;
         sommaNumeriDispari += cifra;
      }
      restante /= 10; // rimuovo l'ultima cifra
   }

   //stampa somma pari
   cout << arrayCifrePari[0];
   for(int i=1; i<sizeArrayCifrePari; i++)
   {
      cout << " + " << arrayCifrePari[i];
   }
   cout << " = " << sommaNumeriPari << "\t\t";

   //stampa somma dispari
   cout << arrayCifreDispari[0];
   for(int i=1; i<sizeArrayCifreDispari; i++)
   {
      cout << " + " << arrayCifreDispari[i];
   }
   cout << " = " << sommaNumeriDispari << "\t\t";
}

void bubbleSort(int *array, int size, int ordinamento)
{
   bool scambiato = 0;
   int limite = size -1;
   int ultimoScambio = 0;
   int valoreTemporaneo = 0;

   do
   {
      scambiato = 0;
      ultimoScambio = 0;

      for(int i=0; i<limite; i++)
      {
         if((ordinamento == ORDINAMENTO_CRESCENTE) ? (array[i] > array[i+1]) : (array[i] < array[i+1]))
         {
            valoreTemporaneo = array[i];
            array[i] = array[i+1];
            array[i+1] = valoreTemporaneo;
            scambiato = 1;
            ultimoScambio = i;
         }
      }
      limite = ultimoScambio;
   }while(scambiato && limite>0);
}

int main()
{

   int a = 0;
   int b = 0;

   cout << "inserire due numeri interi positivi a e b (con a < b)" << endl;;
   do
   {
      cout << "a: ";
      cin >> a;
      if(a<0)
      {
         cout << "valore non corretto - deve essere un numero positivo" << endl;
      }
   }while(a<0);

   cout << endl;

   do
   {
      cout << "b: ";
      cin >> b;
      if(b<0 || b<a)
      {
         cout << "valore non corretto - deve essere un numero positivo e maggiore di a (" << a << ")" << endl;
      }
   }while(b<0 || b<a);

   cout << endl;

   int quantitaNumeriEquilibratiTrovati = 0;
   int *arrayNumeriEquilibrati = new int[quantitaNumeriEquilibratiTrovati];

   //riempimento array contenente i numeri equilibrati trovati
   for(int i=a; i<=b; i++)
   {
      if(equilibrato(i))
      {         
         quantitaNumeriEquilibratiTrovati++;

         maggiorazioneDimensioneArray(&arrayNumeriEquilibrati, quantitaNumeriEquilibratiTrovati);

         arrayNumeriEquilibrati[quantitaNumeriEquilibratiTrovati-1] = i; //il -1 serve perchè gli array in C++ sono 0-based
      }
   }

   //chiusura programma se non è stato trovato nessun numero equilibrato
   if(quantitaNumeriEquilibratiTrovati==0)
   {
      cout << "nessun numero equilibrato trovato tra " << a << "e " << b << endl;
      return 0;
   }

   //riordinamento in ordine crescente array
   bubbleSort(arrayNumeriEquilibrati, quantitaNumeriEquilibratiTrovati, ORDINAMENTO_CRESCENTE);

   //stampa
   cout << "stampa e dimostrazione numeri equilibrati trovati" << endl;
   cout << "numero\t\tsomma num pari\t\tsomma num dispari" << endl;
   for(int i=0; i<quantitaNumeriEquilibratiTrovati; i++)
   {
      cout << arrayNumeriEquilibrati[i] << "\t\t";
      stampaDimostrazioneNumeroEquilibrato(arrayNumeriEquilibrati[i]);
      cout << endl;
   }
   cout << endl << endl;

   return 0;
}