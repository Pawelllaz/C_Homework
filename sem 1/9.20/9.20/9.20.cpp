#include "stdafx.h"
#include <stdio.h>
#include "vector_utils.h"
//#include <conio.h>

int dlugosc(int n)
{
	int i, suma = 0;

	if (n < 0)
	{
		n *= -1;
		//counter++;
	}

	for (i = 0; i < 150; i++)
	{
		if (n < 1) break;
		suma += n % 10; 
		//printf("%d  cou= %d\n",n%10, suma);
		n /= 10;
		//counter++;
	}

	return suma;
}
//==================================================
void sort(int tab[],int size)
{
	int i, j, liczba;
	
	for (i = 0; i < size-1; i++)
	{
		liczba = 0;
		for (j = 0; j < size-1; j++)
		{
			if (dlugosc(tab[j]) > dlugosc(tab[j+1]))
			{
				liczba = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = liczba;
			}
		}
		if (liczba == 0) break;
	}
}
//====================================================
int main()
{
	const int N = 150;
	int size=0,tab[N];
	
	size = read_vector(tab, N, 0);
	sort(tab, size);
	display_vector(tab, size);
	
	//_getch();
	return 0;
}