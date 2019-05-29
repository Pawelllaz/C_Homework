#include <stdio.h>
#include <stdlib.h>
#define N 999
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

	int i,ilosc,p,a;
	float tab[N],w;

	ilosc=0;

	printf("wpisz liczbe calkowita:\n");
	for(i=0;i<=N;i++)
	{
		scanf("%f", &tab[i]);
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

	p = ilosc /2; 			// p to polowa z ilosci

	a = ilosc;

	for(i=0;i<=ilosc;i++)
	{
		if(tab[0]!=0)
		{
			if(i<p)
			{
				a--;
				w=tab[a] - tab[i];
				printf("%.2f ", w);
			}
			else
			{
				if(ilosc%2!=0)
				{
					printf("%.2f", tab[p]);
				}
				break;
			}
		}
	}

	return 0;
}
