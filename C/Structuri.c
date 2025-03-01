/*
  
    Se consideră un fișier csv (comma separated values) în care pe fiecare linie se află mai multe câmpuri separate prin virgulă. Fișierul conține informații despre filme. Pe fiecare linie se află câte o inregistrare ce reprezintă un film cu date despre acesta, date ce sunt separate prin virgulă. O linie are următoarea configurație (cap de tabel)

year,imdb,title,test,clean_test,binary,budget,domgross,intgross,code,budget_2013$,domgross_2013$,intgross_2013$,period code,decade code

Se va citi acest fișier în mod optim. Pentru fiecare înregistrare se vor extrage următoarele date: titlu, an, buget (title, year, budget). Se va proiecte și implementa o structură de date corespunzătoare. Se vor stoca aceste date intr-un tablou alocat dinamic. Se precizează că se consideră necunoscută dimensiunea fișierului ( a numărului de linii) - se va aloca minimul de memorie necesar pentru a stoca toate informațiile. Programul va scrie în fișierul out1.txt toate filmele sortate după anul apariției, în fișierul out2.txt toate filmele sortate după titlu iar în fișierul out3.txt toate filmele sortate după buget. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Movie
{
    int an;
    int buget;
    char *titlu;
}Movie;
Movie *m;
int nr_movies=0;
void sortare_titlu()
{
    Movie aux;
    for(int i=0;i<nr_movies-1;i++)
    {
        for(int j=i;j<nr_movies;j++)
        {
	  if(strcmp(m[i].titlu,m[j].titlu)>0)
            {
                aux=m[i];
                m[i]=m[j];
                m[j]=aux;
            }
        }
    }
}

void sortarebuget()
{
    Movie aux;
    for(int i=0;i<nr_movies-1;i++)
    {
        for(int j=i;j<nr_movies;j++)
        {
            if(m[i].buget>m[j].buget)
            {
                aux=m[i];
                m[i]=m[j];
                m[j]=aux;
            }
        }
    }
}

void sortarean()
{
    Movie aux;
    for(int i=0;i<nr_movies-1;i++)
    {
        for(int j=i;j<nr_movies;j++)
        {
            if(m[i].an>m[j].an)
            {
                aux=m[i];
                m[i]=m[j];
                m[j]=aux;
            }
        }
    }
}

void afisare(FILE *out)
{
    for(int i=0;i<nr_movies;i++)
    {
        fprintf(out,"%d %d %s\n",m[i].an,m[i].buget,m[i].titlu);
    }
}
void eliberare()
{
    for(int i=0;i<nr_movies;i++)
    free(m[i].titlu);
    free(m);
}
void ptext1()
{
    FILE *f=fopen("movies.csv","r");
    if(f==NULL)
      {
	printf("eroare");
	fclose(f);
	exit(-1);
      }
    char s[1000];
    fgets(s,1000,f);
    while(fgets(s,1000,f)!=NULL)
    {
        char *p=strtok(s,",");
        int k=0;
        m=(Movie*)realloc(m,sizeof(Movie)*(nr_movies+1));
        while(p!=NULL)
        {
            if(k==0)
            m[nr_movies].an=atoi(p);
            if(k==2)
            {
            m[nr_movies].titlu=(char*)malloc(sizeof(char)*(strlen(p)+1));
            strcpy(m[nr_movies].titlu,p);
            }
            if(k==6)
                m[nr_movies].buget=atoi(p);
            p=strtok(NULL,",");
            k++;
        }
        nr_movies++;
    }
    fclose(f);
    sortarean();
    FILE *f1=fopen("afisare1.txt","w");
    if (f1==NULL)
      {
	printf("eroare");
	fclose(f1);
	exit(-1);
      }
    afisare(f1);
    fclose(f1);
    sortare_titlu();
    FILE *f2=fopen("afisare2.txt", "w");
    if (f2==NULL)
      {
	printf("eroare");
	fclose(f2);
	exit(-1);
      }
    afisare(f2);
    fclose(f2);
    FILE *f3=fopen("afisare3.txt", "w");
    if (f3==NULL)
      {
	printf("eroare");
	fclose(f3);
	exit(-1);
      }
    sortarebuget();
    afisare(f3);
    fclose(f3);
}
int main(void)
{
    ptext1();
    return 0;
}
*/

