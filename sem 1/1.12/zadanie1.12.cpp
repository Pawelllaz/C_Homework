#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

	float q,w,e,r,t,y,u,i,o,p;

	printf("wpisz 10 cyfr\n");

	scanf("%f",&q);
	scanf("%f",&w);
	scanf("%f",&e);
	scanf("%f",&r);
	scanf("%f",&t);
	scanf("%f",&y);
	scanf("%f",&u);
	scanf("%f",&i);
	scanf("%f",&o);
	scanf("%f",&p);
	float avg;

	avg=(q+w+e+r+t+y+u+i+o+p)/10;
	printf("srednia=%.4f", avg);
	return 0;
}

