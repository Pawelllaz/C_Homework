#include "stdafx.h"
#include <stdio.h>
#include "insertion_sort.h"

//========================================================
void insertion_sort_asc(int tab[], int size)
{
	int i, liczba, j;
	for (i = 1; i<size; i++)
	{
		liczba = tab[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (liczba < tab[j])
			{
				tab[j + 1] = tab[j];
			}
			else break;
		}
		tab[j + 1] = liczba;
	}
}
//=======================================================
void insertion_sort_desc(int tab[], int size)
{
	int i, liczba, j;
	for (i = 1; i<size; i++)
	{
		liczba = tab[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (liczba > tab[j])
			{
				tab[j + 1] = tab[j];
			}
			else break;
		}
		tab[j + 1] = liczba;
	}
}
//============================================================
void insertion_sort(int tab[], int size, int dir)
{
	if (dir == 1) insertion_sort_asc(tab, size);
	else if (dir == 2) insertion_sort_desc(tab, size);
	else printf("Error");
}
//============================================================
void insertion_sort_asc_rec(int tab[], int size)
{
	if (size <= 1) return;

	insertion_sort_asc_rec(tab, size - 1);

	int liczba = tab[size - 1],j;
	for (j=size-2; j >= 0 && tab[j]>liczba; j--)
	{
		tab[j + 1] = tab[j];
	}
	tab[j + 1] = liczba;
}
//==============================================================
void insertion_sort_desc_rec(int tab[], int size)
{
	if (size <= 1) return;

	insertion_sort_desc_rec(tab, size - 1);

	int liczba = tab[size - 1], j;
	for (j = size - 2; j >=0 && tab[j]<liczba; j--)
	{
		tab[j + 1] = tab[j];
	}
	tab[j + 1] = liczba;
}
//==============================================================
void insertion_sort_rec(int tab[], int size, int dir)
{
	if (dir == 1) insertion_sort_asc_rec(tab, size);
	else if (dir == 2) insertion_sort_desc_rec(tab, size);
	else printf("Error");
}
//===============================================================