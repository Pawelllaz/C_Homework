#include "stdafx.h"
#include <stdio.h>

int main()
{
	FILE *f;
	char sciezka[20];
	printf("czerwony kapturek:\n");
	scanf("%19s", sciezka);

	f = fopen(sciezka, "w");
	if (f == 0) {
		printf("error");
		return 1;
	}
	for (int i = 0; i <= 100; i++)
	{
		fprintf(f, "%d\n", i);
	}
	fclose(f);
	printf("File saved");
	return 0;
}