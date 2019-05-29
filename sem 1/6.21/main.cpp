#include <stdio.h>
#include <stdlib.h>
#define N 5

int main()
{
    int a[N][N],i,r;

    printf("wpisz liczby:\n");

    for(i=0;i<N;i++)
    {
        for(r=0;r<N;r++)
        {
            scanf("%d", &a[i][r]);
        }
    }


    float suma;

    for(i=0;i<N;i++)
    {
        suma=0;
        for(r=0;r<N;r++)
        {
            suma+=a[r][i];
        }
        printf("%.2f ", suma/5);
    }

    return 0;
}
