#include <stdio.h>

float na_rad(float a)
{
    return a/57.29577;
}

float na_stopnie(float a)
{
    return a*57.29577;
}

int main()
{
    printf("wybierz rodzaj konwersji (1=stopnie na radiany, 2=radiany na stopnie: ");
    float liczba;
    int wybor;
    scanf("%d", &wybor);
    printf("podaj miare kata: ");
    scanf("%f", &liczba);
    /*if(liczba<0)
    {
        printf("error");
        return 0;
    }*/
    if(wybor==1)
    {
        printf("Wynik: %.2f", na_rad(liczba));
    }
    else if(wybor==2)
    {
        printf("Wynik: %.2f", na_stopnie(liczba));
    }
    else
    {
        printf("error");
        return 0;
    }
}
