#include <stdio.h>
#define N 1000
#include <math.h>

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
//----------------------------------------------

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

   printf("%.2f\n%.2f", average(tab,counter-1), stdDev(tab,counter-1));

    return 0;
}
