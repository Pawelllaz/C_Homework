#include <stdio.h>
#include <stdlib.h>
#define N 11

int main()
{
    int i,a;

    for(i=0;i<11;i++)
    {
        for(a=0;a<11;a++)
        {
            printf("%4d", i*a);
        }
        printf("\n");
    }

    return 0;
}
