#include "stdafx.h"
#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>
#define N 10

int main()
{
	int T[N];
	int *a = T;
	for (int i = 0; i < N; i++)
	{
		*(a+i) = i;
	}
	
	for (int i = 0; i < N; i++)
	{
		printf("%d ", *(a+i));
	}

	//_getch();

	return 0;
}