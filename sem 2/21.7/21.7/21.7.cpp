#include "stdafx.h"
#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define N 100
//================================================================
int sum(const float* tab, unsigned int size, float *result)
{
	if (tab == NULL || size <= 0 || result == NULL) return 0;

	float suma = 0;
	for (unsigned int i = 0; i < size; i++)
	{
		suma += *(tab + i);
	}
	*result = suma;
	return 1;
}
//================================================================
int avg(const float* tab, unsigned int size, float *result)
{
	if (tab == NULL || size <=0 || result == NULL) return 0;
	float suma = 0;
	for (unsigned int i = 0; i < size; i++)
	{
		suma += *(tab + i);
	}
	suma /= size;
	*result = suma;
	return 1;
}
//================================================================
int main()
{
	float T[N];
	float *q = T, suma = 0, srednia = 0;
	int counter = 0, spr = 0;
	float *p_suma = &suma, *p_avg = &srednia;

	printf("podaj liczby:\n");
	for (int i = 0; i < N; i++)
	{
		scanf("%f", q+i);
	//	printf("%f\n", *(q+i));
		if (*(q+i) == 0) break;
		counter++;
	}
	if (counter == 0)
	{
		printf("Error");
		return 1;
	}
	spr += sum(T, counter, p_suma);
	spr+=avg(T,counter,p_avg);
	if (spr == 2)
	{
		printf("Suma: %.2f\nSrednia: %.2f", *p_suma, *p_avg);
	}
	else
	{
		printf("Error");
	}
	//_getch();

	return 0;
}