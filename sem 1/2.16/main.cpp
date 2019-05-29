#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

	int a;
	printf("wprowadz liczbe");
	scanf("%d", &a);

	if(a>0)
	{printf("liczba jest dodatnia");
	}
	if(a==0)
	{printf("liczba jest zerowa");
	}
	if(a<0)
	{printf("liczba jest ujemna");
	}
	return 0;
}
