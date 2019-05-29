#include <stdio.h>
#include <stdlib.h>
#define N 5
#define M 1000

int main()
{
    int tab[N][N],i,j;

    printf("wpisz liczby:\n");

    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            scanf("%d", &tab[i][j]);
        }
    }

    int naj[M],r,x,l=0,wartosc1[M],wartosc2[M],wartosc3[M],wartosc4[M];

    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            for(r=0;r<N;r++)
            {
                for(x=0;x<N;x++)
                {
                    if(i!=r && j!=x)
                    {
                        naj[l]=tab[i][j]+tab[r][x];
                        wartosc1[l]=i;
                        wartosc2[l]=j;
                        wartosc3[l]=r;
                        wartosc4[l]=x;
                        l++;
                    }
                }
            }

        }
    }

    int maxi=tab[0][0];

    for(i=0;i<l;i++)
    {
        if(naj[i]>maxi)
            maxi=naj[i];
    }

    int licz=0;
    for(i=0;i<l;i++)
    {
        if(maxi==naj[i])
        {
            licz++;
        }
    }

    printf("%d %d\n", maxi,licz);
    for(i=0;i<licz;i++)
    {
        if(maxi==naj[i] && i==0)
        {
            printf("%d %d %d %d\n", wartosc1[i],wartosc2[i],wartosc3[i],wartosc4[i]);
        }
        else if(wartosc3[i]!=wartosc1[i-1] && wartosc4[i]!=wartosc2[i-1])
        {
            printf("%d %d %d %d\n", wartosc1[i],wartosc2[i],wartosc3[i],wartosc4[i]);
        }
    }

    return 0;
}