/*
  2.Se citesc de la tastatură maxim 100 numere reale, până la întâlnirea numărului 0. Să se sorteze aceste numere și să se scrie într-un fișier, toate numerele fiind pe o singură linie, separate prin | (bară verticală).

#include <stdio.h>
#include <stdlib.h>

void sortare(int *v, int n)
{
  for (int i=0; i<n-1; i++)
    for (int j=i; j<n; j++)
      {
	if (v[i]>v[j])
	  {
	    int aux = v[i];
	    v[i]=v[j];
	    v[j]=aux;
	  }
      }
}

int main(void)
{
  int v[101];
  int x;
  scanf("%d", &x);
  int i=0;
  while(x!=0 && i<100)
    {
      v[i]=x;
      i++;
      scanf("%d", &x);
    }
  sortare(v, i);
  FILE *f;
  f=fopen("numere.txt", "w");
  if (f==NULL)
    {
      printf("eroare");
      fclose(f);
      exit(-1);
    }
  for (int j=0; j<i; j++)
    fprintf(f, "%d|", v[j]);
  fclose(f);
  return 0;
}
*/

/*
  3.    Se consideră un fișier csv (comma separated values) în care pe fiecare linie se află mai multe câmpuri separate prin semnul punct-virgulă. Fișierul conține informații statistice oferite de Institutul National de Statistica prin platforma OpenData a Guvernului Romaniei (https://data.gov.ro/) despre plata indemnizațiilor de creșterea copilului pe o anumită lună din anul 2021. Fișierul are următorul cap de tabel ce descrie câmpurile din liniile conținue

Judet;Populatie;Beneficiari plãtiti;Beneficiari suspendati la sfârsit de lunã;Suma totalã plãtitã drepturi curente;Alte plãþi

Programul va citi acest fișier folosind funcțiile dedicate pentru citirea fișierelor text, va extrage câmpurile judet, beneficiari platiti si suma total platita drepturi curente, si va stoca datele într-un tablou alocat dinamic, de structuri de date corespunzătoare, de dimensiune minimă necesară. Se cere să se implementeze tipuri de date utilizator. Se va implementa de asemenea o funcție de sortate dupa judet și o funcție de sortare după suma totala platita drepturi curente. Programul va scrie în fișierul rezultat.txt pe câte un rând diferit judetul cu cea mai mare populatie, judetul cu cea mai mare suma din câmpul alte plati.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct date
{
    char *judet;
    int suma,beneficiari;
}date;
date *m;
int numar=0,indice,indice2;
void afisare(FILE *out)
{
    fprintf(out,"judetul cu cea mai mare populatie %s\n",m[indice].judet);
    fprintf(out,"judetul cu cea mai mari cheltuieli  %s\n",m[indice2].judet);
    for(int i=0;i<numar;i++)
    fprintf(out,"%s,%d,%d\n",m[i].judet,m[i].suma,m[i].beneficiari);
}
void elibearare()
{
    for(int i=0;i<numar;i++)
    free(m[i].judet);
    free(m);
}
void sortjudet()
{
    date aux;
    for(int i=0;i<numar-1;i++)
    {
        for(int j=i;j<numar;j++)
        {
            if(strcmp(m[i].judet,m[j].judet)<0)
            {
                aux=m[i];
                m[i]=m[j];
                m[j]=aux;
            }
        }
    }
}
void sortsuma()
{
    date aux;
    for(int i=0;i<numar-1;i++)
    {
        for(int j=i;j<numar;j++)
        {
            if(m[i].suma<m[j].suma)
            {
                aux=m[i];
                m[i]=m[j];
                m[j]=aux;
            }
        }
    }
}
void ptext3()
{
    FILE *f=fopen("indemnizatie.csv","r");
    char s[1000];
    int nrpopcurenta,nrpopmax=0;
    int nrpopcurenta2,nrpopmax2=0;
    fgets(s,1000,f);
    while(fgets(s,1000,f)!=NULL)
    {
        char *p=strtok(s,";");
        int k=0;
        m=(date*)realloc(m,sizeof(date)*(numar+1));
        while(p!=NULL)
        {
            if(k==0)
            {
                m[numar].judet=(char*)malloc(sizeof(char)*(strlen(p)+1));
                strcpy(m[numar].judet,p);
            }
            if(k==1)
            {
                nrpopcurenta=atoi(p);
                if(nrpopcurenta>nrpopmax)
                {
                    nrpopmax=nrpopcurenta;
                    indice=numar;
                }
            }
            if(k==2)
            m[numar].beneficiari=atoi(p);
            if(k==4)
            m[numar].suma=atoi(p);
            if(k==5)
            {
                nrpopcurenta2=atoi(p);
                if(nrpopcurenta2>nrpopmax2)
                {
                    nrpopmax2=nrpopcurenta2;
                    indice2=numar;
                }
            }
            k=k+1;
            p=strtok(NULL,";");
        }
        numar=numar+1;
    }
    fclose(f);
    //puteti activa ce tip de sortare doriti
    //sortjudet();
    //sortsuma();
    FILE *f2=fopen("rezultat.txt","w");
    afisare(f2);
    fclose(f2);
    elibearare();
}
int main()
{
    ptext3();
    return 0;
}
*/

