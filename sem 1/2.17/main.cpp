#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

	float y;
	float x;
	printf("podaj wartosc x:");
	scanf("%f",&x);

	if(x<-5)
	{ y=(x+5)*(x+5)-10;
	printf("%f", y);
	}
	else if (x>=-5&& x<=5)
	{ y=2*(x*x)+3*x-1;
	printf("%f ", y);
	}
	else
	{
        float a=((x/2)-2);
        float b=(2-(3*x)/4);
        printf("%f", a*b);
	}

	return 0;
}
