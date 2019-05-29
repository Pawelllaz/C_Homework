#include "stdafx.h"
#include <stdio.h>
//#include <conio.h>
#define N 401

int add(const char* number1, const char* number2, char* result, int size)
{
	if(number1==NULL || number2==NULL || result==NULL) return 0;
	if (validate(number1) == 0) return 0;
	if (validate(number2) == 0) return 0;
	if (*number1 == '0') return 0;
	int size1=0, size2=0;
	for (int i = 0;; i++)
	{
		if (*(number1+i) == 0) break;
		size1++;
	}
	for (int i = 0;; i++)
	{
		if (*(number2+i) == 0) break;
		size2++;
	}
	char liczba, wieksza=0;
	if (size1 >= size2)
	{
		*(result + size1) = 0;
		size2--;
		for (int i = size1 - 1; i >= 0; i--)
		{
			if(*(number2+size2)>='0') liczba = *(number1 + i) + *(number2 + size2--) - 48;
			else liczba = *(number1 + i);
			
			if (wieksza>0) liczba++;
			if (liczba > '9')
			{
				liczba -= 10;
				wieksza++;
			}
			else wieksza = 0;
			*(result + i) = liczba;
			if (i == 0 && wieksza > 0)
			{
				for (int i = size1+1; i > 0; i--)
				{
					liczba = *(result + i - 1);
					*(result + i) = liczba;
				}
				*result = '1';
			}
		}
	}
	else if (size1 < size2)
	{
		*(result + size2) = 0;
		size1--;
		for (int i = size2 - 1; i >= 0; i--)
		{
			if(*(number1+size1)>='0') liczba = *(number2 + i) + *(number1 + size1--) - 48;
			else liczba = *(number2 + i);
			if (wieksza>0) liczba++;
			if (liczba > '9')
			{
				liczba -= 10;
				wieksza++;
			}
			else wieksza = 0;
			*(result + i) = liczba;
			if (i == 0 && wieksza > 0)
			{
				for (int i = size2 + 1; i > 0; i--)
				{
					liczba = *(result + i - 1);
					*(result + i) = liczba;
				}
				*result = '1';
			}
		}
	}
	int counter = 0;
	for (int i = 0; *(result+i)!=0; i++)
	{
		counter++;
	}
	if (counter >= size) return 0;
	return 1;
}
//===================================================================================
int validate(const char * number)
{
	if (number == NULL) return -1;
	for (int i = 0;; i++)
	{
		if (*(number + i) == 0) break;
		if (*(number + i) < '0' || *(number + i) > '9')  return 0;
		
	}
	return 1;
}
//===================================================================================
int main()
{
	printf("abrakadabra:\n");
	char l1[N], l2[N],result[N];
	char *q_result = result;
	scanf("%200s", l1);
	printf("dzien dobry tvn:\n");
	scanf("%200s", l2);

	if (add(l1, l2, q_result, N)) printf("%s", result);
	else
	{
		printf("error");
		return 1;
	}
	

	//for (int i = 0; i < 10; i++) printf("%d\n", *(result + i));
	//_getch();
	return 0;
}