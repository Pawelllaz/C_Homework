#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

	int a;

	printf("podaj ocene z zakresu 1-6\n");
	scanf("%d", &a);

			switch (a)
			{
				case 1:
					printf("brak promocji do nastepnej klasy\n");
					break;
				case 2:
				case 3:
				case 4:
				case 5:
					printf("promocja do nastepnej klasy\n");
					break;
				case 6:
					printf("promocja
            z ocena celujaca\n");
					break;
					default: printf("wprowadzona ocena jest niepoprawna");
					break;
			}





	return 0;
}
