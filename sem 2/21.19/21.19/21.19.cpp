#include "stdafx.h"
#include <stdio.h>
//#include <conio.h>
#define N 100
//=================================================
int reverse_vector(int* tab, int size)
{
	int tym;
	if (tab == NULL) return 0;
	if (size <= 0) return 0;
	for (int i=0; i < size/2; i++)
	{
		tym = *(tab + size - 1 - i);
		*(tab + size - 1 - i) = *(tab+i);
		*(tab + i) = tym;
	}
	return 1;
}
//=================================================
int display_vector(const int* tab, int size)
{
	if (tab == NULL) return 0;
	if (size <= 0) return 0;
	for (int i = 0; i < size; i++)
	{
		printf("%d ", *(tab + i));
	}
	printf("\n");
	return 1;
}
//=================================================
int main()
{
	int tab[N], size;
	int *p_tab = tab;
	printf("podaj ilosc liczb: ");
	scanf("%d", &size);
	printf("wpisz liczby:");
	for (int i = 0; i < size; i++)
	{
		scanf("%d", p_tab + i);
	}

	display_vector(p_tab, size);
	reverse_vector(p_tab, size);
	display_vector(p_tab, size);
	//_getch();
	return 0;
}

