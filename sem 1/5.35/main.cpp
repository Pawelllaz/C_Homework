#include <stdio.h>
#include <stdlib.h>
#define N 1000

int main()
{
    int c1[N],c2[N],counter,counter1,c,i,tab[N],a;
    counter1=0;
    counter=0;

    printf("wpisz liczby do pierwszego ciagu\n");
    for(i=0;i<N;i++)
    {
        c=scanf("%d", &c1[i]);
        if(c!=1 || c1[0]==0)
        {
            printf("bledne dane wejsciowe\n");
            break;
        }
        if(c1[i]==0 && i!=0)
        {
            break;
        }
        counter1++;
    }

    for(i=0;i<2;i++)
    {
        c=scanf("%d", &c2[i]);
        if(c!=1)
        {
            printf("blednie wpisan ciag");
            return 0;
        }
    }

    a=0;

    for(i=0;i<=counter1;i++)
    {
        if(c1[i]==c2[0] && c1[i+1]==c2[1])
        {
           counter++;
           tab[a]=i;
           a++;
        }
    }

    printf("%d\n", counter);
    for(i=0;i<counter;i++)
    {
        printf("%d\n", tab[i]);
    }

    return 0;
}
