#include <stdio.h>
#include <stdlib.h>
#define N 1000

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	int tab[N],i,c,counter,a,l[N],il;
	counter=0;
	printf("wpisz liczbe:\n");
	for(i=0;i<=N;i++)
	{
		c=scanf("%d", &tab[i]);
		if(tab[i]==0 || c!=1)
		{
			break;
		}
		counter++;
	}
	il=0;
	for(i=0;i<=counter;i++)
	{
		for(a=2;a<N;a++)
		{
			if(i%a!=0)
			{
			if(i==a)
			{
				l[i]=tab[i];
				printf("wykonuje\n");
				il++;
			}
			}
		}
	}
	pritf("%d", il);
	
	for(i=il;i>=0;i--)
	{
		printf("%d ababa ", l[i]);
	}
	
	return 0;
}
