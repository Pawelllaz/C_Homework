#include "stdafx.h"
#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

int main()
{
	srand(time(NULL));
	float T[N], a;
	float *q = T, suma = 0, avg = 0;
	
	for (int i = 0; i < N; i++)
	{
		a = rand()%10000;
		a /= 100;
		*(q+i)=a;
	}
	
	for (int i = 0; i < N; i++)
	{
		suma += *(q + i);
	}
	avg = suma / N;
	for (int i = 0; i < N; i ++ )
	{
		printf("%f ", *(q + i));
	}
	printf("\nSuma: %.2f\nSrednia: %.2f", suma, avg);

	//_getch();

	return 0;
}