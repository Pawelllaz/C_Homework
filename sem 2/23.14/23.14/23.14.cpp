#include "stdafx.h"
#include <stdio.h>
//#include <Windows.h>

int main()
{
	FILE *f;
	char tekst[20];
	printf("#pusty_tekst\n");
	fgets(tekst, 19, stdin);
	for (int i=0;;i++)
	{
		if (*(tekst + i) == '\n')
		{
			*(tekst + i) = 0;
			break;
		}
	}
	
	f = fopen(tekst, "a");
	if (f == 0)
	{
		printf("error");
		//system("PAUSE");
		return 1;
	}
	//int counter = 0;
	char a,b;
	printf("zadanie skradzione\n");
	for (;;)
	{
		scanf("%c", &a);
		//printf("odczytany znak - %d\n", a);
		if (a == '\n')
		{
			scanf("%c", &b);
			if (b == '\n') break;
			else
			{
				fprintf(f, "%c", a);
				fprintf(f, "%c", b);
			}
		}
		else fprintf(f, "%c", a);
	}
	
	printf("File saved");
	fclose(f);
	//system("PAUSE");
	return 0;
}