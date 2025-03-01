#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//1.Fie n un număr natural nenul. Să se genereze permutările de n elemente.

int valid1(int k, int *sol)
{
  for (int i=0; i<k; i++)
    if(sol[i]==sol[k])
      return 0;
  return 1;
}

int solutie1(int k, int n)
{
  return (k==n-1);
}

void afisare1(int *sol, int n)
{
  for (int i=0; i<n; i++)
    printf("%d ", sol[i]);
  printf("\n");
}

void back1(int k, int n, int *sol)
{
  for (int i=1; i<=n; i++)
    {
      sol[k]=i;
      if(valid1(k, sol))
	{
	  if(solutie1(k,n))
	    afisare1(sol, n);
	  else
	    back1(k+1, n, sol);
	}
    }
}

void ex1()
{
  int n;
  printf("Introduceti un n: ");
  scanf("%d", &n);
  int sol[1000];
  back1(0, n, sol);
}

//2.Fie n şi m două numere naturale nenule, m <= n. Să se genereze aranjamentele de n elemente luate câte m

int valid2(int k, int *sol)
{
  for (int i=0; i<k; i++)
    if(sol[i]==sol[k])
      return 0;
  return 1;
}

int solutie2(int k, int m)
{
  return (k==m-1);
}

void afisare2(int *sol, int m)
{
  for (int i=0; i<m; i++)
    printf("%d ", sol[i]);
  printf("\n");
}

void back2(int k, int n, int m, int *sol)
{
  for (int i=1; i<=n; i++)
    {
      sol[k]=i;
      if(valid2(k, sol))
	{
	  if(solutie2(k,m))
	    afisare2(sol, m);
	  else
	    back2(k+1, n, m, sol);
	}
    }
}

void ex2()
{
  int n, m;
  printf("Introduceti n si m: ");
  scanf("%d %d", &n, &m);
  int sol[1000];
  back2(0, n, m, sol);
}

int valid3(int k, int *sol)
{
  for (int i=0; i<k; i++)
    if(sol[i]==sol[k] ||  sol[k]<sol[i])
      return 0;
  return 1;
}

int solutie3(int k, int m)
{
  return (k==m-1);
}

void afisare3(int *sol, int m)
{
  for (int i=0; i<m; i++)
    printf("%d ", sol[i]);
  printf("\n");
}

void back3(int k, int n, int m, int *sol)
{
  for (int i=1; i<=n; i++)
    {
      sol[k]=i;
      if(valid3(k, sol))
	{
	  if(solutie3(k,m))
	    afisare3(sol, m);
	  else
	    back3(k+1, n, m, sol);
	}
    }
}

void ex3()
{
  int n, m;
  printf("Introduceti n si m: ");
  scanf("%d %d", &n, &m);
  int sol[1000];
  back3(0, n, m, sol);
}

//4.Să se genereze toate submulţimile unei mulţimi, ale cărei elemente se introduc de la tastatură.

int valid4(int k, int *sol)
{
  for (int i=0; i<k; i++)
    if(sol[k]==sol[i] || sol[k]<sol[i]) return 0;
  return 1;
}

void afisare4(int *sol, int k)
{
  for (int i=0; i<=k; i++)
    printf("%d ", sol[i]);
  printf("\n");
}

void back4(int k, int *v, int *sol, int n)
{
  for (int i=0; i<n; i++)
    {
      sol[k]=v[i];
      if(valid4(k, sol))
	{
	  afisare4(sol, k);
	  back4(k+1, v, sol, n);
	}
    }
}

void ex4()
{
  int n;
  printf("Introduceti un n: ");
  scanf("%d", &n);
  int v[n], sol[n];
  printf("Introduceti %d elemente:\n", n);
  for (int i=0; i<n; i++)
    scanf("%d", &v[i]);
  back4(0, v, sol, n);
}

//5.Să se genereze toate funcţiile injective f:{1,2,…,n}--> {1,2,…,m}

int solutie5(int k, int n)
{
  return (k==n-1);
}

int valid5(int k, int *sol)
{
  for (int i=0; i<k; i++)
    if(sol[i]==sol[k])
      return 0;
  return 1;
}

void afisare5(int *sol, int n)
{
  for (int i=0; i<n; i++)
    printf("f(%d)=%d ", i+1, sol[i]);
  printf("\n");
}

void back5(int k, int n, int m, int *sol)
{
  for (int i=1; i<=m; i++)
    {
      sol[k]=i;
      if(valid5(k, sol))
	{
	  if(solutie5(k, n))
	    afisare5(sol, n);
	  else
	    back5(k+1, n, m, sol);
	}
    }
}

void ex5()
{
  int n, m;
  printf("Introduceti n si m: ");
  scanf("%d %d", &n, &m);
  int sol[n];
  back5(0, n, m, sol);
}

//6.Să se genereze toate funcţiile surjective f:{1,2,…,n} -> {1,2,…,m}

int valid6(int *count, int m)
{
  for (int i=0; i<m; i++)
    if(count[i]==0) return 0;
  return 1;
}

void afisare6(int n, int *sol)
{
  for (int i=0; i<n; i++)
    printf("f(%d)=%d ", i+1, sol[i]);
  printf("\n");
}

