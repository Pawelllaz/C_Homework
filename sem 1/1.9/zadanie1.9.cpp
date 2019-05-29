#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

	float a;
	float b;
	printf("KALKULATOR\nwpisz pierwsza liczbe");
	scanf("%f",&a);
	printf("wpisz druga liczbe");
	scanf("%f",&b);

	float suma=a+b;
	float roznica=a-b;
	float iloczyn=a*b;
	float iloraz=a/b;

	printf("suma: %f\n", suma);
	printf("roznica: %f\n", roznica);
	printf("iloczyn: %f\n", iloczyn);
	printf("iloraz: %f", iloraz);
	return 0;
}
