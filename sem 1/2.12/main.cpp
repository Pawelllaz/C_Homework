#include <stdio.h>
#include <math.h>
#include <stdlib.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {

	double a,b,c,d,x,y,p;

	printf("wprowadz a, b i c:\na:");
	scanf("%lg", &a);
	printf("b:");
	scanf("%lg", &b);
	printf("c:");
	scanf("%lg", &c);

	if (b==1 && c==0 && a==0)
	{
		printf("nieskonczonosc pierwiastkow rownania kwadratowego");
		exit(0);
	}

	d = (b*b)-(4*a*c);
	p = sqrt(d);
	if (d<0)
	{

		printf("brak pierwiastkow rownania kwadratowego");
	}
	else if (d==0)
	{
		printf("jeden pierwiastek rownania kwadratowego ");
		x = (-b)/(2*a);
		printf("%f", x);
	}
	else if (d>0)
	{
		printf("dwa pierwiastki rownania kwadratowego ");
		x = (-b-p)/(2*a);
		y = (-b+p)/(2*a);
		printf("%f ; %f", x,y);
	}

	return 0;
}