/*
  4.
    Se consideră un fișier text ce conține un număr necunoscut de linii de text de o dimensiune necunoscută. Să se scrie un program ce citește un astfel de fișier și stochează datele într-un tablou alocat dinamic de string-uri C alocate dinamic. Se va folosi o amprentă minimă de memorie. Se vor scrie de asemenea și următoarele funcții

    o funcție void write_sort(char **lines, char *filepath); - funcția va prelua tabloul de linii, le va sorta alfabetic și le va scrie în fișierul cu calea filepath. Se va realiza conex și o funcție de sortare a tabloului de linii lines. Se poate folosi bubble-sort. Pentru compararea aflabetică a două linii se poate folosi funcția strcmp(...)
    o funcție void write_random(char **lines, char *filepath); - funcția va prelua tabloul de linii și le va scrie în fișierul referit prin calea filepath în ordine aleatoare a liniilor. Hint ! Se poate folosi funcția rand(....);
    o funcție uint32_t find_word(char **lines, char *word); - funcția va căuta cuvântul referit prin word în tabloul de linii lines și va returna numărul de apariții.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char **text, **memory_check;
int nr_of_lines = 0;

FILE *file;
void free_memory_text()
{
    for(int i = 0; i < nr_of_lines; i ++)
        free(text[i]);
    free(text);
}

void memory_failed_tasks()
{
    printf("memorie infuficienta\n");
    free_memory_text();
    exit(EXIT_FAILURE);
}

char * read_one_line()
{
    char *this_line =NULL, *memory_test = NULL;
    int nr_of_ch = 0, empty_string = 0;
    char c;
    while(fscanf(file, "%c", &c) == 1)
    {
        if(c == '\n' || c == EOF)
        {
            if(nr_of_ch == 0)
                empty_string = 1;
            break;
        }
        nr_of_ch ++;

        memory_test = (char*)realloc(this_line, nr_of_ch * sizeof(c));
        if(memory_test == NULL)
        {
            memory_failed_tasks();
        }

        this_line = memory_test;
        this_line[nr_of_ch - 1] = c;
    }

    if(nr_of_ch > 0 || empty_string == 1)
    {
        nr_of_ch ++;

        memory_test = (char*)realloc(this_line, nr_of_ch * sizeof(c));

        if(memory_test == NULL)
        {
            memory_failed_tasks();
        }

        this_line = memory_test;
        this_line[nr_of_ch - 1] = '\0';
    }

    return this_line;
}

void print_text(FILE *where)
{
    for(int i = 0; i < nr_of_lines; i ++)
        fprintf(where, "%s\n", text[i]);
}

void opening_error()
{
    printf("eroare deschiodere fisier\n");
    free_memory_text();
    exit(EXIT_FAILURE);
}

void sort_text(char ** lines)
{
    for(int i = 0; i < nr_of_lines - 1; i ++)
    {
        for(int j = i; j < nr_of_lines; j ++)
        {
            if(strcmp(lines[i], lines[j]) == 1)
            {
                char *aux_line = lines[i];
                lines[i] = lines[j];
                lines[j] = aux_line;
            }
        }
    }
}

void write_sort(char **lines,  char *filepath)
{
    file = fopen(filepath, "w");
    if(file == NULL)
        opening_error();

    sort_text(lines);

    print_text(file);
    fclose(file);
}

int main(void)
{
    char *line = NULL;

    file = fopen("scrisoare.txt", "r");
    if(file == NULL)
    {
        opening_error();
    }

    while((line = read_one_line()) != NULL)
    {
        if(strlen(line) == 0)
            continue;
        nr_of_lines ++;

        memory_check = (char**)realloc(text, nr_of_lines * sizeof(char*));
        if(memory_check == NULL)
        {
            memory_failed_tasks();
        }
        text = memory_check;
        text[nr_of_lines - 1] = line;
    }
    fclose(file);
    write_sort(text, "out.txt");
    print_text(stdout);
    free_memory_text();
    return 0;
}
*/

