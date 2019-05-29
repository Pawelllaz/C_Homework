#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

	int a;
	printf("liczba punktow z kolokwium\n");

	scanf("%d", &a);

	if(a>=0 && a<=10)
	{printf("ocena 2");
	}
	else if(a>=11 && a<=13)
	{printf("ocena 3");
	}
	else if(a>=14 && a<=16)
	{printf("ocena 4");
	}
	else if(a>=17 && a<=20)
	{printf("ocena 5");
	}
	else
	{printf("error");
	}

	return 0;
}
