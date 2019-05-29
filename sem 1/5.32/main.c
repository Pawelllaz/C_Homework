#include <stdio.h>
#define N 100

int main() {
	
	int tab1[N],tab2[N],i,r,counter1,counter2,c,counter,spr;
	
	printf("wpisz liczbe:\n");
	spr=0;
	counter1=0;
	counter2=0;
	for(i=0;i<N;i++)
	{
		c=scanf("%d", &tab1[i]);
		if(tab1[i]==0)
		{	
			break;
		}
		else if(c!=1 || tab1[0]==0)
		{
			spr=1;
			break;
			printf("0");
		}
		counter1++;
	}
	for(i=0;i<N;i++)
	{
		if(spr==1)
			break;
		c=scanf("%d", &tab2[i]);
		
		if(tab2[i]==0 || c!=1)
		{	
			break;
		}
		counter2++;
	}
	if(counter1 < counter2)
	{
		counter=counter1;
	}
	else
	{
		counter=counter2;
	}
	for(i=0;i<counter;i++)
	{
		r=tab1[i]*tab2[counter2-i-1];
		printf("%d ",r);
	}
	
	return 0;
}
