#include "stdafx.h"
#include <stdio.h>
#include "vector_utils.h"
#include <stdlib.h>
//#include <conio.h>

int main()
{
	const int N = 150;
	int size, tab[N];

	size = read_vector(tab, N, 0);

	bubble_sort(tab, size);

	display_vector(tab, size);

	//_getch();

	return 0;
}