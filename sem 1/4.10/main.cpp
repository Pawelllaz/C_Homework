#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

	int i;
	float a[10],suma=0;

	for(i=0;i<10;i++)
	{
        printf("wpisz liczbe: \n");
		scanf("%f", &a[i]);

	}
	for(i=0;i<10;i++)
	{
		suma += a[i];

	}
	printf("suma wynosi: %.2f", suma);
	return 0;
}
