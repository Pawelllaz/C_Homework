#include "stdafx.h"
#include <stdio.h>

int main()
{
	FILE *f;

	char sciezka[20];

	printf("podaj sciezke do pliku:\n");
	scanf("%19s", sciezka);

	f = fopen(sciezka, "r");

	if (f == NULL)
	{
		f = fopen(sciezka, "w");
		if (f == NULL)
		{
			printf("error");
			return 1;
		}
		else
		{
			printf("File created");
		}
	}
	else
	{
		printf("File already exists!");
	}
	fclose(f);
	return 0;
}