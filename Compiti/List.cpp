/*
List

Given a binary tree, we need to write a program (with recursive function)
to print all leaf nodes
of the given binary tree from left to right.

Main steps:
1) Check if the given node is null. If null, then return from the function.
2) Check if it is a leaf node. If the node is a leaf node, then print its data.
3) If in the above step, the node is not a leaf node then check if the
   left and right children of node exist. If yes then call the function
   for left and right child of the node recursively.

Example of struct for a node:
typedef struct node
{
    int data;
    Node *left, *right;
} Node;

Utility function to create a new tree node:
Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
*/

/*
Lista

Dato un albero binario, dobbiamo scrivere un programma (con una funzione
ricorsiva) per stampare tutti i nodi foglia
dell’albero binario dato da sinistra a destra.

Passaggi principali:
1) Controllare se il nodo dato è nullo. Se è nullo, allora terminare la funzione.
2) Controllare se è un nodo foglia. Se il nodo è un nodo foglia, stampare il suo dato.
3) Se nel passaggio precedente il nodo non è un nodo foglia, allora controllare se
   i figli sinistro e destro del nodo esistono. Se sì, chiamare ricorsivamente
   la funzione per il figlio sinistro e per il figlio destro del nodo.

Esempio di struttura per un nodo:
typedef struct node
{
    int data;
    Node *left, *right;
} Node;

Funzione di utilità per creare un nuovo nodo dell’albero:
Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
*/


#include <iostream>

using namespace std;

struct NODO
{
	int dato;
	NODO *left;
	NODO *right;
};

NODO* nuovoNodo(int dato)
{
	NODO *nuovoNodo = new NODO;
	if(nuovoNodo==NULL)
	{
		return NULL;
	}
	nuovoNodo->dato = dato;
	nuovoNodo->left = NULL;
	nuovoNodo->right = NULL;
	return nuovoNodo;
}

void stampaFoglie(NODO* nodo)
{
    if (nodo == NULL)
    {
        return;
    }

    if (nodo->left == NULL && nodo->right == NULL)
    {
        cout << nodo->dato << " ";
        return;
    }

    stampaFoglie(nodo->left);
    stampaFoglie(nodo->right);
}


int main()
{
    NODO* radice = nuovoNodo(1);

    radice->left = nuovoNodo(2);
    radice->right = nuovoNodo(3);

    radice->left->left = nuovoNodo(4);
    radice->left->right = nuovoNodo(5);

    radice->right->right = nuovoNodo(6);

    cout << "Nodi foglia: ";
    stampaFoglie(radice);
    cout << endl;

    return 0;
}
