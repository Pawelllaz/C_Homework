#include "stdafx.h"
#include <stdio.h>
//#include <Windows.h>

int read_file(const char *filename)
{
	if (filename == NULL) return 0;
	FILE *f;
	int counter = 0, more = 0, spr=0;
	f = fopen(filename, "r");
	if (f == NULL)
	{
		//printf("error");
		return 0;
	}
	char file_names[30];
	while (feof(f) == 0)
	{
		spr = fscanf(f, "%29s", file_names);
		if (spr == EOF) break;
		printf("%s\n", file_names);
		more = read_file(file_names);
		counter = counter + more;
		/*g = fopen(file_names, "r");
		if (g==NULL)
		{
		//counter++;
		//return read_file(file_names);
		return 0;
		}*/

	}
	++counter;
	fclose(f);
	return counter;
}

int main()
{
	FILE *f;
	char file_name[30];
	printf("Ruda wiewiorka - taka historia:\n");
	scanf("%29s", file_name);
	f = fopen(file_name, "r");
	if (f == 0)
	{
		printf("error");
		return 1;
	}
	/*if (read_file(file_name) == 0)
	{
	printf("error");
	}
	else*/
	printf("%d", read_file(file_name));
	fclose(f);
	//system("PAUSE");
	return 0;
}