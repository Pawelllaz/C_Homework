#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {
	/*
	Wykorzystuj¹c dwie pêtle, napisz program do automatycznego sprawdzania to¿samoœci
	(a+b)(a-b)=a2-b2(a+b)(a-b)=a2-b2
Przyjmij zakres parametrów a oraz b: -10 .. 10. Wyœwietl na ekranie listê par a i b, dla których podana to¿samoœæ jest spe³niona.
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
