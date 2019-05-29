// program wczytuje macierz 5 na 5 i liczy sume przekatnych ;) lecim
#include <stdio.h>
#include <stdlib.h>
#define N 5

int main()
{
    int tab[N][N],i,a,s=0;

    printf("wpisz liczby:\n");

    for(i=0;i<N;i++)
    {
        for(a=0;a<N;a++)
        {
            scanf("%d", &tab[i][a]);
        }
    }

    for(i=0;i<N;i++)
    {
        for(a=0;a<N;a++)
        {
            if(i==a)
                s+=tab[i][a];
        }
    }

    printf("%d ", s);
    s=0;
    for(i=0;i<N;i++)
    {
        for(a=0;a<N;a++)
        {
            if(i==a)
                s+=tab[i][4-i];
        }
    }

    printf("%d", s);

    return 0;
}