/*
  5.Se consideră un fișier text ce conține in general text, de o dimensiune necunoscută, programul considerând-o infinită. Să se scrie un program care citește acest fișier și scrie în fișierul histo.txt histragama literelor din fișier. Prin histrograma literelor (mari și mici) se înțelege distribuția în procente a acestora, procentul de apariție din total. În fișierul histo.txt se vor scrie linii sub forma : litera - numar apariții. 

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define CHUNK 20;

int main(void)
{
  char c;
  FILE * f;
  int ct=0, v[256]={0};
  f = fopen("fisier.txt", "r");
  if (f==NULL)
    {
      printf("eroare");
      fclose(f);
      exit(-1);
    }
  while((c=getc(f))!=EOF)
    {
      ct++;
      if(isalpha(c))
          v[(int)c]++;
    }
  if (fclose(f)!=0)
    {
      printf("eroare");
      exit(-1);
    }
  FILE *out;
  out = fopen("histograma.txt", "w");
  if (out==NULL)
    {
      printf("eroare");
      fclose(out);
      exit(-1);
    }
   for (int i=32; i<127; i++)
    if(isalpha((char)i))
      {
	float ap = v[(int)i];
	fprintf(out, "%c - %g%%\n", (char)i,(float)ap/ct*100);
      }
   if(fclose(out)!=0)
     {
       printf("eroare");
       exit(-1);
     }
  return 0;
}
*/

/*
  1.Se considera un fisier binar ce contine numere intregi pe 4 bytes. Programul nu va cunoaste dimensiunea fisierului. Sa se scrie un program ce citeste un astfel de fisier si scrie numerele citite intr-un alt fisier in format text hexazecimal cu 8 cifre hexa cate unul pe rand.

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int main (void)
{
  FILE *in;
  in = fopen("integers.bin", "rb");
  if (in ==NULL)
    {
      printf("eroare");
      fclose(in);
      exit(-1);
    }
  uint32_t n;
  FILE *out;
  out = fopen("out_binar.txt", "w");
  if (out == NULL)
    {
      printf("eroare");
      fclose(out);
      exit(-1);
    }
  while(fread(&n, sizeof(uint32_t), 1, in)==1)
    {
      fprintf(out,"%08X\n", n);
    }
  if (fclose(in)!=0)
    {
      printf("eroare");
      exit(-1);
    }
  if (fclose(out)!=0)
    {
      printf("eroare");
      exit(-1);
    }
  return 0;
}
*/

/*
  2.Se considera un fisier binar ce contine numere intregi pe 4 bytes. Programul nu va cunoaste dimensiunea fisierului. Sa se scrie un program format din mai multe functii: o functie ce citeste un astfel de fisier si stocheaza numerele intr-un tablou. O functie care sorteaza acest tablou in ordine descrescatoare, o functie ce scrie un astfel de tablou intr-un alt fisier in format text, fiecare numar in zecimal pe un alt rand.

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define CHUNK 20

uint32_t *v;

void afisare(int size, FILE *out)
{
  for (int i=0; i<size; i++)
    {
      fprintf(out, "%d\n", v[i]);
    }
}

void sortare(int size)
{
  for (int i=0; i<size-1; i++)
    for(int j=i+1; j<size; j++)
      {
	if(v[i]<v[j])
	  {
	    int aux = v[i];
	    v[i]=v[j];
	    v[j]=aux;
	  }
      }
}

void citire(int *size, FILE *in)
{
  int i=0, x;
  while(fread(&x, sizeof(uint32_t), 1, in)==1)
    {
  if(i==*size)
    {
      *size = *size + CHUNK;
      v = (uint32_t*)realloc(v, sizeof(uint32_t)*(*size));
      if (v==NULL)
	{
	  printf("eroare");
	  free(v);
	  exit(-1);
	}
    }
  v[i]=x;
  i++;
    }
  *size=i;
}

int main(int argc, char **argv)
{
  if (argc != 2)
    {
      printf("eroare argumente");
      exit(-1);
    }
  int size=0;
  FILE *in = NULL;
  in = fopen(argv[1], "rb");
  if (in == NULL)
    {
      printf("eroare deschidere");
      fclose(in);
      exit(-1);
    }
  citire(&size, in);
  if (fclose(in)!=0)
    {
      printf("eroare inchidere");
      exit(-1);
    }
  FILE *out = NULL;
  out = fopen("2b.txt", "w");
  if (out == NULL)
    {
      printf("eroare deschidere");
      fclose(out);
      exit(-1);
    }
  sortare(size);
  afisare(size, out);
  if (fclose(out)!=0)
    {
      printf("eroare inchidere");
      exit(-1);
    }
  return 0;
}
*/

