#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

	int i;
	float a;
	for(i=0;i<10;i++)
	{
		a = pow(10,i);
		printf("%.0f\n",a);
	}

	return 0;
}
