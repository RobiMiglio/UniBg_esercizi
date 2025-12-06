/*
Scrivere un programma che acquisita una frase permetta a scelta dell'utente di (attraverso un menu):

1. Stamparla
2. Stamparla invertita
3. Stampare la stringa in maiuscolo
4. Stamparla eliminando gli spazi
5. Contare il numero di parole presenti
6. Permetta di sostituire un carattere con un altro
7. Calcoli la ricorrenza di una determinata lettera dell'alfabeto sia essa minuscola o maiuscola
8. Uscire dal programma
*/

#include <iostream>
#include <cstring>

using namespace std;

#define DIM_MAX_FRASE 200

void stampaMenu()
{
    cout << endl << "*******************" << endl << "Menu" << endl << "*******************" << endl << endl;
    cout << "1 - stampa frase" << endl
         << "2 - stampa frase invertita" << endl
         << "3 - stampa frase in maiuscolo" << endl
         << "4 - stampa frase eliminando spazi" << endl
         << "5 - conta numero di parole presenti nella frase" << endl
         << "6 - sostituisci carattere" << endl
         << "7 - calcola ricorrenza di una lettera nella frase" << endl
         << "8 - uscire dal programma" << endl;
}

void stampaFrase(const char frase[])
{
    int i=0;
    while (frase[i] != '\0')   // finché non troviamo il terminatore
    {
        cout << frase[i];
        i++;
    }
    cout << endl;
}

void stampaFraseInvertita(const char frase[])
{
    int len = strlen(frase);

    for(int i=len-1; i>=0; i--)
    {
        cout << frase[i];
    }
    cout << endl;
}

void stampaFraseMaiuscolo(const char frase[])
{
    int i = 0;

    while (frase[i] != '\0')
    {
        char c = frase[i];

        // Se è una lettera minuscola (ASCII)
        if (c >= 'a' && c <= 'z')
        {
            c = c - 32;  // salto tra minuscole e maiuscole
        }

        cout << c;
        i++;
    }

    cout << endl;
}

void stampaFraseSenzaSpazi(const char frase[])
{
    int i = 0;
    while (frase[i] != '\0')
    {
        if (frase[i] != ' ')
            cout << frase[i];

        i++;
    }
    cout << endl;
}

int contaParoleNellaFrase(const char frase[])
{
    int parole = 0;
    bool inParola = false;

    for (int i = 0; frase[i] != '\0'; i++)
    {
        // se troviamo una lettera e non siamo già in una parola
        if (frase[i] != ' ' && !inParola)
        {
            parole++;
            inParola = true;
        }
        // se troviamo uno spazio, usciamo dalla parola
        else if (frase[i] == ' ')
        {
            inParola = false;
        }
    }

    return parole;
}

void sostituisciCarattere(char frase[], char da, char a)
{
    int i = 0;
    while (frase[i] != '\0')
    {
        if (frase[i] == da)
        {
            frase[i] = a;
        }
            
        i++;
    }
}

int calcolaRicorrenzaLettera(const char frase[], char lettera)
{
    // Se è una lettera minuscola (ASCII)
    if (lettera >= 'a' && lettera <= 'z')
    {
        lettera = lettera - 32;  // salto tra minuscole e maiuscole
    }
    int ricorrenza = 0;

    for(int i=0; frase[i]!='\0'; i++)
    {
        char c = frase[i];
        if (c >= 'a' && c <= 'z')
        {
             c -= 32;
        }
        if(c == lettera)
        {
            ricorrenza++;
        }
    }
    return ricorrenza;
}

int main()
{
    char frase[DIM_MAX_FRASE];
    int scelta = 0;

    cout << "inserisci la frase: ";
    cin.getline(frase, DIM_MAX_FRASE);
    cout << endl;

    do
    {
        stampaMenu();
        cout << "inserisci la scelta: ";
        cin >> scelta;
        switch (scelta)
        {
            case 1:
                stampaFrase(frase);
                break;

            case 2:
                stampaFraseInvertita(frase);
                break;

            case 3:
                stampaFraseMaiuscolo(frase);
                break;

            case 4:
                stampaFraseSenzaSpazi(frase);
                break;

            case 5:
                cout << "Numero di parole: " << contaParoleNellaFrase(frase) << endl;
                break;

            case 6:
            {
                char da, a;
                cout << "Carattere da sostituire: ";
                cin >> da;
                cout << "Carattere sostitutivo: ";
                cin >> a;
            
                sostituisciCarattere(frase, da, a);
            
                cout << "Frase aggiornata: " << frase << endl;
                break;
            }
        
            case 7:
            {
                char lettera;
                cout << "Lettera da contare (maiusc/minusc indifferente): ";
                cin >> lettera;
            
                int n = calcolaRicorrenzaLettera(frase, lettera);
            
                cout << "Ricorrenza della lettera '" << lettera << "': " << n << endl;
                break;
            }
        
            case 8:
                cout << "exit" << endl;
                break;
            
            default:
                cout << "scelta non valida - riprovare" << endl;
                break;
        }
    } while (scelta != 8);
    
    return 0;
}