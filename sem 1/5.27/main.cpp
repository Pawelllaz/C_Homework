#include <stdio.h>
#include <stdlib.h>
#define N 2000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

	int tab[N],i,ilosc,a,czy,l[N];

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
	czy=0;

	for(i=0;i<+N;i++)
	{
		l[i]=0;
	}

	for(i=0;i<ilosc;i++)
	{
		l[i] = tab[i];

		for(a=0;a<ilosc;a++)
		{
			if(tab[i]==l[a] && i!=a)
			{
				czy++;
			}
		}

		if(czy==0)
		{
			printf("%d ", tab[i]);
		}
		czy=0;
	}

	return 0;
}
