#include <stdio.h>
#include <stdlib.h>

int valid1(int *sol, int k, int suma, int *cnt)
{
  for (int i=0; i<k; i++)
    if(sol[i]==sol[k]) return 0;
  int s=0;
  for(int i=0; i<=k; i++)
    s+=(sol[i]*cnt[i]);
  if(s<=suma) return 1;
  return 0;
}

int solutie1(int k, int suma, int *sol, int *cnt, int n)
{
  int s=0;
  if (k==n) return 0;
  for(int i=0; i<=k; i++)
    s+=(sol[i]*cnt[i]);
  if(s==suma) return 1;
  return 0;
}

void afisare1(int *sol, int k, int *cnt)
{
  FILE *out=fopen("rec_1.txt", "a");
  if(out==NULL)
    {
      printf("eroare deschidere\n");
      exit(-1);
    }
  for(int i=0; i<=k; i++)
    if(cnt[i]>0)
      fprintf(out,"%d * %d ", cnt[i], sol[i]);
  fprintf(out, "\n");
  fclose(out);
}

void back1(int k, int *sol, int n, int suma, int *bani, int *cnt)
{
  for(int i=0; i<n; i++)
    {
      sol[k]=bani[i];
      for (int j=1; ; j++)
	{
	  cnt[k]=j;
	  if(valid1(sol, k, suma, cnt))
	    {
	      if(solutie1(k, suma, sol, cnt, n))
		afisare1(sol, k, cnt);
	      else
		{
		  back1(k+1, sol, n, suma, bani, cnt);
		}
	    }
	  else break;
	}
      cnt[k]=0;
    }
}

void ex1()
{
  FILE *f=fopen("n.txt", "r");
  if(f==NULL)
    {
      printf("eroare deschidere\n");
      exit(-1);
    }
  int n;
  fscanf(f, "%d", &n);
  int bani[n];
  for(int i=0; i<n; i++)
    fscanf(f, "%d", &bani[i]);
  int suma;
  fscanf(f, "%d", &suma);
  int sol[100], cnt[100];
  for (int i=0; i<100; i++)
    cnt[i]=0;
  back1(0, sol, n, suma, bani, cnt);
  fclose(f);
}

int cmp(const void *el1, const void *el2)
{
  const int* p1=(const int*)el1;
  const int* p2=(const int*)el2;
  if(*p1<*p2) return 1;
  if(*p1>*p2) return -1;
  return 0;
}

int valid2(int *sol, int k, int s, int n, int *credite)
{
  for(int i=0; i<k; i++)
    if(sol[i]==sol[k] || sol[k]<sol[i]) return 0;
  int suma=0;
  for (int i=0; i<=k; i++)
    suma+=credite[sol[i]];
  if(suma-credite[sol[k]] > suma) return 0;
  return 1;
}

int solutie2(int *sol, int k, int s, int *credite)
{
  int suma=0;
  for(int i=0; i<=k; i++)
    suma+=credite[sol[i]];
  if(suma>=s) return 1;
  return 0;
}

void afisare2(int *sol, int k, int *credite)
{
  printf("%d, ", k+1);
  for(int i=0; i<=k; i++)
    printf("%d ", credite[sol[i]]);
  printf("\n");
}

void back2(int k, int *sol, int *credite, int s, int n)
{
  for(int i=0; i<n; i++)
    {
      sol[k]=i;
      if(valid2(sol, k, s, n, credite))
	{
	  if(solutie2(sol, k, s, credite))
	    afisare2(sol, k, credite);
	  else
	    back2(k+1, sol, credite, s, n);
	}
    }
}

void ex2()
{
  FILE *f=fopen("credite.txt", "r");
  if(f==NULL)
    {
      printf("eroare deschidere\n");
      exit(-1);
    }
  int n;
  fscanf(f, "%d", &n);
  int credite[n], sol[n];
  for(int i=0; i<n; i++)
    fscanf(f, "%d", &credite[i]);
  int s;
  fscanf(f, "%d", &s);
  qsort(credite, n, sizeof(int), cmp);
  back2(0, sol, credite, s, n);
  fclose(f);
}

int valid3(int *sol, int k)
{
  if(k==0) return 1;
  int i;
  for(i=0; i<k-1; i++);
  if(sol[i]!=0)
    if(sol[k]!=0) return 0;
  return 1;
}

int solutie3(int *sol, int k, int *ex, int m)
{
  if (k!=m-1) return 0;
  return 1;
}

void afisare3(int *sol, int k)
{
  for (int i=0; i<=k; i++)
    printf("%d ", sol[i]);
  printf("\n");
}

void back3(int k, int *sol, int *ex, int n, int m)
{
  for(int i=0; i<=n; i++)
    {
      sol[k]=i;
      if(valid3(sol, k))
	{
	  if(solutie3(sol, k, ex, m))
	    afisare3(sol, k);
	  else
	    back3(k+1, sol, ex, n, m);
	}
    }
}

void ex3()
{
  int n, m;
  printf("Introduceti numarul de examene si numarul de zile: ");
  scanf("%d %d", &n, &m);
  int sol[m];
  int ex[n];
  for(int i=0; i<n; i++)
    ex[i]=i+1;
  back3(0, sol, ex, n, m);
}


int main(void)
{
  //ex1();
  //ex2();
  ex3();
  return 0;
}
