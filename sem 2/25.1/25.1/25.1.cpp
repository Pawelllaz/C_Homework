#include "stdafx.h"
#include <stdio.h>
//#include <Windows.h>
union byte_set
{
	int liczba;
	unsigned char b[4];
};
int main()
{
	union byte_set byte;
	printf(": ");
	scanf("%d", &byte.liczba);

	//printf("%d\n", byte.liczba);
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", *(byte.b+i));
	}
	//system("PAUSE");
	return 0;
}