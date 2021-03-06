#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//#include <conio.h>

#define N 501
#define M 5
int subtract(const char* number1, const char* number2, char** result);
int add(const char* number1, const char* number2, char** result);
int validate(const char *number);
int compare(const char* number1, const char* number2);
int multiply(const char* number1, const char* number2, char** result);
int odwroc(char *tab);
int validate_expression(const char *expr);
int calculate(const char* expr, char **result);
int pomoc(const char* number1, const char* number2)
{
	if (number1 == NULL || number2 == NULL) return 2;
	if (validate(number1) != 0 || validate(number2) != 0) return 3;
	int id1 = strlen(number1) - 1, id2 = strlen(number2) - 1;
	int i = 0, j = 0;
	if (*number1 == '-') i++;
	if (*number2 == '-') j++;
	if (id1 - i > id2 - j) return 1;
	else if (id1 - i < id2 - j) return -1;
	for (; i <= id1 + 1 && j <= id2 + 2; i++, j++)
	{
		if (j > id2 && i <= id1) return 1;
		else if (i > id1 && j <= id2) return -1;
		if (i < id1 + 1 && j < id2 + 1)
		{
			if (*(number1 + i) > *(number2 + j)) return 1;
			else if (*(number1 + i) < *(number2 + j)) return -1;
		}
	}
	return 0;
}

int main()
{
	char *wynik, *tab;
	tab = (char*)malloc(N);
	if (tab == NULL)
	{
		printf("failed to allocate memory");
		return 3;
	}
	printf("dizalanie: ");
	scanf("%500s", tab);
	int err = validate_expression(tab);
	if (err != 0)
	{
		printf("incorrect input");
		free(tab);
		return 2;
	}
	err = calculate(tab, &wynik);
	if (err == 0)
	{
		printf("%s", wynik);
		free(wynik);
	}
	else
	{
		printf("failed to allocate memory");
		free(tab);
		//_getch();
		return 3;
	}
	free(tab);
	//_getch();
	return 0;
}

int validate(const char *number)
{
	if (number == NULL) return 2;
	if (*number == '\0') return 1;
	int i = 0;
	if ((*(number) == '0' && *(number + 1) != '\0') || (*(number) == '-' && *(number + 1) == '0') || (*number) == '\0') return 1;
	i = 0;
	if (*number == '-' && *(number + 1) == '\0') return 1;
	if (*number == '-') i++;
	while (*(number + i) != '\0')
	{
		if ((*(number + i) > '9' || *(number + i) < '0'))
		{
			return 1;
		}
		i++;
	}
	return 0;
}

int compare(const char* number1, const char* number2)
{
	if (number1 == NULL || number2 == NULL) return 2;
	if (validate(number1) != 0 || validate(number2) != 0) return 3;

	if (*number1 == '0' && *(number1 + 1) != '0' && *(number1 + 1) != '\0') return 3;
	if (*number2 == '0' && *(number2 + 1) != '0' && *(number2 + 1) != '\0') return 3;
	if (*number1 != '-' && *number2 == '-') return 1;
	if (*number1 == '-' && *number2 != '-') return -1;
	int size1 = strlen(number1);
	int size2 = strlen(number2);
	if (size1 > size2) return 1;
	if (size1 < size2) return-1;
	if (*number1 != '-')
	{
		for (int i = 0; i < size1; i++)
		{
			if (*(number1 + i) > *(number2 + i)) return 1;
			else if (*(number1 + i) < *(number2 + i)) return -1;
		}
	}
	else
	{
		for (int i = 1; i < size1; i++)
		{
			if (*(number1 + i) < *(number2 + i)) return 1;
			else if (*(number1 + i) > *(number2 + i)) return -1;
		}
	}
	return 0;
}

int odwroc(char *tab)
{
	if (tab == NULL) return 1;
	int dlugosc = strlen(tab) - 1;
	char swap;
	if (dlugosc < 0)
		return 1;
	for (int i = 0; i <= dlugosc; i++, --dlugosc)
	{
		swap = *(tab + dlugosc);
		*(tab + dlugosc) = *(tab + i);
		*(tab + i) = swap;
	}
	return 0;
}

