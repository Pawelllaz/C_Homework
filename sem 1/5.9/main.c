#include <stdio.h>
#include <stdlib.h>

/* Napisz program pobieraj�cy od u�ytkownika 10 warto�ci zmiennoprzecinkowych pojedynczej precyzji po dwie naraz, kt�ry zapisze je do kolejnych element�w tablicy.
Po pobraniu warto�ci wy�wietl je na ekranie, ka�d� w osobnym wierszu wraz z poprzedzaj�cym j� indeksem odpowiedniego elementu tablicy.
Wszystkie wydruki zako�cz znakiem nowej linii.
 */

int main() {

	printf("wpisz liczbe pojedynczej precyzji:");
	float tab[9];
	int i,c;
	for(i=0;;i++)
	{
		c=scanf("%f %f", &tab[i],&tab[i+1]);
		if(c!=2)
        {
            printf("error");
            return 1;
        }
		if(i==8)
		{
			break;
		}
		i++;
	}
	for(i=0;;i++)
	{
			printf("nr: %d wartosc: %.1f\n", i,tab[i]);
			if(i==9)
			{
				break;
			}
	}

	return 0;
}
