#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#define N 1010
//==========================================================
int my_strlen(const char* str)
{
	if (str == NULL) return -1;
	int counter = 0;
	for (int i = 0; *(str + i) != 0; i++)
	{
		if (*(str + i) == 10) break;
		counter++;
	}
	return counter;
}
//==========================================================
char* my_strcpy(char* dest, const char* src)
{
	if (src == NULL) return NULL;
	for (int i = 0;; i++)
	{
		if (*(src + i) == 0 || *(src+i)==10) 
		{
			*(dest + i) = 0;
			break;
		}
		*(dest + i) = *(src + i);
	}
	return dest;
}
//==========================================================
char* my_strcat(char* dest, const char* src)
{
	if (src == NULL) return NULL;
	int counter = my_strlen(dest);
	printf("o kuzwa : %d\n", *(dest + counter));
	for (int i = 0; i < my_strlen(src); i++)
	{
		*(dest + counter) = *(src + i);
		counter++; 
	}
	for (int i = 0; i < 6; i++)
	{
		printf("%c\n", *(dest + i));
	}
	return dest;
}
//==========================================================
int main()
{
	char tab1[N], tab2[N];
	char *q_tab1 = tab1, *q_tab2 = tab2;
	
	printf("wprowadz napis 1:\n");
	fgets(tab1, N, stdin);
	printf("wprowadz napis 2:\n");
	fgets(tab2, N, stdin);
	printf("napis1: %d napis 2: %d", my_strlen(tab1), my_strlen(tab2));

	printf("\n%s\n%s",my_strcpy(tab1,tab2),my_strcat(tab1,tab2));
	
	_getch();
	return 0;
}