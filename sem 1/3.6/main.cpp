#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

	double suma, roznica, mnozenie, dzielenie;
	double a, b;

	char o;

	printf("wprowadz liczbe ");
    scanf("%lg", &a);

	printf("wprowadz liczbe ");
    scanf("%lg", &b);


    fflush(stdin);
	printf("wprowadz znak ");
	scanf("%c", &o);

	switch (o)
		{
			case '+':
				suma=a+b;
				printf("wynik sumy: %lg", suma);
				break;
			case '-':
				roznica=a-b;
				printf("wynik roznicy: %lg", roznica);
				break;
			case '*':
				mnozenie=a*b;
				printf("wynik mnozenia: %lg", mnozenie);
				break;
			case '/':
				dzielenie=a/b;
				printf("wynik dzielenia %lg", dzielenie);
				break;
				default: printf("niepoprawny znak");
					break;
		}

	return 0;
}
