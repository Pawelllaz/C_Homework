// program wczytuje macierz 5 na 5 i pokazuje kolumny ktorych suma jest najwieksza
#include <stdio.h>
#include <stdlib.h>
#define N 5

int main()
{
    int tab[N][N],i,a,s[N],maxi;

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
        s[i]=0;
        for(a=0;a<N;a++)
        {
            s[i]+=tab[a][i];
        }
    }

    maxi=s[0];

    for(i=0;i<N;i++)
    {
        if(s[i]>maxi)
            maxi=s[i];
    }

    for(i=0;i<N;i++)
    {
        if(maxi==s[i])
            printf("%d %d %d %d %d\n", tab[0][i],tab[1][i],tab[2][i],tab[3][i],tab[4][i]);
    }

    return 0;
}
