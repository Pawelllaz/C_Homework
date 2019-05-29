#include <stdio.h>
#include <stdlib.h>

float dod(float a,float b)
{
    return a+b;
}

float od(float a,float b)
{
    return a-b;
}
float ilocz(float a,float b)
{
    return a*b;
}
float il(float a,float b)
{
    return a/b;
}
int main()
{
    float liczba1,liczba2;
    printf("podaj pierwsza liczbe: ");
    scanf("%f", &liczba1);

    printf("podaj druga liczbe: ");
    scanf("%f", &liczba2);

    printf("Suma: %.3f\n", dod(liczba1,liczba2));
    printf("Roznica: %.3f\n", od(liczba1,liczba2));
    printf("Iloczyn: %.3f\n", ilocz(liczba1,liczba2));
    printf("Iloraz: %.3f", il(liczba1,liczba2));
    return 0;
}
