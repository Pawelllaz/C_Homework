#include <stdio.h>

int sum_rec(int n)
{
    int i,liczba=0;
    for(i=1;i<=n;i++)
    {
        liczba+=i;
    }
    return liczba;
}

int main()
{
    int n;
    printf("podaj liczbe dla ktorej chcesz policzyc sume: ");
    scanf("%d", &n);
    if(n<0)
    {
        printf("Error");
        return 1;
    }
    printf("%d", sum_rec(n));

    return 0;
}
