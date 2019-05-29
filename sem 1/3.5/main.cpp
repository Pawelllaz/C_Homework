#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {

	printf("wpisz liczbe odpowiadajaca kolejnemu dniu tygodnia");
	int a;
	scanf("%d", &a);

		switch (a)
		{
			case 1:
				printf("dzien roboczy");
				break;
				case 2:
				printf("dzien roboczy");
				break;
				case 3:
				printf("dzien roboczy");
				break;
				case 4:
				printf("dzien roboczy");
				break;
				case 5:
				printf("dzien roboczy");
				break;
			case 6:
				printf("weekend");
				break;
				case 7:
				printf("weekend");
				break;
			default: printf("Error");
		}

	return 0;
}
