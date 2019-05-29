#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

	int i;

	for(i=0;i<10;i++)
	{
		printf("10 do potegi %d =  %16.0f\n", i,pow(10,i));
	}
	for(i=10;i<16;i++)
	{
		printf("10 do potegi %d = %16.0f\n", i,pow(10,i));
	}

	return 0;
}
