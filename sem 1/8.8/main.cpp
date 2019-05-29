#include <stdio.h>

int func_rec(int s, int n)
{
	if(n==0) return s;

	if(func_rec(s, n-1)%2==0)
    {
        return func_rec(s,n-1)/2;
    }
	else
    {
        return 3*func_rec(s,n-1)+1;
    }
}

int main()
{
    int s,n;
    printf("podaj wartosc pierwszego wyrazu: ");
    scanf("%d", &s);

    printf("podaj numer wyrazu ktory hcesz wyznaczyc: ");
    scanf("%d", &n);
    if(n<0)
    {
        printf("Error");
        return 1;
    }

    printf("%d", func_rec(s,n));
    return 0;
}
