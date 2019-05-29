#include <stdio.h>
#include <stdlib.h>

int main()
{
	int l1, l2;
    char o;

	printf("podaj pierwsza liczbe: ");
	scanf("%d", &l1);

	printf("wpisz druga liczbe: ");
	scanf("%d", &l2);

	rewind(stdin);
	printf("podaj symbol opracji: ");
    scanf("%c", &o);

    switch (o)
	{
	case '+':
		printf("%d", l1 + l2);
		break;
	case '-':
		printf("%d", l1 - l2);
		break;
	case '*':
		printf("%d", l1*l2);
		break;
	case '/':
		if (l2 != 0)
		{
			printf("%d", l1 / l2);
		}
		else
			printf("Error");
		break;
	}
	return 0;
}
