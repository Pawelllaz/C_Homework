#include <stdio.h>
#include <stdlib.h>

/* Napisz program wype�niaj�cy tablic� kolejnymi warto�ciami ca�kowitymi od 0 do 10 i wy�wietl zawarto�� tablicy na ekranie, w jednej linii.
Wype�nianie i wy�wietlanie musi odbywa� si� w osobnych p�tlach. Wydruk w konsoli powinien ko�czy� si� znakiem nowej linii. */

int main() {

	int tab[11],i;

	for(i=0;i<=10;i++)
	{
		tab[i] = i;
	}
	for(i=0;i<=10;i++)
	{
		printf("%d ", tab[i]);
		if(i==10)
		{
			printf("\n");
		}
	}


	return 0;
}
