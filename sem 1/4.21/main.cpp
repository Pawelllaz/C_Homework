#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {

	int a,b,i;
	printf("wpisz liczbe: ");
	scanf("%d", &a);

	printf("wpisz liczbe: ");
	scanf("%d", &b);

	for(i=a;i<=b;i++)
	{
		printf("%d ", i);
	}

	return 0;
}
