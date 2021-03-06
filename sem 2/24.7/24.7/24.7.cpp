#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <Windows.h>
#include <math.h>
struct complex_t
{
	float re;
	float im;
}; 

struct complex_t* set(struct complex_t* cp, float re, float im, int *err_code)
{
	if (cp == NULL)
	{
		if (err_code != NULL) *err_code = 1;
		return NULL;
	}
	cp->re = re;
	cp->im = im;
	if (err_code != NULL) *err_code = 0;
	return cp;
}
void show(const struct complex_t* cp)
{
	if (cp == NULL) return;
	float tym = 0;
	if (cp->im >= 0) printf("%.2f + i%.2f\n", cp->re, cp->im);
	else
	{
		tym = cp->im*(-1);
		printf("%.2f - i%.2f\n", cp->re, tym);
	}
}
float complex_abs(struct complex_t* cp, int * err_code)
{
	if (cp == NULL)
	{
		if (err_code != NULL) *err_code = 1;
		return -1;
	}
	if (err_code != NULL) *err_code = 0;
	return sqrt(pow(cp->re, 2) + pow(cp->im, 2));
}

int main()
{
	srand(time(NULL));
	struct complex_t cp1,cp2;
	cp1.re = rand() % 1000;
	cp1.im = rand() % 1000;
	cp1.re /= 100;
	cp1.im /= 100;
	cp2.re = rand() % 1000;
	cp2.im = rand() % 1000;
	cp2.re /= 100;
	cp2.im /= 100;
	show(&cp1);
	show(&cp2);
	float dyst1, dyst2;
	int err;
	dyst1 = complex_abs(&cp1, &err);
	if (err == 1)
	{
		printf("Error");
		return 1;
	}
	dyst2 = complex_abs(&cp2, &err);
	if (err == 1)
	{
		printf("Error");
		return 1;
	}
	if (dyst1 > dyst2) show(&cp1);
	else if (dyst2 > dyst1) show(&cp2);
	else
	{
		show(&cp1);
		show(&cp2);
	}
	//system("PAUSE");
	return 0;
}