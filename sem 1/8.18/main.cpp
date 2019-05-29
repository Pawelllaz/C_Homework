#include <stdio.h>


//==================================================
int is_prime_rec(int n, int d)
{
	if(d*d>n) return 1;
	if(n%d==0)
    {
        return 0;
    }
    else
    {
        return is_prime_rec(n,d+1);
    }
}
//==========================================================
int is_superprime_rec(int number)
{
    //printf("%d\n", is_prime_rec(number,2));
    if(number/10==0) return 1;
    if(is_prime_rec(number,2)==0) return 0;
    return is_superprime_rec(number/10);
}
//==================================================
int main()
{
    int a;
    printf("podaj liczbe:");
    scanf("%d", &a);
    if(a<0)
    {
        printf("NIE");
        return 0;
    }
    if(is_superprime_rec(a)) printf("TAK");
    else printf("NIE");

    return 0;
}
