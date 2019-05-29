#pragma once

enum operations_t
{
	op_add, op_sub, op_div, op_mul
};
int(*get_function(enum operations_t op))(int a, int b);
int add_int(int a, int b);
int sub_int(int a, int b);
float div_int(int a, int b);
int mul_int(int a, int b);
