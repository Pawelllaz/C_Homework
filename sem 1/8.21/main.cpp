#include <stdio.h>

unsigned int digits_in_number(unsigned long long number, unsigned int digit)
{
    if(number>0)
	{
		if(number%10==digit) return 1+digits_in_number(number/10,digit);
		else return 0+digits_in_number(number/10,digit);
	}
	return 0;
}
//==========================================================================
int main()
{
    unsigned int d;
    unsigned long long n;

    printf("podaj liczbe: ");
    scanf("%llu", &n);
    printf("podaj cyfre: ");
    scanf("%u", &d);

    printf("%u", digits_in_number(n,d));
    return 0;
}
