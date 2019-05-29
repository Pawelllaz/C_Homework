#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

	float tab[]={10,11,4,5,6,12,16,1,2,3,13,14,15,7,8,9};
	int i;

	for(i=0;i<=15;i++)
	{
		printf("%.0f\n", tab[i]);
		i++;
	}

	return 0;
}
