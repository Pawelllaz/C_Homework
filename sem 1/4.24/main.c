#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {
	
	srand (time(0));
	int a=rand(); 
	printf("%d",a);
	
	return 0;
}
