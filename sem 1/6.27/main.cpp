#include <stdio.h>
#include <stdlib.h>
#define N 10
#define M 5

int main()
{
    int tab[M][N],i,r;

    printf("wpisz liczby:\n");

    for(i=0;i<M;i++)
    {
        for(r=0;r<N;r++)
        {
            scanf("%d", &tab[i][r]);
        }
    }

    for(i=0;i<N;i++)
    {
        for(r=0;r<M;r++)
        {
            printf("%3d ", tab[r][i]);
        }
        printf("\n");
    }

    return 0;
}
