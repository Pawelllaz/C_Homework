#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void for_loop(double beg, double next, double end, double(*ptr)(double))
{
	if (beg == end) return;
	ptr(beg);
	for_loop(beg += next, next, end, ptr);
}

void print_value(double value)
{
	printf("%.6lg", value);
}

void print_accumulated(double value)
{
	printf("%.6lg", value);
}

void print_square(double value)
{
	printf("%.6lg", value*value);
}

void print_abs(double value)
{
	if(value<0) printf("%.6lg", value*(-1));
	else printf("%.6lg", value);
}

int main()
{
	double beg, next, end;
	printf("podaj poczatek ktrok i koniec pzedzialu: ");
	scanf("%lg %dlg %ld", &beg, &next, &end);
	for_loop(beg,next,end,)
	return 0;
}