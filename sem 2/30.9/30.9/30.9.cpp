#include "stdafx.h"
#include <stdio.h>
#include <stdint.h>
//#include <conio.h>

int is_sparse(uint64_t value);

int main()
{
	//long long int a;
	uint64_t a;
	printf("podaj liczbe: ");
	scanf("%zu", &a);
	printf("Liczba: %016zx", a);
	printf(", Wynik: %d", is_sparse(a));
	//_getch();
	return 0;
}


int is_sparse(uint64_t value)
{
	int rep = 0;
	for (int i = (sizeof(long long int) * 8) - 1; i >= 0; i--)
	{
		if (value >> i & 1) rep++;
		else rep = 0;
		if (rep == 2) return 0;
	}
	return 1;
}