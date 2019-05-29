#include <stdio.h>
#include <stdlib.h>

/* Napisz program pobieraj¹cy od u¿ytkownika 10 wartoœci zmiennoprzecinkowych pojedynczej precyzji po dwie naraz, który zapisze je do kolejnych elementów tablicy.
Po pobraniu wartoœci wyœwietl je na ekranie, ka¿d¹ w osobnym wierszu wraz z poprzedzaj¹cym j¹ indeksem odpowiedniego elementu tablicy.
Wszystkie wydruki zakoñcz znakiem nowej linii.
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
