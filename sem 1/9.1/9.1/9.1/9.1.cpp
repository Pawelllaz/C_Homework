// 9.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include "vector_utils.h"

int main()
{
	const int size = 150;
	int tab[size];

	read_vector(tab, size, 0);
	display_vector(tab, size);
    return 0;
}

