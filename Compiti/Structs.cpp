/*
Si scriva un programma C che legga due serie di dati e li memorizzi in 
due vettori di strutture.

Nel primo vettore M (di dimensione 3) vengono memorizzati dati del tipo:
<matricola, nome, cognome>.
Si noti che la matricola identifica univocamente uno studente e che non 
ci sono due strutture che contengono lo stesso numero di matricola.

Nel secondo vettore V (di dimensione 7) vengono memorizzati dati del tipo:
<matricola, esame, voto>.
Possono esserci più record con lo stesso numero di matricola che denotano 
diversi esami fatti dallo stesso studente.

Si scriva un programma che tramite opportune procedure legga i dati in 
ingresso e li inserisca nei due vettori.

Successivamente per ogni studente con matricola X contenuto nel vettore 
M si sommi tutti i suoi voti ottenuti negli esami contenuti nel vettore V.
*/

#include <iostream>
#include <cstring>

using namespace std;

#define DIM_M 3
#define DIM_V 7
#define DIM_MAX 20

struct Nominativi
{
    int matricola;
    char nome[DIM_MAX];
    char cognome[DIM_MAX];
};

struct Esami
{
    int matricola;
    char esame[DIM_MAX];
    int voto;
};

bool matricolaPresente(Nominativi arr[], int size, int matricola)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i].matricola == matricola)
        {
            return true;
        }
    }
    return false;
}

int sommaVoti(Esami arr[], int size, int matricola)
{
    int somma = 0;

    for(int i = 0; i < size; i++)
    {
        if(arr[i].matricola == matricola)
        {
            somma += arr[i].voto;
        }
    }

    return somma;
}

int main()
{
    Nominativi M[DIM_M];
    Esami V[DIM_V];

    int countNominativi = 0;

    cout << "\n--- INSERIMENTO NOMINATIVI (3 STUDENTI) ---\n" << endl;

    while(countNominativi < DIM_M)
    {
        int tempMatricola = 0;
        bool esiste = false;

        do
        {
            cout << "Inserisci matricola studente " << countNominativi + 1 << ": ";
            cin >> tempMatricola;

            if(tempMatricola <= 0)
            {
                cout << "La matricola deve essere positiva.\n";
                continue;
            }

            esiste = matricolaPresente(M, countNominativi, tempMatricola);

            if(esiste)
            {
                cout << "Matricola già presente. Reinserire.\n";
            }

        }
        while(tempMatricola <= 0 || esiste);

        M[countNominativi].matricola = tempMatricola;

        cout << "Inserisci il nome: ";
        cin.ignore();
        cin.getline(M[countNominativi].nome, DIM_MAX);

        cout << "Inserisci il cognome: ";
        cin.getline(M[countNominativi].cognome, DIM_MAX);

        countNominativi++;
        cout << endl;
    }

    int countEsami = 0;

    cout << "\n--- INSERIMENTO ESAMI (7 ESAMI TOTALI) ---\n" << endl;

    while(countEsami < DIM_V)
    {
        int tempMatricola = 0;

        do
        {
            cout << "Inserisci la matricola per l'esame " << countEsami + 1 << ": ";
            cin >> tempMatricola;

            if(tempMatricola <= 0)
            {
                cout << "La matricola deve essere positiva.\n";
            }
        }
        while(tempMatricola <= 0);

        V[countEsami].matricola = tempMatricola;

        cout << "Inserisci il nome dell'esame: ";
        cin.ignore();
        cin.getline(V[countEsami].esame, DIM_MAX);

        cout << "Inserisci il voto: ";
        cin >> V[countEsami].voto;

        cout << endl;
        countEsami++;
    }

    cout << "\n--- SOMMA VOTI PER STUDENTE ---\n" << endl;

    cout << "Matricola\tSomma voti" << endl;

    for(int i = 0; i < countNominativi; i++)
    {
        cout << M[i].matricola << "\t\t" 
             << sommaVoti(V, countEsami, M[i].matricola) 
             << endl;
    }

    return 0;
}
