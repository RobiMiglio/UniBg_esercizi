/*

Si consideri un array v[...] di n interi.
Si vuole scrivere un sottoprogramma per "esplorare" il vettore, iniziando
dal primo elemento v[0]
e muovendosi con la regola descritta in seguito.
Il sottoprogramma restituisce 0 e modifica il vettore inserendo in ogni
cella il valore 0 se
l'esplorazione porta ad un percorso "infinito”, perché il vettore è ciclico,
altrimenti restituisce 1 e
non modifica il vettore se a un certo punto termina.

*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int esploraVettore(int arr[], int size)
{
    int indice = 0;
    int visitato[size];
    for (int i = 0; i < size; i++)
        visitato[i] = 0; // 0 = non visitato

    while (indice >= 0 && indice < size)
    {
        if (visitato[indice])
        {
            // ciclo trovato → setta tutto a 0
            for (int j = 0; j < size; j++)
                arr[j] = 0;
            return 0; // ciclico
        }

        visitato[indice] = 1;
        indice += arr[indice];
    }

    // è uscito dai limiti → termina
    return 1;
}

int main()
{
    const int size = 4;
    srand(time(NULL));

    int v[size];
    for (int i = 0; i < size; i++)
        v[i] = (rand() % 21) - 10; // da -10 a 10

    cout << "Vettore iniziale: ";
    for (int i = 0; i < size; i++)
        cout << v[i] << " ";
    cout << endl;

    int risultato = esploraVettore(v, size);

    if (risultato == 0)
        cout << "Percorso ciclico → vettore azzerato" << endl;
    else
        cout << "Percorso terminato" << endl;

    cout << "Vettore finale: ";
    for (int i = 0; i < size; i++)
        cout << v[i] << " ";
    cout << endl;

    return 0;
}
