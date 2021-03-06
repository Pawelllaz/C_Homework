#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>

struct matrix_t {
	int **ptr;
	int width;
	int height;
};
//=============================================================================
int create(struct matrix_t *m, int width, int height)
{
	if (m == NULL || width < 1 || height < 1) return 1;

	m->ptr = (int**)malloc(sizeof(int*) * height);
	if (m->ptr == NULL) return 2;
	for (int i = 0; i<height; i++)
	{
		*(m->ptr + i) = (int*)malloc(sizeof(int) * width);
		if (*(m->ptr + i) == NULL)
		{
			for (int j = 0; j <i; j++)
				free(*(m->ptr + j));
			free(m->ptr);
			return 2;
		}
	}
	m->height = height;
	m->width = width;
	return 0;
}
//============================================================================
void destroy(struct matrix_t *m)
{
	if (m == NULL || m->height < 1 || m->width < 1 || m->ptr == NULL) return;
	for (int i = 0; i<m->height; i++)
		free(*(m->ptr + i));
	free(m->ptr);	
}
//================================================================================
void display(const struct matrix_t *m)
{
	if (m == NULL || m->width < 1 || m->height < 1) return;

	for (int i = 0; i < m->height; i++)
	{
		for (int j = 0; j < m->width; j++)
			printf("%4d", *(*((*m).ptr + i) + j));
		printf("\n");
	}
}
//===================================================================================
int read(struct matrix_t *m)
{
	if (m == NULL || m->width < 1 || m->height < 1 || m->ptr == NULL) return 1;
	
	printf("podaj liczby:\n");
	for (int i = 0; i<m->height; i++)
		for (int j = 0; j<m->width; j++)
			scanf("%d", (*(m->ptr + i) + j));
	return 0;
}
//==================================================================================
int main()
{
	int w, h;
	struct matrix_t m;
	printf("podaj szerokosc i wysokosc: ");
	scanf("%d%d", &w,&h);
	/*if (w <= 0)
	{
		printf("failed to allocate memory");
		return 1;
	}
	scanf("%d", &h);
	if (h <= 0)
	{
		printf("fai");
		return 1;
	}*/
	int spr = create(&m, w, h);
	if (spr == 2)
	{
		printf("Failed to allocate memory");
		return 1;
	}
	else if (spr == 1)
	{
		printf("failed to allocate memory");
		return 1;
	}
	spr = read(&m);
	if (spr)
	{
		printf("incorrect input");
		return 1;
	}
	display(&m);
	destroy(&m);
	//_getch();
	return 0;
}
