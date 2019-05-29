#include <stdio.h>
#include <stdlib.h>
#define N 40
/* Napisz program, który policzy elementy tablicy zadeklarowanej przez programistê. Zaproponuj sposób oznaczenia koñca tablicy. */

int main(void) {
	
	int tab[N],i,s;
	s=0;
	for(i=0;i<=N;i++)
	{
		s++;
	}
	
	printf("%d", s);
	
	return 0;
}
