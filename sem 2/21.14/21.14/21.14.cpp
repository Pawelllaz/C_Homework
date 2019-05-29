#include "stdafx.h"
#include <stdio.h>
//#include <conio.h>

int add(const int *first, const int *second, int* result)
{
	if (first == NULL) return 0;
	if (second == NULL) return 0;
	if (result == NULL) return 0;
	int suma = 0;
	suma = *first + *second;
	*result = suma;
	return 1;
}
//=====================================================================
int subtract(const int *first, const int *second, int* result)
{
	if (first == NULL) return 0;
	if (second == NULL) return 0;
	if (result == NULL) return 0;
	int odej = 0;
	odej = *first - *second;
	*result = odej;
	return 1;
}
//=====================================================================
int multiply(const int *first, const int *second, int* result)
{
	if (first == NULL) return 0;
	if (second == NULL) return 0;
	if (result == NULL) return 0;
	int mnoz = 0;
	mnoz = *first*(*second);
	*result = mnoz;
	return 1;
}
//=====================================================================
int divide(const int *first, const int *second, float* result)
{
	if (first == NULL) return 0;
	if (second == NULL) return 0;
	if (result == NULL) return 0;
	if (*second == 0) return 0;
	float dziel = 0;
	float a, b;
	a = *first; b = *second;
	dziel = a / b;
	*result = dziel;
	return 1;
}
//=====================================================================
int main()
{
	int a, b,spr=0;
	int *p_a = &a, *p_b = &b;

	int suma, roznica, mnozenie;
	float dzielenie;
	int *p_suma = &suma, *p_rozncia = &roznica, *p_mnozenie = &mnozenie;
	float *p_dzielenie = &dzielenie;
	printf("wpisz pierwsza liczbe: ");
	scanf("%d", p_a);
	printf("wpisz druga liczbe: ");
	scanf("%d", p_b);
	spr = add(p_a, p_b, p_suma);
	if (spr == 1) printf("%d\n", *p_suma); 
	else
	{
		printf("Error");
	}
	spr = 0;
	spr = subtract(p_a, p_b, p_rozncia);
	if (spr == 1) printf("%d\n", *p_rozncia);
	else
	{
		printf("Error");
	}
	spr = 0;
	spr = multiply(p_a, p_b, p_mnozenie);
	if (spr == 1) printf("%d\n", *p_mnozenie); 
	else
	{
		printf("Error");
	}
	spr = 0;
	spr = divide(p_a, p_b, p_dzielenie);
	if (spr == 1) printf("%f\n", *p_dzielenie);
	else
	{
		printf("Error");
	}

	//_getch();
	return 0;
}