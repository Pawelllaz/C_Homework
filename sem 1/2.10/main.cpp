#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

	float a,b;

	printf("KALKULATOR\nwpisz pierwsza liczbe ");
	scanf("%f",&a);
	printf("wpisz druga liczbe ");
	scanf("%f",&b);

	float suma=a+b;
	float  roznica=a-b;
	float iloczyn=a*b;


	printf("suma: %.2f\n", suma);
	printf("roznica: %.2f\n", roznica);
	printf("iloczyn: %.2f\n", iloczyn);
	if(b==0)
	{printf("iloraz: blad");
	}
	else
	{float iloraz=a/b;
	printf("iloraz: %.2f", iloraz);
	}

	return 0;
}