int add(const char* number1, const char* number2, char** result)
{
	// jeszcze raz robie add bo ten z 26.12 nie pojdzie
	if (number1 == NULL || number2 == NULL || result == NULL) return 1;
	if (validate(number1) != 0 || validate(number2) != 0) return 2;
	int minus = 0;
	int id1 = strlen(number1) - 1, id2 = strlen(number2) - 1;
	if (id1 < 0 || id2 < 0) return 2;
	int pamiec = 0, score = 0, size = 0, i = 0;
	if (id1 > id2) size = id1 + 5;
	else size = id2 + 5;
	char *res_rev = (char*)malloc(size); 
	if (res_rev == NULL) return 3;
	//dziala
	int sprawdz1 = compare(number1, number2), sprawdz2 = pomoc(number1, number2);
	if (*number1 == '-' && *number2 == '-') minus++;
	if (sprawdz2 == 0 && minus == 0 && *number1 == '0')
	{
		*res_rev = '0';
		*(res_rev + 1) = '\0';
	}
	else if (sprawdz2 == 0 && minus == 0 && *number1 != '-' && *number2 == '-')
	{
		*res_rev = '0';
		*(res_rev + 1) = '\0';
	}
	else if ((*number1 == '-' && sprawdz1 == -1 && minus == 0) || (*number2 == '-' && sprawdz1 == 1 && minus == 0))
	{
		if (sprawdz2 == 1)
		{
			if (*number1 == '-') minus = 1;
			for (i = 0; i < size + 5; i++)
			{
				if (id1 >= 0 && id2 >= 0)
				{
					score = (int)*(number1 + id1) - (int)*(number2 + id2) + pamiec;
					if (score < 0)
					{
						score = 10 + (int)*(number1 + id1) - (int)*(number2 + id2) + pamiec;
						pamiec = -1;
					}
					else pamiec = 0;
				}
				else if (id1 >= 0 && id2 < 0)
				{
					score = (int)*(number1 + id1) - '0' + pamiec;
					if (score < 0)
					{
						score = 10 + (int)*(number1 + id1) - '0' + pamiec;
						pamiec = -1;
					}
					else pamiec = 0;
				}
				else
				{
					score = (int)*(number2 + id1) - '0' + pamiec;
					if (score < 0)
					{
						score = 10 + (int)*(number2 + id1) - '0' + pamiec;
						pamiec = -1;
					}
					else pamiec = 0;
				}
				id1--;
				id2--;
				if (*(number1 + id1) == '-') id1--;
				if (*(number2 + id2) == '-') id2--;
				
				*(res_rev + i) = (char)score + '0';
				if (id1 < 0 && id2 < 0)	break;
			}
			if (*(res_rev + i) != '0')
			{
				i++;
				*(res_rev + i) = '\0';
			}
			else
			{
				while (*(res_rev + i) == '0' && i>0)
				{
					*(res_rev + i) = '\0';
					i--;
				}
				i++;
			}
			if (minus == 1)
			{
				*(res_rev + i) = '-';
				*(res_rev + i + 1) = '\0';
			}
		}
		else
		{
			if (*number1 != '-') minus = 1;
			for (i = 0; i < size + 5; i++)
			{
				if (id1 >= 0 && id2 >= 0)
				{
					score = (int)*(number2 + id2) - (int)*(number1 + id1) + pamiec;
					if (score < 0)
					{
						score = 10 + (int)*(number2 + id2) - (int)*(number1 + id1) + pamiec;
						pamiec = -1;
					}
					else pamiec = 0;
				}
				else if (id2 >= 0 && id1 < 0)
				{
					score = (int)*(number2 + id2) - '0' + pamiec;
					if (score < 0)
					{
						score = 10 + (int)*(number2 + id2) - '0' + pamiec;
						pamiec = -1;
					}
					else pamiec = 0;
				}
				else
				{
					score = (int)*(number1 + id1) - '0' + pamiec;
					if (score < 0)
					{
						score = 10 + (int)*(number1 + id1) - '0' + pamiec;
						pamiec = -1;
					}
					else pamiec = 0;
				}
				// poszlo
				id1--;
				id2--;
				if (id1 >= 0 && *(number1 + id1) == '-') id1--;
				if (id2 >= 0 && *(number2 + id2) == '-') id2--;
				*(res_rev + i) = (char)score + '0';
				if (id1 < 0 && id2 < 0)	break;
			}
			if (*(res_rev + i) != '0')
			{
				i++;
				*(res_rev + i) = '\0';
			}
			// dziala
			else
			{
				while (*(res_rev + i) == '0' && i>0)
				{
					*(res_rev + i) = '\0';
					i--;
				}
				i++;
			}
			if (minus == 1)
			{
				*(res_rev + i) = '-';
				*(res_rev + i + 1) = '\0';
			}
		}
	}
	// to mam
	else
	{
		for (i = 0; i < size + 5; i++)
		{
			//bez minusow
			if (id1 == 0 && *(number1 + id1) == '-') id1 = id1 - 1;
			if (id2 == 0 && *(number2 + id2) == '-') id2 = id2 - 1;
			if (id1 >= 0 && id2 >= 0)
			{
				int length1 = strlen(number1), length2 = strlen(number2);  //bo inaczej nie przechodzi....
				if (id1 > length1 || id2 > length2)
				{
					free(res_rev);
					return 2;
				}
				score = (int)*(number1 + id1) - '0' + (int)*(number2 + id2) - '0' + pamiec;
				pamiec = 0;
			}
			else if (id1 >= 0 && id2 < 0)
			{
				int length1 = strlen(number1);  //znowu nie przechodzi
				if (id1 > length1)
				{
					free(res_rev);
					return 2;
				}
				score = (int)*(number1 + id1) - '0' + pamiec;
				pamiec = 0;
			}
			else if (id1 < 0 && id2 >= 0)
			{
				int length2 = strlen(number2);  // znowu..????
				if (id2 > length2)
				{
					free(res_rev);
					return 2;
				}
				score = (int)*(number2 + id2) - '0' + pamiec;
				pamiec = 0;
			}
			else
			{
				score = pamiec;
				pamiec = 0;
			}
			id1--;
			id2--;
			if (score > 9)
			{
				pamiec = 1;
				score = score - 10;
			}
			// ok
			*(res_rev + i) = (char)score + '0';
			if (id1 < 0 && id2 < 0 && pamiec == 0) break;
		}
		if (*(res_rev + i) != '0')
		{
			i++;
			*(res_rev + i) = '\0';
		}
		else
		{
			while (*(res_rev + i) == '0' && i>0)
			{
				*(res_rev + i) = '\0';
				i--;
			}
			i++;
		}
		if (minus == 1)
		{
			*(res_rev + i) = '-';
			*(res_rev + i + 1) = '\0';
		}
		//chyba poszlo
	}
	i++;
	int k = 0;
	size = i; 
	if (result != 0) *result = (char*)malloc(size + 1);
	if (result == 0 || *result == NULL)
	{
		free(res_rev);
		return 3;
	}
	for (i = size - 1; i >= 0; i--)
	{
		if ((*(res_rev + i) >= '0' && *(res_rev + i) <= '9') || *(res_rev + i) == '-')
		{
			*(*result + k) = *(res_rev + i);
			++k;
		}
	}
	*(*result + k) = '\0';
	free(res_rev);
	return 0;
	// chyba da rade
	/*
	if (number1 == NULL || number2 == NULL || result == NULL) return 1;
	if (validate(number1) != 0)
	{
		printf("numer:%s\n", number1);
		return 2;
	}
	if (validate(number2) != 0)
	{
		printf("numer:%s\n", number1);
		return 2;
	}
	if (*(number1) != '-'&&*(number2) == '-')
		return subtract(number1, number2 + 1, result);
	if (*(number1) == '-'&&*(number2) != '-')
		return subtract(number2, number1 + 1, result);
	if (*number1 == '-' &&*number2 == '-')
	{
		int size = 0;
		int x = add(number1 + 1, number2 + 1, result);
		if (x != 0) return x;
		for (int i = 0; *(*result + i) != 0; i++)
			size++;
		for (int k = size + 1; k >= 0; k--)
		{
			*(*result + k + 1) = *(*result + k);
		}
		*(*result) = '-';
		return x;
	}
	int size1 = 0, size2 = 1;
	for (int i = 0; *(number1 + i + 1) != 0; i++)
		size1++;
	for (int i = 0; *(number2 + i + 1) != 0; i++)
		size2++;
	int size;
	if (size1 > size2) size = size1;
	else size = size2;
	*result = (char*)malloc(size + 5);
	if (*result == NULL) return 3;
	if (compare(number1, number2) == 1)
	{
		for (int i = 0; i <= size1 + 1; i++)
			*(*result + i) = *(number1 + i);
		for (int i = size1, j = size2 - 1; i >= 0; i--, j--)
		{
			if (j >= 0 && i == 0 && *(*result + i) + *(number2 + j) - '0' > '9')
			{
				for (int k = size1 + 1; k >= 0; k--)
				{
					*(*result + k + 1) = *(*result + k);
				}
				*(*result) = '1';
				i++;
				*(*result + i) -= 10;
				*(*result + i) += *(number2 + j);
				*(*result + i) -= '0';
				i--;
			}
			else if (j >= 0 &&*(*result + i) + *(number2 + j) - '0' > '9')
			{
				*(*result + i - 1) += 1;
				*(*result + i) -= 10;
				*(*result + i) += *(number2 + j);
				*(*result + i) -= '0';
			}
			else if (i == 0 && *(*result + i)>'9')
			{
				*(*result) = '0';
				for (int k = size1 + 1; k >= 0; k--)
				{
					*(*result + k + 1) = *(*result + k);
				}
				*(*result) = '1';
			}
			else if (j >= 0)
			{
				*(*result + i) += *(number2 + j);
				*(*result + i) -= '0';
			}
			else if (i>0 && *(*result + i) > '9')
			{
				*(*result + i) -= 10;
				*(*result + i - 1) += 1;
			}
		}
	}
	if (compare(number1, number2) == -1)
	{
		for (int i = 0; i <= size2 + 1; i++)
			*(*result + i) = *(number2 + i);
		for (int j = size1, i = size2 - 1; i >= 0; i--, j--)
		{
			if (j >= 0 && i == 0 &&*(*result + i) + *(number1 + j) - '0' > '9')
			{
				for (int k = size2 + 1; k >= 0; k--)
				{
					*(*result + k + 1) = *(*result + k);
				}
				*(*result) = '1';
				i++;
				*(*result + i) -= 10;
				*(*result + i) += *(number1 + j);
				*(*result + i) -= '0';
				i--;
			}
			else if (j >= 0 && *(*result + i) + *(number1 + j) - '0' > '9')
			{
				*(*result + i - 1) += 1;
				*(*result + i) -= 10;
				*(*result + i) += *(number1 + j);
				*(*result + i) -= '0';
			}
			else if (i == 0 && *(*result + i)>'9')
			{
				*(*result) = '0';
				for (int k = size2 + 1; k >= 0; k--)
				{
					*(*result + k + 1) = *(*result + k);
				}
				*(*result) = '1';
			}
			else if (j >= 0)
			{
				*(*result + i) += *(number1 + j);
				*(*result + i) -= '0';
			}
			else if (i>0 &&*(*result + i) > '9')
			{
				*(*result + i) -= 10;
				*(*result + i - 1) += 1;
			}
		}
	}
	//else if (compare(number1, number2) == 0) return 3;

	return 0;*/
}

