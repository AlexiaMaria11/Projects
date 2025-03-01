/*
Un pătrat de dimensiune nXn conține celule negre și albe aranjate într-un anumit tipar. Să se determine numărul de zone albe și numărul de celule albe din fiecare zonă.

Ex:
n n n n n n n n

n a a a n a a n

n a a a n a a n

n n a a n n n n

n n n n n a a n

n n n n n a a n

n a a n n n n n

n n n n n n n n

Raspuns:

4 zone:

C1 =  8 celule albe

C2 =  4 celule albe

C3 =  4 celule albe

C4 =  2  celule albe
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 8

typedef struct coordonate
{
	int linie, coloana;
}coordonate;

coordonate pos[4];

int c = 0;

char matrice[N][N] = { {'n', 'n', 'n', 'n', 'n', 'n', 'n', 'n'},
	{'n', 'a', 'a', 'a', 'n', 'a', 'a', 'n'},
	{'n', 'a', 'a', 'a', 'n', 'a', 'a', 'n'},
	{'n', 'n', 'a', 'a', 'n', 'n', 'n', 'n'},
	{'n', 'n', 'n', 'n', 'n', 'a', 'a', 'n'},
	{'n', 'n', 'n', 'n', 'n', 'a', 'a', 'n'},
	{'n', 'a', 'a', 'n', 'n', 'n', 'n', 'n'},
	{'n', 'n', 'n', 'n', 'n', 'n', 'n', 'n'} };

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

int valid(coordonate aux)
{
	return aux.linie >= 0 && aux.linie < N && aux.coloana >= 0 && aux.coloana < N;
}

void vecini(int i, int j, int* nr)
{
	matrice[i][j] = 'x';
	for (int k = 0; k < 4; k++)
	{
		coordonate aux;
		aux.linie = i + pos[k].linie;
		aux.coloana = j + pos[k].coloana;
		if (valid(aux))
		{
			if (matrice[aux.linie][aux.coloana] == 'a')
			{
				*nr = *nr + 1;
				vecini(aux.linie, aux.coloana, nr);
			}

		}
	}
}

void labirint()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (matrice[i][j] == 'a')
			{
				c++;
				int nr = 1;
				vecini(i, j, &nr);
				printf("Zona %d are %d celule albe\n", c, nr);
			}
		}
	}
}

int main(void)
{
	initializare();
	labirint();
	return 0;
}