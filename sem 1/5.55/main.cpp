#include <stdio.h>
#include <stdlib.h>
#define N 1000

int main()
{
    char tab[N];
    int i,a;

    printf("wpisz liczby:\n");

    fgets(tab,1000,stdin);

    atoi(tab[2]);
    printf("%d", tab[2]);

    return 0;
}
