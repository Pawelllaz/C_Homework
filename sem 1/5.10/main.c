#include <stdio.h>
#include <stdlib.h>

/* Napisz program pobieraj�cy od u�ytkownika 10 liczb ca�kowitych, po dwie naraz, kt�ry zapisuje je do kolejnych element�w tablicy.
Po pobraniu tych liczb wy�wietl je na ekranie, ka�d� w osobnym wierszu razem z informacj� o jej parzysto�ci w formie opisu �parzysta� albo �nieparzysta�.
Ka�dy opis (wyr�wnany do lewej) musi by� poprzedzony odpowiadaj�c� mu warto�ci� liczbow� w danym wierszu.
Wszystkie wydruki zako�cz znakiem nowej linii. */

int main() {

	printf("wpisz liczbe calkowita:");
	int tab[9];
	int i,c;
	for(i=0;;i++)
	{
		c=scanf("%d %d", &tab[i],&tab[i+1]);
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
			printf("%d   ", tab[i]);
			if(tab[i]% 2 == 0)
			{
				printf("parzysta\n");
			}
			else if(tab[i]%2 != 0)
			{
				printf("nieparzysta\n");
			}
			if(i==9)
			{
				break;
			}
	}

	return 0;
}
