#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>

int create_array_2d_2(int ***ptr, int width, int height)
{
	if (width <= 0 || height <= 0 || ptr==NULL) return 1;

	*ptr = (int**)malloc(sizeof(int*) * height);
	if (*ptr == NULL) return 2;
	for (int i = 0; i<height; i++)
	{
		*((*ptr) + i) = (int*)malloc(sizeof(int) * width);
		if (*((*ptr) + i) == NULL)
		{
			for (int j = 0; j <i; j++)
				free(*((*ptr) + j));
			free(*ptr);
			return 2;
		}
	}
	
	return 0;
}
//=====================================================================================
void destroy_array_2d(int ***ptr, int height)
{
	if (height <= 0) return;
	for (int i = 0; i<height; i++)
		free(*((*ptr) + i));
	free(*ptr);
}
//===========================================================================================
int sum_array_2d(int **ptr, int width, int height)
{
	if (width < 1 || height < 1 || ptr==NULL) return 0;
	int suma = 0;
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			suma += *(*(ptr + i) + j);
	return suma;
}
//==============================================================================================
int sum_row(int *ptr, int width)
{
	if (width < 1 || ptr==NULL) return 0;
	int suma = 0;
	for (int i = 0; i < width; i++)
		suma += *(ptr + i);
	return suma;
}
//============================================================================================
//========================================================================================
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
	if (ptr == NULL || width<=0 || height<=0) return;
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
	if (ptr == NULL || width<=0 || height<=0) return 1;
	printf("podaj liczby:\n");
	for(int i=0;i<height;i++)
		for(int j=0;j<width;j++)
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
	int spr = create_array_2d_2(&tab, w, h);
	if (spr==2)
	{
		printf("Failed to allocate memory");
		return 1;
	}
	else if (spr == 1)
	{
		printf("error");
		return 1;
	}
	spr = read_array_2d(tab, w, h);
	if (spr)
	{
		printf("incorrect input");
		return 1;
	}
	display_array_2d(tab, w, h);
	
	int suma = sum_array_2d(tab, w, h);
	if (suma != 0) printf("%d\n", suma);
	else
	{
		printf("error");
		return 1;
	}
	for (int i = 0; i < h; i++)
		printf("%d\n", sum_row(*(tab + i), w));
	destroy_array_2d(&tab, h);
	//_getch();
	return 0;
}