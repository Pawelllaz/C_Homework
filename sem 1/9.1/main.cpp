#include <stdio.h>
#include "vector_utils.h"

int main()
{
	const int amount = 150;
	int tab[amount],counter=0;

	counter=read_vector(tab, amount, 0);
	display_vector(tab, counter);
    return 0;
}

