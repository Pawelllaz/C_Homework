#include <stdio.h>
#include <stdlib.h>

int main()
{
    char w[]={"Witaj"}, im[100];
    int i,a=0;

    printf("podaj swoje imie:\n");

    fgets(im,100,stdin);

    for(i=0;i<100;i++)
    {
        if(im[i]==' ')
        {
            a=i;
            break;
        }

        if(im[i+1]==0)
        {
            a=i;
            break;
        }

    }

    printf("%s ", w);


    for(i=0;i<a;i++)
    {
        printf("%c", im[i]);
    }
    printf("!");


    return 0;
}
