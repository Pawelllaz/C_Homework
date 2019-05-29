#include <stdio.h>
#include <stdlib.h>
#define N 10
#define M 2

int main()
{
    int a[N][N],b[M][M],i,j;

    printf("wpisz liczby:\n");

    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for(i=0;i<M;i++)
    {
        for(j=0;j<M;j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    int counter=0,x[100],y[100];

    for(i=0;i<N-1;i++)
    {
        for(j=0;j<N-1;j++)
        {
            if(a[i][j]==b[0][0] && a[i][j+1]==b[0][1] && a[i+1][j]==b[1][0] && a[i+1][j+1]==b[1][1])
            {
                x[counter]=j;
                y[counter]=i;
                counter++;
            }
        }
    }

    printf("%d\n", counter);
    for(i=0;i<counter;i++)
    {
        printf("%d %d\n", x[i],y[i]);
    }
    return 0;
}
