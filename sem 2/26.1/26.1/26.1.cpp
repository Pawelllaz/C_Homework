#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#define N 100
int main()
{
	int *tablica = (int*) malloc(N * sizeof(int));
	if (tablica == NULL)
	{
		printf("error");
		return 1;
	}
	for (int i = 0; i < N; i++)
	{
		*(tablica + i) = i;
	}
	for (int  i = 0; i < N; i++)
	{
		printf("%d ", *(tablica + i));
	}

	free(tablica);
	return 0;
}