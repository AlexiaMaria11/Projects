/*
Fie o suprafata caroiata, reprezentata printr-o matrice patratica de dimensiune n*m si 4 culori. Sa se
implementeze structurile de date necesare si urmatoarele functionalitati:
☐Coloreaza harta - functia propune un mod de colorare al suprafetei, folosind cele 4 culori astfel incat 
vecinii pe diagonala ai unei celule sa aiba culori diferite decat cea a celulei.
Sa se aleaga un exemplu de suprafata de cel putin 3*3 elemente si sa se reprezinfic suprafata dupa apelul 
functiei Coloreaza harta.
Nota:
Algoritmul poate fi scris in pseudocod (C like).
Este obligatorie comentarea algoritmului si specificarea complexitatii acestuia in termeni de O(f(n)), 
comentarea structurilor de date alese, precum si justificarea alegerii acestora. Este obligatorie
exemplificarea efectului apelului functiilor implementate pe un exemplu ales.
*/

#include <stdio.h>
#include<string.h>

#define n_culori 4
#define nr 5

char culori[n_culori][10] = { "rosu", "alb", "verde", "galben" }; //culorile cu care se poate colora 
char harta[nr][nr][10]; //harta ce urmeaza sa fie colorata
int c = 0;

int solutie(int i, int j)
{
	if (i == nr)
		return 1;
	else
		return 0;
}

int acceptabil(char* pos, int i, int j)
{
	if (i > 0 && j > 0 && strcmp(harta[i - 1][j - 1], pos) == 0)
		return 0;
	if (i > 0 && j < nr - 1 && strcmp(harta[i - 1][j + 1], pos) == 0)
		return 0;
	if (i < nr - 1 && j > 0 && strcmp(harta[i + 1][j - 1], pos) == 0)
		return 0;
	if (i < nr - 1 && j < nr - 1 && strcmp(harta[i + 1][j + 1], pos) == 0)
		return 0;
	return 1;
}

void afisare()
{
	c++;
	printf("Harta%d\n", c);
	for (int i = 0; i < nr; i++)
	{
		for (int j = 0; j < nr; j++)
			printf("%s\t", harta[i][j]);
		printf("\n");
	}
}

int coloreaza(int i, int j)
{
	if (solutie(i, j))
	{
		afisare();
		return 1;
	}
	else
	{
		for (int in = 0; in < n_culori; in++)
		{
			if (acceptabil(culori[in], i, j))
			{
				strcpy(harta[i][j], culori[in]);
				int next_i = (j == nr - 1) ? i + 1 : i;
				int next_j = (j == nr - 1) ? 0 : j + 1;
				if (coloreaza(next_i, next_j))
					return;
			}
		}
	}
	printf("Nu s-a gasit o solutie valida\n");
	return 0;
}

int main(void)
{
	for (int i = 0; i < nr; i++) {
		for (int j = 0; j < nr; j++) {
			strcpy(harta[i][j], "-");
		}
	}
	coloreaza(0, 0);
}