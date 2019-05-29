#include <stdio.h>
#include <stdlib.h>

int wzrost(float m)
{
    if(m>=1.10 && m<=2.75)
    {
        return 0;
    }
    else
    {
    	return 1;
	}
}

int main()
{
    float metry;
    int stopa,cal;

    printf("Podaj wzrost w metrach: ");
    scanf("%f", &metry);
    while(wzrost(metry))
    {
        printf("Wartosc poza zakresem. Sprobuj ponownie: ");
        scanf("%f", &metry);
    }
    cal=metry*100/2.54;
    stopa=cal/12;
    cal-=12*stopa;

    printf("Wzrost w jednostkach imperialnych to %d'%d''",stopa,cal);

return 0;
}
