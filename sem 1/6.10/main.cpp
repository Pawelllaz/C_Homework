#include <stdio.h>
#include <stdlib.h>
#define N 10

int main()
{
    int tab[N][N],i,j;

    printf("wpisz liczby:\n");

    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            scanf("%d", &tab[i][j]);
        }
    }

    int maxi=0,x,p;

    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(tab[i][j]%2==0)
            {
                maxi=tab[i][j];
                break;
            }
        }
    }

    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            p=tab[i][j]%2;
            if(p==0 && tab[i][j]>maxi)
                maxi=tab[i][j];
        }
    }

    int w,k,h=0;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            w=0;k=0;
            if(maxi==tab[i][j])
            {
                printf("%d %d ", j,i);
                for(x=0;x<N;x++)
                {
                    w+=tab[i][x];
                }
                for(x=0;x<N;x++)
                {
                    k+=tab[x][j];
                    h++;
                }
                printf("%d\n", w-k);
            }
        }
    }

    if(h==0)
        printf("0");
    return 0;
}
