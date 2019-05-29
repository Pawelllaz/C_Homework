#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int i;
	int a;
	printf("wpisz liczbe:");
	scanf("%d", &a);

	int tak=0,nie=0;

	if(a < 2)
	{
		printf("Error");
	}
	else
    {
		for(i=1;i<a;i++)
		{
		    //printf("%d\n", i);
            if (a%a==0 && a%1==0 && a!=i && a%i!=0 )
			{
				tak++;
			}
			else if(a%i==0 && i!=1)
			{
				nie++;
			}
		}
	}

	if(tak!=0 && nie==0)
    {
        printf("TAK");
    }
    if(nie!=0)
    {
        printf("NIE");
    }2

	return 0;
}
