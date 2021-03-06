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

int save_points_b(const char *filename, const struct point_t* p, unsigned int N)
{
	if (p == NULL || filename == NULL || N <= 0) return 0;
	FILE *f;
	f = fopen(filename, "wb");
	if (f == NULL) return 0;
	for (unsigned int i = 0; i < N; i++)
	{
		fwrite(&(p+i)->x, sizeof(int), 1, f);
		fwrite(&(p + i)->y, sizeof(int), 1, f);
	}
	fclose(f);
	return 1;
}

//==================================
struct point_t* read(struct point_t* p)
{
	if (p == NULL) return NULL;
	int spr;
	//printf("tekst zachety:\n");
	spr = scanf("%d", &p->x);
	if (spr == EOF) return NULL;
	//printf("tekst zachety:\n");
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
	//float dist = 0;
	struct point_t p[100];
	printf("podaj liczbe punktow: ");
	int liczba_punktow;
	scanf("%d", &liczba_punktow);
	if (liczba_punktow > 100) liczba_punktow = 100;
	if (liczba_punktow <= 0)
	{
		printf("Error");
		return 1;
	}
	for (int i = 0; i < liczba_punktow; i++)
		read(p+i);

	char sciezka[40];
	printf("podaj plik: ");
	scanf("%39s", sciezka);
	err = save_points_b(sciezka, p, liczba_punktow);
	if (err) printf("File saved");
	else
	{
		printf("Couldn't create file");
		return 1;
	}
	//system("PAUSE");
	return 0;
}