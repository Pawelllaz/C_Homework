#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "int_operations.h"

int main()
{
	printf("podaj liczby: ");
	int a, b, op, res;
	scanf("%d %d", &a, &b);
	printf("podaj rodzaj operacji: ");
	scanf("%d", &op);
	if(op==0) res = get_function(op_add)(a, b);
	else if(op==1) res = get_function(op_sub)(a, b);
	else if (op == 2) res = get_function(op_sub)(a, b);
	else if (op == 3) res = get_function(op_sub)(a, b);
	else
	{
		printf("Incorrect input");
		return 0;
	}

	return 0;
}