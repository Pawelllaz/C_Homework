#include "stdafx.h"
#include <stdio.h>
//#include <conio.h>

int main()
{
	FILE *f;
	FILE *g;
	char sciezka1[30], sciezka2[30], c;
	printf("hokus pokus:\n");
	scanf("%29s", sciezka1);
	f = fopen(sciezka1, "r");
	if (f == 0) {
		printf("error");
		return 1;
	}
	printf("czary mary:\n");
	scanf("%29s", sciezka2);
	g = fopen(sciezka2, "w");
	if (g == 0)
	{
		printf("error");
		fclose(f);
		return 1;
	}
	int x=0,i=0;
	char tab[10000];
	do
	{
		x = fscanf(f, "%c", &c);
		if (x != 1) break;
		tab[i++] = c;
	} while (feof(f) == 0);
	for (int j = i - 1; j >= 0; j--)
	{
		fprintf(g, "%c", tab[j]);
	}
	printf("file copied");

	fclose(g);
	fclose(f);


	return 0;
}