#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {
	/*
	Wykorzystuj�c dwie p�tle, napisz program do automatycznego sprawdzania to�samo�ci
	(a+b)(a-b)=a2-b2(a+b)(a-b)=a2-b2
Przyjmij zakres parametr�w a oraz b: -10 .. 10. Wy�wietl na ekranie list� par a i b, dla kt�rych podana to�samo�� jest spe�niona.
	*/

	int a,b;
	float l,p;

	for(a=-10;a<=10;a++)
	{
		for(b=-10;b<=10;b++)
		{
			l = (a+b)*(a-b);
			p = a*a - b*b;
			if(p==l)
			{
				printf("%d %d\n", a,b);
			}
		}
	}

	return 0;
}
