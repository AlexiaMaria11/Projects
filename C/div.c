#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//1.Se consideră un șir cu n elemente, numere naturale. Folosind metoda Divide et Impera, determinați câte elemente impare sunt în acest șir.

int count(int *v, int a, int b)
{
  if (a==b)
    return v[a]%2;
  int mijloc=(a+b)/2;
  int stanga=count(v, a, mijloc);
  int dreapta=count(v, mijloc+1, b);
  return stanga + dreapta;
}

void ex1()
{
  int n;
  printf("Introduceti un n: ");
  scanf("%d", &n);
  int v[n];
  printf("Introduceti %d numere:\n", n);
  for (int i=0; i<n; i++)
    scanf("%d", &v[i]);
  printf("Sunt %d numere impare\n", count(v, 0, n-1));
}

//2.Se dă funcția f(x)=sin(x)+sin(2∗x)+x și o valoare y. Știind că funcția este strict crescătoare pe intervalul [0,1), se cere să se găsească pentru ce x∈[0,1) avem că f(x) ≈ y(aproximare cu 8 zecimale)

float f(float x)
{
  return sin(x) + sin(2*x) + x;
}

float cauta(float y)
{
  float a=0.0, b=1.0, mijloc;
  while((b-a)>pow(2.73, -8))
    {
      mijloc=(a+b)/2.0;
      float f_m=f(mijloc);
      if(fabs(f_m-y)<pow(2.73, -8))
	return mijloc;
      else
	{
	  if(f_m<y)
	    a=mijloc;
	  else
	    b=mijloc;
	}
    }
  return (a+b)/2.0;
}

void ex2()
{
  float y;
  printf("Introduceti y: ");
  scanf("%f", &y);
  if(y<f(0) || y>f(1-pow(2.73, -8)))
     printf("nu exista\n");
  else
    printf("Valoarea este: %f\n", cauta(y));
}

//3.Se dă un vector x cu n elemente numere naturale, ordonate crescător, și un vector y cu m elemente, de asemenea numere naturale. Verificați pentru fiecare element al vectorului y dacă apare în x. Se va folosi tehnica Divide et Impera.

int cautare_element(int *x, int a, int b, int el)
{
  if(a<=b)
    {
      int mijloc=(a+b)/2;
      if(x[mijloc]==el) return 1;
      if(x[mijloc]>el) return cautare_element(x, a, mijloc, el);
      else return cautare_element(x, mijloc+1, b, el);
    }
  return 0;
}

int cauta_vector(int *x, int n, int *y, int m)
{
  for (int i=0; i<m; i++)
    {
      if(cautare_element(x, 0, n-1, y[i])==0)
	return 0;
    }
  return 1;
}

void ex3()
{
  int n, m;
  printf("Introduceti un n: ");
  scanf("%d", &n);
  int x[n];
  printf("Introduceti %d numere orodonate crescator\n", n);
  for (int i=0; i<n; i++)
    scanf("%d", &x[i]);
  printf("Introduceti un m: ");
  scanf("%d", &m);
  int y[m];
  printf("Introduceti %d numere\n", m);
  for (int i=0; i<m; i++)
    scanf("%d", &y[i]);
  if(cauta_vector(x, n, y, m)==1)
    printf("Vectorul y apare in vectorul x\n");
  else
    printf("Vectorul y nu apare in vectorul x\n");
}

//4.Se consideră o matrice cu m linii și n coloane, numere naturale. Folosind metoda Divide et Impera, determinați suma numerelor pare din matrice

int suma_pare(int **matrix, int startRow, int endRow, int startCol, int endCol) {
    if (startRow == endRow && startCol == endCol) {
        if (matrix[startRow][startCol] % 2 == 0) {
            return matrix[startRow][startCol];
        } else {
            return 0;
        }
    }
    int midRow = (startRow + endRow) / 2;
    int midCol = (startCol + endCol) / 2;
    int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
    if (startRow <= midRow && startCol <= midCol) {
        sum1 = suma_pare(matrix, startRow, midRow, startCol, midCol);
    }
    if (startRow <= midRow && midCol + 1 <= endCol) {
        sum2 = suma_pare(matrix, startRow, midRow, midCol + 1, endCol);
    }
    if (midRow + 1 <= endRow && startCol <= midCol) {
        sum3 = suma_pare(matrix, midRow + 1, endRow, startCol, midCol);
    }
    if (midRow + 1 <= endRow && midCol + 1 <= endCol) {
        sum4 = suma_pare(matrix, midRow + 1, endRow, midCol + 1, endCol);
    }
    return sum1 + sum2 + sum3 + sum4;
}

