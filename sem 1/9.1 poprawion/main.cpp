#include <stdio.h>
#include <stdlib.h>
#include "vector_utils.h"

int main()
{
	const int amount = 150;
	int tab[amount],counter=0;

	counter=read_vector(tab, amount, 0);

    bubble_sort(tab,counter);
    display_vector(tab,counter);
    return 0;
}

