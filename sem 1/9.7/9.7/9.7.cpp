#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h"
#include "vector_utils.h"

int main()
{
	const int N = 150;
	int i, size, direction, tab1[N], tab2[N], tab3[N];

	size = read_vector(tab1, N, 0);

	printf("wybierz kierunek: ");
	scanf("%d", &direction);
	if (direction != 1 && direction != 2)
	{
		printf("Error");
		return 0;
	}

	for (i = 0; i < size; i++)
	{
		tab2[i] = tab1[i];
	}

	for (i = 0; i < size; i++)
	{
		tab3[i] = tab1[i];
	}

	bubble_sort(tab1, size, direction);
	selection_sort(tab2, size, direction);
	insertion_sort(tab3, size, direction);

	display_vector(tab1, size);

	return 0;
}
