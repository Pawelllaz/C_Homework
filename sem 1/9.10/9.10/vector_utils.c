//#include "stdafx.h"
#include "stdafx.h"
#include <stdio.h>
#include "vector_utils.h"

int read_vector(int vec[], int size, int stop_value)
{
	int counter = 0;
	printf("podaj liczby:\n");
	for (counter = 0; counter < size; counter++)
	{
		scanf("%d", &vec[counter]);
		if (vec[counter] == stop_value) break;
	}
	return counter;
}
//==========================================================
void display_vector(int vec[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d ", vec[i]);
	}
	printf("\n");
}
