#include "stdafx.h"
#include <stdio.h>
#include <Windows.h>
union word_set
{
	int liczba;
	unsigned short b[2];
};
int main()
{
	union word_set byte;
	printf(": ");
	scanf("%d", &byte.liczba);

	//printf("%d\n", byte.liczba);
	for (int i = 0; i < 2; i++)
	{
		printf("%d ", *(byte.b + i));
	}
	system("PAUSE");
	return 0;
}