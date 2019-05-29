#include <stdio.h>
#include <stdlib.h>


int main()
{
    int i,a;
    char tab[26];

    a=65;

    for(i=0;i<26;i++)
    {
        tab[i]=a;
        a++;
    }

    for(i=0;i<26;i++)
    {
        printf("%d %c %c\n", tab[i], tab[i], tab[i]+32);
    }


    return 0;
}
