#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
int longest_series(unsigned int x);
int main()
{
	unsigned int a;
	printf("podaj liczbe: ");
	scanf("%ui", &a);
	printf("wynik: %d", longest_series(a));
	//_getch();
	return 0;
}
int longest_series(unsigned int x)
{
	int t[1000], c = 0, rep = 0;
	t[0] = 0;
	for (int i = (sizeof(unsigned int) * 8) - 1; i >= 0; i--)
	{
		//printf("%d", x >> i & 1);
		if (x >> i & 1) rep++;
		else
		{
			//printf("\n%d", rep);
			t[c++] = rep;
			rep = 0;
		}
	}
	t[c++] = rep;
	int max = t[0];
	for (int i = 0; i < c; i++)
	{
		if (t[i] > max) max = t[i];
	}
	return max;
}