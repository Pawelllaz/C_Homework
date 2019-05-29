#include <stdio.h>

int NWD(int a, int b)
{
    if(b==0) return a;

    if(b!=0)
    	return NWD(b,a%b);

    return a;
}

int main()
{
    int a,b;
    printf("podaj a: ");
    scanf("%d", &a);

    printf("podaj b: ");
    scanf("%d", &b);

    printf("%d", NWD(a,b));
    return 0;
}
