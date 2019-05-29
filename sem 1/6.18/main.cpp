#include <stdio.h>
#include <stdlib.h>
#define N 5

int main()
{
    int a[N][N],b[N][N],c[N][N],i,r;

    printf("wpisz liczbe:\n");

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

    for(i=0;i<N;i++)
    {
        for(r=0;r<N;r++)
        {
            if(a[i][r]>=b[i][r])
                c[i][r]=a[i][r];
            else if(b[i][r]>a[i][r])
                c[i][r]=b[i][r];
        }
    }

    for(i=0;i<N;i++)
    {
        for(r=0;r<N;r++)
        {
            printf("%4d ", c[i][r]);
        }
        printf("\n");
    }


    return 0;
}
