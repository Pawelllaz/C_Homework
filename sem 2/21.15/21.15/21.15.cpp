#include "stdafx.h"
#include <stdio.h>

int clamp(int *v, int lo, int hi)
{
	if (v == NULL) return 1;
	int wyn=0;
	if (*v >= lo && *v <= hi)
		wyn=*v;
	if (*v >= hi && *v <= lo)
		wyn= *v;
	if (*v>hi && hi>lo)
		wyn =hi;
	if (*v>hi && lo>hi)
		wyn= lo;
	if (*v<lo && lo<hi)
		wyn= lo;
	if (*v<lo && hi<lo)
		wyn= hi;
	if (hi == lo)
		wyn= hi;
	*v = wyn;
	return 0;
}

int main()
{
	int v, hi, low,spr=0;
	int *p_v = &v;
	printf("wpisz liczbe: ");
	scanf("%d", p_v);
	printf("wpisz pierwsza granice: ");
	scanf("%d", &low);
	printf("pisz druga granice: ");
	scanf("%d", &hi);
	spr = clamp(p_v, low, hi);
	if(spr==0) printf("%d", *p_v);
	else printf("Error");
	return 0;
}