#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "vector_utils.h"

int main()
{
    const int N=150;
    int metoda,size,direction,tab[N];

    printf("wcztaj tablice:\n");
    size=read_vector(tab,N,0);

    printf("wybierz kierunek: ");
    scanf("%d", &direction);
    if(direction!=1 && direction!=2)
    {
        printf("Error");
        return 0;
    }

    printf("wybierz metode: ");
    scanf("%d", &metoda);
    if(metoda==1)
    {
        bubble_sort(tab,size,direction);
    }
    else if(metoda==2)
    {
        selection_sort(tab,size,direction);
    }
    else if(metoda==3)
    {
        insertion_sort(tab,size,direction);
    }
    else
    {
        printf("Error");
        return 0;
    }
    display_vector(tab,size);
    return 0;
}
