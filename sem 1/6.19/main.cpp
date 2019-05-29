#include <stdio.h>
#include <stdlib.h>
#define N 5
int main() {

    int a[N][N],b[N][N],i,j;

    printf("Podaj liczby:\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for(i = 0; i < N; ++i)
    {
        for(j = 0; j < N; ++j)
        {
            scanf("%d", &b[i][j]);
        }
    }

    int d[N],k,h=0,x,test;

    for(i=0;i<N;i++)
    {
        for(k=0;k<N;k++)
        {
            for(j=0;j<N;j++)
            {
                if(a[k][i]==b[j][i])
                {
                    if(d==0)
                    {
                        d[h] = b[j][i];
                        h++;
                        break;
                    }
                    test=0;
                    for(x=0;x<h;x++)
                        if(d[x]==b[j][i]) test += 1;
                    if(test != 0) break;
                    d[h] = b[j][i];
                    h++;
                }
            }
        }
        printf("%d ", h);
        for(x = 0; x < h; ++x)
            printf("%d ", d[x]);
        printf("\n");
        h = 0;
    }
    return 0;
}
