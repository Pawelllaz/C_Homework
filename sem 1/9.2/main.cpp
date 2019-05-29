#include <stdio.h>
#include <stdlib.h>
#include "vector_utils.h"

int main()
{
    const int amount=150;
    printf("wpisz liczby:\n");
    int counter=0,tab[amount],direction;
    counter=read_vector(tab,amount,0);

    printf("podaj kierunek sortowania: ");
    scanf("%d", &direction);
    if(direction!=1 && direction!=2)
    {
        printf("Error");
        return 0;
    }

    bubble_sort(tab,counter,direction);
    display_vector(tab,counter);
    return 0;
}
