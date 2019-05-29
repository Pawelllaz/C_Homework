#include <stdio.h>
#include <stdlib.h>

long power_it(int a, int n)
{
	long w=1;
	for(int i=0;i<n;i++)
	{
		w*=a;
	}
	return w;
}

long power_rec(int a, int n)
{
    if(n==0) return 1;
    return a*(power_rec(a,n-1));
}

int main()
{
    int i,a,wybor;
    int n;
    for(i=0;i<1000;i++)
    {
        printf("wybierz metode obliczania potegi: ");
        scanf("%d", &wybor);
        if(wybor==1 || wybor==2) break;
    }

    switch (wybor)
    {
    case 1:
        printf("podaj a: ");
        scanf("%d", &a);
        printf("podaj n:");
        scanf("%d", &n);
        if(n<0)
        {
            printf("Error");
            return 1;
        }
        printf("%ld", power_it(a,n));
        break;
    case 2:
        printf("podaj a: ");
        scanf("%d", &a);
        printf("podaj n:");
        scanf("%d", &n);
        if(n<0)
        {
            printf("Error");
            return 1;
        }
        printf("%ld", power_rec(a,n));
        break;
    default:
        printf("Nieprawidlowy wybor.");
    }

    return 0;
}
