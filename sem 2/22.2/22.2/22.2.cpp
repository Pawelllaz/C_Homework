#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#define N 1010

int ASCIIZ_length(const char* txt)
{
	if (txt == NULL) return -1;
	int counter = 0;
	if (*txt == 0) return 0;
	for (int i = 0; *(txt + i)!=0; i++)
	{
		counter++;
	}
	return counter;
}

int	main()
{
	char txt[N];
	//char *q_txt = "";
	//int ilosc;
	printf("Pisz:\n");
	fgets(txt, N, stdin);
	printf("size: %d\n", ASCIIZ_length(txt)-1);
	_getch();
	return 0;
}