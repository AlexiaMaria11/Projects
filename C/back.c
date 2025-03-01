#include <stdio.h>
#include <stdlib.h>

//1. Se citesc doua numere naturale n si k. Generati si afisati toate toate numerele naturale formate din n cifre care contin exact k cifre de 1.

void afisare1(int *sol ,int n)
{
  for (int i=0; i<n; i++)
    printf("%d", sol[i]);
  printf("\n");
}

void back1(int pas, int *sol, int n, int k, int unu)
{
  if(pas==n)
    {
      if(unu==k)
	afisare1(sol, n);
      return;
    }
  for (int i=0; i<=9; i++)
    {
      sol[pas]=i;
      if(i==1)
	{
	  if(unu+1 <= k)
	  back1(pas+1, sol, n, k, unu+1);
	}
      else
	back1(pas+1, sol, n, k, unu);
    }
}

void ex1()
{
  int n, k;
  int sol[10000];
  printf("Introduceti n: ");
  scanf("%d", &n);
  printf("Introduceti k: ");
  scanf("%d", &k);
  back1(0, sol, n, k, 0);
}

//2.Se citeste un numar natural n. Afisati permutarile multimii 1,2,3...n in care pana la jumatate elementele sunt in ordine descrescatoare, iar de la jumatate pana la final in ordine crescatoare.

void afisare2(int *sol, int n)
{
  for (int i=0; i<n; i++)
    printf("%d ", sol[i]);
  printf("\n");
}

int solutie2(int k, int n, int *sol)
{
  if(k!=n-1)
    return 0;
  int mijloc=n/2;
  for(int i=0; i<mijloc; i++)
    {
      for (int j=i+1; j<=mijloc; j++)
	if(sol[i]<sol[j])
	  return 0;
    }
  for(int i=mijloc; i<n-1; i++)
    {
      for (int j=i+1; j<n; j++)
	if(sol[i]>sol[j])
	  return 0;
    }
  return 1;
}

int valid2(int k, int *sol)
{
  for(int i=0; i<k; i++)
    if(sol[i]==sol[k]) return 0;
  return 1;
}

void back2(int k, int *sol, int n)
{
  for (int i=1; i<=n; i++)
    {
      sol[k]=i;
      if(valid2(k,sol))
	{
	  if(solutie2(k, n, sol))
	    afisare2(sol, n);
	  else
	    back2(k+1, sol ,n);
	}
    }
}

void ex2()
{
  int n;
  int sol[3000];
  printf("Introduceti n: ");
  scanf("%d", &n);
  back2(0, sol, n);
}

//3.Se dau urmatoarele 6 culori: alb, galben, rosu, verde, albastru si negru. Costruiti toate steagurile formate din 3 culori care indeplinesc urmatoarele conditii: - orice steag trebuie sa contina culoarea verde sau culoarea galben la mijloc. - culorile din fiecare steag trebuie sa fie distincte
//alb-0, galben-1, rosu-2, verde-3, albastru-4, negru-5
//sol[1]=3 || sol[1]=1, permutari de culori

int valid3(int k, int *sol)
{
  for(int i=0; i<k; i++)
    if(sol[i]==sol[k])
      return 0;
  return 1;
}

int solutie3(int k, int *sol)
{
  if(k!=5) return 0;
  if(sol[1]==1 || sol[1]==3) return 1;
  else return 0;
}

void afisare3(int *sol)
{
  for (int i=0; i<3; i++)
    printf("%d", sol[i]);
  printf("\n");
}

void back3(int k, int *sol)
{
  for(int i=0; i<6; i++)
    {
      sol[k]=i;
      if(valid3(k, sol))
	{
	  if(solutie3(k, sol))
	    afisare3(sol);
	  else
	    back3(k+1, sol);
	}
    }
}

void ex3()
{
  int sol[10];
  back3(0, sol);
}

