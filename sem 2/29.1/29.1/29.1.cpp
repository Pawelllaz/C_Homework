#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "int_operations.h"
// <conio.h>

int main()
{
	int a, b, op;
	printf("podaj liczby: ");
	int x = scanf("%d %d", &a, &b);
	if (x != 2)
	{
		printf("Incorrect input");
		return 1;
	}
	printf("podaj numer operacji: ");
	x = scanf("%d", &op);
	if (x != 1)
	{
		printf("Incorrect input");
		return 1;
	}
	switch (op)
	{
	case 0:
		printf("Wynik: %d", calculate(a, b, add_int));
		break;
	case 1:
		printf("Wynik: %d", calculate(a, b, sub_int));
		break;
	case 2:
		if (b == 0)
		{
			printf("Incorrect input");
			return 1;
		}
		printf("Wynik: %d", calculate(a, b, div_int));
		break;
	case 3:
		printf("Wynik: %d", calculate(a, b, mul_int));
		break;
	default:
		printf("Incorrect input");
		return 1;
	}
	//_getch();
	return 0;
}