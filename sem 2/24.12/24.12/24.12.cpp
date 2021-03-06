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
	printf("wspolrzedne poczatku odcinka: x = %d; y = %d\n", p->start.x, p->start.y);
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
int load_segments_b(const char *filename, struct segment_t* p, unsigned int N)
{
	if (filename == NULL || p == NULL || N<=0) return -1;
	FILE *f;
	f = fopen(filename, "rb");
	if (f == NULL)	return -2;
	unsigned int n;
	fread(&n, sizeof(unsigned int), 1, f);
	if (N != n)
	{
		fclose(f);
		return 0;
	}
	int spr = 0;
	//printf("%d\n", N);
	for (unsigned int i = 0; i < N; i++)
	{
		spr = fread(&(p + i)->start.x, sizeof(int), 1, f);
		if (spr != 1)
		{
			fclose(f);
			return 0;	
		}
		//printf("%d ", (p + i)->start.x);
		fread(&(p + i)->start.y, sizeof(int), 1, f);
		if (spr != 1)
		{
			fclose(f);
			return 0;
		}
		//printf("%d ", (p + i)->start.y);
		fread(&(p + i)->end.x, sizeof(int), 1, f);
		if (spr != 1)
		{
			fclose(f);
			return 0;
		}
		//printf("%d ", (p + i)->end.x);
		fread(&(p + i)->end.y, sizeof(int), 1, f);
		if (spr != 1)
		{
			fclose(f);
			return 0;
		}
		//printf("%d \n", (p + i)->end.y);
	}
	if (N > 100)
	{
		fclose(f);
		return N;
	}
	fclose(f);
	return 1;
}
int save_segments_b(const char *filename, const struct segment_t* s, unsigned int N)	
{
	if (filename == NULL || s == NULL || N==0) return 0	;
	FILE *f;
	f = fopen(filename, "wb");
	if (f == NULL) return 0;
	fwrite(&N, sizeof(unsigned int), 1, f);
	int spr;
	//if (N > 100) N = 100;
	for (unsigned int i = 0; i < N; i++)
	{
		spr = fwrite(&(s + i)->start.x, sizeof(int), 1, f);
		if (spr != 1)
		{
			fclose(f);
			return 0;
		}
		spr=fwrite(&(s + i)->start.y, sizeof(int), 1, f);
		if (spr != 1)
		{
			fclose(f);
			return 0;
		}
		spr=fwrite(&(s + i)->end.x, sizeof(int), 1, f);
		if (spr != 1)
		{
			fclose(f);
			return 0;
		}
		spr=fwrite(&(s + i)->end.y, sizeof(int), 1, f);
		if (spr != 1)
		{
			fclose(f);
			return 0;
		}
	}

	fclose(f);
	return 1;
}
void swap(int *i, int *j) {
	int t = *i;
	*i = *j;
	*j = t;
}
int sort(struct segment_t *s, int N)
{
	if (s == NULL || N<=0) return 0;
	//										pierwszy x
	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j < N - i; j++)
		{
			if ((s + j - 1)->start.x > (s + j)->start.x)
			{
				swap(&(s + j - 1)->start.x, &(s + j)->start.x);
				swap(&(s + j - 1)->start.y, &(s + j)->start.y);
				swap(&(s + j - 1)->end.x, &(s + j)->end.x);
				swap(&(s + j - 1)->end.y, &(s + j)->end.y);
			}
		}
	}
	//											pierwszy y
	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j < N - i; j++)
		{
			if (((s + j - 1)->start.x ==(s + j)->start.x) && (s + j - 1)->start.y >(s + j)->start.y)
			{
				swap(&(s + j - 1)->start.x, &(s + j)->start.x);
				swap(&(s + j - 1)->start.y, &(s + j)->start.y);
				swap(&(s + j - 1)->end.x, &(s + j)->end.x);
				swap(&(s + j - 1)->end.y, &(s + j)->end.y);
			}
		}
	}
	//										drugi x
	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j < N - i; j++)
		{
			if ((s + j - 1)->start.x ==(s + j)->start.x && (s + j - 1)->start.y == (s + j)->start.y && (s + j - 1)->end.x < (s + j)->end.x)
			{
				swap(&(s + j - 1)->start.x, &(s + j)->start.x);
				swap(&(s + j - 1)->start.y, &(s + j)->start.y);
				swap(&(s + j - 1)->end.x, &(s + j)->end.x);
				swap(&(s + j - 1)->end.y, &(s + j)->end.y);
			}
		}
	}
	//									drugi y
	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j < N - i; j++)
		{
			if ((s + j - 1)->start.x == (s + j)->start.x && (s + j - 1)->start.y == (s + j)->start.y && (s + j - 1)->end.x == (s + j)->end.x && (s + j - 1)->end.y < (s + j)->end.y)
			{
				swap(&(s + j - 1)->start.x, &(s + j)->start.x);
				swap(&(s + j - 1)->start.y, &(s + j)->start.y);
				swap(&(s + j - 1)->end.x, &(s + j)->end.x);
				swap(&(s + j - 1)->end.y, &(s + j)->end.y);
			}
		}
	}
	return 1;
}
int main()
{
	struct segment_t segmenty[200];
	char sciezka[40];
	printf("podaj plik: ");
	scanf("%39s", sciezka);
	int counter = 0;
	unsigned int N=0;
	for (int i = 0; *(sciezka + i) != 0; i++)
	{
		counter++;
	}
	if (*(sciezka + --counter) != 'n')
	{
		printf("Couldn't create file");
		return 1;
	}
	if (*(sciezka + --counter) != 'i')
	{
		printf("Couldn't create file");
		return 1;
	}
	if (*(sciezka + --counter) != 'b')
	{
		printf("Couldn't create file");
		return 1;
	}
	if (*(sciezka + --counter) != '.')
	{
		printf("Couldn't create file");
		return 1;
	}
	int spr;
	FILE *f;
	f = fopen(sciezka, "rb");
	if (f == NULL)
	{
		printf("couldn't open file");
		return 1;
	}
	fread(&N, sizeof(unsigned int), 1, f);
	fclose(f);
	spr = load_segments_b(sciezka, segmenty, N);
	if (spr == 0 || spr==-2 || spr==-1)
	{
		printf("file corrupted");
		return 1;
	}
	if (N > 100) N = 100;
	spr = sort(segmenty, N);
	if (spr != 1)
	{
		printf("error");
		return 1;
	}
	spr = save_segments_b(sciezka, segmenty, N);
	if (spr != 1)
	{
		printf("error");
		return 1;
	}
	//system("PAUSE");
	printf("file saved");
	return 0;
}