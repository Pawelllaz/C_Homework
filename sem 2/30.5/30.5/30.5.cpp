#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

void show(const void* ptr, size_t count);
void inverse_bits(void* ptr, size_t offset, size_t count);

void zamiana(int n)
{
	if (n>0)
	{
		zamiana(n / 16); //dzieki rekurencjji liczby sa wyswietlane w poprawnej kolejnosci
		if (n % 16 > 9)
		{	//dla systemów o podstawie większej niż 9 cyfry są literami
			switch (n % 16)
			{
			case 10:
				printf("A");
				break;
			case 11:
				printf("B");
				break;
			case 12:
				printf("C");
				break;
			case 13:
				printf("D");
				break;
			case 14:
				printf("E");
				break;
			case 15:
				printf("F");
				break;
			}
		}
		else
		{
			printf("%d", n % 16);
			//cout << n % p;
		}
	}
}
int main()
{
	int n;
	printf("Podaj dowolna liczbe dziesietna: ");
	scanf("%d", &n);
	zamiana(n); // wywolanie funkcji
	system("pause");
	return 0;
}