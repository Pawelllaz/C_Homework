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

    selection_sort(tab,counter,direction);
    return 0;
}
