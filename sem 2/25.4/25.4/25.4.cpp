#include "stdafx.h"
#include <stdio.h>
#include <Windows.h>
struct bites {
	unsigned char a : 1;
	unsigned char b : 1;
	unsigned char c : 1;
	unsigned char d : 1;
	unsigned char e : 1;
	unsigned char f : 1;
	unsigned char g : 1;
	unsigned char h : 1;
};

union bit_set
{
	unsigned int liczba;
	unsigned short slowo[2];
	unsigned char bajt[4];
	struct bites bity[4];
};
int main()
{
	union bit_set unia;
	printf(": ");
	scanf("%ud", &unia.liczba);
	
	printf("%u\n", unia.liczba);
	printf("%d %d\n", *(unia.slowo+0), *(unia.slowo + 1));
	for (int i = 0; i < 4; i++)
		printf("%u ", *(unia.bajt + i));
	printf("\n");
	for (int i = 0; i < 4; i++)
	{
		printf("%d", unia.bity[i].h);
		printf("%d", unia.bity[i].g);
		printf("%d", unia.bity[i].f);
		printf("%d", unia.bity[i].e);
		printf("%d", unia.bity[i].d);
		printf("%d", unia.bity[i].c);
		printf("%d", unia.bity[i].b);
		printf("%d ", unia.bity[i].a);
	}
	system("PAUSE");
	return 0;
}