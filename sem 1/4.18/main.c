#include <stdio.h>
#include <stdlib.h>
#define N 10
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {

	double l[N],s=0;
	int i;
	printf("wpisz 10 liczb:\n");
	for(i=0;i<N;i++)
	{
		scanf("%lg", &l[i]);
		if(l[i]<0)
		{
			s -= l[i];
		}

		else
		{
			s+=l[i];
		}
	}

	printf("\n%.2f", s);

	return 0;
}