int subtract(const char* number1, const char* number2, char** result)
{
	// no teraz jeszcze to nie dziala... od nowa....
	int minus = 0;
	if (number1 == NULL || number2 == NULL || result == NULL) return 1;
	if (validate(number1) != 0 || validate(number2) != 0) return 2;
	int id1 = strlen(number1) - 1, id2 = strlen(number2) - 1;
	if (id1 < 0 || id2 < 0) return 2;
	
	int sprawdz1 = compare(number1, number2), sprawdz2 = pomoc(number1, number2);
	int pamiec = 0, score = 0, size = 0, i = 0;
	
	if (id1 > id2) size = id1 + 5;
	else size = id2 + 5;
	char *res_rev = (char*)malloc(size); 
	if (res_rev == NULL) return 3;
	// ok
	if (sprawdz1 == 0 && sprawdz2 == 0)
	{
		*res_rev = '0';
		*(res_rev + 1) = '\0';
	}
	else if ((*number1 == '-' && *number2 != '-') || (*number1 != '-' && *number2 == '-'))
	{

		if (sprawdz1 == -1) minus = 1;
		for (i = 0; i < size + 5; i++)
		{
			if (*(number1 + id1) == '-') id1--;
			if (*(number2 + id2) == '-') id2--;
			if (id1 >= 0 && id2 >= 0)
			{
				score = (int)*(number1 + id1) - '0' + (int)*(number2 + id2) - '0' + pamiec;
				pamiec = 0;
			}
			else if (id1 >= 0 && id2 <= 0)
			{
				score = (int)*(number1 + id1) - '0' + pamiec;
				pamiec = 0;
			}
			else if (id1 <= 0 && id2 >= 0)
			{
				score = (int)*(number2 + id2) - '0' + pamiec;
				pamiec = 0;
			}
			else
			{
				score = pamiec;
				pamiec = 0;
			}
			id1--;
			id2--;
			if (score > 9)
			{
				pamiec = 1;
				score = score - 10;
			}
			*(res_rev + i) = (char)score + '0';
			if (id1 < 0 && id2 < 0 && pamiec == 0) break;
		}
		//ok
		if (*(res_rev + i) != '0')
		{
			i++;
			*(res_rev + i) = '\0';
		}
		else
		{
			while (*(res_rev + i) == '0' && i>0)
			{
				*(res_rev + i) = '\0';
				i--;
			}
			i++;
		}
		if (minus == 1)
		{
			*(res_rev + i) = '-';
			*(res_rev + i + 1) = '\0';
		}
	}
	else if (sprawdz2 == 1)
	{
		if (*number1 == '-') minus = 1;
		for (i = 0; i < size + 5; i++)
		{
			if (id1 >= 0 && id2 >= 0)
			{
				int length1 = strlen(number1), length2 = strlen(number2);
				if (id1 > length1 || id2 > length2)
				{
					free(res_rev);
					return 2;
				}
				score = (int)*(number1 + id1) - (int)*(number2 + id2) + pamiec;
				if (score < 0)
				{
					score = 10 + (int)*(number1 + id1) - (int)*(number2 + id2) + pamiec;
					pamiec = -1;
				}
				else pamiec = 0;
			}
			else if (id1 >= 0 && id2 < 0)
			{
				int length1 = strlen(number1);
				if (id1 > length1)
				{
					free(res_rev);
					return 2;
				}
				score = (int)*(number1 + id1) - '0' + pamiec;
				if (score < 0)
				{
					score = 10 + (int)*(number1 + id1) - '0' + pamiec;
					pamiec = -1;
				}
				else pamiec = 0;
			}
			else
			{
				score = (int)*(number2 + id1) - '0' + pamiec;
				if (score < 0)
				{
					score = 10 + (int)*(number2 + id1) - '0' + pamiec;
					pamiec = -1;
				}
				else
					pamiec = 0;
			}
			id1--;
			id2--;
			if (id1 == 0 && *(number1 + id1) == '-') id1--;
			if (id2 == 0 && *(number2 + id2) == '-') id2--;
			*(res_rev + i) = (char)score + '0';
			if (id1 < 0 && id2 < 0)	break;
		}
		if (*(res_rev + i) != '0')
		{
			i++;
			*(res_rev + i) = '\0';
		}
		else
		{
			while (*(res_rev + i) == '0' && i>0)
			{
				*(res_rev + i) = '\0';
				i--;
			}
			i++;
		}
		if (minus == 1)
		{
			*(res_rev + i) = '-';
			*(res_rev + i + 1) = '\0';
		}
	}
	else
	{
		if (*number1 != '-') minus = 1;
		for (i = 0; i < size + 5; i++)
		{
			if (id1 >= 0 && id2 >= 0)
			{
				int length1 = strlen(number1), length2 = strlen(number2);
				if (id1 > length1 || id2 > length2)
				{
					free(res_rev);
					return 2;
				}
				score = (int)*(number2 + id2) - (int)*(number1 + id1) + pamiec;
				if (score < 0)
				{
					score = 10 + (int)*(number2 + id2) - (int)*(number1 + id1) + pamiec;
					pamiec = -1;
				}
				else pamiec = 0;
			}
			else if (id2 >= 0 && id1 < 0)
			{
				int length2 = strlen(number2);
				if (id2 > length2)
				{
					free(res_rev);
					return 2;
				}
				score = (int)*(number2 + id2) - '0' + pamiec;
				if (score < 0)
				{
					score = 10 + (int)*(number2 + id2) - '0' + pamiec;
					pamiec = -1;
				}
				else pamiec = 0;
			}
			else
			{
				score = (int)*(number1 + id1) - '0' + pamiec;
				if (score < 0)
				{
					score = 10 + (int)*(number1 + id1) - '0' + pamiec;
					pamiec = -1;
				}
				else pamiec = 0;
			}
			id1--;
			id2--;
			if (id1 == 0 && *(number1 + id1) == '-') id1--;
			if (id2 == 0 && *(number2 + id2) == '-') id2--;
			*(res_rev + i) = (char)score + '0';
			if (id1 < 0 && id2 < 0) break;
		}
		if (*(res_rev + i) != '0')
		{
			i++;
			*(res_rev + i) = '\0';
		}
		else
		{
			while (*(res_rev + i) == '0' && i>0)
			{
				*(res_rev + i) = '\0';
				i--;
			}
			i++;
		}
		if (minus == 1)
		{
			*(res_rev + i) = '-';
			*(res_rev + i + 1) = '\0';
		}
	}
	i++;
	int k = 0;
	size = i; 
	if (result != 0)
		*result = (char*)malloc(size + 1);
	if (result == 0 || *result == NULL)
	{
		free(res_rev);
		return 3;
	}
	for (i = size - 1; i >= 0; i--)
	{
		if ((*(res_rev + i) >= '0' && *(res_rev + i) <= '9') || *(res_rev + i) == '-')
		{
			*(*result + k) = *(res_rev + i);
			k++;
		}
	}
	*(*result + k) = '\0';
	free(res_rev);
	return 0;
	//chyba jezusek mi pomogl, bo juz sam nie wiem
	/*
	if (number1 == NULL || number2 == NULL || result == NULL) return 1;
	if (validate(number1) != 0) return 2;
	if (validate(number2) != 0) return 2;

	if (*(number1) != '-'&&*(number2) == '-')
		return add(number1, number2 + 1, result);
	else if (*(number1) == '-' && *(number2) != '-')
	{
		int size = 0;
		int x = add(number1 + 1, number2, result);
		if (x != 0) return x;
		for (int i = 0; *(*result + i) != 0; i++)
			size++;
		for (int k = size + 1; k >= 0; k--)
		{
			*(*result + k + 1) = *(*result + k);
		}
		*(*result) = '-';
		return x;
	}
	else if (*number1 == '-' && *number2 == '-')
	{
		return subtract(number2 + 1, number1 + 1, result);
	}
	int size1 = 0, size2 = 0;
	for (int i = 0; *(number1 + i + 1) != 0; i++)
		size1++;
	for (int i = 0; *(number2 + i + 1) != 0; i++)
		size2++;
	int size;
	if (size1 > size2) size = size1;
	else size = size2;
	*result = (char*)malloc(size + 4);
	if (*result == NULL) return 3;
	if (compare(number1, number2) == 1)
	{
		for (int i = 0; i <= size1 + 1; i++)
			*(*result + i) = *(number1 + i);
		for (int i = size1, j = size2; i >= 0; i--, j--)
		{
			if (j >= 0)
			{
				if (*(*result + i) - *(number2 + j) + '0' < '0')
				{
					*(*result + i - 1) -= 1;
					*(*result + i) += 10;
				}
				*(*result + i) -= *(number2 + j); *(*result + i) += '0';
			}
			else
			{
				if (*(*result + i) < '0')
				{
					*(*result + i) = '9';
					*(*result + i - 1) -= 1;
				}
			}
		}
		for (int i = 0; i < size1; i++)
		{
			if (*(*result + i) == '0')
			{
				for (int i = 0; *(*result + i) != 0; i++)
				{
					*(*result + i) = *(*result + i + 1);
				}
				i--;
			}
			else break;
		}
	}
	else if (compare(number1, number2) == -1)
	{
		for (int i = 0; i <= size2 + 1; i++)
			*(*result + i) = *(number2 + i);
		for (int i = size1, j = size2; j >= 0; i--, j--)
		{
			if (i >= 0)
			{
				if (*(*result + j) - *(number1 + i) + '0' < '0')
				{
					*(*result + j - 1) -= 1;
					*(*result + j) += 10;
				}
				*(*result + j) -= *(number1 + i); *(*result + j) += '0';
			}
			else
			{
				if (*(*result + j) < '0')
				{
					*(*result + j) = '9';
					*(*result + j - 1) -= 1;
				}
			}
		}
		for (int i = size2 + 1; i >= 0; i--)
		{
			*(*result + i + 1) = *(*result + i);
		}
		if (*(*result) == '0')
		{
			for (int i = 0; *(*result + i) != 0; i++)
			{
				*(*result + i) = *(*result + i + 1);
			}
		}
		*(*result + 0) = '-';
		for (int i = 1; i < size2; i++)
		{
			if (*(*result + i) == '0')
			{
				for (int i = 1; *(*result + i) != 0; i++)
				{
					*(*result + i) = *(*result + i + 1);
				}
				i--;
			}
			else break;
		}
	}
	else if (compare(number1, number2) == 0)
	{
		*(*result) = '0';
		*(*result + 1) = '\0';
	}
	return 0;*/
}

