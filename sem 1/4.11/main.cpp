#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {

	float r,o,p;
	do
	{
	printf("wpisz promien kola aby orzymac jego obwod i powierzchnie:\n");
	scanf("%f", &r);
	if(r<=0)
	{
		printf("blad\n");
	}
	} while(r<=0);

	o = 2*PI*r;
	p = PI*r*r;

	printf("%.2f\n%.2f", o,p);

	return 0;
}
