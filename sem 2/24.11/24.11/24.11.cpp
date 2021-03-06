#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
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
	struct point_t point1, point2;
	int err,x;
	float naj_dyst=100000, dyst;
	char sciezka[40];
	printf("wpisz: ");
	scanf("%39s", sciezka);
	FILE *f;
	f = fopen(sciezka, "r");
	if (f == NULL)
	{
		printf("couldn't open file");
		return 1;
	}
	int i = 0;
	for (;;)
	{
		x = fscanf(f, "%d %d", point1.x, point1.y);
		printf("%d %d\n", point1.x, point1.y);
		if (x != 2) break;
		for (;;)
		{
			x = fscanf(f, "%d %d", &point2.x, &point2.y);
			printf("%d %d\n", point2.x, point2.y);
			if (x != 2) break;
			dyst = distance(&point1, &point2, &err);
			printf("%d\n", dyst);
			if (dyst < naj_dyst) naj_dyst = dyst;
		}
		i++;
	}
	if (i == 1)
	{
		printf("error");
		system("PAUSE");
		return 0;
	}
	for (;;)
	{
		x = fscanf(f, "%d %d", &point1.x, &point1.y);
		if (x != 2) break;
		for (;;)
		{
			x = fscanf(f, "%d %d", &point2.x, &point2.y);
			if (x != 2) break;
			dyst = distance(&point1, &point2, &err);
			if (dyst == naj_dyst)
			{
				printf("%d %d %d %d", point1.x, point1.y, point2.x, point2.y);
				break;
			}
		}
	}

	fclose(f);
	system("PAUSE");
	return 0;
}
