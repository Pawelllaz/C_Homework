#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

	int a;
	printf("wpisz liczbe odpowiadajajcej dniu tygodnia od 1 do 7\n");
	scanf("%d", &a);\
	switch (a)
	{
		case 1:
			printf("poniedzialek");
			break;

				case 2:
			printf("wtorek");
			break;

				case 3:
			printf("sroda");
			break;

				case 4:
			printf("czwartek");
			break;

				case 5:
			printf("piatek");
			break;

				case 6:
			printf("sobota");
			break;

				case 7:
			printf("niedziela");
			break;

			default: printf("Error");
			break;

	}

	return 0;
}
