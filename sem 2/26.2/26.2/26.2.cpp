#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
//#include <Windows.h>

int main()
{
	double *PI = (double*)malloc(sizeof(double));
	if (PI == NULL)
	{
		printf("Error");
		return 1;
	}
	*PI = 3.14159265359;
	printf("%g %p", *PI,(void*)PI);

	free(PI);
	//system("PAUSE");
	return 0;
}