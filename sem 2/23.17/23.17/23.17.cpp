#include "stdafx.h"
#include <stdio.h>
#include <string.h>
//#include <conio.h>

int main()
{
	FILE *f;
	FILE *g;
	char sciezka1[60], sciezka2[70]="copy_", c;
	printf("hokus pokus:\n");
	scanf("%59s", sciezka1);
	int counter = 0;
	for (int i = 0; *(sciezka1 + i) != 0; i++)
	{
		counter++;
	}
	//_getch();
	if (*(sciezka1 + --counter) != 'p')
	{
		printf("Unsupported File Format");
		return 2;
	}
	if (*(sciezka1 + --counter) != 'm')
	{
		printf("Unsupported File Format");
		return 2;
	}
	if (*(sciezka1 + --counter) != 'b')
	{
		printf("Unsupported File Format");
		return 2;
	}
	if (*(sciezka1 + --counter) != '.')
	{
		printf("Unsupported File Format");
		return 2;
	}
	f = fopen(sciezka1, "r");
	if (f == 0) {
		printf("File not found");
		return 1;
	}
	strcat(sciezka2, sciezka1);
	g = fopen(sciezka2, "w");
	if (g == 0)
	{
		printf("Can't create file");
		fclose(f);
		return 1;
	}
	int x = 0;
	do
	{
		x = fscanf(f, "%c", &c);
		if (x != 1) break;
		fprintf(g, "%c", c);
	} while (feof(f) == 0);

	printf("File created");

	fclose(g);
	fclose(f);


	return 0;
}