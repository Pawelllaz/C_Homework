#include <stdio.h>

int main() {

	float a = 47;
	float b = 74;

	float x = a*b;
	float suma = a+b;
	float roznica = a-b;
	float iloraz = a/b;

	printf("%.0f %.0f\n", a,b);
	printf("niloczyn: %f\n", x);
	printf("iloraz: %.2f\n", iloraz);
	printf("suma: %f\n", suma);
	printf("roznica: %f", roznica);


	return 0;
}
