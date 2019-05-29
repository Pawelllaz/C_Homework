#include <stdio.h>
#include <stdlib.h>
#define n 100

int main()
{
    char im[n];
    int i;

    printf("podaj imie:\n");
    fgets(im,n,stdin);

    for(i=0;im[i]!=0;i++)
    {
        if(im[i+1]==0)
        {
            if(im[i-1]=='a')
                printf("Imie zenskie");
            else
                printf("Imie meskie");
        }
    }

    return 0;
}