int validate_expression(const char *expr)
{
	if (expr == NULL) return 2;
	if (validate(expr) == 0) return 0;
	if (*expr == '+' || *expr == '*') return 1;
	//poczatek wyrazenia
	int wielkosc = strlen(expr);
	if (wielkosc <= 0) return 1;
	// czy wgl jest
	for (int i = 0; i < wielkosc; i++)
	{
		if (*(expr + i) == '-' && (*(expr + i + 1) > '9' || *(expr + i + 1) < '0') && (*(expr + i + 1) != '\0' && *(expr + i + 1) != '-')) return 1;
		else if (isdigit(*(expr + i)) == 0 && (*(expr + i) != '+' && *(expr + i) != '-' && *(expr + i) != '*'))
		{
			if (*(expr + i) != '-' && *(expr + i + 1) != '-') return 1;
		}

		if (isdigit(*(expr + i)) == 0 && *(expr + i + 1) == '\0') return 1;

		if (isdigit(*(expr + i)) == 0 && isdigit(*(expr + i + 1)) == 0)
		{
			if (*(expr + i) != '-' && *(expr + i + 1) != '-') return 1;
		}
	}
	//glowne sprawdzenie czy wszystko jak powinno
	return 0;
}

int calculate(const char* expr, char **result)
{
	if (expr == NULL || result == NULL) return 1;
	if (validate_expression(expr) != 0) return 2;

	int wielkosc = strlen(expr);
	if (wielkosc <= 0) return 1;
	
	if (validate(expr) == 0)
	{
		*result = (char*)malloc(wielkosc + M);
		if (*result == NULL) return 3;
		for (int i = 0; i <= wielkosc; i++)
			*(*result + i) = *(expr + i);
		return 0;
	}
	
	char *number1 = (char*)malloc(wielkosc + M);
	if (number1 == NULL) return 3;
	char *number2 = (char*)malloc(wielkosc + M);
	if (number2 == NULL)
	{
		free(number1);
		return 3;
	}
	// ok
	int i, j, x = 0;
	char znak;
	for (i = 0; i < wielkosc; i++)
	{
		if (i == 0 && *(expr + i) == '-' && isdigit(*(expr + i + 1)) != 0)
			*(number1 + i) = *(expr + i);
		else if (isdigit(*(expr + i)) != 0)
			*(number1 + i) = *(expr + i);
		else break;
	}
	*(number1 + i) = '\0';
	char *temp;
	while (i < wielkosc)
	{
		znak = *(expr + i);
		i++;
		for (j = 0; i < wielkosc; i++, j++)
		{
			if (*(expr + i) == '-' && j == 0 && isdigit(*(expr + i + 1)) != 0)
				*(number2 + j) = *(expr + i);
			else if (isdigit(*(expr + i)) != 0)
				*(number2 + j) = *(expr + i);
			else break;
		}
		*(number2 + j) = '\0';
		if (znak == '+')
		{
			x = add(number1, number2, &temp);
			if (x != 0)
			{
				free(number1);
				free(number2);
				return 3;
			}
			free(number1);
			int wielkosctemp = strlen(temp) + M;
			number1 = (char*)malloc(wielkosctemp);
			strcpy(number1, temp);
			free(temp);
		}
		else if (znak == '-')
		{
			x = subtract(number1, number2, &temp);
			if (x != 0)
			{
				free(number1);
				free(number2);
				return 3;
			}
			free(number1);
			int wielkosctemp = strlen(temp) + M;
			number1 = (char*)malloc(wielkosctemp);
			strcpy(number1, temp);
			free(temp);
		}
		else if (znak == '*')
		{
			x = multiply(number1, number2, &temp);
			if (x != 0)
			{
				free(number1);
				free(number2); //tutaj problem
				return 3;
			}
			free(number1);
			int wielkosctemp = strlen(temp) + M;
			number1 = (char*)malloc(wielkosctemp);
			strcpy(number1, temp);
			free(temp);
		}
		else
		{
			free(number1);
			free(number2);
			return 2;
		}
	}
	int wielkosckoncowa = strlen(number1);
	if (result != 0) *result = (char*)malloc(wielkosckoncowa + M);
	if (*result == NULL || result == 0)
	{
		free(number1);
		free(number2);
		return 3;
	}
	strcpy(*result, number1);
	free(number1);
	free(number2);
	return 0;
}

