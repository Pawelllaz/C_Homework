#include "stdafx.h"
#include <stdio.h>
//#include <conio.h>

int marks_counter(const char* text, int* uppercase, int* lowercase, int* whitespace)
{
	if (text == NULL) return -1;
	if (uppercase == NULL || lowercase == NULL || whitespace == NULL) return -2;

	int upper = 0, lower = 0, space = 0;
	for (int i = 0; *(text + i) != 0; i++)
	{
		if (*(text + i) >= 'a' && *(text + i) <= 'z') lower++;
		if (*(text + i) >= 'A' && *(text + i) <= 'Z') upper++;
		if (*(text + i) == ' ') space++;
	}
	*uppercase = upper;
	*lowercase = lower;
	*whitespace = space;
	return 1;
}

int main()
{
	const char* t1 = "Ala Ma Kota a kot Ma AlE";
	int up, low, space;

	if (marks_counter(t1, &up, &low, &space)) printf("%d %d %d", up, low, space);
	else printf("Error");
	//_getch();
	return 0;
}