// 🧠 DOMANDA 1 – Manipolazione di stringhe C
//
// ✅ OBIETTIVO:
//  - Leggere una parola (max 30 char)
//  - Stampare:
//      → lunghezza (strlen)
//      → parola in maiuscolo
//      → parola rovesciata
//
// 🔍 DOMANDA TEORICA:
//  - Cosa succede se dimentichi il terminatore '\0'?
//  - Differenza tra strlen() e sizeof()

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

// 🔹 Funzione che inverte una stringa in-place
void invertiParola(char parola[]) {
    int len = strlen(parola);
    for (int i = 0; i < len / 2; i++) {
        char temp = parola[i];
        parola[i] = parola[len - i - 1];   // -1 per non toccare il terminatore '\0'
        parola[len - i - 1] = temp;
    }
}

int main() {
    char parola[31];   // 🔸 30 caratteri + '\0' finale obbligatorio

    cout << "Inserisci una parola (max 30 caratteri): ";
    cin >> parola;

    // 1️⃣ Lunghezza
    cout << "\nLunghezza (strlen): " << strlen(parola) << endl;

    // 2️⃣ Parola in maiuscolo
    char lunghezzaParola = strlen(parola);
    cout << "Parola in maiuscolo: ";
    for (int i = 0; i < lunghezzaParola; i++)
        cout << (char)toupper(parola[i]);
    cout << endl;

    // 3️⃣ Parola rovesciata
    char copia[31];
    strcpy(copia, parola);   // 🔸 Creo una copia per non perdere l’originale
    invertiParola(copia);
    cout << "Parola rovesciata: " << copia << endl;

    return 0;
}

/*
=========================================================
🧠 SPIEGAZIONE TEORICA

🔹 strlen(s)
   - Conta i caratteri fino al terminatore '\0'
   - Non include '\0' nel conteggio.

🔹 sizeof(s)
   - Restituisce la dimensione in byte dell’array (es. 31 se dichiari char[31])

🔹 Terminatore '\0'
   - È un byte con valore 0 che segnala la fine della stringa.
   - Se manca, funzioni come strlen o strcpy continueranno a leggere memoria a caso → comportamento indefinito / crash.

🔹 toupper(c)
   - Trasforma un carattere minuscolo in maiuscolo.
   - Serve includere <cctype>.

=========================================================
*/
