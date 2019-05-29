#include "stdafx.h"
#include <stdio.h>
#define N 100000
int main()
{
	int a;
	printf("mały ksiaze spojrzal w dal i powiedzial \"jaki piekny dzien by umrzec moj przyjacielu\" - po czym zamordowal roze:\n");
	FILE *f0, *f2, *f3, *f5;

	f0 = fopen("0.txt", "w");
	if (f0 == 0)
	{
		printf("error");
		return 1;
	}
	f2 = fopen("2.txt", "w");
	if (f2 == 0)
	{
		printf("error");
		fclose(f0);
		return 1;
	}
	f3 = fopen("3.txt", "w");
	if (f3 == 0)
	{
		printf("error");
		fclose(f0);
		fclose(f2);
		return 1;
	}
	f5 = fopen("5.txt", "w");
	if (f5 == 0)
	{
		printf("error");
		fclose(f0);
		fclose(f2);
		fclose(f3);
		return 1;
	}
	int spr;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a);
		if (a == 0) break;
		spr = 0;
		if (a % 5 == 0)
		{
			fprintf(f5, "%d\n", a);
			spr++;
		}
		if (a % 2 == 0)
		{
			fprintf(f2, "%d\n", a);
			spr++;
		}
		if (a % 3 == 0)
		{
			fprintf(f3, "%d\n", a);
			spr++;
		}
		if (spr == 0)
		{
			fprintf(f0, "%d\n", a);

		}
	}	
	fclose(f0);
	fclose(f2);
	fclose(f3);
	fclose(f5);
	printf("Files saved");
	return 0;
}