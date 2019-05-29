#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int read_vector(int tab[])
{
	int r=0,i=0;
	printf("Wprowadz wektor:\n");
	for(i=0;i<150;i++)
	{
		r=scanf("%d",&tab[i]);
		if(!r) return 0;
		if(tab[i]==0)break;
	}
	return i;
}
void display_vector(int tab[],int i)
{
	int j=0;
	for(j=0;j<i;j++)
	{
		printf("%d ",tab[j]);
	}
	printf("\n");
}
