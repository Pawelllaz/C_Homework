#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

int comp_int(int a, int b)
{
	//printf("a");
	if (a > b) return 1;
	else if (a < b) return -1;
	else return 0;
}
int comp_int_abs(int a, int b)
{
	int l1, l2;
	l1 = a;
	l2 = b;
	if (l1 < 0) l1 *= (-1);
	if (l2 < 0) l2 *= (-1);
	if (l1 > l2) return 1;
	else if (l1 < l2) return -1;
	else return 0;
}
int comp_int_length(int a, int b)
{
	int l1 = 1, l2 = 1;
	if (a < 0) a *= -1;
	if (b < 0) b *= -1;
	while ((a /= 10) != 0)
		l1++;
	while ((b /= 10) != 0)
		l2++;
	if (l1 > l2) return 1;
	else if (l1 < l2) return -1;
	else return 0;
}
int comp_int_digits_sum(int a, int b)
{
	
	int l1 = 0, l2 = 0;
	if (a < 0) a *= -1;
	if (b < 0) b *= -1;
	l1 += a % 10;
	l2 += b % 10;
	while ((a /= 10) != 0)
		l1 += a % 10;
	while ((b /= 10) != 0)
		l2+=b%10;
	if (l1 > l2) return 1;
	else if (l1 < l2) return -1;
	else return 0;
}
void swap(int *a, int *b)
{
	int tym;
	tym = *b;
	*b = *a;
	*a = tym;
}
int sort_int(int *tab, int lenth, int(*ptr)(int, int))
{
	if (tab == NULL || lenth < 1 || ptr==NULL) return 1;
	for (int i = 0; i < lenth; i++)
	{
		for (int j = 0; j < lenth-1; j++)
		{
			if (ptr(*(tab + j), *(tab + j+1))==1)
			{
				swap((tab + j), (tab + j+1));
			}
		}
	}
	return 0;
}