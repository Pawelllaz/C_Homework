#include <stdio.h>
#include <stdlib.h>

int test1(int a)
{
    return a*a;
}

int main()
{
    int liczba,a;printf("podaj argument: ");scanf("%d", &liczba);a=test1(liczba);printf("wynik funkcji: %d", a);
    return 0;
}
