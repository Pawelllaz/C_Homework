#include <stdio.h>
#include "stdafx.h"
//#include <conio.h>

int main()
{
	int a = 5;
	int *q;

	q = &a;

	printf("%d %d %p", a, *q, (void *)q);

	*q = 10;

	printf("\n%d %d %p", a, *q, (void*)q);

	//_getch();
	return 0;
}