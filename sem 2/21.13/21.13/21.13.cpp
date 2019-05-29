#include "stdafx.h"
#include <stdio.h>

int swap(int *a, int *b)
{
	if (a == NULL) return 0;
	if (b == NULL) return 0;
	int t;
	t = *a;
	*a = *b;
	*b = t;
	return 1;
}

int main()
{
	int a, b;
	int *p_a = &a, *p_b = &b;
	printf("wpisz dwie liczby: ");
	scanf("%d %d", &a, &b);
	int spr = 0;
	spr=swap(p_a, p_b);
	if (spr)
	{
		printf("a: %d b: %d", a, b);
	}
	else
	{
		printf("Error");
	}
	
	return 0;
}