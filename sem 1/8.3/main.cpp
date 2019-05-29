#include <stdio.h>

int fibonacci(int n)
{
    if(n==0)
    {
        return 1;
    }
    else if(n==1)
    {
        return 2;
    }
    else if(n>1)
    {
        return fibonacci(n-1)+fibonacci(n-2)+n;
    }
    return -1;
}

int main()
{
    int n;
    printf("ktory wyraz ciagu chcesz otrzymac: ");
    scanf("%d", &n);
    if(n<0)
    {
        printf("Error");
        return 1;
    }
    printf("%d", fibonacci(n));
    return 0;
}
