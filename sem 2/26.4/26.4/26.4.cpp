#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <Windows.h>

int create_array2(float **ptr, int N)
{
	if (ptr == NULL) return 2;
	if (N <= 0) return 2;
	*ptr = (float*)malloc(sizeof(float)*N);
	if (*ptr == NULL) return 1;
	return 0;
}

int main()
{
	srand(time(NULL));
	int N;
	printf("wpisz wielksc: ");
	scanf("%d", &N);
	float *tab;
	int spr = create_array2(&tab,N);
	if (spr!=0)
	{
		printf("Error");
		return 1;
	}
	for (int i = 0; i < N; i++)
	{
		int liczba;
		liczba = rand() % 1900 - 1000;
		*(tab + i) = liczba;
		*(tab + i) /= 100;
		printf("%.2f ", *(tab + i));
	}
	free(tab);
	//system("PAUSE");
	return 0;
}