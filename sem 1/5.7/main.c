#include <stdio.h>
#include <stdlib.h>

/* Napisz program wype³niaj¹cy tablicê kolejnymi wartoœciami ca³kowitymi od 0 do 10 i wyœwietl zawartoœæ tablicy na ekranie, w jednej linii.
Wype³nianie i wyœwietlanie musi odbywaæ siê w osobnych pêtlach. Wydruk w konsoli powinien koñczyæ siê znakiem nowej linii. */

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
