#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

	float a, b, x, y;

	printf("wprowadz wartosc a:");
	scanf("%f", &a);
	printf("wprowadz wartosc b:");
	scanf("%f", &b);

	x=(a+b)*(a-b);
	y=(a*a)+(b*b);

	if(y==x)
	{ printf("Tozsamosc jest nieprawdziwa");
	}
	else
	{ printf("Tozsamosc jest prawdziwa");
	}

	return 0;
}
