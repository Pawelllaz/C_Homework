#include "stdafx.h"
#include <stdio.h>
#include <Windows.h>

int main()
{
	FILE *f;
	f = fopen("a.bmp", "wb");
	if (f == NULL)
	{
		printf("nie otworzyl");
		return 1;
	}
	
	int tab[10];
	for (int i = 0; i < 10; i++) *(tab + i) = i;
	int tab2[10], write, read;;
	write = fwrite(tab, sizeof(int), 10, f);
	fclose(f);
	f = fopen("a.bmp", "rb");
	if (f == NULL)
	{
		printf("nie otworzyl");
		return 1;
	}

	read = fread(tab2, sizeof(int), 10, f);
	for (int i = 0; i < 10; i++) printf("%d\n", *(tab2 + i));
	printf("write = %d\nread = %d", write, read);
	fclose(f);
	system("PAUSE");
	return 0;
}