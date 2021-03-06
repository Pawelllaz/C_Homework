#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "selection_sort.h"
#include "vector_utils.h"

int main()
{
	const int N = 150;
	int size, direction, tab[N],met;

	size = read_vector(tab, N, 0);

	printf("wybierz kierunek: ");
	scanf("%d", &direction);
	if (direction != 1 && direction != 2)
	{
		printf("Error");
		return 0;
	}

	printf("wybierz metode: ");
	scanf("%d", &met);
	if (met == 1) selection_sort(tab, size, direction);
	else if (met == 2) selection_sort_rec(tab, size, direction);
	else
	{
		printf("Error");
		return 0;
	}

	display_vector(tab, size);
	return 0;
}
