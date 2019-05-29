#include <stdio.h>
#include <stdlib.h>
#define N 999

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	int tab[N],i,c,counter;
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
	
	for(i=counter-1;i>=0;i--)
	{
		if(i%2==0)
		printf("%d ", tab[i]);
	}
	
	return 0;
}
