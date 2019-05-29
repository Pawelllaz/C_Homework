#include <stdio.h>
#include <stdlib.h>
#define N 1000

int main()
{
    char tab[N];
    int i,a=0;

    printf("wprowadz nawiasy:\n");
    fgets(tab,N,stdin);

    for(i=0;tab[i]!=0;i++)
    {
        if(tab[i]=='(' || tab[i]==')')
        {
            a++;
        }
    }

    int najzag[N],b=0,inds[N];

    for(i=0;i<a;i++)
    {
        if(tab[i]=='(')
        {
            najzag[b]+=1;
            inds[b]=i;
        }
        else
            b++;
    }

    int maxi=najzag[0];

    for(i=0;i<b;i++)
    {
        if(najzag[i]>maxi)
            maxi=najzag[i];            // maxi najwieksze zagniezdzenie
    }

    printf("%d ", maxi);
    for(i=0;i<b;i++)
    {
        if(maxi==najzag[i])
        {
            printf("%d ", inds[i]);
        }
    }
    return 0;
}
