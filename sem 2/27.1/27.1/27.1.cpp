#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
//#include <conio.h>
int main()
{
	int **tab;
	tab = (int**)malloc(sizeof(int*) * 10);
	if (tab == NULL)
	{
		printf("error");
		return 1;
	}
	for (int i = 0; i<10; i++)
	{
		*(tab + i) = (int*)malloc(sizeof(int) * 10);
		if (*(tab + i) == NULL)
		{
			for (int j = i; j>=0; j--)
				free(*(tab + j));
			free(tab);
			printf("error");
			return 1;
		}
	}
	for (int i = 0; i<10; i++)
		for (int j = 0; j<10; j++)
			*(*(tab + i) + j) = (j + 1)*(i + 1);
	for (int i = 0; i<10; i++)
	{
		for (int j = 0; j<10; j++)
		{
			printf("%3d ", *(*(tab + i) + j));
		}
		printf("\n");
	}
	for (int i = 0; i<10; i++)
		free(*(tab + i));
	free(tab);
	
	//_getch();
	return 0;
}
