#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

	int a;
	int b;

	printf("wpisz liczbe do kalkulatora:");

	scanf("%d", &a);
	printf("wpisz druga liczbe");
	scanf("%d", &b);


	int suma = a+b;
	int roznica = a-b;
	int iloczyn = a*b;
	float iloraz = a/b;

	printf("suma: %d\n", suma);
	printf("roznica: %d\n", roznica);
	printf("iloczyn: %d\n", iloczyn);
	printf("iloraz: %.0f\n", iloraz);




	return 0;
}
