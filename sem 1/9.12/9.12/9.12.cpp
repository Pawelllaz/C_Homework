#include <stdio.h>
//#include "stdafx.h"
#include "vector_utils.h"
#include <stdlib.h>

int main()
{
	const int N = 150;
	int size, tab[N];
	
	size = read_vector(tab, N, 0);
	
	bubble_sort_asc(tab, size);

	display_vector(tab, size);

	return 0;
}