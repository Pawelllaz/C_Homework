#include "stdafx.h"
#include <stdio.h>
//#include <conio.h>

int main()
{
	int tab[] = { 67305985, 134678021, 202050057 };
	char *ptrc;
	ptrc = (char*)tab;
	/*for (int i = 0; i < sizeof(tab); i++)
	{
		printf("%d\n", *(tab + i));
	}*/
	for (int i = 0; i < 12; i++)
	{
		printf("%d ", *(ptrc + i));
	}
	//_getch();
	return 0;
}