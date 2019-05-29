#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

	int a;
	int x;
	printf("wpisz liczbe:\n");

	scanf("%d", &a);
	printf("liczba podana: %d\n", a);

	x=a*10;

	printf("dziesieciokrotnosc wynosi: %d", x);

	return 0;
}
