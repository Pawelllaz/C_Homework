#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <Windows.h>
#define N 201
int add(const char* number1, const char* number2, char** result);
int validate(const char *number)
{
	if (number == NULL) return 2;
	if (*number != '-' && (*number > '9' || *number < '0')) return 1;
	int i;
	for (i = 0;; i++)
	{
		if (*(number + i) == 0) break;
		if ((*(number + i) < '0' || *(number + i) > '9') && i>0)  return 1;
	}
	if (i == 0) return 1;
	if (*number == '-' && i < 2) return 1;
	return 0;
}
//====================================================================================================================
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
//====================================================================================================================
int subtract(const char* number1, const char* number2, char** result)
{
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
	return 0;
}
//====================================================================================================================
int add(const char* number1, const char* number2, char** result)
{
	if (number1 == NULL || number2 == NULL || result == NULL) return 1;
	if (validate(number1) != 0) return 2;
	if (validate(number2) != 0) return 2;
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
			if (*(*result + i) + *(number2 + j) - '0' > '9' && j >= 0 && i == 0)
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
			else if (*(*result + i) + *(number2 + j) - '0' > '9' && j >= 0)
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
			else if (*(*result + i) > '9' && i>0)
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
			if (*(*result + i) + *(number1 + j) - '0' > '9' && j >= 0 && i == 0)
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
			else if (*(*result + i) + *(number1 + j) - '0' > '9' && j >= 0)
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
			else if (*(*result + i) > '9' && i>0)
			{
				*(*result + i) -= 10;
				*(*result + i - 1) += 1;
			}
		}
	}
	else if (compare(number1, number2) == 0) return 3;

	return 0;
}
//=====================================================================================================================
int main()
{
	char *number1, *number2, *result;
	number1 = (char*)malloc(N);
	if (number1 == NULL)
	{
		printf("failed to allocate memory");
		return 2;
	}
	number2 = (char*)malloc(N);
	if (number2 == NULL)
	{
		printf("Failed to allocate memory");
		free(number1);
		return 2;
	}
	char znak=0;
	printf("wpisz pierwszo liczbe: ");
	scanf("%200s", number1);
	while (znak != '\n')
		znak = (char)fgetc(stdin);
	printf("wpisz drugo: ");
	scanf("%200s", number2);
	while (znak != '\n')
		znak = (char)fgetc(stdin);
	if (compare(number1, number2) == 0)
	{
		printf("0\n0");
		return 0;
	}
	int spr = add(number1, number2, &result);
	if (spr == 3)
	{
		printf("failed to allocate memory");
		free(number1);
		free(number2);
		return 2;
	}
	else if (spr == 2)
	{
		printf("error");
		free(number1);
		free(number2);
		return 1;
	}
	else if (spr != 0)
	{
		printf("failed to allocate memory");
		free(number1);
		free(number2);
		return spr;
	}
	for (int i = 0; *(result + i) != 0; i++)
	{
		printf("%c", *(result + i));
	}
	free(result);
	printf("\n");
	spr = subtract(number1, number2, &result);
	if (spr == 3)
	{
		printf("failed to allocate memory");
		free(number1);
		free(number2);
		return 2;
	}
	else if (spr == 2)
	{
		printf("error");
		free(number1);
		free(number2);
		return 1;
	}
	else if (spr != 0)
	{
		printf("failed to allocate memory");
		free(number1);
		free(number2);
		return spr;
	}
	for (int i = 0; *(result + i) != 0; i++)
	{
		printf("%c", *(result + i));
	}
	free(number1);
	free(number2);
	free(result);
	//system("PAUSE");
	return 0;
}