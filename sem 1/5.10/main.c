#include <stdio.h>
#include <stdlib.h>

/* Napisz program pobieraj¹cy od u¿ytkownika 10 liczb ca³kowitych, po dwie naraz, który zapisuje je do kolejnych elementów tablicy.
Po pobraniu tych liczb wyœwietl je na ekranie, ka¿d¹ w osobnym wierszu razem z informacj¹ o jej parzystoœci w formie opisu „parzysta” albo „nieparzysta”.
Ka¿dy opis (wyrównany do lewej) musi byæ poprzedzony odpowiadaj¹c¹ mu wartoœci¹ liczbow¹ w danym wierszu.
Wszystkie wydruki zakoñcz znakiem nowej linii. */

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
