#include <stdio.h>
#include <stdlib.h>
#define N 1000

int main()
{
    int c[N],i,counter=0;

    printf("wpisz liczby:\n");

    for(i=0;i<N;i++)
    {
        scanf("%d", &c[i]);
        if(c[i]==0)
            break;
        counter++;
    }

    int t[N],a=0,il[N];
    for(i=0;i<counter-1;i++)
    {
        if(c[i+1]>c[i])
        {
            t[a]+=1;
            il[a]=i;
        }
        else
            if(t[a]!=0)
            {
                t[a]+=1;
                il[a]+=1;
                a++;
            }
    }

    int max=t[0];
    for(i=0;i<a;i++)
    {
        if(t[i]>max)
            max=t[i];
    }
    printf("%d\n%d\n", max,a);

    int b;
    for(i=0;i<a;i++)
    {
        printf("%d - ", il[i]-t[i]+1);
        for(b=il[i]-t[i];b<=t[i];b++)
            printf("%d ", c[b]);

    }
    return 0;
}
