#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tab[11],i;

    for(i=0;i<=10;i++)
    {
        tab[i]=i;
    }

    printf("%d %d %d %d %d %d %d %d %d %d %d\n",tab[0],tab[1],tab[2],tab[3],tab[4],tab[5],tab[6],tab[7],tab[8],tab[9],tab[10]);
    for(i=0;i<=10;i++)
    {
        printf("%d\n", tab[i]);
    }

    return 0;
}
