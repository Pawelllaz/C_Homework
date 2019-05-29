#include <stdio.h>
#include <stdlib.h>
#define n 10

int main()
{
    int tab1[n],i,c,spr=0;

    printf("wrowadz 10 liczb, w tym 4 parzyste:\n");
    for(i=0;i<n;i++)
    {
        c=scanf("%d", &tab1[i]);

        if(c!=1)
        {
            printf("BLAD");
            return 1;
        }
    }

    for(i=0;i<n;i++)
    {
        if(tab1[i]%2==0)
        {
            spr++;
        }
    }
    if(spr!=4)
        {
            printf("BLAD");
            return 1;
        }

    int par[4],a=0;
    for(i=0;i<n;i++)
    {
        if(tab1[i]%2==0)
        {
            par[a]=tab1[i];
            a++;
        }
    }

    int b=0,np[n];

    for(i=0;i<n;i++)
    {
       if(tab1[i]%2!=0)
       {
           np[b]=tab1[i];
           b++;
       }
    }
    b=0;
    a=0;
    for(i=0;i<n;i++)
    {
        if(i==0 || i==3 || i==6 || i==9)
        {
            printf("%d ", par[a]);
            a++;
        }
        else
        {
            printf("%d ", np[b]);
            b++;
        }
    }



    return 0;
}
