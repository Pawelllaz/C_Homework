#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#define N 100

//===========================================================
int find(int to_find, const int* vector, int size)
{
	if (vector == NULL) return 0;
	int wyn=-1;
	for (int i = 0; i < size; i++)
	{
		if (to_find == *(vector + i)) wyn = i;
	}
	return wyn;
}
//===========================================================
int read_vector(int* vector, int max_size)
{
	if (vector == NULL) return 0;
	int counter = -1;
	for (int i = 0; i < max_size; i++)
	{
		scanf("%d", vector + i);
		counter++;
	}
	return counter;
}
//==========================================================
int main()
{
	int tab[N], size, counter,szukany,indeks;
	int *p_tab = tab;

	printf("podaj ilosc liczb: ");
	scanf("%d", &size);
	printf("wprowadz elementy: ");
	counter = read_vector(p_tab, size);
	printf("podaj element ktory chcesz znalezc");
	scanf("%d", &szukany);
	indeks=find(szukany, p_tab, size);
	printf("indeks szukanego elementu: %d", indeks);

	return 0;
}