//4.Se cere un 0<n<=100 și apoi n valori reale, fiecare reprezentând volumul unui obiect. În final se cere v, volumul unei cutii. Se cere să se umple cutia cu unele dintre obiecte date, astfel încât volumul ei să fie utilizat în mod optim.

void back4(int k, int n, float v_curent, float v_total, float *v, float *maxim, int *sol, float volum)
{
  if(k==n)
    {
      if(v_curent > *maxim && v_total<=volum)
	{
	  *maxim=v_curent;
	  for (int i=0; i<n; i++)
	    sol[i]=(int)v[i];
	}
      return;
    }
  sol[k]=1;
  back4(k+1, n, v_curent+v[k], v_total+v[k], v, maxim, sol, volum);
  sol[k]=0;
  back4(k+1, n, v_curent, v_total, v, maxim, sol, volum);
}

void ex4()
{
  int n;
  printf("Introduceti n: ");
  scanf("%d", &n);
  float v[n];
  printf("Introduceti %d numere:\n", n);
  for (int i=0; i<n; i++)
    scanf("%f", &v[i]);
  printf("Introduceti volumul cutiei: ");
  float volum;
  scanf("%f", &volum);
  float maxim=0.0;
  int sol[n];
  back4(0, n, 0.0, 0.0, v, &maxim, sol, volum);
  printf("Volumul utilizat: %f\n", maxim);
}

//5.De-a lungul unei șosele trebuie amplasate una lângă alta următoarele entități: case, blocuri, grădini,ateliere. O entitate se poate învecina doar cu una de același tip (ex: casă cu casă) sau conform următoarelor reguli(orice relație o implică și pe cea inversă): un bloc poate avea ca vecini case; o casă sau un atelier poate avea ca vecini grădini. Se cer de la tastatură numerele c,b,g,a care reprezintă respectiv numărul de case, blocuri, grădini și ateliere. Să se determine toate variantele în care acestea pot fi aranjate

//casa-0, bloc-1, gradina-2, atelier-3
//se poate 00 11 22 33
//01 sau 10 + 02 sau 20 + 32 sau 23

void afisare5(int *sol, int n)
{
  for (int i=0; i<n; i++)
    printf("%d", sol[i]);
  printf("\n");
}

int valid5(int k, int *sol)
{
  if(k==0) return 1;
  switch(sol[k])
    {
    case 0:
      if(sol[k-1] == 0 || sol[k-1]==1 || sol[k-1]==2) return 1;
      break;
    case 1:
      if(sol[k-1]==0 || sol[k-1]==1) return 1;
      break;
    case 2:
      if(sol[k-1]==0 || sol[k-1]==3|| sol[k-1]==2 ) return 1;
      break;
    case 3:
      if(sol[k-1]==0 || sol[k-1]==2 || sol[k-1]==3) return 1;
      break;
    }
  return 0;
}

void back5(int k, int c, int cc, int b, int bc, int g, int gc, int a, int ac, int total, int *sol)
{
  if(cc>c || gc>g || bc>b || ac>a) return;
  if(k==total)
    {
      if(cc=c && gc==g && bc==b && ac==a)
	afisare5(sol, total);
      return;
    }
  for (int i=0; i<4; i++)
    {
      sol[k]=i;
      if(valid5(k, sol))
	{
	  int cc_nou = cc+(i==0);
	  int bc_nou = bc+(i==1);
	  int gc_nou = gc+(i==2);
	  int ac_nou = ac+(i==3);
	  back5(k+1, c, cc_nou, b, bc_nou, g, gc_nou, a, ac_nou, total, sol);
	}
    }
}

void ex5()
{
  int c, b, g, a;
  int sol[10];
  printf("Introduceti c, b, g, a: ");
  scanf("%d %d %d %d", &c, &b, &g, &a);
  int total=c+b+g+a;
  back5(0, c,0, b,0, g,0, a,0, total, sol); 
}

int main(void)
{
  //ex1();
  //ex2();
  ex3();
  //ex4();
  //ex5();
  return 0;
}
