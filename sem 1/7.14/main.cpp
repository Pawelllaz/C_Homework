#include <stdio.h>
#include <stdlib.h>

float A(float a)
{
    for(;;)
    {
        if(a>=-20 && a<=20)
        {
            return a;
        }
        else
        {
            printf("blad, wpisz liczbe a jeszcze raz: ");
            scanf("%f", &a);
        }
    }
    return 1;
}

float B(float b)
{
    for(;;)
    {
        if(b>=-100 && b<=300)
        {
            return b;
        }
        else
        {
            printf("blad, wpisz liczbe b jeszcze raz: ");
            scanf("%f", &b);
        }
    }
    return 1;
}

float C(float c)
{
    for(;;)
    {
        if(c>=-1000 && c<=4000)
        {
            return c;
        }
        else
        {
            printf("blad, wpisz liczbe c jeszcze raz: ");
            scanf("%f", &c);
        }
    }
    return 1;
}

float X(float x)
{
    for(;;)
    {
        if(x>=-10 && x<=10)
        {
            return x;
        }
        else
        {
            printf("blad, wpisz liczbe x jeszcze raz: ");
            scanf("%f", &x);
        }
    }
    return 1;
}

float kwadrat(float a,float b,float c,float x)
{
    return a*x*x+b*x+c;
}

int main()
{
    float la,lb,lc,lx;

    printf("wpisz a: ");
    scanf("%f", &la);

    la=A(la);

    printf("wpisz b: ");
    scanf("%f", &lb);

    lb=B(lb);

    printf("wpisz c: ");
    scanf("%f", &lc);

    lc=C(lc);
    printf("wpisz x: ");
    scanf("%f", &lx);

    lx=X(lx);

    printf("wynik: %.2f", kwadrat(la,lb,lc,lx));
    return 0;
}
