#include <stdio.h>
#include <stdlib.h>
#define N 5

int main()
{
    int tab[N][N],i,a,b;

    printf("wprowadz liczby:\n");
    for(i=0;i<N;i++)
    {
        for(a=0;a<N;a++)
        {
            scanf("%d", &b);
            tab[i][a]=b;
        }
    }

    int maxi;

    for(i=0;i<N;i++)
    {
        maxi=tab[i][0];
        for(a=0;a<N;a++)
        {
            if(tab[i][a]>maxi)
                maxi=tab[i][a];
        }
        printf("%d ", maxi);
    }

    for(i=0;i<N;i++)
    {
        maxi=tab[0][i];
        for(a=0;a<N;a++)
        {
            if(tab[a][i]>maxi)
                maxi=tab[a][i];
        }
        printf("%d ", maxi);
    }

    return 0;
}
