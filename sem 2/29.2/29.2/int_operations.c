#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "int_operations.h"

int (*get_function(enum operations_t op))(int a, int b)
{
	if (op == op_add) return add_int;
	else if (op == op_sub) return sub_int;
	else if (op == op_div) return div_int;
	else if (op == op_mul) return mul_int;
}
int add_int(int a, int b)
{
	return a + b;
}
int sub_int(int a, int b)
{
	return a - b;
}
float div_int(int a, int b)
{
	return a / b;
}
int mul_int(int a, int b)
{
	return a * b;
}
	