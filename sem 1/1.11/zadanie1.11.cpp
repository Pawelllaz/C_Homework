#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

	float a,b,c,x;
	printf("wprowadz liczby a:\n ");
	scanf("%f",&a);
	printf("wprowadz liczby b:\n ");
	scanf("%f",&b);
	printf("wprowadz liczby c:\n ");
	scanf("%f",&c);

	x=sqrt(pow(a,2)+pow(b,2)+pow(c,2));

	printf("%.2f\n", x);

	return 0;
}
