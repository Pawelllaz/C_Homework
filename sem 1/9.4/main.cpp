#include <stdio.h>
#include <stdlib.h>
#include "vector_utils.h"

int main()
{
    const int N = 150;
    int size,direction,tab[N];


    printf("wpisz liczby:\n");
    size=read_vector(tab,N,0);

    printf("wybierz kierunek: ");
    scanf("%d", &direction);
    if(direction!=1 && direction!=2)
    {
        printf("Error");
        return 0;
    }
    insertion_sort(tab,size,direction);

    display_vector(tab,size);
    return 0;
}
