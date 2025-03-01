/*

Fie un sistem de gestionare a unor pasageri din cadrul unor zboruri. Zborul este caracterizat printr-un nume
unic, iar pasagerii printr-un cod numeric (max 8 cifre). Sa se scrie si sa se implementeze o structura 
multilista adecvate pentru gestionarea acestor zboruri. Structura va avea urmatoarea componenta: Fiecare zbor
reprezinta o intrare separata intr-o lista principala, si fiecare zbor contine o lista secundara ordonata dupa
cod a pasagerilor din acel zbor frel putin una din liste va fi implementata dinamic).
Sa se implementeze structurile de date necesare si urmatoarele functionalitati: DEliminare pasager - se sterge
un pasager identificat dupa cod din toate zborurile.
Sa se aleaga un exemplu de lista care sa cuprinda cel putin 3 zboruri, fiecare cu cel putin 5 pasageri. Sa se
reprezinte grafic structura multilista pentru acest exemplu, inainte si dupa apelul functiei Eliminare pasager.
Nota:
Algoritmul poate fi scris in pseudocod (C like).
Este obligatorie comentarea algoritmului si specificarea complexitatii acestuia in termeni de O(f(n)),
comentarea structurilor de date alese, precum si justificarea alegerii acestora. Este obligatorie 
exemplificarea efectului apelului functiilor implementate pe un exemplu ales.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ambele liste dinamic

typedef struct pasager {
	int cod;
	struct pasager* urm;
}pasager;

typedef struct zbor {
	char nume[30];
	struct zbor* urm_zbor;
	pasager* prim;
}zbor;

typedef zbor* lista;

void eliberare(lista* prim)
{
	zbor* curent = *prim;
	while (curent)
	{
		zbor* aux = curent;
		pasager* pas = curent->prim;
		while (pas)
		{
			pasager* aux2 = pas;
			pas = pas->urm;
			free(aux2);
		}
		curent = curent->urm_zbor;
		free(aux);
	}
	*prim = NULL;
}

void inserare_zbor(lista* l, char* nume)
{
	//inserare in fata
	zbor* z = (zbor*)malloc(sizeof(zbor));
	if (z == NULL)
	{
		printf("Eroare la alocarea de memorie pentru un zbor\n");
		eliberare(&l);
		exit(-1);
	}
	strcpy(z->nume, nume);
	z->urm_zbor = *l;
	z->prim = NULL;
	*l = z;
}

void inserare_pasager(lista* l, int cod, char* nume)
{
	zbor* curent = *l;
	while (curent)
	{
		if (strcmp(curent->nume, nume) == 0)
		{
			//se insereaza pasager
			pasager* p = (pasager*)malloc(sizeof(pasager));
			if (p == NULL)
			{
				printf("Eroare la alocarea de memorie pentru un pasager\n");
				eliberare(&l);
				exit(-1);
			}
			p->cod = cod;
			p->urm = NULL;
			if (curent->prim == NULL || cod < curent->prim->cod)
			{
				//inserare in fata
				p->urm = curent->prim;
				curent->prim = p;
				return;
			}
			pasager* a = curent->prim;
			while (a->urm && a->urm->cod < cod)
				a = a->urm;
			p->urm = a->urm;
			a->urm = p;
			return;
		}
		curent = curent->urm_zbor;
	}
	printf("Nu s-a gasit un zbor cu numele dat\n");
}

void eliminare_pasager(lista* l, int cod)
{
	zbor* curent = *l;
	int ok = 0;
	while (curent)
	{
		pasager *ant=NULL, *pas = curent->prim;
		while (pas)
		{
			if (pas->cod == cod)
			{
				//trebuie sters pasagerul
				pasager* aux = pas;
				if (ant == NULL)
					curent->prim = pas->urm;
				else
					ant->urm = pas->urm;
				pas = pas->urm;
				free(aux);
				ok = 1;
			}
			else
			{
				ant = pas;
				pas = pas->urm;
			}
		}
		curent = curent->urm_zbor;
	}
	if (ok == 0)
		printf("Nu s-a gasit un passager cu codul dat\n");
}

void afisare_pasageri(pasager* prim)
{
	if (prim == NULL)
	{
		printf("Nu este niciun pasager\n");
		return;
	}
	pasager* p = prim;
	while (p)
	{
		printf("pasager(%d)", p->cod);
		if (p->urm)
			printf(", ");
		p = p->urm;
	}
}

void afisare(lista l)
{
	if (l == NULL)
	{
		printf("Nu sunt zboruri\n");
		return;
	}
	zbor* curent = l;
	while (curent)
	{
		printf("%s: ", curent->nume);
		afisare_pasageri(curent->prim);
		printf("\n");
		curent = curent->urm_zbor;
	}
}

int main(void)
{
	lista l = NULL;
	inserare_zbor(&l, "Zbor1");
	inserare_zbor(&l, "Zbor2");
	inserare_zbor(&l, "Zbor3");

	inserare_pasager(&l, 4, "Zbor1");
	inserare_pasager(&l, 1, "Zbor1");
	inserare_pasager(&l, 7, "Zbor1");
	inserare_pasager(&l, 3, "Zbor1");
	inserare_pasager(&l, 9, "Zbor1");

	inserare_pasager(&l, 2, "Zbor2");
	inserare_pasager(&l, 7, "Zbor2");
	inserare_pasager(&l, 4, "Zbor2");
	inserare_pasager(&l, 1, "Zbor2");
	inserare_pasager(&l, 5, "Zbor2");

	inserare_pasager(&l, 9, "Zbor3");
	inserare_pasager(&l, 4, "Zbor3");
	inserare_pasager(&l, 3, "Zbor3");
	inserare_pasager(&l, 1, "Zbor3");
	inserare_pasager(&l, 7, "Zbor3");

	afisare(l);
	eliminare_pasager(&l, 4);
	afisare(l);
	eliberare(&l);
	return 0;
}