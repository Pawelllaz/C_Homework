#include <stdio.h>
#include <stdlib.h>
#define N 4
#include <time.h>

int main()
{
    int a[N][N],b[N][N],c[N][N],i,r,d;

    srand(time(0));

    for(i=0;i<N;i++)
    {
        for(r=0;r<N;r++)
        {
            d=rand()%9;
            a[i][r]=d;
        }
    }

    for(i=0;i<N;i++)
    {
        for(r=0;r<N;r++)
        {
            d=rand()%9;
            b[i][r]=d;
        }
    }

    for(i=0;i<N;i++)
    {
        for(r=0;r<N;r++)
        {
            if(i==r)
                c[i][r]=1;
            else
                c[i][r]=0;
        }
    }

    for(i=0;i<4;i++)
    {
        for(r=0;r<4;r++)
        {
            printf("%4d", a[i][r]);
        }
        printf("\n");
    }

    printf("\n");
    for(i=0;i<4;i++)
    {
        for(r=0;r<4;r++)
        {
            printf("%4d", b[i][r]);
        }
        printf("\n");
    }

    printf("\n");
    for(i=0;i<4;i++)
    {
        for(r=0;r<4;r++)
        {
            printf("%4d", c[i][r]);
        }
        printf("\n");
    }

    printf("\n");
    for(i=0;i<N;i++)
    {
        for(r=0;r<N;r++)
        {
            printf("%4d ", a[i][r]+b[i][r]);
        }
        printf("\n");
    }

    printf("\n");
    for(i=0;i<N;i++)
    {
        for(r=0;r<N;r++)
        {
            printf("%4d ", a[i][r]-b[i][r]);
        }
        printf("\n");
    }

    printf("\n");
    for(i=0;i<N;i++)
    {
        for(r=0;r<N;r++)
        {
            printf("%4d ", a[i][r]+b[i][r]+c[i][r]);
        }
        printf("\n");
    }

    printf("\n");
    for(i=0;i<N;i++)
    {
        for(r=0;r<N;r++)
        {
            printf("%4d ", a[i][r]-b[i][r]-c[i][r]);
        }
        printf("\n");
    }

    printf("\n");
    for(i=0;i<N;i++)
    {
        for(r=0;r<N;r++)
        {
            printf("%4d ", -b[i][r]);
        }
        printf("\n");
    }

    return 0;
}
