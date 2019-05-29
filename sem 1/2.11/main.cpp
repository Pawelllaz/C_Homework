#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

int a;

	printf("wpiz liczbe:");

	scanf("%d", &a);

	if ( a == 0 )
	{ printf("zero");}
	else if ( a == 1 )
	{ printf("jeden");}
	else if ( a == 2 )
	{ printf("dwa");}
	else if ( a == 3 )
	{ printf("trzy");}
	else if ( a == 4 )
	{ printf("cztery");}

	else if ( a == 5 )
	{ printf("piec");}

	else if ( a == 6)
	{ printf("szesc");}

	else if ( a == 7 )
	{ printf("siedem");}

	else if ( a == 8 )
	{ printf("osiem");}

	else if ( a == 9 )
	{ printf("dziewiec");}

	else if ( a == 10 )
	{ printf("dziesiec");}
	else
	{printf("blad");}


	return 0;
}
