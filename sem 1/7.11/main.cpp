#include <stdio.h>
#include <stdlib.h>

float fun(float x)
{
    return 5*x*x+12.55*x+0.75;
}

int main()
{
    float liczba;
    printf("wpisz liczbe: ");
    scanf("%f", &liczba);

    printf("wynik: %.2f", fun(liczba));

    return 0;
}
