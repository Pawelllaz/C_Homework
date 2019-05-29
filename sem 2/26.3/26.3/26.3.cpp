#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <Windows.h>

float* create_array(int N)
{
	if (N <= 0) return NULL;
	return (float*)malloc(sizeof(float)*N);
}

int main()
{
	srand(time(NULL));
	int N;
	printf("wpisz wielksc: ");
	scanf("%d", &N);
	float *tab;
	tab = create_array(N);
	if (tab == NULL)
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