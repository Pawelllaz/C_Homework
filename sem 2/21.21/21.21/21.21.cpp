#include "stdafx.h"
#include <stdio.h>
//#include <conio.h>
#define N 5
int column_statistics(const int *ptr, int width, int height, int column_id, int* max, int* min, float *avg)
{
	if (ptr == NULL || max == NULL || min == NULL || avg == NULL) return 0;
	if (width <= 0 || height <= 0) return 0;
	if (column_id >= width || column_id < 0) return 0;
	float sum = 0, mini = *(ptr + column_id), liczba, maxi = *(ptr + column_id);

	for (int i = 0; i < height; i++)
	{
		liczba = *(ptr + column_id + i * width);
		//printf("kolumny - %.0f\n", liczba);
		sum += liczba;
		if (mini > liczba) mini = liczba;
		if (maxi < liczba) maxi = liczba;
	}
	*max = maxi;
	*min = mini;
	*avg = sum / height;

	return 1;
}
//==========================================================================================================
int row_statistics(const int *ptr, int width, int height, int row_id, int* max, int* min, float *avg)
{
	if (ptr == NULL || max == NULL || min == NULL || avg == NULL) return 0;
	if (width <= 0 || height <= 0) return 0;
	if (row_id >= height || row_id<0) return 0;
	float sum = 0, mini = *(ptr + row_id * width), liczba, maxi = *(ptr + row_id * width);

	for (int i = 0; i < width; i++)
	{
		liczba = *(ptr + i + width * row_id);
		//printf("wiersze: %.0f\n", liczba);
		sum += liczba;
		if (mini > liczba) mini = liczba;
		if (maxi < liczba) maxi = liczba;
	}
	*max = maxi;
	*min = mini;
	*avg = sum / width;

	return 1;
}
//==========================================================================================================
int main()
{
	int tab[N][N], maxi, mini;
	int *q_tab = tab[0], *qmaxi = &maxi, *qmini = &mini;
	float avg;
	float  *qavg = &avg;
	printf("opowiedz historie: \n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", *(tab + i) + j);
		}
	}
	int spr;
	for (int i = 0; i < N; i++)
	{
		spr = column_statistics(q_tab, N, N, i, qmaxi, qmini, qavg);
		if (spr) printf("%d %d %.2f\n", *qmini, *qmaxi, *qavg);
		else printf("Error");
	}
	for (int i = 0; i < N; i++)
	{
		spr = row_statistics(q_tab, N, N, i, qmaxi, qmini, qavg);
		if (spr) printf("%d %d %.2f\n", *qmini, *qmaxi, *qavg);
		else printf("Error");
	}
	//_getch();
	return 0;
}