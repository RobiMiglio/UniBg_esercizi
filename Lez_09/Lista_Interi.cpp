#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

struct NODO
{
	int dato;
	NODO *next;
};

int ins_testa(NODO *&head, int dato)
{
	NODO *t;
	
	t = new NODO;
	if(t == (NODO *)NULL)
	{
		cout << "Memoria Esaurita";
		return 1;
	}
	
	t->dato = dato;
	t->next= head;
	head = t;
	
	return 0;
}


int ins_coda(NODO *&head, int dato)
{
	NODO *t;
	NODO *p;
	
	t = new NODO;
	if(t == (NODO *)NULL)
	{
		cout << "Memoria Esaurita";
		return 1;
	}
	
	t->dato = dato;
	t->next= NULL;
	
	if(head == NULL )	
	{
		head = t;
		return 0;
	}
	
	p = head;
	while(p->next != NULL)
		p = p->next;
	p->next = t;
	
	return 0;
}

int canc_testa(NODO *&head)
{
	NODO *t;
	
	if(head == NULL)
	   return 1;
	   
	t = head;
	head = t->next;
	delete t;
	
	return 0;
}

int canc_coda(NODO *&head)
{
	NODO *t;
	NODO *p;
	NODO *prec;
	
	if(head == NULL)
	   return 1;
	   
	if(head->next == NULL)
	{
		t = head;
		head = NULL;
	}
	else
	{
		p = head->next;
		prec = head;
		while(p->next != NULL)
		{
			prec = p;
			p = p->next;
		}
		t = p;
		prec->next = NULL;
	}
	   
	delete t;
	
	return 0;
}

int canc_valore(NODO *&head, int dato)
{
	NODO *t;
	NODO *p;
	NODO *prec;
	
	if(head == NULL)
		return 1;
	if(head->dato == dato)
	{
		t = head;
		head=head->next;
		delete t;
		return 0;
	}
	
	p = head->next;
	prec = head;
	while(p!=NULL)
	{
		if(p->dato == dato)
		{
			t = p;
			prec->next = p->next;
			delete t;
			return 0;
		}
		prec = p;
		p = p->next;
	}
	return 1;
}

void stampa(NODO *head)
{
	NODO *p;
	
	cout << "--------------------------------" << endl;
	p = head;
	while(p != NULL)
	{
		cout << "Valore: " << p->dato << endl;
		p = p->next;
	}
	cout << "--------------------------------" << endl;
}

int main(int argc, char*argv[])
{
	NODO *lista1=NULL;
	NODO *lista2=NULL;
	int v;
	char buffer[1000];
	
	do
	{
		cout << "Inserisci un valore (0: termina)";
		cin.getline(buffer, 1000);
		v = atoi(buffer);
		if( v!= 0)
		{
			if(ins_testa(lista1, v))
				exit(1);
		}
	} while(v!= 0);

	stampa(lista1);
	cout << "Cancello dalla testa" << endl;
	canc_testa(lista1);
	stampa(lista1);

	cout << "Valore da cancellare";
	cin.getline(buffer, 1000);
	v = atoi(buffer);
	if(canc_valore(lista1, v) == 1)
		cout << "Valore non trovato" << endl;
	else
		cout << "Valore cancellato" << endl;
	stampa(lista1);

	do
	{
		cout << "Inserisci un valore (0: termina)";
		cin.getline(buffer, 1000);
		v = atoi(buffer);
		if( v!= 0)
		{
			if(ins_coda(lista2, v))
				exit(1);
		}
	} while(v!= 0);

	stampa(lista2);
	cout << "Cancello dalla coda" << endl;
	canc_coda(lista2);
	stampa(lista2);
	

    return 0;
}




