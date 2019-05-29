#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

    double q,w,e,r,t;

	printf("wpisz 5 cyfr");

	scanf("%lg",&q);
	scanf("%lg",&w);
	scanf("%lg",&e);
	scanf("%lg",&r);
	scanf("%lg",&t);

	double avg;
	avg = (q+w+e+r+t)/5;
	printf("wynik: %.4lf", avg);


	return 0;
}
