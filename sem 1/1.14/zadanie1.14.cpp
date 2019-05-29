#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	float a;
	float b;

	printf("wprowac liczbe x:");

	scanf("%f", &a);

	b = 2*(a*a*a)-4*(a*a)+3*a-7;
	printf("%.2f", b);

	return 0;
}
