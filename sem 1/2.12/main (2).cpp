#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

	float t,a,b,c;
	printf("Wpisz wspolczynniki a, b, c rownania kwadratowego y=ax^2+bx+c\na: ");
	scanf("%f", &a);
	printf("b: ");
	scanf("%f", &b);
	printf("c:");
	scanf("%f", &c);

	t=b*b-(4*a*c);

	float p1,p2;

	if (t<0)
	{printf("brak\n");
	}
	if (t==0)
	{
	    p1=(-b)/(2*a);
	    printf("jeden pierwiastek %f\n", p1);
	}
	if(t>0)
    {
        p1=(-b)-(sqrt(t)/(2*a);
        p2=-b+sqrt(t)/(2*a);
        printf("dwa pierwiastki %f i %f", p1, p2);
	}

	return 0;
}
