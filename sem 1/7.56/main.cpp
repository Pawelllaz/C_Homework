#include <stdio.h>
#define N 150
void swap_vector(int first[], int size, int second[], int size2)
{
    int i, liczba,maxi;
    if(size>size2)
    {
        maxi=size;
    }
    else
    {
        maxi=size2;
    }

    for(i=0;i<maxi;i++)
    {
        liczba=second[i];
        second[i]=first[i];
        first[i]=liczba;
    }
}

int main()
{
    int tab1[N], tab2[N], i,counter1=0,counter2=0;

    printf("podaj pierwszy wektor: ");
    for(i=0;i<N;i++)
    {
        scanf("%d", &tab1[i]);
        if(tab1[i]==0) break;
        counter1++;
    }

    printf("podaj drugi wektor: ");
    for(i=0;i<N;i++)
    {
        scanf("%d", &tab2[i]);
        if(tab2[i]==0) break;
        counter2++;
    }

    swap_vector(tab1, counter1, tab2, counter2);

    for(i=0;i<counter2;i++)
    {
        printf("%d ", tab1[i]);
    }
    printf("\n");

    for(i=0;i<counter1;i++)
    {
        printf("%d ", tab2[i]);
    }

    return 0;
}
