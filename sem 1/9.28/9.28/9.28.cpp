#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h>
#define SIZE 50
#define LEN 30

void sort_names_alphabetically(char names[SIZE][LEN], int size)
{
	int i,j;
	char tymczasowa[50];
	for (i = 0; i < size; i++)
	{
		for (j = 1; j < size; j++)
		{
			if (strcmp(names[j - 1], names[j])>0)
			{
				strcpy(tymczasowa, names[j - 1]);
				strcpy(names[j - 1], names[j]);
				strcpy(names[j], tymczasowa);
			}
		}
	}
}
//===============================================================
int main()
{
	char names[SIZE][LEN];
	int i, ilosc;
	char mojeimie[6] = { "Pawe\210" };
	printf("podaj liczbe imion: ");
	scanf("%d", &ilosc);

	printf("podaj imiona:\n");
	for (i = 0; i < ilosc; i++)
	{
		scanf("%s", names[i]);
	}
	strcpy(names[ilosc], mojeimie);
	ilosc++;
	sort_names_alphabetically(names, ilosc);
	for (i = 0; i < ilosc; i++)
	{
		printf("%s", names[i]);
		printf("\n");
	}
	//_getch();
	return 0;
}