void ex4()
{
  int m, n;
  printf("Introduceti m linii si n coloane: ");
  scanf("%d %d", &m, &n);
  int **a=(int**)malloc(m+sizeof(int*));
  if(a==NULL)
    {
      printf("memorie insuficienta\n");
      return;
    }
  for (int i=0; i<m; i++)
    {
      a[i]=(int*)malloc(n*sizeof(int));
      if(a[i]==NULL)
	{
	  printf("memorie insuficienta\n");
	  return;
	}
    }
  printf("Introduceti elementele matricii:\n");
  for (int i=0; i<m; i++)
    for (int j=0; j<n; j++)
      scanf("%d", &a[i][j]);
  printf("Suma elementelor pare este %d\n", suma_pare(a, 0, m-1, 0, n-1));
}

//5. Se dă un vector cu n elemente numere naturale. Folosind metoda Divide et Impera să se verifice dacă are elementele ordonate strict crescător sau strict descrescător.

int crescator(int *v, int a, int b)
{
  if(a>=b) return 1;
  int mijloc=(a+b)/2;
  if(crescator(v, a, mijloc)==0) return 0;
  if(crescator(v, mijloc+1, b)==0) return 0;
  if(v[mijloc] >= v[mijloc+1]) return 0;
  return 1;
}

int descrescator(int *v, int a, int b)
{
  if(a>=b) return 1;
  int mijloc=(a+b)/2;
  if(descrescator(v, a, mijloc)==0) return 0;
  if(descrescator(v, mijloc+1, b)==0) return 0;
  if(v[mijloc] <= v[mijloc+1]) return 0;
  return 1;
}

void ex5()
{
  int n;
  printf("Introduceti n: ");
  scanf("%d", &n);
  int v[n];
  printf("Introduceti %d elemente\n", n);
  for (int i=0; i<n; i++)
    scanf("%d", &v[i]);
  if(crescator(v, 0, n-1))
    printf("strict crescator\n");
  else
    {
      if(descrescator(v, 0, n-1))
	printf("strict descrescator\n");
      else
	printf("neordonat\n");
    }
}

//6.Se dă un şir x format din n numere naturale nenule. Pentru fiecare element xi din şir să se verifice dacă există un număr k astfel încât elementul xi să fie egal cu suma primelor k elemente din şir.

void sume_partiale(int *x, int *sume, int a, int b)
{
  sume[a]=x[a];
  for (int i=a+1; i<=b; i++)
    sume[i]=sume[i-1]+x[i];
}

int ver(int *x, int *sume, int a, int b)
{
  if(a>=b) return 0;
  int mijloc=(a+b)/2;
  sume_partiale(x, sume, a, mijloc);
  sume_partiale(x, sume, mijloc+1, b);
  for (int i=a; i<=b; i++)
    for (int j=a; j<=b; j++)
      if(x[i]==sume[j])
	{
	  printf("%d\n", j);
	  return 1;
	}
  int st=ver(x, sume, a, mijloc);
  int dr=ver(x, sume, mijloc+1, b);
  return st||dr;
}

void verifica_sume(int *x, int n)
{
  int sume[n];
  if(!ver(x, sume, 0, n-1))
    printf("0\n");
}

void ex6()
{
  printf("Introduceti un n: ");
  int n; scanf("%d", &n);
  int x[n];
  printf("Introduceti %d numere\n", n);
  for (int i=0; i<n; i++)
    scanf("%d", &x[i]);
  verifica_sume(x, n);
}

int main(void)
{
  //ex1();
  //ex2();
  //ex3();
  //ex4();
  //ex5();
  ex6();
  return 0;
}
