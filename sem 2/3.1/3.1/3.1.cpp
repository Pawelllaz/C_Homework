#include "stdafx.h"
#include <stdio.h>
#include <conio.h>

int main()
{
	FILE *f;
	char t[20];
	printf("wpisz cokolwiek bo tak jezus kaze:\n");
	scanf("%s", t);
	
	f = fopen(t, "w");
	if (f == NULL) printf("Error");

	return 0;
}