/*
Se dau urmatoarele 6 culori: alb, galben, rosu, verde, albastru si negru.
Sa se implementeze structurile de date necesare si urmatoarele functionalitati:
• Construiti toate steagurile formate din 3 culori care indeplinesc urmatoarele conditii:
• orice steag trebuie sa contina culoarea verde sau culoarea galben la mijloc.
• culorile din fiecare steag trebuie sa fie distincte.
Sa se aleaga cel putin 3 exemple de steaguri si sa se reprezinte grafic. Descrieti continutul structurilor 
de date folosite dupa apelul functiilor corespunzatoare.
Nota:
Algoritmul poate fi scris in pseudocod (C like).
Este obligatorie comentarea algoritmului si specificarea complexitatii acestuia in termeni de O(f(n)), comentarea structurilor de date alese, precum si justificarea alegerii acestora.
Este obligatorie exemplificarea efectului apelului functiilor implementate pe un exemplu ales.
*/

#include <stdio.h>
#include <string.h>

#define nr_culori 6
#define nr_steag 3

char culori[nr_culori][10] = { "alb", "galben", "rosu", "verde", "albastru", "negru" }; //posibilitati
char steag[nr_steag][10];  //solutia 
int c=0; //contor

void afisare()
{
	printf("Steag%d:\t|", c);
	c++;
	for (int i = 0; i < nr_steag; i++)
		printf("%s|", steag[i]);
	printf("\n");
}

int acceptabil(char *pos, int k)
{
	//culorile trebuie sa fie unice
	for (int i = 0; i < k; i++)
	{
		if (strcmp(steag[i], pos) == 0)
			return 0;
	}
	if ( k==1 && strcmp(pos, "verde") && strcmp(pos, "galben"))
		return 0;
	return 1;
}

int solutie(int k)
{
	return (k == nr_steag);
}

void gen_steag(int k)
{
	if (solutie(k)) // solutie completa 3 culori in steag
		afisare();
	else
	{
		for (int i = 0; i < nr_culori; i++)
		{
			char aux[10];
			strcpy(aux, culori[i]);
			if (acceptabil(aux, k))
			{
				strcpy(steag[k], aux);
				gen_steag(k + 1);
			}
		}
	}
}

int main(void)
{
	gen_steag(0);
}