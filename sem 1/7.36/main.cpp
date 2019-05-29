#include <stdio.h>
#include <math.h>
#define N 1000
//=====================================================
float fclamp(float v,float lo, float hi)
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
//====================================================
float average(int tab[], int siza)
{
    int i;
    float suma=0;
    for(i=0;i<=siza;i++)
    {
        suma+=tab[i];
    }
    return suma/siza;
}
//-----------------------------------------------
float stdDev(int tab[], int siza)
{
    int i;
    float odchylenie=0;

    for(i=0;i<siza;i++)
    {
        odchylenie+=(tab[i]-average(tab,siza))*(tab[i]-average(tab,siza));
    }
    return sqrt(odchylenie/siza);
}
//=================================================
int main()
{
    int tab[N],i,counter=0;

    printf("podaj liczby: ");
    for(i=0;i<N;i++)
    {
        scanf("%d", &tab[i]);
        counter++;
        if(tab[i]==0) break;
    }

    float srednia;
    srednia=average(tab,counter-1);
    float odchylenie=stdDev(tab,counter-1);

    //printf("%.2f\n%.2f\nlo%.2f\nhi%.2f\n", srednia, odchylenie,srednia-odchylenie,srednia+odchylenie);
    for(i=0;i<counter-1;i++)
    {
        printf("%.2f ", fclamp(tab[i],srednia-odchylenie,srednia+odchylenie));
    }

    return 0;
}
