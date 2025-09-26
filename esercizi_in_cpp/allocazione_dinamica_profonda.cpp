// ⚙️ DOMANDA 13 – Allocazione dinamica con struct e copia profonda
//
// Scrivi un programma che gestisca un elenco dinamico di sensori.
// Ogni sensore è una struct con:
//    - nome (stringa dinamica char*)
//    - valore (float)
//
// Il programma deve:
//
// 1️⃣ Chiedere quanti sensori creare.
// 2️⃣ Allocare dinamicamente un array di `Sensore`.
// 3️⃣ Per ogni sensore:
//        - chiedere il nome (usando new char[])
//        - chiedere il valore.
// 4️⃣ Implementare una funzione `copiaSensori()` che esegua una **copia profonda**:
//        - alloca un nuovo array di struct
//        - copia anche le stringhe (non solo i puntatori!)
// 5️⃣ Dimostrare che modificare il nome o valore del nuovo array
//        non altera quello originale.
// 6️⃣ Liberare tutta la memoria (sia array che stringhe).
//
// 🔍 DOMANDA TEORICA:
// - Perché serve la copia profonda quando una struct contiene puntatori?
// - Quali errori comuni si possono generare se si copia solo i puntatori (shallow copy)?
//
// BONUS 💡: implementa anche una funzione `stampaSensori()`
//           per mostrare ordinatamente i dati dei sensori.
//
#include <iostream>
#include <cstring> // per strcpy
using namespace std;

struct Sensore {
    char* nome;
    float valore;
};

Sensore* copiaProfonda(Sensore* s, int quantita) {
    Sensore* nuovo = new Sensore[quantita];
    for (int i = 0; i < quantita; i++) {
        nuovo[i].nome = new char[30];
        strcpy(nuovo[i].nome, s[i].nome); // copia vera
        nuovo[i].valore = s[i].valore;
    }
    return nuovo;
}

int main() {
    int numeroSensori;
    cout << "Inserisci il numero di sensori da gestire: ";
    cin >> numeroSensori;

    Sensore* sensori = new Sensore[numeroSensori];

    for (int i = 0; i < numeroSensori; i++) {
        sensori[i].nome = new char[30];
        cout << "Nome del sensore " << i + 1 << ": ";
        cin >> sensori[i].nome;
        cout << "Valore del sensore " << i + 1 << ": ";
        cin >> sensori[i].valore;
    }

    Sensore* copia = copiaProfonda(sensori, numeroSensori);

    cout << "\n--- Array originale vs copia ---\n";
    for (int i = 0; i < numeroSensori; i++) {
        cout << sensori[i].nome << " (" << sensori[i].valore << ")"
             << "\t\t" << copia[i].nome << " (" << copia[i].valore << ")\n";
    }

    // modifica solo la copia
    strcpy(copia[0].nome, "pippo");
    copia[0].valore = 99.9;

    cout << "\n--- Dopo modifica della copia ---\n";
    for (int i = 0; i < numeroSensori; i++) {
        cout << sensori[i].nome << " (" << sensori[i].valore << ")"
             << "\t\t" << copia[i].nome << " (" << copia[i].valore << ")\n";
    }

    for (int i = 0; i < numeroSensori; i++) {
        delete[] sensori[i].nome;
        delete[] copia[i].nome;
    }
    delete[] sensori;
    delete[] copia;

    return 0;
}
