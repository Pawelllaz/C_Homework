#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#define N 1010

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

int connect(const char* t1, const char* t2, const char* t3, char* t4, int size)
{
	if (t1 == NULL || t2 == NULL || t3 == NULL || t4 == NULL ) return 0;
	if (size <= 0) return 0;
	int counter = 0,i;
	for (i = 0; i < my_strlen(t1); i++)
	{
		*(t4 + i) = *(t1 + i); 
		printf("%c", *(t4 + i));
		counter++;
		if (counter > size) return 0;
	}
	for (i = 0; i < my_strlen(t2); i++);
	{
		*(t4 + counter) = *(t2 + i);
		printf("%c", *(t4 + counter));
		counter++;
		if (counter > size) return 0;
	}
	for (i = 0; i < my_strlen(t2); i++);
	{
		*(t4 + counter) = *(t3 + i);
		printf("%c", *(t4 + counter));
		counter++;
		if (counter > size) return 0;
	}
	return 1;
}

int main()
{
	char tab1[N], tab2[N], tab3[N], tab4[N];
	char *q_tab1 = tab1, *q_tab2 = tab2;

	printf("wprowadz napis 1:\n");
	fgets(tab1, N, stdin);
	printf("wprowadz napis 2:\n");
	fgets(tab2, N, stdin);
	printf("wprowadz napis 3:\n");
	fgets(tab3, N, stdin);

	if (connect(tab1, tab2, tab3, tab4, N))
	{
		/*for (int i = 0; i < 9; i++)
		{
			printf("%c", tab4[i]);
		}*/
	}
	_getch();
	return 0;
}