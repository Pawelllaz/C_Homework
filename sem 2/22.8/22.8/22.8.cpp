#include "stdafx.h"
#include <stdio.h>
//#include <conio.h>
#define N 1010
int change_letter_size(const char* src, char* dest)
{
	if (src == NULL || dest == NULL) return 0;
	char c,counter=0;
	for (int i = 0; *(src + i)!=0 ; i++)
	{
		if (*(src + i) == 10) break;
		c = *(src + i);
		if (c >= 'a' && c <= 'z') c -= 32;
		else if (c >= 'A' && c <= 'Z') c += 32;
		*(dest + i) = c;
		counter++;
	}
	*(dest + counter) = 0;
	return 1;
}

int main()
{
	char txt1[N], txt2[N];
	char *q_txt2 = txt2;
	printf("wpisz tekst:\n");
	fgets(txt1, N, stdin);
	int spr;

	spr = change_letter_size(txt1, txt2);
	if (spr)
	{
		for (int i = 0; *(txt2 + i) != 0; i++)
		{
			printf("%c", *(q_txt2 + i));
		}
	}
	//_getch();
	return 0;
}