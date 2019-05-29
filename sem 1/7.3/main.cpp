#include <stdio.h>
#include <stdlib.h>
#define pi 3.14159265359

float obwod_kola(float b)
{
    return pi*b;
}

int main()
{
    float liczba;

    printf("podaj srednice kola: ");

    scanf("%f", &liczba);

    printf("obwod kola to %f", obwod_kola(liczba));

    return 0;
}
