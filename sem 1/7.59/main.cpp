#include <stdio.h>
#define N 10

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

int closest_prime_number(int a)
{
    int i;
    if(a<=1)
    {
        return a;
    }
    else
    {

        for(i=0;;i++)
        {
            if(czy_pierwsza(a-i))
            {
                return a-i;
            }
            if(czy_pierwsza(a+i))
            {
                return a+i;
            }
        }
    }
    return 0;
}

int main()
{
    int tab[N][N],i,j;

    printf("podaj iczby:\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            scanf("%d", &tab[i][j]);

        }
    }

    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            rewind(stdin);
            printf("%4d", closest_prime_number(tab[i][j]));
        }
        printf("\n");
    }

    return 0;
}
