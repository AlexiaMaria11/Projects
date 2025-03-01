/*
Se dă multimea M={a,b,c}
Sa se implementeze structurile de date necesare si urmatoarele functionalitati:
• Generează cuvinte - funcția determină toate cuvintele ce conţin numai literele din mulțimea M de lungime 10
care conţin exact 3 simboluri 'a', 4 simboluri 'b' şi 3 simboluri 'c'.
• Sa se noteze primele 5 cuvinte generate în ordine.
Nota:
Algoritmul poate fi scris in pseudocod (C like).
Este obligatorie comentarea algoritmului si specificarea complexitatii acestuia in termeni de O(f(n)),
comentarea structurilor de date alese, precum si justificarea alegerii acestora.
Este obligatorie exemplificarea efectului apelului functiilor implementate pe un exemplu ales.
*/

#include <stdio.h>

#define nr 3 //simboluri posibile a,b,c
#define nmax 10 //lungime cuvant
#define nsol 5 //numar de solutii

char a[nmax];  // tablou cu solutia
char pos[nr];  //tabloul de posibilitati
int ca, cb, cc; //contoare
int sol; // numar solutii

void initializare()
{
    //initializarea posibilitatilor
    int i;
    for (i = 0; i < nr; i++)
        pos[i] = 'a'+i;
}

void afiseaza_solutia()
{
    int i;
    for (i = 0; i < nmax; i++)
        printf("%c ", a[i]);
    printf("\n");
}

int solutie(int k)
{
    return (k == nmax);  //solutia cuprinde nmax elemente
}

void generare(int k)  //k pasul, 
{
    int i, aux;
    if (sol >= nsol)
        return; //se opreste dupa 5 afisari
    if (solutie(k))              //solutie completa (avem n elemente)
    {
        afiseaza_solutia();
        sol++;
    }
    else
    {
        for (i = 0; i < nr; i++)  // parcurgem pe rand posibilitatile
        {
            a[k] = pos[i];
            if (pos[i] == 'a' && ca < 3)
            {
                ca++;
                generare(k + 1);
                ca--;
            }
            else
                if (pos[i] == 'b' && cb < 4)
                {
                    cb++;
                    generare(k + 1);
                    cb--;
                }
                else
                    if (pos[i] == 'c' && cc < 3)
                    {
                        cc++;
                        generare(k + 1);
                        cc--;
                    }
        }
    }
}   /*permuta*/

int main(void)
{
    initializare();
    generare(0);
}