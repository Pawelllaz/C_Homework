#include "stdafx.h"
#include <stdio.h>
#include "bubble_sort.h"
#include "vector_utils.h"

//====================================================
void bubble_sort(int tab[], int size, int dir)
{
	if (dir == 1)
	{
		bubble_sort_asc(tab, size);
	}
	else if (dir == 2)
	{
		bubble_sort_desc(tab, size);
	}
}
//====================================================
void bubble_sort_desc(int tab[], int size)
{
	int i, j, liczba;
	for (i = 0; i<size - 1; i++)
	{
		liczba = 0;
		for (j = 0; j<size - 1; j++)
		{
			if (tab[j]<tab[j + 1])
			{
				liczba = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = liczba;
			}
		}
		if (liczba == 0) break;
		//display_vector(tab, size);
	}
	//display_vector(tab, size);
}
//======================================================
void bubble_sort_asc(int tab[], int size)
{
	int i, j, liczba;
	for (i = 0; i<size - 1; i++)
	{
		liczba = 0;
		for (j = 0; j<size - 1; j++)
		{
			if (tab[j]>tab[j + 1])
			{
				liczba = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = liczba;
			}
		}
		//display_vector(tab, size);
		if (liczba == 0) break;
	}
}
//===========================================================
void bubble_sort_asc_rec(int tab[], int size)
{
	int i, liczba;
	if (size == 1) return;
	//printf("%d\n", size);
	for (i = 0; i < size - 1; i++)
	{
		liczba = 0;
		if (tab[i] > tab[i + 1])
		{
			liczba = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = liczba;
		}
	}
	bubble_sort_asc_rec(tab, size - 1);
}
//==============================================================
void bubble_sort_desc_rec(int tab[], int size)
{
	int i, liczba;
	if (size == 1) return;
	//printf("%d\n", size);
	for (i = 0; i < size - 1; i++)
	{
		liczba = 0;
		if (tab[i] < tab[i + 1])
		{
			liczba = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = liczba;
		}
		
	}
	bubble_sort_desc_rec(tab, size - 1);
}
//==============================================================
void bubble_sort_rec(int tab[], int size, int dir)
{
	if (dir == 1)
	{
		bubble_sort_asc_rec(tab, size);
	}
	else if (dir == 2)
	{
		bubble_sort_desc_rec(tab, size);
	}
}
//==============================================================