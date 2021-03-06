#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
//#include <Windows.h>
#include <time.h>
#include <math.h>
struct point_t {
	int x;
	int y;
};
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
//======================================
   
void show(const struct point_t* p)
{
	if (p == NULL) return;
    printf("x = %d; y = %d\n", (*p).x, p->y);
}
//============================================
struct point_t* set(struct point_t* p, int x, int y)
{
	if (p == NULL) return NULL;
	p->x = x;
	p->y = y;
	return p;
}
//=============================================================================
int save_point_b(const char *filename, const struct point_t* p)
{
	if (filename == NULL || p == NULL) return 0;

	FILE *f;
	f = fopen(filename, "wb");
	if (f == NULL) return 0;
	fwrite(&p->x, sizeof(int), 1, f);
	fwrite(&p->y, sizeof(int), 1, f);
	fclose(f);
	printf("File saved");
	return 1;
}
//=============================================================================
int load_point_b(const char *filename, struct point_t* p)
{
	if (filename == NULL || p == NULL) return 0;
	FILE *f;
	f = fopen(filename, "rb");
	if (f == NULL) return 0;
	fread(&p->x, sizeof(int), 1, f);
	fread(&p->y, sizeof(int), 1, f);
	fclose(f);
	return 1;
}
//=============================================================================
int save_point_t(const char *filename, const struct point_t* p)
{
	if (filename == NULL || p == NULL) return 0;
	
	FILE *f;
	f = fopen(filename, "w");
	if (f == NULL) return 0;

	fprintf(f,"%d %d", p->x, p->y);
	fclose(f);
	printf("File saved");
	return 1;
}
//============================================================================
int load_point_t(const char *filename, struct point_t* p)
{
	if (filename == NULL || p == NULL) return 0;
	FILE *f;
	f = fopen(filename, "r");
	if (f == NULL) return 0;
	int x, y;
	fscanf(f, "%d %d", &x, &y);
	set(p, x, y);
	fclose(f);
	return 1;
}
//=============================================================================
int main()
{
	struct point_t p;
	srand(time(NULL));			
	set(&p, rand() % 100, rand() % 100);
	show(&p);
	char sciezka[30];
	scanf("%29s", sciezka);
	char file;
	for (int i=0;;i++)
	{
		if (*(sciezka + i) == '.' && *(sciezka + i + 1) == 't' && *(sciezka + i + 2) == 'x' && *(sciezka + i + 3) == 't')
		{
			file = 't';
			break;
		}
		if (*(sciezka + i) == '.' && *(sciezka + i + 1) == 'b' && *(sciezka + i + 2) == 'i' && *(sciezka + i + 3) == 'n')
		{
			file = 'b';
			break;
		}
		if(*(sciezka+i)=='\0')
		{
			file = 'e';
			break;
		}
	}
	if (file == 'e')
	{
		printf("Wrong filename!");
		return 1;
	}

	
	if (file == 't')
	{
		if (save_point_t(sciezka, &p) == 0)
		{
			printf("Couldn't create file");
			return 1;
		}
	}
	else if (file == 'b')
	{
		if (save_point_b(sciezka, &p) == 0)
		{
			printf("Couldn't create file");
			return 1;
		}	
	}
	printf("\nCzy chcesz wczytac plik?\n");
	char czy_chce;	
	scanf("%c", &czy_chce);
	scanf("%c", &czy_chce);
	if (czy_chce == 'n' || czy_chce == 'N')
	{
		return 0;
	}
	else if(czy_chce=='y' || czy_chce=='Y')
	{
		if (file == 'b')
		{
			int spr = load_point_b(sciezka, &p);
			if (spr)show(&p);
			else
			{
				printf("File corrupted");
				return 1;
			}
		}
		else if (file == 't')
		{
			int spr = load_point_t(sciezka, &p);
			if(spr) show(&p);
			else
			{
				printf("File corrupted");
				return 1;
			}
		}
	}
	

	//system("PAUSE");
	return 0;
}