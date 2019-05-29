#include <stdio.h>
#include <stdlib.h>
#define N 1000
#define M 2000
int main()
{
    char tab[N];
    int i,a=0;

    printf("wpisz litery i znaki:\n");
    fgets(tab,N,stdin);

    for(i=0;tab[i]!=0;i++)
    {
        a++;
    }

    a-=1;

    for(i=a-1;i>=0;i--)
    {
        switch(tab[i])
        {
        case '1':
            //printf("%c", tab[i+1]);
            break;
        case '2':
            //printf("%c", tab[i+1]);
            printf("%c", tab[i+1]);
            break;
        case '3':
            //printf("%c", tab[i+1]);
            printf("%c", tab[i+1]);
            printf("%c", tab[i+1]);
            break;
        case '4':
            //printf("%c", tab[i+1]);
            printf("%c", tab[i+1]);
            printf("%c", tab[i+1]);
            printf("%c", tab[i+1]);
            break;
        case '5':
            //printf("%c", tab[i+1]);
            printf("%c", tab[i+1]);
            printf("%c", tab[i+1]);
            printf("%c", tab[i+1]);
            printf("%c", tab[i+1]);
            break;
        case '6':
            //printf("%c", tab[i+1]);
            printf("%c", tab[i+1]);
            printf("%c", tab[i+1]);
            printf("%c", tab[i+1]);
            printf("%c", tab[i+1]);
            printf("%c", tab[i+1]);
            break;
        case '7':
            //printf("%c", tab[i+1]);
            printf("%c", tab[i+1]);
            printf("%c", tab[i+1]);
            printf("%c", tab[i+1]);
            printf("%c", tab[i+1]);
            printf("%c", tab[i+1]);
            printf("%c", tab[i+1]);
            break;
        case '8':
            //printf("%c", tab[i+1]);
            printf("%c", tab[i+1]);
            printf("%c", tab[i+1]);
            printf("%c", tab[i+1]);
            printf("%c", tab[i+1]);
            printf("%c", tab[i+1]);
            printf("%c", tab[i+1]);
            printf("%c", tab[i+1]);
            break;
        case '9':
            //printf("%c", tab[i+1]);
            printf("%c", tab[i+1]);
            printf("%c", tab[i+1]);
            printf("%c", tab[i+1]);
            printf("%c", tab[i+1]);
            printf("%c", tab[i+1]);
            printf("%c", tab[i+1]);
            printf("%c", tab[i+1]);
            printf("%c", tab[i+1]);
            break;
        default:
            printf("%c", tab[i]);
            break;
        }
    }

    return 0;
}
