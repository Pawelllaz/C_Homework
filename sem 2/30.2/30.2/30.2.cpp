#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdint.h>

int toggle_bit(uint32_t* pvalue, int b);
int set_bit(uint32_t* pvalue, int b);
int clear_bit(uint32_t* pvalue, int b);
int isset_bit(const uint32_t* pvalue, int b);

int main()
{
	


	return 0;
}

int toggle_bit(uint32_t* pvalue, int b)
{
	uint32_t a=*pvalue,b=0;
	for (int i = (sizeof(uint32_t) * 8) - 1; i >= 0; i--)
	{
		if (a >>= 1 & 1) b += 1;
		else b += 0;
		b >>= 1;
	}
	if (b > 31 || b < 0) return -1;
	~*pvalue >> b;
	return 0;	
}
int set_bit(uint32_t* pvalue, int b)
{
	long int a = *pvalue;
	if (b > 31 || b < 0) return -1;
	(a >> b)+=1;
	return 0;
}
int clear_bit(uint32_t* pvalue, int b);
int isset_bit(const uint32_t* pvalue, int b);
