#include "stdafx.h"
#include <stdio.h>
//#include <conio.h>

int main()
{
	long long int a;
	printf("podaj liczbe: ");
	scanf("%lli", &a);
	//printf("%lli", a);
	for (int i = (sizeof(long long int) * 8); i >=0 ; i--)
	{
		if (i % 8== 0 && i!=0) printf(" ");
		printf("%lli",a >> i & 1);
	}

	//_getch();
	return 0;
}