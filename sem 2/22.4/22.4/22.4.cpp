#include "stdafx.h"
#include <stdio.h>
//#include <conio.h>

int main()
{
	const char* t1 = "Ala Ma Kota a kot Ma AlE";
	int counter = 0;
	
	for (int i = 0; *(t1 + i+1) != 0; i++)
	{
		counter++;
	}

	for (int i = counter; i >= 0; i--)
	{
		printf("%c", *(t1 + i));
	}
	//_getch();
	return 0;
}