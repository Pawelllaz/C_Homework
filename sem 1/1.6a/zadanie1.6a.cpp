#include <stdio.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	int a = 470;
	int b = 74;
	float q,w;
	int x = a*b;
	int suma = a+b;
	int roznica = a-b;
	q=a;
	w=b;
	float iloraz = q/w;
	
	printf("%d %d", a,b);
	printf("\niloczyn: %d", x);
	printf("iloraz: %.2f", iloraz);
	printf("\nsuma: %d\n", suma);
	printf("roznica: %d\n", roznica);
	
	
	return 0;
}
