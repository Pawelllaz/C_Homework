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
void selection_sort_asc(int tab[], int size)
{
    int i,liczba,k;
	for(i=0;i<size;i++)
	{
		k=find_min(tab,size,i);
		if(tab[i]>tab[k])
		{
		    liczba=tab[k];
			tab[k]=tab[i];
			tab[i]=liczba;
		}
		display_vector(tab,size);
	}
}
//=======================================================
void selection_sort_desc(int tab[], int size)
{
    int i,liczba,k;
	for(i=0;i<size;i++)
	{
		k=find_max(tab,size,i);
		if(tab[i]<tab[k])
		{
		    liczba=tab[k];
			tab[k]=tab[i];
			tab[i]=liczba;
		}
		display_vector(tab,size);
	}
}
//=========================================================
void selection_sort(int tab[], int size, int dir)
{
    if(dir==1) selection_sort_asc(tab,size);
    else if(dir==2) selection_sort_desc(tab,size);
    else printf("Error");
}
//=======================================================
void insertion_sort(int tab[], int size, int dir)
{
    if(dir==1) insertion_sort_asc(tab,size);
    else if(dir==2) insertion_sort_desc(tab,size);
    else printf("Error");
}
//========================================================
void insertion_sort_asc(int tab[], int size)
{
    int i,liczba,j;
    for(i=1;i<size;i++)
    {
        liczba=tab[i];
        for(j=i-1;j>=0;j--)
        {
            if(liczba<tab[j]) tab[j+1]=tab[j];
            else break;
        }
        tab[j+1]=liczba;
        display_vector(tab,size);
    }
}
//=======================================================
void insertion_sort_desc(int tab[], int size)
{
    int i,liczba,j;
    for(i=1;i<size;i++)
    {
        liczba=tab[i];
        for(j=i-1;j>=0;j--)
        {
            if(liczba>tab[j]) tab[j+1]=tab[j];
            else break;
        }
        tab[j+1]=liczba;
        display_vector(tab,size);
    }
}

//========================================================
int find_max(int tab[], int size, int start_index)
{
    int max=tab[start_index],i,index=start_index;
    for(i=start_index;i<size;i++)
    {
        if(max<tab[i])
        {
            max=tab[i];
            index=i;
        }
    }
    return index;
}
//==================================================
int find_min(int tab[], int size, int start_index)
{
    int min=tab[start_index],i,index=start_index;

    for(i=start_index;i<size;i++)
    {
        if(tab[i]<min)
        {
            min=tab[i];
            index=i;
        }
    }
    return index;
}
//============================================================

