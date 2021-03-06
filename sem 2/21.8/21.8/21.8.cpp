#include "stdafx.h"
#include <stdio.h>
//#include <conio.h>
#define N 100
//====================================================
int read_vector(int* tab, int size, int stop_value)
{
	int counter = 0;
	if (size <= 0) return 0;
	printf("wpisz liczby calkowiete:\n");
	for (int i = 0; i < size; i++)
	{
		scanf("%d", tab+i);
		//printf("%d\n", *(tab + i));
		if (*(tab+i) == stop_value) break;
		counter++;
	}
	return counter;
}
//=====================================================
void display_vector(const int* tab, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", *(tab + i));
	}
}
//=====================================================
int sort(int* tab, int size)
{
	if (tab == NULL) return 0;
	if (size <= 0) return 0;

	int zmienna;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (*(tab + i) < *(tab + j))
			{
				zmienna = *(tab + i);
				*(tab + i) = *(tab + j);
				*(tab + j) = zmienna;
			}
		}
	}
	return 1;
}
//=====================================================
int main()
{
	int tab[N], size = 0,spr=0;
	int *p_tab = tab;
	size = read_vector(p_tab, N, -1);
	spr=sort(p_tab, size);
	if (spr == 1)
	{
		display_vector(p_tab, size);
	}
	else
	{
		printf("Error");
	}

	//_getch();
	return 0;
}