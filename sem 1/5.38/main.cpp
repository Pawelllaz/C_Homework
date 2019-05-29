#include <stdio.h>
#include <stdlib.h>
#define N 1000

int main()
{
    int tab[N],c,i,counter1=0;

    printf("wprowadz liczby:\n");

    for(i=0;i<N;i++)
    {
        c=scanf("%d", &tab[i]);
        if(c!=1 || tab[0]==0)
        {
            printf("blednie wprowadzone dane");
            break;
        }
        if(tab[i]==0 && i!=0)
        {
            break;
        }
        counter1++;
    }

    int s=0,avg=0;
    for(i=0;i<counter1;i++)
    {
        s+=(tab[i]+tab[i+1])/2;
    }

    avg=s/counter1;

    for(i=0;i<counter1;i++)
    {
        if(tab[i]+tab[i+1]>avg)
        {
            printf("%d avg - %d s - %d c - %d\n", tab[i], avg,s,counter1);
        }
    }

// do poprawy

    return 0;
}
