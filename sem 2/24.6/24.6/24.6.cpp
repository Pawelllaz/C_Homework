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
struct segment_t
{
	struct point_t start;
	struct point_t end;
};
//===========================================
struct segment_t* read_segment(struct segment_t* p)
{
	if (p == NULL) return NULL;
	printf("podaj wspolrzedne pierwszego punktu\npodaj wspolrzedna x: ");
	scanf("%d", &p->start.x);
	printf("podaj wspolrzedna y: ");
	scanf("%d", &p->start.y);
	printf("podaj wspolrzedne drugiego punktu\npodaj wspolrzedna x: ");
	scanf("%d", &p->end.x);
	printf("podaj wspolrzedna y: ");
	scanf("%d", &p->end.y);
	return p;
}
//========================================================================
void show_segment(const struct segment_t* p)
{
	if (p == NULL) return;
	printf("wspolrzedne poczatku odcinka: x = %d; y = %d\n", p->start.x,p->start.y);
	printf("wspolrzedne konca odcinka: x = %d; y = %d\n", p->end.x, p->end.y);
}
//==================================================
float length(const struct segment_t* s, int *err_code)
{
	if (s == NULL)
	{
		if (err_code != NULL) *err_code = 1;
		return -1;
	}

	float dist, x1, y1, x2, y2;
	x1 = s->start.x; x2 = s->end.x; y1 = s->start.y; y2 = s->end.y;
	dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	if (err_code != NULL) *err_code = 0;

	return dist;
}
//=========================================================================================
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
	struct segment_t seg;
	read_segment(&seg);
	show_segment(&seg);
	dist = length(&seg, &err);
	if (!err) printf("%.2f", dist);
	else printf("error");
	//system("PAUSE");
	return 0;
}