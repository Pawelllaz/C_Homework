#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
int main() {
	char czy_chce[5];
	while (1)
	{
		printf("chcesz zagrac w gre (tak/nie)");

		scanf("%4s", czy_chce);
		if (czy_chce == "tak")
		{
			int i, b;
			srand(time(0));
			int a = rand() % 1001;
			printf("\tGRA W ZGADYWANIE\nzgadnij liczbe z przedzialu od 0 do 1000 w 20 probach, powodzenia\n");

			for (i = 0; i < 20; i++)
			{
				scanf("%d", &b);
				if (b < a)
				{
					printf("za malo\n");
				}
				else if (b > a)
				{
					printf("za duzo\n");
				}
				else if (a == b)
				{
					printf("\nwygrales");
					break;
				}
				if (i == 19)
				{
					printf("\nprzegrales");
					break;
				}
			}
		}
		if (czy_chce == "nie")
		{
			printf("\nzegnaj");
			_getchar();
			return 1;
		}
		else
		{
			printf("blad");
			_getchar();
			return 2;
		}
	}
	return 0;
}
