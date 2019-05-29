#include <stdio.h>
#include <stdlib.h>
#define N 5

int main()
{
    int a[N][N],b[N][N],c[N][N],i,r;

    printf("wpisz liczby:\n");

    for(i=0;i<N;i++)
    {
        for(r=0;r<N;r++)
        {
            scanf("%d", &a[i][r]);
        }
    }

    for(i=0;i<N;i++)
    {
        for(r=0;r<N;r++)
        {
            scanf("%d", &b[i][r]);
        }
    }

    int suma1,suma2;

    for(i=0;i<N;i++)
    {
        suma1=0;
        suma2=0;
        for(r=0;r<N;r++)
        {
            suma1+=a[r][i];
            suma2+=b[r][i];
        }
        if(suma1>=suma2)
        {
            c[0][i]=a[0][i];
            c[1][i]=a[1][i];
            c[2][i]=a[2][i];
            c[3][i]=a[3][i];
            c[4][i]=a[4][i];
        }
        else
        {
            c[0][i]=b[0][i];
            c[1][i]=b[1][i];
            c[2][i]=b[2][i];
            c[3][i]=b[3][i];
            c[4][i]=b[4][i];
        }

    }

    for(i=0;i<N;i++)
    {
        for(r=0;r<N;r++)
        {
            printf("%3d ", c[i][r]);
        }
        printf("\n");
    }
    return 0;
}
