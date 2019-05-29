#include <stdio.h>
#include <stdlib.h>
#define N 10

int main()
{
    float tab[N][N];
    int i,j;

    printf("wpisz liczbe:\n");

    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            scanf("%f", &tab[i][j]);
        }
    }
    float avg[8][8];
    for(i=0;i<N-2;i++)
    {
        for(j=0;j<N-2;j++)
        {
            avg[i][j]=(tab[i][j]+tab[i][j+1]+tab[i][j+2]+tab[i+1][j]+tab[i+1][j+1]+tab[i+1][j+2]+tab[i+2][j]+tab[i+2][j+1]+tab[i+2][j+2])/9.00;
        }
    }

    for(i=0;i<N-2;i++)
    {
        for(j=0;j<N-2;j++)
        {
            printf("%.2f ", avg[i][j]);
        }
        printf("\n");
    }
    return 0;
}
