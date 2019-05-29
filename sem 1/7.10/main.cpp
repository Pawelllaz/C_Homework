#include <stdio.h>

int fun(int a, int b, int c)
{
	if (a == b && b == c) return 1;
	return 0;
}
int main()
{
	printf("podaj trzy liczby: ");
	int a, b, c,czy;

	scanf("%d %d %d", &a, &b, &c);

	czy = fun(a, b, c);
	if (czy == 1)
		printf("TAK");
	else if (czy == 0)
		printf("NIE");
    return 0;
}

