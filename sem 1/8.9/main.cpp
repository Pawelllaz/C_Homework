#include <stdio.h>

long long exp_by_squaring(long long x, unsigned int n)
{
    if(n==0) return 1;

    if(n%2==1) return x*exp_by_squaring(x,n-1);

    long long d=exp_by_squaring(x,n/2);
    return d*d;
}

int main()
{
    unsigned int n;
	long long x;

	printf("podaj podstawe: ");
	scanf("%lld", &x);

	printf("podaj wykladnik: ");
	scanf("%u", &n);

	printf("wynik: %lld", exp_by_squaring(x,n));
    return 0;
}
