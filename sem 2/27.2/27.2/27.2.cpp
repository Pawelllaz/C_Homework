#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>

int **create_array_2d(int width, int height)
{
	if (width <= 0 || height <= 0) return 0;

	int **tab;
	tab = (int**)malloc(sizeof(int*) * height);
	if (tab == NULL) return 0;
	for (int i = 0; i<height; i++)
	{
		*(tab + i) = (int*)malloc(sizeof(int) * width);
		if (*(tab + i) == NULL)
		{
			for (int j = 0; j <i; j++)
				free(*(tab + j));
			free(tab);
			return NULL;
		}
	}

	return tab;
}
//===========================================================================================
void display_array_2d(int **ptr, int width, int height)
{
	if (ptr == NULL || width <= 0 || height <= 0) return;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			printf("%d ", *(*(ptr + i) + j));
		printf("\n");
	}
}
//==============================================================================================
int read_array_2d(int **ptr, int width, int height)
{
	if (ptr == NULL || width <= 0 || height <= 0) return 1;
	printf("podaj liczby:\n");
	for (int i = 0; i<height; i++)
		for (int j = 0; j<width; j++)
			scanf("%d", (*(ptr + i) + j));
	return 0;
}
//=============================================================================================
int main()
{
	int w, h, **tab;
	printf("podaj szerokosc i wysokosc: ");
	scanf("%d", &w);
	if (w <= 0)
	{
		printf("incorrect input");
		return 1;
	}
	scanf("%d", &h);
	if (h <= 0)
	{
		printf("incorrect input");
		return 1;
	}
	tab = create_array_2d(w, h);
	if (tab == NULL)
	{
		printf("Failed to allocate memory");
		return 1;
	}
	int spr = read_array_2d(tab, w, h);
	if (spr)
	{
		printf("incorrect input");
		return 1;
	}
	display_array_2d(tab, w, h);

	for (int i = 0; i < h; i++)
		free(*(tab + i));
	free(tab);
	//_getch();
	return 0;
}