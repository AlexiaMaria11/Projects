/*
O fotografie alb-negru este prezentata sub forma unei matrice binare. Fiecare element din matrice reprezinta
un pixel. In fotografie pot exista unul sau mai multe obiecte. Portiunile corespunzatoare obiectului (sau
obiectelor) in matrice au valoarea 1, restul au valoarea 0.
Sa se proiecteze un algoritm care determina cate obiecte sunt prezente in fotografie.
Nota:
Algoritmul poate fi scris in pseudocod (C like).
Este obligatorie comentarea algoritmului, comentarea structurilor de date alese, precum si justificarea 
alegerii acestora. Este obligatorie exemplificarea efectului apelului functiilor implementate pe un exemplu 
ales.
*/

#include <stdio.h>
#define N 4

typedef struct coordonate
{
	int linie, coloana;
}coordonate;

coordonate pos[4];

int matrice[N][N] = { 1,1,1,1,
				      0,0,1,1,
				      1,0,0,0,
				      1,0,1,0 };

void initializare() //int pos[] variabila globala
{	//initializarea posibilitatilor de deplasare Posibilitățile de deplasare sunt Nord, Est, Sud, Vest
	pos[0].coloana = 0; // Nord
	pos[0].linie = -1;// y scade spre Nord
	pos[1].coloana = 1; // Est – x creste spre Est
	pos[1].linie = 0;
	pos[2].coloana = 0; // Sud
	pos[2].linie = 1; // y creste spre Sud
	pos[3].coloana = -1;// Vest – x scade spre Vest
	pos[3].linie = 0;
}

int valid(coordonate c)
{
	return c.linie >= 0 && c.linie < N && c.coloana >= 0 && c.coloana < N;
}

void back(int i, int j)
{
	matrice[i][j] = 2;
	for (int k = 0; k < 4; k++)
	{
		coordonate urm;
		urm.linie = i + pos[k].linie;
		urm.coloana = j + pos[k].coloana;
		if (valid(urm))
		{
			if (matrice[urm.linie][urm.coloana] == 1)
				back(urm.linie, urm.coloana);
		}
	}
}

int obiecte()
{
	int c = 0;
	for (int i = 0; i < N; i++)
	{
		for(int j=0; j<N; j++)
			if (matrice[i][j] == 1)
			{
				c++;
				back(i, j);
			}
	}
	return c;
}


int main(void)
{
	initializare();
	printf("Numarul de obiecte este %d\n", obiecte());
}