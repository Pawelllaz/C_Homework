#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

void quicksort_asc(int l, int r, int tab[])
{
	int i = l, j = r;
	int x = tab[(l + r)/2];
	do {
		while (tab[i]<x) i++;
		while (tab[j]>x) j--;
		if (i <= j) {
			int temp = tab[i];
			tab[i] = tab[j];
			tab[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);
	if (l<j) quicksort(tab, l, j);
	if (r>i) quicksort(tab, i, r);
	
}
void quicksort_desc(int l, int r, int tab[])
void quicksort(int tab[], int size, int dir)
{
	if (dir == 1) quicksort_asc(0, size, tab);
	else if (dir == 2) quicksort_desc(0, size, tab);
	else printf("Error");
}