#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

	printf("wpisz liczbe aby wyswietlic slowna informacje:");

	int a;
	scanf("%d", &a);

	switch (a)
	{
            case 0:
            printf("zero");
            break;

            case 1:
			printf("jeden");
			break;

			case 2:
			printf("dwa");
			break;

			case 3:
			printf("trzy");
			break;

			case 4:
			printf("cztery");
			break;

			case 5:
			printf("piec");
			break;

			case 6:
			printf("szesc");
			break;

			case 7:
			printf("siedem");
			break;

			case 8:
			printf("osiem");
			break;

			case 9:
			printf("dziewiec");
			break;

			case 10:
			printf("dziesiec");
			break;

			default: printf("Blad");
				break;
	}

	return 0;
}
