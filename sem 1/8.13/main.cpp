#include <stdio.h>
#include <stdlib.h>

int sum_of_digits(int nu)
{
    if(nu<10)
        return nu;
    else
        return nu%10+sum_of_digits(nu/10);
}
//-------------------------
int is_divisible_by_3(int w)
{
    if(w%3==0)
        return 1;
    else
        return 2;
}
int main()
{
    int nu;
    printf("wpisz liczbe:\n");

    scanf("%d", &nu);

    int w=sum_of_digits(nu);

    int p3=is_divisible_by_3(w);

    if(p3==1)
        printf("TAK");
    else
        printf("NIE");

    return 0;
}
