#include <stdio.h>
#include <stdlib.h>

int clamp(int v,int lo, int hi)
{
    if(v>=lo && v<=hi)
        return v;
    if(v>=hi && v<=lo)
        return v;
    if(v>hi && hi>lo)
        return hi;
    if(v>hi && lo>hi)
        return lo;
    if(v<lo && lo<hi)
        return lo;
    if(v<lo && hi<lo)
        return hi;
    if(hi==lo)
        return hi;
    return 0;
}

int main()
{
    int v,lo,hi;
    printf("wpisz liczbe: ktora bedzie program ograniczac: ");
    scanf("%d", &v);
    printf("wpisz pierwsza liczbe przedzialu: ");
    scanf("%d", &lo);
    printf("wpisz druga liczbe przedzialu: ");
    scanf("%d", &hi);

    int wynik = clamp(v,lo,hi);
    printf("%d", wynik);

    return 0;
}