/*
  3.Sa se scrie si testeze o functie ce primeste ca argument o cale de fisier sursa si o cale de fisier destinatie. Programul va copia continutul fisierului sursa in fisierul destinatie. Se vor folosi functii specializate de lucru cu fisiere binare.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  if (argc!=3)
    {
      printf("eroare argumente");
      exit(-1);
    }
  FILE *in=NULL;
  in = fopen(argv[1], "rb");
  if (in == NULL)
    {
      printf("eroare deschidere");
      fclose(in);
      exit(-1);
    }
  FILE *out=NULL;
  out = fopen(argv[2], "wb");
  if(out==NULL)
    {
      printf("eroare deschidere");
      fclose(out);
      exit(-1);
    }
  int x;
  while(fread(&x, sizeof(int), 1, in)==1)
    {
      fwrite(&x, sizeof(int), 1, out);
    }
  fclose(in);
  fclose(out);
  return 0;
}
*/

/*
  5.Un fisier binar incepe cu un numar fara semn pe 32 de biti care reprezinta numarul de inregistrari din fisier. Dupa acesta urmeaza inregistrarile, implementate prin structura urmatoare:
- an - nr fara semn pe 16 biti
- luna - nr fara semn pe 8 biti
- zi - nr fara semn pe 8 biti
- idx senzor - nr fara semn pe 8 biti
- valoare - nr cu semn pe 16 biti
O inregistrare codifica valoarea citita de un senzor la o anumita data. Valorile corecte pot fi in intervalul [-1000,1000]. Daca un senzor da din cand in cand valori in afara intervalului, atunci se considera ca are probleme. Daca toate valorile sunt in afara intervalului, atunci senzorul este defect.
Cerinte:
- sa se scrie o functie care creaza un fisier de test, ce cuprinde valori pentru un senzor care merge, altul care are probleme
si altul defect.
- sa se citeasca fisierul de test si sa se afiseze care senzor merge, care are probleme si care e defect.
- se cere de la tastatura un an si o luna. Se cere sa se afiseze toate valorile senzorilor din acel an/luna.*/

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

typedef struct
{
  uint16_t an;
  uint8_t luna, zi, idx;
  int16_t valoare;
}SENZOR;

void creare()
{
  FILE *f=NULL;
  f=fopen("f_test.bin","wb");
  if (f==NULL)
    {
      printf("eroare deschidere");
      fclose(f);
      exit(-1);
    }
  uint32_t x=5; //5 inregistrari in fisier
  fwrite(&x, sizeof(uint32_t), 1, f);
  SENZOR s[]={
    {2022, 3, 23, 1, 100},
    {2022, 5, 12, 2, 1500},
    {2021, 6, 11, 2, 200},
    {2023, 7, 10, 3, -600},
    {2021, 6, 12, 3, 1200},};
    fwrite(s, sizeof(SENZOR), x, f);
    if (fclose(f)!=0)
      {
	printf("eroare inchidere");
	exit(-1);
      }
}

int main(void)
{
  creare();
  /* FILE *in=NULL;
  in = fopen("f_test.bin", "rb");
  if (in == NULL)
    {
      printf("eroare deschidere");
      fclose(in);
      exit(-1);
    }
  uint32_t n;
  fread(&n, sizeof(uint32_t), 1, in);
  if(fclose(in)!=0)
    {
      printf("eroare");
      exit(-1);
      }*/
  return 0;
}
