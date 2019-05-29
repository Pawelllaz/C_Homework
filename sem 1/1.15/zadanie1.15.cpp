#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

	float c,a, b;
	a=3;
	b=4;
	c=sqrt(pow(a,2)+pow(b,2));
	double x,y;
	x=a/c;
	y=b/c;
	double d,e,f;
	e=sin(x);
	d= sin(y);
	f=(180-(d+e));

	printf("katy wynsza: %.2g\n %.2g\n %.2g\n", d,e,f);
	printf("przeciwprostokatna: %.1f", c);

	return 0;
}
