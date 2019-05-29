#include <stdio.h>
#include "vector_utils.h"

//=======================================================
int read_vector(int vec[], int size, int stop_value)
{
	int counter = 0;
	printf("podaj liczby:\n");
	for (counter = 0; counter < size; counter++)
	{
		scanf("%d", &vec[counter]);
		if (vec[counter] == stop_value) break;
	}
	return counter;
}
//==========================================================
void display_vector(int vec[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d ", vec[i]);
	}
	printf("\n");
}
//====================================================
void bubble_sort(int tab[], int size, int dir)
{
    if(dir==1)
    {
        bubble_sort_asc(tab,size);
    }
    else if(dir==2)
    {
        bubble_sort_desc(tab,size);
    }
}
//====================================================
void bubble_sort_desc(int tab[], int size)
{
    int i,j,liczba;
    for(i=0;i<size-1;i++)
    {
        liczba=0;
        for(j=0;j<size-1;j++)
        {
            if(tab[j]<tab[j+1])
            {
                liczba=tab[j];
                tab[j]=tab[j+1];
                tab[j+1]=liczba;
            }
        }
        if(liczba==0) break;
        display_vector(tab,size);
    }
}
//======================================================
void bubble_sort_asc(int tab[], int size)
{
    int i,j,liczba;
    for(i=0;i<size-1;i++)
    {
        liczba=0;
        for(j=0;j<size-1;j++)
        {
            if(tab[j]>tab[j+1])
            {
                liczba=tab[j];
                tab[j]=tab[j+1];
                tab[j+1]=liczba;
            }
        }
        if(liczba==0) break;
        display_vector(tab,size);
    }
}
//=====================================================
