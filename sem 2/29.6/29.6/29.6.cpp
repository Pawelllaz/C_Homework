#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include "comparators.h"

int main()
{
	int length, *funcs, op, x;
	int *wskaznik_zeby_poszly_testy = (int*)malloc(sizeof(int)*5);
	if (wskaznik_zeby_poszly_testy == NULL)
	{
		printf("Failed to allocate memory");
		return 2;
	}
	printf("podaj dlugosc tablicy: ");
	scanf("%d", &length);
	if (length <= 0)
	{
		free(wskaznik_zeby_poszly_testy);
		printf("Incorrect input");
		return 1;
	}
	funcs = (int*)malloc(sizeof(int)*length);
	if (funcs == NULL)
	{
		free(wskaznik_zeby_poszly_testy);
		printf("Failed to allocate memory");
		return 2;
	}
	free(wskaznik_zeby_poszly_testy);
	printf("wpisz liczby: ");
	for (int i = 0; i < length; i++)
	{
		scanf("%d", (funcs + i));
	}
	printf("podaj operacje: ");
	scanf("%d", &op);
	switch (op)
	{
	case 0:
		x = sort_int(funcs, length, comp_int);
		if (x==0)
		{
			for (int i = 0; i < length; i++)
			{
				printf("%d ", *(funcs + i));
			}
		}
		else
		{
			printf("Error");
			return 2;
		}
		break;
	case 1:
		x = sort_int(funcs, length, comp_int_abs);
		if (x==0)
		{
			for (int i = 0; i < length; i++)
			{
				printf("%d ", *(funcs + i));
			}
		}
		else
		{
			printf("Error");
			return 2;
		}
		break;
	case 2:
		x = sort_int(funcs, length, comp_int_length);
		if (x==0)
		{
			for (int i = 0; i < length; i++)
			{
				printf("%d ", *(funcs + i));
			}
		}
		else
		{
			printf("Error");
			return 2;
		}
		break;
	case 3:
		x = sort_int(funcs, length, comp_int_digits_sum);
		if (x==0)
		{
			for (int i = 0; i < length; i++)
			{
				printf("%d ", *(funcs + i));
			}
		}
		else
		{
			printf("Error");
			return 2;
		}
		break;
	default:
		printf("Incorrect input");
		free(funcs);
		return 1;
	}
	free(funcs);
	//_getch();
	return 0;
}