#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <stdarg.h>

int stats(int *sum, float *avg, int num, ...);

int main()
{
	int suma=0;
	float avg=0;
	if (stats(&suma, &avg, 4, 2, 3, 4, 5) == 0) printf("%d %.2f", suma, avg);
	else printf("error");
	printf("\n");
	if (stats(&suma, &avg, 3, 1,7,12) == 0) printf("%d %.2f", suma, avg);
	else printf("error");
	//_getch();
	return 0;
}

int stats(int *sum, float *avg, int num, ...)
{
	if (sum == NULL || avg == NULL || num < 1) return 1;
	float suma = 0;
	int number=num;
	va_list arg;
	va_start(arg, num);

	for (int i = 0;i<number; i++)
	{
		suma += va_arg(arg, int);
	}
	va_end(arg);
	*avg = suma / number;
	*sum = suma;
	return 0;
}