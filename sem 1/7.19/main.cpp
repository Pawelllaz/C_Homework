#include <stdio.h>
#include <stdlib.h>

int czy_pierwsza(int a)
{
    if(a<=1)
        {
            return 0;
        }
    if(a==2) return 1;
    int i,spr=0;
    for(i=2;i<a;i++)
    {
        if(a%i==0 && a!=i)
        {
            spr++;
        }
    }
    if(spr!=0)
    {
        return 0;
    }
    return 1;
}
//-----------------------------------

int goldbach(int x)
{
	int i,spr=0,czy=0,counter=0;

    if(x%2!=0) return 0;

	for (i=1; i<x; i++)
	{
		spr=czy_pierwsza(i);

		if (spr==1)
		{
			czy=czy_pierwsza(x-i);
			if (czy==1)
			{
				printf("(%d, %d) ", i, x-i);
				counter++;
			}
		}
		if (i==x-1 && counter>0) return 1;
	}
	return 0;
}
//------------------------------------------
int main()
{
    int i,x1,x2;

    printf("Podaj x1: ");
    scanf("%d", &x1);

    printf("Podaj x2: ");
    scanf("%d", &x2);

    for (i=x1;i<=x2;i++)
    {
    	if (i%2==0)
    	{
				printf("%d: ", i);
				goldbach(i);
				printf("\n");
    	}
    }
    return 0;
}
