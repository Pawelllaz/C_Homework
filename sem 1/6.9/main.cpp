#include <stdio.h>
#include <stdlib.h>
#define N 10

int main()
{
    int tab[N][N],i,j;

    printf("wpisz liczbe:\n");

    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            scanf("%d", &tab[i][j]);
        }
    }

    int sp=0,sn=0;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if((i+j)%2==0)
            {
                sp+=tab[i][j];
            }
            else
            {
                sn+=tab[i][j];
            }
        }
    }

    printf("%d", sp-sn);

    return 0;
}
