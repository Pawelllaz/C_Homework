#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

	double n,a,b=1,c;

	printf("wpisz liczbe aby uzyskac wynik silni:\n");

	c=scanf("%lg",&n);

	if(c!=1)
    {
        printf("blad");
        return 1;
    }
    if(n<=0 || n>=21)
    {
        printf("blad");
        return 1;
    }

	for(a=1;a<=n;a++)
	{
		b*=a;
	}
	printf("%.0f", b);

	return 0;
}
