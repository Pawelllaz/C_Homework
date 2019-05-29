#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>

//===================================================================
void sort_dates(int day[], int month[], int year[], int size)
{
	int i, j, liczba;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (year[j] > year[j + 1] || (year[j] == year[j + 1] && month[j] > month[j + 1]) || (year[j] == year[j + 1] && month[j] == month[j + 1] && day[j] > day[j + 1]))
			{
				liczba = year[j];
				year[j] = year[j + 1];
				year[j + 1] = liczba;
				liczba = month[j];
				month[j] = month[j + 1];
				month[j + 1] = liczba;
				liczba = day[j];
				day[j] = day[j + 1];
				day[j + 1] = liczba;
			}
		}
	}
}
//==================================================================
int main()
{
	const int N = 150;
	int day[N], month[N], year[N], ile_dat, i;
	
	printf("podaj liczbe dat: ");
	scanf("%d", &ile_dat);

	printf("podaj daty:\n");
	for (i = 0; i < ile_dat; i++)
	{
		scanf("%d-%d-%d", &month[i],&day[i],&year[i]);
	}
	printf("\n");
	sort_dates(day, month, year, ile_dat);
	for (i = 0; i < ile_dat; i++)
	{
		printf("%.2d-%.2d-%.4d\n", month[i], day[i], year[i]);
	}
	
	//_getch();
	return 0;
}