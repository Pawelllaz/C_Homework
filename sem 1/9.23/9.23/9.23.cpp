#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

void sortowanie(char tab[])
{
	int i, j, counter=0;
	char znak;
	for (i = 0; tab[i + 1] != 0; i++)
	{
		counter++;
	}

	for (i = 0; i < counter-1; i++)
	{
		znak = 0;
		for (j = 0; j < counter-1; j++)
		{
			if (tab[j] > tab[j + 1])
			{
				znak = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = znak;
			}
		}
		if (znak == 0) break;
	}
}
int main()
{
	const int N = 500;
	char tab[N];
	int i;

	printf("wprowadz tekst do posortowania:\n");
	fgets(tab, N, stdin);
	
	sortowanie(tab);

	for (i = 0;tab[i+1]!=0; i++)
	{
		if(tab[i]>'0') printf("%c", tab[i]);
	}
	printf("\n");

	return 0;
}
