#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "insertion_sort.h"
#include "vector_utils.h"
//#include <conio.h>

int main()
{
	const int N = 150;
	int size, direction, tab[N],metoda;

	size = read_vector(tab, N, 0);

	printf("wybierz kierunek: ");
	scanf("%d", &direction);
	if (direction != 1 && direction != 2)
	{
		printf("Error");
		return 0;
	}
	printf("wprowadz metode: ");
	scanf("%d", &metoda);
	if (metoda == 1) insertion_sort(tab, size, direction);
	else if(metoda==2) insertion_sort_rec(tab, size, direction);
	else
	{
		printf("Error");
		return 0;
	}
	display_vector(tab, size);

	//_getch();

	return 0;
}
