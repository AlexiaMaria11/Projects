/*
Fie un tablou de structuri de forma struct student(char nume[35]; int varsta; int premii). (Câmpul premii 
este setat pe 1 dacă studentul a fost premiat, respectiv pe 0 daca nu).
Ştiind ca tabloul are dimensiunea N, sa se implementeze cate o funcție pentru:
a. Mutarea, intr-un mod cat mai eficient, pe primele poziții din vector a studentilor care au primit premii,
b. Sortarea in ordine invers alfabetica dupa nume, a studentilor premiati (doar studentii premiati vor fi 
sortati).
Sa se considere un exemplu de tablou cu minim 5 astfel de filme si sa se exemplifice cum va arata tabloul 
dupa apelul fiecareia din functiile de mai sus.
Nota:
Algoritmul poate fi scris in pseudocod (C like).
Este obligatorie comentarea algoritmului si specificarea complexitatii acestuia in termeni de O(f(n)), 
comentarea structurilor de date alese, precum si justificarea alegerii acestora.
Este obligatorie exemplificarea efectului apelului functiilor implementate pe un exemplu ales.
*/

#include <stdio.h>
#include <string.h>

typedef struct {
	char nume[35];
	int varsta, premii;
}student;

void afisare(student* s, int n)
{
	for (int i = 0; i < n; i++)
		printf("%s --- %d --- %d\n", s[i].nume, s[i].varsta, s[i].premii);
	printf("\n");
}

void swap(student* a, student* b)
{
	student c = *a;
	*a = *b;
	*b = c;
}

int separare(student* s, int n)
{
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i].premii == 1)
		{
			if (i != j)
				swap(&s[i], &s[j]);
			j++;
		}
	}
	//indicele la care incep studentii fara premii
	//sau numarul de studenti premiati
	return j;
}

void quicksort(student a[], int prim, int ultim)
{
	int stanga = prim + 1;
	int dreapta = ultim;
	//alegere pivot
	swap(&a[prim], &a[(prim + ultim) / 2]);
	//mutare pivot pe prima pozitie
	student pivot = a[prim];
	while (stanga <= dreapta) //partitionare
	{
		while (stanga <= ultim && strcmp(a[stanga].nume,pivot.nume)>0)
			stanga++;
		while (dreapta >= prim && strcmp(pivot.nume,a[dreapta].nume)>0)
			dreapta--;
		if (stanga < dreapta)
			swap(&a[stanga++], &a[dreapta--]);
		else
			stanga++;
	}
	//mutare pivot la locul sau final
	swap(&a[dreapta], &a[prim]);
	//apelurile recursive
	if (prim < dreapta - 1)
		quicksort(a, prim, dreapta - 1);
	if (dreapta + 1 < ultim)
		quicksort(a, dreapta + 1, ultim);
}

int main(void)
{
	student s[] = { {"Ale", 20, 1}, {"Bogdan", 19, 0}, {"Ion", 18, 0}, {"Ana", 23, 1}, {"Paul", 25, 1} };
	int n = sizeof(s) / sizeof(student);
	afisare(s, n);
	quicksort(s, 0, separare(s, n) - 1);
	afisare(s, n);
	return 0;
}