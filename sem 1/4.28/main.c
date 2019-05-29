#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {

	int i;
	int s=0;
	srand (time(0));

	for(i=0;i<100;i++)
	{
		int a=rand()%11 +10;
		s+=a;
	}

	printf("%d", s);
	return 0;
}
