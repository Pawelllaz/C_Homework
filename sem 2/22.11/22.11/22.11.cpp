#include "stdafx.h"
#include <stdio.h>
#include <ctype.h>
//#include <conio.h>
#define N 1010
int change_letter_size(char* txt, char c)
{
	if (txt == NULL) return 0;
	int counter = 0;
	char tym;
	if (c == 'B' || c == 'b')
	{
		for (int i = 0; *(txt + i) != 0; i++)
		{
			if (*(txt + i) == 10) break;
			tym = *(txt + i);
			if (*(txt+i) >= 'a' && *(txt+i) <= 'z') *(txt+i)=toupper(tym);
			//if (*(txt+i) >= 'A' && *(txt+i) <= 'Z') *(txt + i) += 32;
			counter++;
		}
		*(txt + counter) = 0;
	}
	else if (c == 's' || c == 'S')
	{
		for (int i = 0; *(txt + i) != 0; i++)
		{
			if (*(txt + i) == 10) break;
			tym = *(txt + i);
			//if (*(txt + i) >= 'a' && *(txt + i) <= 'z') *(txt + i) -= 32;
			if (*(txt+i) >= 'A' && *(txt+i) <= 'Z') *(txt + i)=tolower(tym);
			counter++;
		}
		*(txt + counter) = 0;
	}
	else return 0;

	return 1;
}

int main()
{
	char txt[N], c;
	char *q_txt = txt;
	printf("wpisz tekst:\n");
	fgets(txt, N, stdin);
	printf("podaj rodzaj modyfikacji: ");
	int sp=0;
	for (;;)
	{
		sp = 0;
		scanf("%c", &c);
		if (c == 10) sp++;
		if (sp)
		{
			printf("Incorrect data");
			scanf("%c", &c);
		}
		if (c == 's' || c == 'S' || c == 'B' || c == 'b') break;
	}
	int spr;

	spr = change_letter_size(q_txt, c);
	if (spr)
	{
		for (int i = 0; *(txt + i) != 0; i++)
		{
			if (*(txt + i) == 10) break;
			printf("%c", *(q_txt + i));
		}
	}
	//_getch();
	return 0;
}