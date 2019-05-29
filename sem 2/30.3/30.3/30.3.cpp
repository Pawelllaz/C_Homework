#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

void show(const void* ptr, size_t count);
void inverse_bits(void* ptr, size_t offset, size_t count);
void hex(int n);
int main()
{
	char *tekst = (char*)malloc(1000);
	if (tekst == NULL)	return 1;
	printf("podaj tekst: ");
	scanf("%99s", tekst);
	show(tekst, strlen(tekst) + 1);
	system("pause");
	return 0;
}

void hex(int n)
{
	if (n>0)
	{
		hex(n / 16);
		if (n % 16 > 9)
		{
			switch (n % 16)
			{
			case 10:
				printf("a");
				break;
			case 11:
				printf("b");
				break;
			case 12:
				printf("c");
				break;
			case 13:
				printf("d");
				break;
			case 14:
				printf("e");
				break;
			case 15:
				printf("f");
				break;
			}
		}
		else
		{
			printf("%d", n % 16);
		}
	}
	else printf("0");
}

void show(const void* ptr, size_t count)
{
	int *wsk = (int*)ptr;
	for (int i = 0; i < count; i++)
	{
		*wsk = (int)*(ptr+i);
		printf("wsk: %c\n", *(wsk+i));
		hex(*(wsk+i));
		printf(" ");
	}
}
void inverse_bits(void* ptr, size_t offset, size_t count)
{

}