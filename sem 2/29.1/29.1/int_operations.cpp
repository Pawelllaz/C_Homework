#include "stdafx.h"
#include <stdio.h>

int add_int(int a, int b)
{
	return a + b;
}
int sub_int(int a, int b)
{
	return a - b;
}
int mul_int(int a, int b)
{
	return a * b;
}
int div_int(int a, int b)
{
	if (b == 0) return 0;
	return a / b;
}
int calculate(int a, int b, int(*ptr)(int, int))
{
	return ptr(a, b);
}