#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
//#include <Windows.h>
//======================================
struct point_t {
	int x;
	int y;
};
//==================================
struct point_t* read(struct point_t* p)
{
	if (p == NULL) return NULL;
	int spr;
	printf("tekst zachety:\n");
	spr = scanf("%d", &p->x);
	if (spr == EOF) return NULL;
	printf("tekst zachety:\n");
	spr = scanf("%d", &p->y);
	if (spr == EOF) return NULL;
	return p;
}
//===========================================
void show(const struct point_t* p)
{
	if (p == NULL) return;
	printf("%d %d\n", (*p).x, p->y);
}
//============================================
struct point_t* set(struct point_t* p, int x, int y)
{
	if (p == NULL) return NULL;
	p->x = x;
	p->y = y;
	return p;
}
//=======================================================
float distance(const struct point_t* p1, const struct point_t* p2, int *err_code)
{
	
	if (p1 == NULL)
	{
		if (err_code != NULL) *err_code = 1;
		return -1;
	}
	if (p2 == NULL) 
	{
		if (err_code != NULL) *err_code = 1;
		return -1;
	}
	float dist, x1, y1, x2, y2;
	x1 = p1->x; x2 = p2->x; y1 = p1->y; y2 = p2->y;
	dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	if (err_code != NULL) *err_code = 0;

	return dist;
}
//================================================================
int main()
{
	int err;
	float dist = 0;
	struct point_t p1, p2;
	read(&p1);
	int x2 = rand() % 100;
	int y2 = rand() % 100;
	set(&p2, x2, y2);
	show(&p1);
	show(&p2);
	dist = distance(&p1, &p2, &err);
	printf("%.2f", dist);
	/*
	if (err == 0) printf("%f", dist);
	else
	{
		printf("error");
		return 1;
	}*/
	//system("PAUSE");
	return 0;
}
