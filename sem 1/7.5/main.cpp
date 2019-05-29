#include <stdio.h>
#include <stdlib.h>

int dod(int a,int b)
{
    return a+b;
}

int main()
{
    int liczba1,liczba2;
    printf("podaj pierwsza liczbe: ");
    scanf("%d", &liczba1);

    printf("podaj druga liczbe: ");
    scanf("%d", &liczba2);

    printf("%d", dod(liczba1,liczba2));
    return 0;
}
