#include "stdafx.h"
#include <stdio.h>
//#include <conio.h>

int main()
{
	FILE *f;

	char sciezka[20];
	
	printf("podaj sciezke do pliku:\n");
	scanf("%19s", sciezka);
	
	f = fopen(sciezka, "r");

	if (f == NULL)
	{
		printf("Error");
		return 1;
	}
	char t;
	int x = 0;
	do
	{
		x=fscanf(f, "%c", &t);
		if (x == 0 || x == EOF) break;
		printf("%c", t);
	} while (feof(f) == 0);  

	fclose(f);
	//_getch();
	return 0;
}