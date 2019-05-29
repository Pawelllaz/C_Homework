#include <stdio.h>
#include <stdlib.h>

int czy_pierwsza(int a)
{
    if(a<=1)
        {
            return 0;
        }
    if(a==2) return 1;
    int i,spr=0;
    for(i=2;i<a;i++)
    {
        if(a%i==0 && a!=i)
        {
            spr++;
        }
    }
    if(spr!=0)
    {
        return 0;
    }
    return 1;
}

int czy_blizniacze(int a, int b)
{
    int i,spr=0;
    if(a<=1 && b<=1) return 0;
    if(a==2 && b==4) return 1;
    if(a==1 && b==3) return 0;

    if(a<b)
    {
        for(i=2;i<a;i++)
        {
            if(a%i==0 && a!=i)
            {
                spr++;
            }
        }

        for(i=2;i<b;i++)
        {
            if(b%i==0 && b!=i)
            {
                spr++;
            }
        }

        if(spr!=0)
        {
            return 0;
        }
        else
        {
            if(a+2==b)
            {
                return 1;
            }
        }
        return 0;
    }
    else
    {
        for(i=2;i<a;i++)
        {
            if(a%i==0 && a!=i)
            {
                spr++;
            }
        }

        for(i=2;i<b;i++)
        {
            if(b%i==0 && b!=i)
            {
                spr++;
            }
        }

        if(spr!=0)
        {
            return 0;
        }
        else
        {
            if(b+2==a)
            {
                return 1;
            }
        }
        return 0;
    }
}
int main()
{
    int i,x1,x2,liczbyp[1000],licznik=0,liczba;

    printf("wpisz liczbe: ");
    scanf("%d", &x1);
    printf("wpisz liczbe: ");
    scanf("%d", &x2);

    for(i=x1;i<=x2;i++)
    {
        liczba=czy_pierwsza(i);
        if(liczba==1)
        {
            liczbyp[licznik]=i;
            licznik++;
        }
    }
    int wyn;
    for(i=0;i<licznik-1;i++)
    {
        wyn=czy_blizniacze(liczbyp[i],liczbyp[i+1]);
        if(wyn==1)
        {
            printf("%d, %d\n", liczbyp[i], liczbyp[i+1]);
        }
    }

    return 0;
}
