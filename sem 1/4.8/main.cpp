#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {

	int i,a;
	float q;

	for(i=0;i<=10;i++)
	{
		for(a=0;a<=10;a++)
		{
			q = a*i;
			printf("%d * %d = %.0f\n", i,a,q);
		}
	}

	return 0;
}
