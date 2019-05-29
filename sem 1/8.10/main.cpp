#include <stdio.h>
#include <stdlib.h>

int sum_of_digits(int n)
{
    if(n<10)
        return n;
    else
        return n%10+sum_of_digits(n/10);
}
//-------------------------
int main()
{
    int n;
    printf("wpisz liczbe:\n");

    scanf("%d", &n);

    int w=sum_of_digits(n);

    printf("%d", w);

    return 0;
}
