#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

	printf("wpisz liczbe calkowita:");
	int tab[10];
	int i,c,min,max;
	float s=0,avg;

	for(i=0;;i++)
	{
		c=scanf("%d %d", &tab[i],&tab[i+1]);
		if(c!=2)
        {
            printf("error");
            return 1;
        }
		s+=tab[i];
		s+=tab[i+1];
			if(i==8)
			{
				break;
			}
		i++;
	}
	min=tab[0];
	max=tab[0];
	for(i=1;i<10;i++)
    {
        if(tab[i]>max)
            max=tab[i];
        if(tab[i]<min)
            min=tab[i];
    }
	avg = s / 10;

	printf("%.4f\n%d\n%d\n", avg, max, min);

    return 0;
}
