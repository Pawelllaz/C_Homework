#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {

	int i;
	float a,b,c;

	printf("wpisz liczbe:");
	scanf("%f", &a);

	printf("wpisz liczbe:");
	scanf("%f", &b);

	c=(b-a)/0.25;

	for(i=0;i<=c;i++)
    {
        printf("%.2f ", a);
        a+=0.25;
    }

	return 0;
}
