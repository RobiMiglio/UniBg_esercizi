// ⚙️ DOMANDA 15 – Lookup Table con puntatori a funzione
//
// Scrivi un programma che simuli una mini-calcolatrice basata su *lookup table*.
// Ogni operazione (somma, sottrazione, moltiplicazione, divisione) è implementata
// come una funzione separata.  Il programma deve:
//
// 1️⃣ Definire un `typedef` per un puntatore a funzione che prenda due `float` e ritorni un `float`.
// 2️⃣ Definire una `struct Operazione` con:
//        - nome (stringa)
//        - simbolo (char)
//        - puntatore a funzione
// 3️⃣ Creare un array statico di `Operazione` che rappresenta la tabella.
// 4️⃣ Chiedere all’utente di inserire due numeri e un simbolo ('+', '-', '*', '/').
// 5️⃣ Cercare nella tabella l’operazione corrispondente e invocare la funzione.
// 6️⃣ Stampare il risultato.
//
// 🔍 DOMANDA TEORICA:
// - Cos’è una lookup table e perché è utile rispetto a uno `switch`?
// - Qual è il vantaggio di associare funzioni a simboli o stringhe tramite puntatori a funzione?
//
// BONUS 💡:
// - Estendi la tabella con una funzione “potenza” (x^y) e falla gestire dinamicamente
//   (aggiunta all’array via `new` invece che staticamente).
//

#include <iostream>
using namespace std;

#define OPERAZIONI_X \
X(SOMMA, '+', a+b) \
X(SOTTRAZIONE, '-', a-b) \
X(MOLTIPLICAZIONE, '*', a*b) \
X(DIVISIONE, '/', a/b)

typedef enum {
    #define X(tipoOperazione, ...) tipoOperazione,
        OPERAZIONI_X
    #undef X
    enumTipoOperazioneMax
} enumTipoOperazione;

const char* arrNomiOps[] = {
    #define X(tipoOperazione, ...) #tipoOperazione,
        OPERAZIONI_X
    #undef X
};

#define X(tipoOperazione, simbolo, formula) \
float op_##tipoOperazione(float a, float b) { return formula; }
OPERAZIONI_X
#undef X

typedef float (*FunzOperazione)(float, float);

typedef struct {
    enumTipoOperazione tipo;
    char simbolo;
    FunzOperazione funzione;
} Operazione;

Operazione arrOps[] = {
    #define X(tipoOperazione, simbolo, formula) \
        { tipoOperazione, simbolo, op_##tipoOperazione },
        OPERAZIONI_X
    #undef X
};

int main() {
    float a, b;
    char simbolo;

    cout << "Inserisci due numeri: ";
    cin >> a >> b;
    cout << "Inserisci simbolo (+ - * /): ";
    cin >> simbolo;

    for (int i = 0; i < enumTipoOperazioneMax; i++) {
        if (arrOps[i].simbolo == simbolo) {
            cout << "Risultato della " << arrNomiOps[i]
                 << " = " << arrOps[i].funzione(a, b) << endl;
            return 0;
        }
    }

    cout << "Simbolo non valido." << endl;
    return 0;
}

/*

Spiegazione teorica

Una lookup table è una tabella di associazione → in questo caso tra un simbolo ('+') e una funzione (op_SOMMA()).

È utile rispetto a uno switch perché:

Evita codice ripetuto e “verboso”.

Permette di aggiungere nuove operazioni semplicemente aggiungendo una riga nella macro X.

È più flessibile e “data-driven”: puoi persino costruirla a runtime.

Associare funzioni a simboli tramite puntatori è la base per simulare un meccanismo di “metodo virtuale” in C — ogni voce della tabella sa cosa fare quando viene chiamata.

*/