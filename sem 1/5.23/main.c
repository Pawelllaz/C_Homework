#include <stdio.h>
#include <stdlib.h>
#define N 999	
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {
	
	int tab[N],i,il=0,max,w;
	max=tab[0];
	w=0;
	
	printf("wpisz liczbe:\n");
	for(i=0;i<=N;i++)
	{
		scanf("%d", &tab[i]);
		w++;
		if(i==N)
		{
			printf("koniec wczytywania danych\n");
		}
		if(tab[i]>max)
		{
			max=tab[i];
		}
		if(tab[i]==0 && w<=3)
		{
			printf("zbyt malo danych, dopisz wiecej\n");
		}
		if(tab[i]==0 && w>=3)
		{
			break;
		}
		il++;
	}
	int c[N];
	
	for(i=0;i<=N;i++)
	{
		c[i]=0;
	}
	
	int ic=0,p,a=0; // a zwieksza c[]

	for(i=0;i<il;i++)
	{
			if(tab[i]>tab[i+1] && tab[i+1]<tab[i+2] && tab[i+2]!=0 && tab[i+1]!=0)
			{
				c[a]+=1; // zawsze o 1 za malo pamietaj aby pozniej dodac
				printf("%d ", tab[i]);
			}
			else if(tab[i]<tab[i+1] && tab[i+1]>tab[i+2] && tab[i+2]!=0 && tab[i+1]!=0)
			{
				c[a]+=1; // zawsze o 1 za malo pamietaj aby pozniej dodac
				printf("%d ", tab[i]);
			}
			else
			{
				if(c[a]!=0)
				{
					printf("%d %d\nnr indeksu: %d\n\n",tab[i],tab[i+1],i-c[a]);
					p=max;
					a++;
					ic++;
				}
			}
		
	}
	int q,b; // q to jest ilosc elementow najdluzszego ciagu
	q=c[0];
	for(b=0;b<ic;b++)
	{
		if(c[b+1]>c[b])
		{
			q=c[b+1];	
		}
	}
	q+=2;
	printf("ilosc ciagow: %d\nilosc elementow najdluzszego ciagu: %d", ic,q);
	
	return 0;
}
