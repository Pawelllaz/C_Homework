#include <stdio.h>
#include <stdlib.h>
#define N 999
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

	int tab[N],i,max,min;
	float avg,s,ilosc,il;

	ilosc=0;
	s=0;
	il=1;

	printf("wpisz liczbe calkowita:\n");
	for(i=0;i<=N;i++)
	{
		scanf("%d", &tab[i]);
		if(i==N)
			{
				printf("koniec wprowadzania danych\n");
			}

		if(tab[i]==-1)
			{
				tab[i]=1;
				break;
			}
		ilosc++;
		s+=tab[i];
		il*=tab[i];
	}

	max=tab[0];
	min=tab[0];

	for(i=0;i<ilosc;i++)
	{
		if(tab[i]>max)
		{
			max=tab[i];
		}
			if(tab[i]<min)
			{
				min=tab[i];
			}
	}
	avg = s / ilosc;
	int iloczyn=il;
	printf("%.0f\n%d\n%d\n%.6f\n%d\n", ilosc,min,max,avg,iloczyn);

	for(i=0;i<ilosc;i++)
    {
        if(min==tab[i])
        {
            printf("%d ", i);
        }
    }
    printf("\n");
    for(i=0;i<ilosc;i++)
    {
        if(max==tab[i])
        {
            printf("%d ", i);
        }
    }

	return 0;
}
