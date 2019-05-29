#include <stdio.h>
long power_rec(int a, int n)
{
    if(n==0) return 1;
    return a*(power_rec(a,n-1));
}
//=====================================================================
int is_divisible_by_7(int number)
{
    if(number%7==0) return 1;
    return 0;
}
//===================================================================
int sum_of_digit_multiplied_by_power_of_3(int number, int exponent)
{
    if((number/10)==0) return (number%10)*power_rec(3,exponent);
    else return number%10*(power_rec(3,exponent))+sum_of_digit_multiplied_by_power_of_3(number/10,exponent+1);
}
//====================================================================
int main()
{
    int a,s;

    printf("wpisz liczbe: ");
    scanf("%d",&a);

    s=sum_of_digit_multiplied_by_power_of_3(a,0);

    if(is_divisible_by_7(s)==1) printf("TAK");
    else printf("NIE");

    return 0;
}
