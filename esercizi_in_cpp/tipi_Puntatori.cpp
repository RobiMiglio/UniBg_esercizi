/*
===========================================================
   MEGA TEST FINALE — DOMANDA 6
   Argomenti: const, puntatori a costanti, costanti puntatori
===========================================================

Scrivere un breve programma che mostri la differenza tra:

1️⃣ puntatore a costante (`const int *p`)
2️⃣ costante puntatore (`int *const p`)
3️⃣ costante puntatore a costante (`const int *const p`)

Il programma deve:
 - dichiarare una variabile intera `a` e una seconda variabile `b`;
 - utilizzare le tre tipologie di puntatori indicate sopra;
 - provare ad assegnare o modificare valori per verificare
   cosa è lecito e cosa provoca errore;
 - stampare i risultati validi con `cout`.

⚙️ Obiettivo:
dimostrare, tramite codice compilabile e brevi commenti,
quale parte (dato o indirizzo) è costante in ciascun caso.

Esempio atteso (concettualmente):
const int *p1 → non posso modificare il dato, ma posso cambiare a cosa punta  
int *const p2 → posso modificare il dato, ma non cambiare a cosa punta  
const int *const p3 → non posso modificare né il dato, né il puntatore

-----------------------------------------------------------
💭 Domande teoriche:

1️⃣ Spiega la differenza tra “costante puntata” e “puntatore costante”.
2️⃣ In quali casi pratici conviene usare `const` con i puntatori?
   (esempi di sicurezza o interfacce di funzioni)
===========================================================
*/

#include <iostream>

using namespace std;

int main()
{
  int a = 3;
  int b = 30;
  int c = 300;

  //puntatore non costatnte a dati costanti
  const int *ptrA = &a;
  cout << "valore ptrA: " << *ptrA << endl;

  //se proviamo a modificare il valore da errore
  //possiamo invece modificare a cosa punta
  ptrA = &b;
  cout << "valore ptrA: " << *ptrA << endl;

  //puntatore costatnte a dati non costanti
  int *const ptrB = &b;
  cout << "valore ptrB: " << *ptrB << endl;
  //se proviamo a modificare a cosa punta da errore
  //possiamo invece modificare il valore della variabile a cui punta
  (*ptrB)++;
  cout << "valore ptrB: " << *ptrB << endl;

  //puntatore costatnte a dati costanti
  //se proviamo a modificare a cosa punta da errore
  //se proviamo a modificare il valore da errore
  const int *const ptrC = &c;
  cout << "valore ptrC: " << *ptrC << endl;

  return 0;
}

/*
domande teoriche:

1.
costante puntata = 
*il puntatore punta a dati costanti che quindi non ha i permessi per cambiarli
*può però puntare ad una variabile differente perchè esso non è costante

puntatore costante = 
*il puntatore è costante quindi punta e punterà sempre alla stessa variabile
*punta a dati non costanti quindi potrà modificare il valore della variabile a cui punta

puntatore costante a dati costanti = 
*il puntatore punta a dati costanti che quindi non ha i permessi per cambiarli
*il puntatore è costante quindi punta e punterà sempre alla stessa variabile



2.
*conviene puntare a dati costanti quando per esempio lo scopo del puntatore deve essere
 quello di poter leggere la variabile ma non deve assolutamente poter modificarne il valore
 per vari motivi (es sicurezza, oppure semplicemente non è il suo compito..)

*conviene che il puntatore sia costante quando vogliamo essere certi che punti a ciò che 
 vogliamo e che nessuno ne cambi a cosa punta...

*/