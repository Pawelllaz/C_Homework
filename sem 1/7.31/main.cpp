#include <stdio.h>
#define N 5

int czy_pierwsza(int a)
{
    if(a<=1) return 0;
    if(a==2)
        {
            return 0;
        }
    int i,spr=0;
    for(i=2;i<a;i++)
    {
        if(a%i==0 && a!=i)
        {
            spr++;
        }
    }
    if(spr!=0)
    {
        return 0;
    }
    return 1;
}
int main()
{
    int counter=0,i,j,tab[N][N],pary[100][4];
    printf("podaj liczby:\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            scanf("%d", &tab[i][j]);
        }
    }

    for(i=0;i<N-1;i++)
    {
        for(j=0;j<N;j++)
        {
            if(czy_pierwsza(tab[i][j]))
            {
                if(czy_pierwsza(tab[i+1][j]))
                {
                    pary[counter][0]=i;
                    pary[counter][1]=j;
                    pary[counter][2]=i+1;
                    pary[counter][3]=j;
                    counter++;
                }
                if(czy_pierwsza(tab[i+1][j]))
                {
                    pary[counter][0]=i;
                    pary[counter][1]=j;
                    pary[counter][2]=i+1;
                    pary[counter][3]=j-1;
                    counter++;
                }
            }
        }
    }

     for(i=0;i<N;i++)
    {
        for(j=0;j<N-1;j++)
        {
            if(czy_pierwsza(tab[i][j]))
            {
                if(czy_pierwsza(tab[i][j+1]))
                {
                    pary[counter][0]=i;
                    pary[counter][1]=j;
                    pary[counter][2]=i;
                    pary[counter][3]=j+1;
                    counter++;
                }
            }
        }
    }

    for(i=0;i<N;i++)
    {
        for(j=0;j<N-1;j++)
        {
            if(czy_pierwsza(tab[i][j]))
            {
                if(czy_pierwsza(tab[i+1][j]))
                {
                    pary[counter][0]=i;
                    pary[counter][1]=j;
                    pary[counter][2]=i+1;
                    pary[counter][3]=j;
                    counter++;
                }
            }
        }
    }


    for(i=0;i<N-1;i++)
    {
        for(j=0;j<N;j++)
        {
            if(czy_pierwsza(tab[i][j]))
            {
                if(czy_pierwsza(tab[i+1][j]))
                {
                    pary[counter][0]=i;
                    pary[counter][1]=j;
                    pary[counter][2]=i+1;
                    pary[counter][3]=j;
                    counter++;
                }
                if(czy_pierwsza(tab[i+1][j]))
                {
                    pary[counter][0]=i;
                    pary[counter][1]=j;
                    pary[counter][2]=i+1;
                    pary[counter][3]=j-1;
                    counter++;
                }
            }
        }
    }

    for(i=0;i<N-1;i++)
    {
        for(j=0;j<N-1;j++)
        {
            if(czy_pierwsza(tab[i][j]))
            {
                if(czy_pierwsza(tab[i+1][j+1]))
                {
                    pary[counter][0]=i;
                    pary[counter][1]=j;
                    pary[counter][2]=i+1;
                    pary[counter][3]=j+1;
                    counter++;
                }
            }
        }
    }
    printf("%d\n", counter);
    for(i=0;i<counter;i++)
    {
        printf("%d %d %d %d\n", pary[i][0], pary[i][1], pary[i][2], pary[i][3]);
    }
    return 0;
}
