#include <stdio.h>
#include <stdlib.h>
#define N 1000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	/*
	Wyznacz iloczyn wszystkich liczb zmiennoprzecinkowych wpisywanych przez u¿ytkownika.
	Podczas wpisywania kolejnych liczb, wyœwietlaj iloczyn wszystkich ju¿ wpisanych.
	Liczby wczytuj tak d³ugo, a¿ u¿ytkownik wpisze dowolny inny znak/ci¹g znaków ni¿ liczba a nastêpnie wyœwietl komunikat “Blad danych wejsciowych”.
	Wynik wyœwietlaj z dok³adnoœci¹ do dwóch miejsc po przecinku. Nale¿y sprawdzaæ czy u¿ytkownik poda³ liczbê. Wskazówka:
	Po wpisaniu pierwszej liczby jest ona mno¿ona przez 1
	*/

	float l[N],a=1;
	int i,c;

	printf("wpisz liczbe: ");

	for(i=0;i<N;i++)
	{
		c=scanf("%f", &l[i]);
		if(c!=1)
		{
			puts("Blad danych wejsciowych");
			break;
		}

		if(i==0)
		{
			a = l[i];
			printf("iloczyn = %.2f\n", a);
		}
		else
		{
		a*=l[i];
		printf("iloczyn = %.2f\n", a);
		}
	}


	return 0;
}