void back6(int k, int n, int m, int *sol, int *count)
{
  if(k==n)
    {
      if(valid6(count,m))
	afisare6(n, sol);
      return;
    }
  for (int i=0; i<m; i++)
    {
      sol[k]=i+1;
      count[i]++;
      back6(k+1, n, m, sol, count);
      count[i]--;
    }
}

void ex6()
{
  int n, m;
  printf("Introduceti n si m: ");
  scanf("%d %d", &n, &m);
  int sol[1000], count[1000];
  for (int i=0; i<n; i++)
    count[i]=0;
  back6(0, n, m, sol, count);
}

//7.Scrieți un program care afișează toate posibilitatile de a aranja elementele unui vector întreg astfel incat în șirul rezultat să nu existe 2 numere negative alaturate

int valid7(int k, int *sol)
{
  if(k==0) return 1;
  if(sol[k]<0 && sol[k-1]<0)
    return 0;
  for (int i=0; i<k; i++)
    if(sol[i]==sol[k]) return 0;
  return 1;
}

int solutie7(int n, int k)
{
  return (k==n-1);
}

void afisare7(int *sol, int n)
{
  for (int i=0; i<n; i++)
    printf("%d ", sol[i]);
  printf("\n");
}

void back7(int k, int n, int *sol, int *v)
{
  for (int i=0; i<n; i++)
    {
      sol[k]=v[i];
      if(valid7(k, sol))
	{
	  if(solutie7(n, k))
	    afisare7(sol, n);
	  else
	    back7(k+1, n, sol, v);
	}
    }
}

void ex7()
{
  int n;
  printf("Introduceti numarul de elemente: ");
  scanf("%d", &n);
  int v[n], sol[n];
  printf("Introduceti %d numere:\n", n);
  for (int i=0; i<n; i++)
    scanf("%d", &v[i]);
  back7(0, n, sol, v);
}

//8.Să se plaseze n regine pe o tablă de şah de dimensiune nxn astfel încât oricare două regine să nu se atace. Conform regulilor de şah două regine se atacă dacă sunt pe aceeaşi linie, coloană sau diagonală

int valid8(int k, int *sol, int n)
{
  for (int i=0; i<k; i++)
    {
      if(sol[i]==sol[k]) return 0;
      if(abs(i-k) == abs(sol[i]-sol[k]))
	return 0;
    }
  return 1;
}

int solutie8(int k, int *sol, int n)
{
  return k==n-1;
}

void afisare8(int *sol, int n)
{
  for (int i=0; i<n; i++)
    printf("Linie %d Coloana %d\n", sol[i], i);
  printf("\n");
}

void back8(int k, int *sol, int n)
{
  for (int i=0; i<n; i++)
    {
      sol[k]=i;
      if(valid8(k, sol, n))
	{
	  if(solutie8(k, sol, n))
	    afisare8(sol, n);
	  else
	    back8(k+1, sol, n);
	}
    }
}

void ex8()
{
  int n=5;
  int sol[1000];
  back8(0, sol, n);
}

//9.Se considera un număr par n. Generati toate șirurile de paranteze echilibrate de lungime n

void afisare9(char *sol, int n)
{
  for (int i=0; i<n; i++)
    printf("%c", sol[i]);
  printf("\n");
}

void back9(int k, char *sol, int n, int a, int b)
{
  if(b==n/2)
    {
      afisare9(sol, n);
      return;
    }
  if(a<n/2)
    {
      sol[k]='(';
      back9(k+1, sol, n, a+1, b);
    }
  if(b<a)
    {
      sol[k]=')';
      back9(k+1, sol, n, a, b+1);
    }
}

void ex9()
{
  int n;
  printf("Introduceti un numar par: ");
  scanf("%d", &n);
  char sol[n];
  back9(0, sol, n, 0, 0);
}

//10.Se citeşte de la tastatură dimensiunea n a unei matrici binare (cu elem. 0 sau 1). Să se formeze toate matricele posibile astfel încât pe fiecare linie respectiv coloană să fie exact un element nenul.

int valid_10(int k, int i, int **a)
{
  for(int j=0; j<i; j++)
    if(a[k][j]==1) return 0;
  for (int j=0; j<k; j++)
    if(a[j][i]==1) return 0;
  return 1;
}

void afisare_10(int **a, int n)
{
  for (int i=0; i<n; i++)
    {
      for (int j=0; j<n; j++)
	printf("%d ", a[i][j]);
      printf("\n");
    }
  printf("\n");
}

void back_10(int k, int **a, int n)
{
  if(k==n)
    {
      afisare_10(a, n);
      return;
    }
  for (int i=0; i<k; i++)
    {
      if(valid_10(k,i, a))
	{
	  a[k][i]=1;
	  back_10(k+1, a, n);
	  a[k][i]=0;
	}
    }
}

void ex10()
{
  printf("Introduceti un n: ");
  int n; scanf("%d", &n);
  int **a=(int**)malloc(n*sizeof(int*));
  if(a==NULL)
    return;
  for (int i=0; i<n; i++)
    {
      a[i]=(int*)malloc(n*sizeof(int));
      if(a[i]==NULL)
	return;
    }
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      a[i][j]=0;
  back_10(0, a, n);
}

int main(void)
{
  //ex1();
  //ex2();
  //ex3();
  //ex4();
  //ex5();
  //ex6();
  //ex7();
  //ex8();
  //ex9();
  ex10();
  return 0;
}
