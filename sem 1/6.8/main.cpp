#include <stdio.h>
#include <stdlib.h>
#define N 15
int main()
{
    int tab[N][N],i,a,b;

    printf("podaj liczby:\n");
    for(i=0;i<N;i++)
    {
        for(a=0;a<N;a++)
        {
            scanf("%d", &b);
            tab[i][a]=b;
        }
    }

    printf("\n\n");
    int r,d,c=0;
    for(i=0;i<N;i++)
    {
        for(a=0;a<N;a++)
        {
                                        // do tutaj petle od pierwszej
            for(r=0;r<N;r++)
            {
                for(d=0;d<N;d++)
                {
                    if(tab[i][a]==tab[r][d])
                    {
                        c++;
                    }
                }
            }
            printf("%3d ", c);
            c=0;
        }
        printf("\n");
    }


    return 0;
}
