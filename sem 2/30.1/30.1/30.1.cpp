#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

int is_equal(int a, int b)
{
	int ax = a, bx = b;
	int c = ~0, i = 0;
	while(c<<=1) {
		if (ax >> i ^ bx >> i) return 0;
		i++;
	}
	return 1;
}
int is_negative(int value)
{
	int liczba = value;
	if (liczba >> 31 & 1 ) return 1;
	return 0;
}

int main()
{
	int a, b;
	printf("podaj dwie liczby: ");
	scanf("%d %d", &a, &b);
	if (is_equal(a, b)) printf("rowne\n");
	else printf("nierowne\n");
	if (is_negative(a)) printf("ujemna ");
	else printf("nieujemna ");
	if (is_negative(b)) printf("ujemna ");
	else printf("nieujemna ");
	return 0;
}