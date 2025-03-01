/*
Fie un sistem de calcul care deserveste evenimente. Evenimentele sunt caracterizate printr-un ID, printr-o 
prioritate (de tip intreg cu valori intre 1 si 8) si momentul activarii (de tip long. reprezentand momentul 
de timp in ciclii de clock). Sa se stocheze aceste evenimente intr-o structura de tip multilista, in care 
evenimentele cu aceeasi prioritate vor fi stocate ordonat dupa momentul activarii.
Sa se implementeze structurile de date necesare si urmatoarele functionalitati:
DDeservire eveniment-se va deservi evenimentul cu prioritatea cea mai mare si momentul activarii cel mai mic.
Se va afisa ID-ul evenimentului deservit si se va scoate din multilista si se va adauga intr-o coada de 
asteptare de tip FIFO (first in first out), care este implementata independent de structura multilista.
Ex.
P1 e1 10, e2 20
P2-e3 15
P7-e11 20, e12 40
P8-
Se va deservi procesul proc 11 avand prioritatea 7 si momentul activarii 20.
FIFO e11
Sa se aleaga un exemplu de lista care sa cuprinda cel putin 3 procese si sa se exemplifice apelul functiei de
mai sus pentru cazul ales.
Nota:
Codul ce implementeaza solutia trebuie sa fie compilabil, programul trebuie sa ruleze.
Este obligatorie comentarea algoritmului si specificarea complexitatii acestuia in termeni de O(f(n)), 
comentarea structurilor de date alese, precum si justificarea alegerii acestora. Este obligatorie 
exemplificarea efectului apelului functiilor implementate pe un exemplu ales.
Barem:
Alegere si implementare corecta structuri de date 20%
Comentare cod si specificare complexitate 10%
Alegerea unui exemplu relevant 10%
Implementare cerinte 60%
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define pr_max 8

typedef struct even {
	int id, pri;
	long timp;
	struct even* urm;
}even;

typedef struct
{
	int p;
	even* prim;
}prioritate;

typedef struct {
	prioritate pr[8];
}lista;

typedef struct {
	even* prim_coada;
	even* ultim;
}tip_coada;

void initializare(lista* l)
{
	for (int i = 0; i < pr_max; i++)
	{
		l->pr[i].prim = NULL;
		l->pr[i].p = i + 1;
	}
}

void initializeaza_coada(tip_coada* c)
{
	c->prim_coada = NULL;
	c->ultim = NULL; /*coada este vida,
					 nici prim nici ultim nu indica spre vreun element*/
}/*initializeaza*/

void adauga(tip_coada* c, even* x) {
	even* nou = (even*)malloc(sizeof(even));
	if (nou == NULL) {
		printf("Eroare alocare memorie\n");
		exit(-1);
	}
	nou->id = x->id;
	nou->pri = x->pri;
	nou->timp = x->timp;
	nou->urm = NULL;
	if (c->prim_coada == NULL) { // Coada este goală
		c->prim_coada = nou;
		c->ultim = nou;
	}
	else {
		c->ultim->urm = nou; // Adăugare la sfârșit
		c->ultim = nou;
	}
}

void eliberare(lista* l)
{
	for (int i = 0; i < pr_max; i++)
	{
		even* curent = l->pr[i].prim;
		while (curent)
		{
			even* aux = curent;
			curent = curent->urm;
			free(aux);
		}
		l->pr[i].prim = NULL;
	}
}

void eliberare_coada(tip_coada* c)
{
	even* curent = c->prim_coada;
	while (curent)
	{
		even* aux = curent;
		curent = curent->urm;
		free(aux);
	}
	c->prim_coada = NULL;
	c->ultim = NULL;
}

void afisare_evenimente(lista l, int i)
{
	even* curent = l.pr[i].prim;
	if (curent == NULL)
	{
		printf("Nu sunt evenimente");
		return;
	}
	while (curent)
	{
		printf("e%d %ld", curent->id, curent->timp);
		if (curent->urm)
			printf(", ");
		curent = curent->urm;
	}
}

void afisare(lista l)
{
	for (int i = 0; i < pr_max; i++)
	{
		printf("P%d: - ", i + 1);
		afisare_evenimente(l, i);
		printf("\n");
	}
}

void adaugare_eveniment(lista *l, int id, int pri, long timp)
{
	even* nou = (even*)malloc(sizeof(even));
	if (nou == NULL)
	{
		printf("Eroare la alocarea de memorie pentru un nod nou\n");
		eliberare(l);
		exit(-1);
	}
	nou->id = id;
	nou->pri = pri;
	nou->timp = timp;
	nou->urm = NULL;
	//adaugare la prioritatea data
	even* primul = l->pr[pri - 1].prim;
	//se adauga in ordine in functie de timp
	if (primul == NULL || timp < primul->timp)
	{
		//adaugare la inceput
		nou->urm = primul;
		primul = nou;
		l->pr[pri - 1].prim = nou;
		return;
	}
	even* curent = primul;
	while (curent->urm && curent->urm->timp < timp)
		curent = curent->urm;
	nou->urm = curent->urm;
	curent->urm = nou;
}

void deservire_eveniment(lista* l, tip_coada *c)
{
	for (int i = pr_max - 1; i >= 0; i--)
	{
		even* des = l->pr[i].prim;
		if (des)
		{
			even* aux = des;
			adauga(c, aux);
			l->pr[i].prim = aux->urm;
			return;
		}
	}
}

void afisare_coada(tip_coada c)
{
	if (c.prim_coada == NULL)
	{
		printf("Coada este goala\n");
		return;
	}
	even* curent = c.prim_coada;
	while (curent)
	{
		printf("e%d %ld", curent->id, curent->timp);
		if (curent->urm)
			printf(", ");
		curent = curent->urm;
	}
}

int main(void)
{
	lista l;
	initializare(&l);
	adaugare_eveniment(&l, 1, 1, 10);
	adaugare_eveniment(&l, 3, 2, 15);
	adaugare_eveniment(&l, 12, 7, 40);
	adaugare_eveniment(&l, 11, 7, 20);
	adaugare_eveniment(&l, 2, 1, 20);
	afisare(l);
	tip_coada c;
	initializeaza_coada(&c);
	deservire_eveniment(&l, &c);
	afisare(l);
	afisare_coada(c);
	eliberare_coada(&c);
	eliberare(&l);
	return 0;
}