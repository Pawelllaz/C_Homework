#include <stdio.h>
#include <stdlib.h>

unsigned long factorial_it(int n)
{
    int i;
    double liczba=1;
    for(i=1;i<=n;i++)
    {
        liczba*=i;
    }
    return liczba;
}

unsigned long factorial_rec(int n)
{
    double x;
    if(n==1) return 1;
    x=n*(factorial_it(n-1));
    return x;
}

int main()
{
    int wybor,liczban,i;
    for(i=0;i<1000;i++)
    {
        printf("wybierz metode obliczenia silni (1=iteracyjna, 2=rekurencyjna): ");
        scanf("%d", &wybor);
        if(wybor==1 || wybor==2)
        {
            break;
        }
    }

    double a,b;
    switch (wybor)
    {
    case 1:
        printf("podaj n: ");
        scanf("%d", &liczban);
        if(liczban<0 || liczban>20)
        {
            printf("blad");
            return 1;
        }
        a=factorial_it(liczban);
        printf("%.0f", a);
        break;
    case 2:
        printf("podaj n: ");
        scanf("%d", &liczban);
        if(liczban<0 || liczban>20)
        {
            printf("blad");
            return 1;
        }
        b=factorial_rec(liczban);
        printf("%.0f", b);
        break;
    default:
        printf("Nieprawidlowy wybor.");
    }

    return 0;
}
