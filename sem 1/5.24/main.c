#include <stdio.h>
#include <stdlib.h>
#define N 999

int main() {

	float tab[N],avg,s;
	int i,ilosc;
	ilosc=0;

	printf("wpisz liczbe:\n");
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

	for(i=0;i<ilosc-1;i++)
	{
		if(tab[0]==0)
		{
			printf("0");
			break;
		}
		s = tab[i]+tab[i+1];
		avg = s / 2;
		printf("%.2f ", avg);
	}

	return 0;
}