int multiply(const char* number1, const char* number2, char** result)
{
	if (number1 == NULL || number2 == NULL || result == NULL) return 1;
	if (validate(number1) != 0 || validate(number2) != 0) return 2;
	if (*number1 == '0' || *number2 == '0')
	{
		*result = (char*)malloc(2);
		*(*result) = '0';
		*(*result + 1) = '\0';
		return 0;
	}
	int id1 = strlen(number1) - 1, id2 = strlen(number2) - 1, minus = 0, i = 0, j = 0, k;
	if (*number1 == '-' || *number2 == '-')	minus++;
	if (*number1 == '-' && *number2 == '-')	minus = 0;
	int counter = 0, temp = 0;

	char *pomoc1 = (char*)malloc(id1 + id2 + M);
	if (pomoc1 == NULL)	return 3;

	char *pomoc2 = (char*)malloc(id1 + id2 + M);
	if (pomoc2 == NULL)
	{
		free(pomoc1);
		return 3;
	}
	int cyfra, wynik = 0;
	for (j = id2; j >= 0; j--)
	{
		if (*(number2 + j) == '-'&& j == 0) break;
		cyfra = (int)*(number2 + j) - '0';
		k = 0;
		for (i = id1; i >= 0 || temp != 0; i--)
		{
			if (i >= 0)
			{
				if (i == 0 && *(number1 + i) == '-' && temp == 0) break;
				else if (i == 0 && *(number1 + i) == '-' && temp != 0)
				{
					wynik = temp;
					temp = 0;
					*(pomoc2 + k) = (char)wynik + '0';
					k++;
					break;
				}
				int analiza = strlen(number1);
				if (i < analiza && i >= 0)
				{
					wynik = cyfra * ((int)*(number1 + i) - '0') + temp;
					if (wynik > 9)
					{
						temp = wynik / 10;
						wynik = wynik - (temp * 10);
					}
					else temp = 0;
				}
			}
			else
			{
				wynik = temp;
				temp = 0;
			}
			*(pomoc2 + k) = (char)wynik + '0';
			k++;
		}
		*(pomoc2 + k) = '\0';
		odwroc(pomoc2);
		for (int x = 0; x < counter; x++)
		{
			*(pomoc2 + k + x) = '0';
			*(pomoc2 + k + x + 1) = '\0';
		}
		int x = validate(pomoc2);
		if (x != 0)
		{
			for (int x = 0; *(pomoc2 + x) != '\0'; ++x)
				*(pomoc2 + x) = '\0';
			*(pomoc2) = '0';
			*(pomoc2 + 1) = '\0';
		}
		if (counter == 0)
		{
			int dlugosc = strlen(pomoc2);
			for (int x = 0; x <= dlugosc; ++x)
				*(pomoc1 + x) = *(pomoc2 + x);
		}
		else
		{
			char *wynik_tymczasowy;
			x = add(pomoc1, pomoc2, &wynik_tymczasowy);
			if (x != 0)
			{
				free(pomoc1);
				free(pomoc2);

				//printf("number1mp:%s\nnumer2mp:%s\ndebug\nx:%d\n", pomoc1,pomoc2,x);  //problem
				return 3;
			}
			else
			{
				strcpy(pomoc1, wynik_tymczasowy);
				free(wynik_tymczasowy);
			}
		}
		for (int x = 0; *(pomoc2 + x) != '\0'; ++x)
			*(pomoc2 + x) = '\0';
		counter++;
	}
	if (result != 0) *result = (char*)malloc(id1 + id2 + M);
	if (result == 0 || *result == NULL)
	{
		free(pomoc1);
		free(pomoc2);
		return 3;
	}
	if (*pomoc1 == '0' && *(pomoc1 + 1) == '\0') minus = 0;
	int pomoc1end = strlen(pomoc1);
	if (minus == 0)
	{
		for (i = 0; i < pomoc1end; i++)
			*(*result + i) = *(pomoc1 + i);
		*(*result + i) = '\0';
	}
	else
	{
		*(*result) = '-';
		for (i = 0; i < pomoc1end; i++)
			*(*result + i + 1) = *(pomoc1 + i);
		*(*result + i + 1) = '\0';
	}
	free(pomoc1);
	free(pomoc2);
	return 0;
}
