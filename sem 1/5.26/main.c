#include <stdio.h>
#include <stdlib.h>
#define N 999
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	int tab[N],i,ilosc,d,m,w; // d - dodatkowa liczba / m - liczby mniejsze / w - liczby wieksze
	
	ilosc=0;
	
	printf("wpisz liczbe calkowita:\n");
	for(i=0;i<=N;i++)
	{
		scanf("%d", &tab[i]);
		if(i==N)
			{
				printf("koniec wprowadzania danych\n");
			}

		if(tab[i]==0)
			{
		    	break;
			}
		ilosc++;
	}	
	
	if(tab[0]!=0)
	{
		scanf("%d", &d);
	}
	
	m=0;
	w=0;
	
	for(i=0;i<ilosc;i++)
	{
		if(tab[i]<d)
		{
			m++;
		}
		if(tab[i]>d)
		{
			w++;
		}
	}
	
	printf("\n%d\n%d", m,w);
	
	return 0;
}
