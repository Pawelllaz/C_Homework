#include "stdafx.h"
#include <stdio.h>
//#include <conio.h>

int main()
{
	const char* t1 = "Ala Ma Kota a kot Ma AlE";

	for (int i = 0; *(t1 + i) != 0; i++)
	{
		putchar(*(t1 + i));
	}
	//_getch();
	return 0;
}