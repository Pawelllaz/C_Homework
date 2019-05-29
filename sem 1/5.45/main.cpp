#include <stdio.h>
#include <stdlib.h>

int main()
{
    char tekst[] = {'T','o',' ','j','e','s','t',' ','t','e','k','s','t','\x0'};
    int i;

    for(i=0;tekst[i]!=0;i++)
    {
        putc(tekst[i],stdout);
        printf(" %d %c\n", tekst[i],tekst[i]);
    }


    return 0;
}
