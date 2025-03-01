#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ex1()
{
  int n;
  int **a;
  FILE *f=fopen("numere_in.txt", "r");
  if(f==NULL)
    {
      printf("eroare deschidere\n");
      exit(-1);
    }
  fscanf(f, "%d", &n);
  int radical=sqrt(n);
  a=(int**)malloc(radical*sizeof(int));
  if(a==NULL)
    {
      printf("memorie insuficienta\n");
      exit(-1);
    }
  for (int i=0; i<radical; i++)
    {
      a[i]=(int*)malloc(n*sizeof(int));
      if(a[i]==NULL)
	{
	  for(i--; i>=0; i--)
	    free(a[i]);
	  free(a);
	  printf("memorie insuficienta\n");
	  exit(-1);
	}
    }
  int *nr=(int*)malloc(n*sizeof(int));
  if(nr==NULL)
    {
      printf("memorie insuficienta\n");
      exit(-1);
    }
  for (int i=0; i<n; i++)
    fscanf(f, "%d", &nr[i]);
  int k=0;
  int stanga=0, dreapta=radical-1, sus=0, jos=radical-1;
  while(stanga<=dreapta && sus<=jos)
    {
      for(int i=sus; i<=jos; i++)
	a[i][stanga]=nr[k++];
      stanga++;
      for (int i=stanga; i<=dreapta; i++)
	a[jos][i]=nr[k++];
      jos--;
      for(int i=jos; i>=sus; i--)
	a[i][dreapta]=nr[k++];
      dreapta--;
      for (int i=dreapta; i>=stanga; i--)
	a[sus][i]=nr[k++];
      sus++;
    }
  FILE *f_out=fopen("numere_out.txt", "w");
  if(f_out==NULL)
    {
      printf("eroare deschidere\n");
      exit(-1);
    }
  for (int i=0; i<radical; i++)
    {
      for (int j=0; j<radical; j++)
	fprintf(f_out, "%d ", a[i][j]);
      fprintf(f_out, "\n");
    }
  for (int i=0; i<radical; i++)
    free(a[i]);
  free(a);
  free(nr);
  fclose(f);
  fclose(f_out);
}

void ex2()
{
  int n, m;
  int **a;
  printf("Introduceti n si m: ");
  scanf("%d %d", &n, &m);
  a=(int**)malloc(n*sizeof(int*));
  if(a==NULL)
    {
      printf("memorie insuficienta\n");
      exit(-1);
    }
  for (int i=0; i<n; i++)
    {
      a[i]=(int*)malloc(m*sizeof(int));
      if(a[i]==NULL)
	{
	  for(i--; i>=0; i--)
	    free(a[i]);
	  free(a);
	  printf("memorie insuficienta\n");
	  exit(-1);
	}
    }
  for(int i=0; i<n; i++)
    for (int j=0; j<m; j++)
      a[i][j]=0;
  int c=1, rand=0, col=0, d=0; //0-dreapta jos, 1-drepata sus, 2-stanga sus, 3-stanga jos
  do
    {
      a[rand][col]=c++;
      switch(d)
	{
	case 0:
	  {
	    if(rand<=n-2)
	      {
		rand++;
		col++;
	      }
	    else
	      {
		d=1;
		rand--;
		col++;
	      }
	    break;
	  }
	case 1:
	  {
	    if(col<=m-2)
	      {
		rand--;
		col++;
	      }
	    else
	      {
		d=2;
		col--;
		rand--;
	      }
	    break;
	  }
	case 2:
	  {
	    if(rand>=1)
	      {
		rand--;
		col--;
	      }
	    else
	      {
		d=3;
		rand++;
		col--;
	      }
	    break;
	  }
	case 3:
	  {
	    if(rand<=n-2)
	      {
		rand++;
		col--;
	      }
	    else
	      {
		d=0;
		rand--;
		col--;
	      }
	    break;
	  }
	}
    }while(col);
  a[rand][col]=c;
  for (int i=0; i<n; i++)
    {
      for (int j=0; j<m; j++)
	printf("%2d ", a[i][j]);
      printf("\n");
    }
  for (int i=0; i<n;i++)
    free(a[i]);
  free(a);
}

int main(void)
{
  //ex1();
  ex2();
  return 0;
}
