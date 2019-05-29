#include <stdio.h>
#include <stdlib.h>
#define N 999
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

	int tab[N],i,ilosc;
	float avg,s;

	ilosc=0;
	s=0;

	printf("wpisz liczbe calkowita:\n");
	for(i=0;i<=N;i++)
	{
		scanf("%d", &tab[i]);
		if(i==N)
			{
				printf("koniec wprowadzania danych\n");
			}

		if(tab[i]==0 && i!=0)
			{
				break;
			}
        if(tab[0]==0)
        {
            printf("brak danych");
            return 0;
        }
		ilosc++;
		s+=tab[i];
	}


	avg = s / ilosc;

	int il1=0,il2=0;

	for(i=0;i<ilosc;i++)
	{
		if(tab[i]<avg)
		{
			il1+=tab[i];
		}
			if(tab[i]>avg)
			{
				il2+=tab[i];
			}
	}
	printf("%.2f\n%d\n%d\n", avg,il2,il1) ;

	return 0;
}
