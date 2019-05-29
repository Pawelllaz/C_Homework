#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>

int main()
{
    int M=15,N=10,i,j,tab[M][N];
    srand(time(0));
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            tab[i][j]=rand()%100;
        }
    }

    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%3d", tab[i][j]/10);
        }
        printf("\n");
    }



}
