#include "stdafx.h"
#include <stdio.h>
//#include <conio.h>
#define N 1010
int space_changer(char* t)
{
	if (t == NULL) return 0;

	for (int i = 0; *(t + i) != 0; i++)
	{
		if (*(t + i) == 10) break;
		if (*(t + i) == ' ') *(t + i) = '_';
	}
	return 1;
}

int main()
{
	char txt1[N];
	char *q_txt1 = txt1;
	printf("wpisz tekst:\n");
	fgets(txt1, N, stdin);
	int spr;

	spr = space_changer(txt1);
	if (spr)
	{
		for (int i = 0; *(q_txt1 + i) != 0; i++)
		{
			if (*(q_txt1 + i) == 10) break;
			printf("%c", *(q_txt1 + i));
		}
	}
	//_getch();
	return 0;
}