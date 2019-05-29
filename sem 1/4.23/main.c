#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {
	
	int i;
	
	for(i=0;i<=100;i++)
	{
		if(i>=10 && i <15)
		{
			printf("*%d\n", i);
		}
		else if(i>=40 && i <=60)
		{
			printf("*%d\n", i);
		}
		else if(i>70 && i <80)
		{
			printf("*%d\n", i);
		}
		else 
		{
			printf("%d\n", i);
		}
	}
	
	return 0;
}
