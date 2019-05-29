#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

unsigned int swap_bits(unsigned int * pvalue, int b1, int b2)
{
	unsigned int liczba = *pvalue;
	int a, b;
	for (int i =0;i< (sizeof(unsigned int) * 8) ; i++)
	{
		if (i == b1) a = liczba >> i & 1;
		if (i == b2) b = liczba >> i & 1;
	}
	for (int i = 0; i< (sizeof(unsigned int) * 8); i++)
	{
		if (i == b1) 
		{
			if(b==1) (liczba >> i) =1;
		if (i == b2) b = *pvalue >> i & 1;
	}
}

int main()
{
	unsigned int liczba;
	printf("Enter an unit32 number: ");
	scanf("%ui", &liczba);
	int pos1, pos2;
	printf("Enter 1st bit index: ");
	scanf("%d", &pos1);
	printf("Enter 2nd bit index: ");
	scanf("%d", &pos2);
	printf("Result: ");

	return 0;
}