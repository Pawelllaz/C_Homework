#include <stdio.h>
#include <stdlib.h>
#define N 100

int main()
{
    int tab[N],i,counter,c;

    counter=0;
    printf("wprowadz liczbe:\n");

    for(i=0;i<N;i++)
    {
        c=scanf("%d", &tab[i]);
        if(c!=1 || tab[0]==-1)
        {
            printf("bledne dane wejsciowe");
            return 2;
        }
        if(tab[i]==-1 && i!=0)
            break;

        counter++;
    }

    int n=0,t=0;

    for(i=0;i<counter;i++)
    {
        if(tab[i]==tab[counter-i-1])
            t++;
        if(tab[i]!=tab[counter-1-i])
            n++;
    }

    if(n!=0)
    {
        printf("NIE");
    }
    if(n==0 && t!=0)
    {
        printf("TAK");
    }

    return 0;
}
