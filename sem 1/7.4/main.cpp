#include <stdio.h>
#include <stdlib.h>

void znak(int wart)
{
    if(wart>0) printf("dodatnia");
    if(wart==0) printf("zero");
    if(wart<0) printf("ujemna");
}

int main()
{
    int liczba;

    printf("podaj liczbe: ");
    scanf("%d", &liczba);

    znak(liczba);


    return 0;
}
