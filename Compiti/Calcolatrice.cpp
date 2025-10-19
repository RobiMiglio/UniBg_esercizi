/*

Instructions

Realizzare un programma che legga tre valori interi (n1, n2, n3) compresi tra 1 e 100, estremi inclusi, 
e poi presenti a video il seguente menù di operazioni possibili:

A - somma tra n1, n2 e n3
B - prodotto tra n1 e n2
C - sottrazione tra n3 e n1
D - divisione tra n1 e n2 (risultato double).
X - uscita dal programma

Legge poi un carattere da tastiera: se il carattere è tra quelli indicati nel menù, si deve eseguire 
l’operazione richiesta, stampare i numeri utilizzati nell’operazione e il risultato e poi ripresentare 
il menù; altrimenti il carattere deve essere ignorato e si deve ripresentare solo il menù.

Nel caso il carattere sia X, il programma termina.

Nota: nel caso D è necessaria la conversione di almeno uno dei due operandi.

*/

#include <iostream>

using namespace std;

int main()
{
    int numeri[3] = {0};
    char letteraOperazione = 0;
    int isLetteraErrata = 0;

    cout << "inserire tre valori interi compresi da 1 e 100" << endl;
    for(int i=0; i<3; i++)
    {
        do
        {
            cout << "inserire " << i+1 << "° valore: ";
            cin >> numeri[i];
            if((numeri[i]<1) || (numeri[i]>100))
            {
                cout << "valore non corretto" << endl;
            }
        } while ((numeri[i]<1) || (numeri[i]>100));
    }


    do
    {
        isLetteraErrata = 0;
        cout << "\nmenu calcolatrice, possibili operazioni selezionabili" << endl
         << " A - somma tra n1, n2 e n3 " << endl
         << " B - prodotto tra n1 e n2 " << endl
         << " C - sottrazione tra n3 e n1 " << endl
         << " D - divisione tra n1 e n2 " << endl
         << " X - uscita dal programma " << endl;
        cout << "selezionare l'operazione desiderata, indicando la lettera corrispondente: ";
        cin >> letteraOperazione;
        switch(letteraOperazione)
        {
            case 'A':
                cout << "\nsomma tra questi valori: " 
                     << numeri[0] << "+" 
                     << numeri[1] << "+" 
                     << numeri[2] << " = " << numeri[0]+numeri[1]+numeri[2] << endl;
                break;
            case 'B':
                cout << "\nprodotto tra questi valori: " 
                     << numeri[0] << "*"
                     << numeri[1] << " = " << numeri[0]*numeri[1] << endl;
                break;
            case 'C':
                cout << "\nsottrazione tra questi valori: " 
                     << numeri[2] << "-"
                     << numeri[0] << " = " << numeri[2]-numeri[0] << endl;
                break;
            case 'D':
                cout << "\ndivisione tra questi valori: " 
                     << numeri[0] << "/"
                     << numeri[1] << " = " << (float)numeri[0]/numeri[1] << endl;
                break;
            case 'X':
                cout << "\nchiusura programma" << endl;
                break;
            default:
                cout << "\nlettera errata, riprovare" <<endl;
                isLetteraErrata = 1;
        }
    } while (isLetteraErrata || (letteraOperazione != 'X'));

    return 0;
}
