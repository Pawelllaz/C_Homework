//program liczacy sume skrajnych wartosci macierzy 5 x 5
#include <stdio.h>
#include <stdlib.h>
#define N 5

int main()
{
    int tab[N][N],i,a,suma=0;

    printf("wpisz liczbe:\n");
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
            if(i==0 || a==0 || i==4 || a==4)
                suma+=tab[i][a];
        }
    }

    printf("%d", suma);


    return 0;
}
