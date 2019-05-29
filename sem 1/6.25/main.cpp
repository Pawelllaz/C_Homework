#include <stdio.h>
#include <stdlib.h>
#define N 5

int main()
{
    int tab[N][N],i,r;

    printf("wpisz liczby:\n");

    for(i=0;i<N;i++)
    {
        for(r=0;r<N;r++)
        {
            scanf("%d", &tab[i][r]);
        }
    }

    int suma=0;

    for(i=0;i<N;i++)
    {
        for(r=0;r<N;r++)
        {
            if(r>=i)
                suma+=tab[i][r];
        }
    }

    printf("%d", suma);

    return 0;
}
