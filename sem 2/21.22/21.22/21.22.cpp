#include "stdafx.h"
#include <stdio.h>
//#include <conio.h>

int dd_test(const int *ptr, int width, int height)
{
	int suma_sr = 0, suma_poz = 0, liczba, spr=0;
	if (ptr == NULL) return -1;
	if (width <= 0 || height <= 0) return -1;
	if (width != height) return -1;
	for (int i = 0; i < height; i++)
	{
		suma_sr = 0; suma_poz = 0;
		for (int j = 0; j < width; j++)
		{
			liczba = *(ptr + i * height + j);
			if (liczba < 0) liczba *= -1;
			if (i == j)
			{
				suma_sr += liczba;
			}
			else
			{
				suma_poz += liczba;
			}
		}
		if (suma_sr > suma_poz) spr++;
	}
	//printf("%d %d\n", suma_sr, suma_poz);
	if (spr==height) return 1;
	return 0;
}

int main()
{
	const int N = 5;
	int tab[N][N];
	int *q_tab = tab[0];
	printf("wpisz liczby bo bedzie smutno :(\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", *(tab + i) + j);
		}
	}

	if (dd_test(q_tab, N, N)) printf("TAK");
	else printf("NIE");

	//_getch();
	return 0;
}