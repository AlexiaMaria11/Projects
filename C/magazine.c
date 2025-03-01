#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  int h_intrare, h_iesire;
  int m_intrare, m_iesire;
}timp;

int main(void)
{
  int n;
  printf("Introduceti numarul de magazine: ");
  scanf("%d", &n);
  timp mag[n];
  for (int i=0; i<n; i++)
    {
      printf("Introduceti ora si minutul de intrare in magazinul %d: ", i+1);
      scanf("%d %d", &mag[i].h_intrare, &mag[i].m_intrare);
      if(mag[i].h_intrare > 24 || mag[i].m_intrare>59)
	{
	  printf("ore de intrare introduse gresit\n");
	  return 0;
	}
      printf("Introduceti ora si minutul de iesire din magazinul %d: ", i+1);
      scanf("%d %d", &mag[i].h_iesire, &mag[i].m_iesire);
      if(mag[i].h_iesire > 24 || mag[i].m_iesire>59)
	{
	  printf("ore de iesire introduse gresit\n");
	  return 0;
	}
    }
  for(int i=0; i<n-1; i++)
    {
      for(int j=i+1; j<n; j++)
	{
	  if(mag[i].h_iesire != mag[j].h_iesire)
	    {
	      if(mag[i].h_iesire > mag[j].h_iesire)
		{
		  timp aux=mag[i];
		  mag[i]=mag[j];
		  mag[j]=aux;
		}
	    }
	  else
	    {
	      if(mag[i].m_iesire > mag[j].m_iesire)
		{
		  timp aux=mag[i];
		  mag[i]=mag[j];
		  mag[j]=aux;
		}
	    }
	} 
    }
  for(int i=0; i<n; i++)
    {
      printf("intrare: %2d %2d - iesire: %2d %2d\n", mag[i].h_intrare, mag[i].m_intrare, mag[i].h_iesire, mag[i].m_iesire);
    }
  int k=0;
  for (int i=1; i<n; i++)
    if(mag[i].h_iesire != mag[k].h_iesire)
      {
	if(mag[i].h_intrare >= mag[k].h_iesire)
	  {
	    printf("intervalul orar: %2d %2d - %2d %2d\n", mag[i].h_intrare, mag[i].m_intrare, mag[i].h_iesire, mag[i].m_iesire);
	    k=i;
	  }
      }
    else
      if(mag[i].m_intrare >= mag[k].m_iesire)
	{
	  printf("intervalul orar: %2d %2d - %2d %2d\n", mag[i].h_intrare, mag[i].m_intrare, mag[i].h_iesire, mag[i].m_iesire);
	  k=i;
	}
  return 0;
}
