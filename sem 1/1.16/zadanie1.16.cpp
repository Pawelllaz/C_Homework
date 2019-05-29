#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

	float a;
	printf("PRZELICZNIK TEMPERTURY\npodaj wartosc w C:");
	scanf("%f", &a);

	float k;
	k = a+273.149994;
	float f;
	f = 9*a/5+32;
	printf("K: %f\nF: %f\n", k, f);

	return 0;
}
