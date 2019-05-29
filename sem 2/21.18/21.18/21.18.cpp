#include "stdafx.h"
#include <stdio.h>
//#include <conio.h>
#define N 100

int tab_min(const int* tab, int size, int *min)
{
	if (tab == NULL) return 0;
	if (size <= 0) return 0;
	if (min == NULL) return 0;
	
	*min = *tab;
	for (int i = 0; i < size; i++)
	{
		if (*min > *(tab + i))
		{
			*min = *(tab + i);
		}
	}
	return 1;
}

int main()
{
	int tab[N], size, min=0;
	int *p_tab = tab,*p_min=&min;

	printf("podaj ile liczb wprowadzisz: ");
	scanf("%d", &size);

	for (int i = 0; i < size; i++)
	{
		scanf("%d", p_tab+i);
	}
	
	int spr = 0;
	spr = tab_min(tab, size, p_min);
	if (spr) printf("Min: %d", *p_min);
	else printf("Error");

	//_getch();
	return 0;
}