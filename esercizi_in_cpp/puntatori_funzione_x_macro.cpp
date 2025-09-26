// 🎯 DOMANDA 6 – Puntatori a funzione
// Scrivi un programma che definisca quattro funzioni:
//   add, sub, mul, divi — ognuna prende due double e restituisce un double.
// Poi:
//   - Crea un array di puntatori a funzione che contenga i riferimenti a queste funzioni.
//   - Chiedi all'utente quale operazione vuole eseguire (0=add, 1=sub, 2=mul, 3=div).
//   - Esegui la funzione corretta usando il puntatore scelto.
//
// BONUS: Spiega perché un array di puntatori a funzione può essere utile
// in un programma che simula un menù o un “metodo virtuale” in stile OOP.


#include <iostream>

using namespace std;

#define OPS_X \
X(ADD, a+b) \
X(SUB, a-b) \
X(MUL, a*b) \
X(DIV, a/b)

typedef enum 
{
    #define X(tipo, formula) tipo,
       OPS_X
    #undef X
    enumOpsMax
}enumOps;

const char *arrNomi[] = 
{
    #define X(tipo, formula) #tipo,
       OPS_X
    #undef X   
};

typedef struct Ops 
{
    double(*pOps)(double a, double b);
}Ops;


//generatore di funzioni
#define X(tipo, formula) \
  double op_##tipo(double a, double b) {return formula;}
  OPS_X
#undef X


int main()
{
    Ops operazioniSemplici[enumOpsMax] = {
        #define X(tipo, formula) { op_##tipo },
            OPS_X
        #undef X
    };

    double a = 0;
    double b = 0;
    cout << "inserisci due numeri (ad ogni inserimento premere invio):" << endl;
    cin >> a;
    cin >> b;
    int scelta = 0;
    cout << "Scegli operazione (0=ADD, 1=SUB, 2=MUL, 3=DIV): ";
    cin >> scelta;

    cout << "Operazione scelta: " << arrNomi[scelta]
         << "\nRisultato: " << operazioniSemplici[scelta].pOps(a, b) << endl;

    return 0;
}