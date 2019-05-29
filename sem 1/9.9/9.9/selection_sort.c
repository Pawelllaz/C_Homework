#include "stdafx.h"
#include <stdlib.h>
#include "selection_sort.h"
#include "vector_utils.h"

//========================================================
void selection_sort_asc_rec(int tab[], int size, int index)
{
	int liczba, k;
	if (index==size) return;

	k = find_min(tab, size,index);
	if (tab[index] > tab[k])
	{
		liczba = tab[k];
		tab[k] = tab[index];
		tab[index] = liczba;
	}

	selection_sort_asc_rec(tab, size, index+1);
}
//============================================================
void selection_sort_desc_rec(int tab[], int size, int index)
{
	int liczba, k;
	if (index == size) return;

	k = find_max(tab, size, index);
	if (tab[index] < tab[k])
	{
		liczba = tab[k];
		tab[k] = tab[index];
		tab[index] = liczba;
	}
	selection_sort_desc_rec(tab, size, index + 1);
}
//===========================================================
void selection_sort_rec(int tab[], int size, int dir)
{
	if (dir == 1) selection_sort_asc_rec(tab, size, 0);
	else if (dir == 2) selection_sort_desc_rec(tab, size, 0);
}
//=====================================================
void selection_sort_asc(int tab[], int size)
{
	int i, liczba, k;
	for (i = 0; i < size; i++)
	{
		k = find_min(tab, size, i);
		if (tab[i] > tab[k])
		{
			liczba = tab[k];
			tab[k] = tab[i];
			tab[i] = liczba;
		}
		//display_vector(tab, size);
	}
}
//=======================================================
void selection_sort_desc(int tab[], int size)
{
	int i, liczba, k;
	for (i = 0; i<size; i++)
	{
		k = find_max(tab, size, i);
		if (tab[i]<tab[k])
		{
			liczba = tab[k];
			tab[k] = tab[i];
			tab[i] = liczba;

		}
		//display_vector(tab, size);
	}
}
//=========================================================
void selection_sort(int tab[], int size, int dir)
{
	if (dir == 1) selection_sort_asc(tab, size);
	else if (dir == 2) selection_sort_desc(tab, size);
}
//========================================================
int find_min(int tab[], int size, int start_index)
{
	int min = tab[start_index], i, index = start_index;

	for (i = start_index; i<size; i++)
	{
		if (tab[i]<min)
		{
			min = tab[i];
			index = i;
		}
	}
	return index;
}
//============================================================
int find_max(int tab[], int size, int start_index)
{
	int max = tab[start_index], i, index = start_index;
	for (i = start_index; i<size; i++)
	{
		if (max<tab[i])
		{
			max = tab[i];
			index = i;
		}
	}
	return index;
}
//==================================================
