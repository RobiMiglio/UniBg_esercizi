// 🧠 DOMANDA 10 – Array statici e automatici
// Scrivi un programma che definisca una funzione `testArray()` che:
//   - dichiari un array AUTOMATICO di 3 interi inizializzati a 0
//   - dichiari un array STATICO di 3 interi inizializzati a 0
//   - ad ogni chiamata, incrementi tutti gli elementi di entrambi gli array
//   - stampi il loro contenuto
//
// Poi nel main() chiama la funzione 3 volte.
//
// 🔍 DOMANDA TEORICA:
// Spiega le differenze tra un array automatico e uno statico in termini di:
//   - allocazione (dove risiedono in memoria?)
//   - tempo di vita (quando vengono creati e distrutti?)
//   - inizializzazione (quante volte viene eseguita?)
//
// BONUS: perché un array statico può essere utile per conservare lo stato
//         di una funzione tra più chiamate?

#include <iostream>
using namespace std;

void testArray() {
    // 🔹 Array AUTOMATICO → si crea e si distrugge ad ogni chiamata
    int arrAuto[3] = {0, 0, 0};

    // 🔸 Array STATICO → esiste una sola copia in tutta l’esecuzione
    static int arrStatic[3] = {0, 0, 0};

    // Incremento di tutti gli elementi
    for (int i = 0; i < 3; i++) {
        arrAuto[i]++;
        arrStatic[i]++;
    }

    // Stampa
    cout << "Array automatico: ";
    for (int i = 0; i < 3; i++) cout << arrAuto[i] << " ";
    cout << endl;

    cout << "Array statico:    ";
    for (int i = 0; i < 3; i++) cout << arrStatic[i] << " ";
    cout << endl;

    cout << "--------------------------" << endl;
}

int main() {
    for (int i = 0; i < 3; i++) {
        cout << "Chiamata " << i + 1 << ":" << endl;
        testArray();
    }
    return 0;
}

/*
📘 SPIEGAZIONE TEORICA

✅ ARRAY AUTOMATICO
- Allocazione: nello **stack** (memoria automatica).
- Tempo di vita: creato all’ingresso della funzione, distrutto all’uscita.
- Inizializzazione: eseguita ad ogni chiamata della funzione.
- Quindi riparte sempre da zero.

✅ ARRAY STATICO
- Allocazione: nel **data segment** (memoria statica globale).
- Tempo di vita: creato una sola volta, rimane valido fino alla fine del programma.
- Inizializzazione: eseguita solo la prima volta (alla definizione).
- Mantiene il proprio valore tra più chiamate della funzione.

💡 BONUS:
Un array statico è utile quando vogliamo che una funzione
“ricordi” informazioni da una chiamata all’altra — ad esempio
per contatori, buffer circolari o filtri numerici (come negli ADC).
*/
