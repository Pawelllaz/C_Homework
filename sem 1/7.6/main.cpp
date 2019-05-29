#include <stdio.h>
#include <stdlib.h>

float dod(float a,float b)
{
    return a+b;
}

int main()
{
    float liczba1,liczba2;
    printf("podaj pierwsza liczbe: ");
    scanf("%f", &liczba1);

    printf("podaj druga liczbe: ");
    scanf("%f", &liczba2);

    printf("%.2f", dod(liczba1,liczba2));
    return 0;
}
