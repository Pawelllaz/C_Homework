#include <stdio.h>
#include <stdlib.h>
#define N 1000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	/*
	Wyznacz iloczyn wszystkich liczb zmiennoprzecinkowych wpisywanych przez u�ytkownika.
	Podczas wpisywania kolejnych liczb, wy�wietlaj iloczyn wszystkich ju� wpisanych.
	Liczby wczytuj tak d�ugo, a� u�ytkownik wpisze dowolny inny znak/ci�g znak�w ni� liczba a nast�pnie wy�wietl komunikat �Blad danych wejsciowych�.
	Wynik wy�wietlaj z dok�adno�ci� do dw�ch miejsc po przecinku. Nale�y sprawdza� czy u�ytkownik poda� liczb�. Wskaz�wka:
	Po wpisaniu pierwszej liczby jest ona mno�ona przez 1
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
