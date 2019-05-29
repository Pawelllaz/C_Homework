#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {
	
	int i;
	srand (time(0));
	for(i=0;i<2001;i++)
	{
		int a=rand()%2001 -1000; 
		printf("%d\n",a);
		if(a>=100 && a<=200)
		{
			break;
		}
	}
	return 0;
}
