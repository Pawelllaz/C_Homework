#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h>

struct image_t {
	char type[3];
	int **ptr;
	int width;
	int height;
};
void destroy_image(struct image_t **m);
//==================================================================================================
struct image_t* load_image_t(const char *filename, int *err_code)
{
	if (filename == NULL)
	{
		if (err_code != NULL) *err_code = 1;
		return NULL;
	}
	FILE *f;
	f = fopen(filename, "r");
	if (f == NULL)
	{
		if (err_code != NULL) *err_code = 2;
		return NULL;
	}
	struct image_t *img;
	img = (struct image_t*)malloc(sizeof(struct image_t));
	if (img == NULL)
	{
		if (err_code != NULL) *err_code = 4;
		fclose(f);
		return NULL;
	}
	fscanf(f, "%2s", img->type);
	if ((*(img->type) != 'P' || *(img->type + 1) != '2'))
	{
		if (err_code != NULL) *err_code = 3;
		fclose(f);
		free(img);
		return NULL;
	}
	int spr = fscanf(f, "%d %d", &img->width, &img->height);
	//printf("%d %d\n", img->width, img->height);
	if (spr != 2)
	{
		if (err_code != NULL) *err_code = 3;
		fclose(f);
		free(img);
		return NULL;
	}
	img->ptr = (int**)malloc(sizeof(int*)*img->height);
	if (img->ptr == NULL)
	{
		if (err_code != NULL) *err_code = 4;
		free(img);
		fclose(f);
		return NULL;
	}
	for (int i = 0; i<img->height; i++)
	{
		*(img->ptr + i) = (int*)malloc(sizeof(int)*img->width);
		if (*(img->ptr + i) == NULL)
		{
			for (int j = 0; j <= i; j++)
			{
				free(*(img->ptr + j));
			}
			free(img->ptr);
			if (err_code != NULL) *err_code = 4;
			free(img);
			fclose(f);
			return NULL;
		}
	}
	int max;
	spr = fscanf(f, "%d", &max);
	if (spr != 1)
	{
		if (err_code != NULL) *err_code = 3;
		destroy_image(&img);
		fclose(f);
		return NULL;
	}
	for (int i = 0; i<img->height; i++)
		for (int j = 0; j<img->width; j++)
		{
			spr = fscanf(f, "%d", (*(img->ptr + i) + j));
			if (spr != 1)
			{
				if (err_code != NULL) *err_code = 3;
				fclose(f);
				destroy_image(&img);
				return NULL;
			}
		}
	if (err_code != NULL)
		*err_code = 0;
	fclose(f);
	return img;
}
//====================================================================================================
int save_image_t(const char * filename, const struct image_t *m1)
{
	if (filename == NULL || m1 == NULL || m1->ptr == NULL) return 1;
	if (m1->height < 1 || m1->width < 1) return 1;
	FILE *f;
	f = fopen(filename, "w");
	if (f == NULL) return 2;

	fprintf(f, "P2\n%d %d\n%d\n", m1->width, m1->height, 255);
	for (int i = 0; i < m1->height; i++)
	{
		for (int j = 0; j < m1->width; j++)
			fprintf(f, "%3d ", *(*(m1->ptr + i) + j));
		fprintf(f, "\n");
	}
	fclose(f);
	return 0;
}
//===================================================================================================
void destroy_image(struct image_t **m)
{
	if (m == NULL || (*m)->height < 1 || (*m)->width < 1 || (*m)->ptr == NULL) return;

	for (int i = 0; i < (*m)->height; i++)
	{
		if (*((*m)->ptr + i) == NULL) return;
		free(*((*m)->ptr + i));
	}
	if ((*m)->ptr != NULL) free((*m)->ptr);
	free(*m);
}
//======================================================================================================
int draw_image(struct image_t *img, const struct image_t *src, int destx, int desty)
{
	if (img == NULL || src == NULL || src->ptr == NULL || img->ptr == NULL || destx < 0 || desty < 0) return 1;
	if (src->height + desty > img->height || src->width + destx > img->width) return 1;
	int x = 0, y = 0;
	for (int i = desty; i < (desty + src->height); i++)
	{
		for (int j = destx; j < (destx + src->width); j++)
		{
			*(*(img->ptr + i) + j) = *(*(src->ptr + y) + x++);
		}
		x = 0;
		y++;
	}
	return 0;
}
//======================================================================================================
int main()
{
	char *nazwa_pliku1, *nazwa_pliku2;
	int err;
	nazwa_pliku1 = (char*)malloc(30 * sizeof(char));
	if (nazwa_pliku1 == NULL)
	{
		printf("Failed to allocate memory");
		return 4;
	}
	printf("nazwa pliku: ");
	scanf("%29s", nazwa_pliku1);

	struct image_t *img1, *img2;
	img1 = load_image_t(nazwa_pliku1, &err);
	if (err == 2)
	{
		printf("File not found");
		free(nazwa_pliku1);
		return 2;
	}
	else if (err == 3)
	{
		printf("File corrupted");
		free(nazwa_pliku1);
		return 3;
	}
	else if (err == 4)
	{
		printf("Failed to allocate memory");
		free(nazwa_pliku1);
		return 4;
	}
	int ilosc, spr;
	printf("podaj ilosc plikow: ");
	spr = scanf("%d", &ilosc);
	if (ilosc<1 || spr != 1)
	{
		printf("Incorrect input");
		destroy_image(&img1);
		free(nazwa_pliku1);
		return 1;

	}
	nazwa_pliku2 = (char*)malloc(30 * sizeof(char));
	if (nazwa_pliku2 == NULL)
	{
		printf("Failed to allocate memory");
		free(nazwa_pliku1);
		destroy_image(&img1);
		return 4;
	}
	int destx, desty;
	for (int i = 0; i<ilosc; i++)
	{
		printf("nazwa pliku narysowanego: ");
		scanf("%29s", nazwa_pliku2);
		img2 = load_image_t(nazwa_pliku2, &err);
		if (err == 2)
		{
			printf("File not found\n");
			/*free(nazwa_pliku1);
			free(nazwa_pliku2);
			destroy_image(&img1);
			return 2;*/
			continue;
		}
		else if (err == 3)
		{
			printf("File corrupted\n");
			/*free(nazwa_pliku1);
			free(nazwa_pliku2);
			destroy_image(&img1);
			return 3;*/
			continue;
		}
		else if (err == 4)
		{
			printf("Failed to allocate memory");
			free(nazwa_pliku1);
			free(nazwa_pliku2);
			destroy_image(&img1);
			return 4;
		}
		printf("x i y: ");
		spr = scanf("%d %d", &destx, &desty);
		if (spr != 2)
		{
			printf("Incorrect input\n");
		}
		spr = draw_image(img1, img2, destx, desty);
		if (spr == 1)
		{
			printf("Incorrect input\n");
		}
		destroy_image(&img2);
	}

	for (int i = 0; *(nazwa_pliku1 + i) != 0; i++)
	{
		*(nazwa_pliku2 + i) = *(nazwa_pliku1 + i);
		if (*(nazwa_pliku1 + i + 1) == '.' && *(nazwa_pliku1 + i + 2) == 't' &&*(nazwa_pliku1 + i + 3) == 'x' &&*(nazwa_pliku1 + i + 4) == 't')
		{
			*(nazwa_pliku2 + i + 1) = '\0';
			strcat(nazwa_pliku2, "_modified.txt"); 
			break;
		}
		/*else if (*(nazwa_pliku1 + i + 1) == '.' && *(nazwa_pliku1 + i + 2) == 'b' &&*(nazwa_pliku1 + i + 3) == 'm' &&*(nazwa_pliku1 + i + 4) == 'p')
		{
		*(nazwa_pliku1 + i + 1) = '_';
		*(nazwa_pliku1 + i + 2) = 'm';
		*(nazwa_pliku1 + i + 3) = 'o';
		*(nazwa_pliku1 + i + 4) = 'd';
		*(nazwa_pliku1 + i + 5) = 'i';
		*(nazwa_pliku1 + i + 6) = 'f';
		*(nazwa_pliku1 + i + 7) = 'i';
		*(nazwa_pliku1 + i + 8) = 'e';
		*(nazwa_pliku1 + i + 9) = 'd';
		*(nazwa_pliku1 + i + 10) = '.';
		*(nazwa_pliku1 + i + 11) = 't';
		*(nazwa_pliku1 + i + 12) = 'x';
		*(nazwa_pliku1 + i + 13) = 't';
		*(nazwa_pliku1 + i + 14) = '\0';
		break;
		}*/
	}

	spr = save_image_t(nazwa_pliku2z, img1);
	if (spr == 0) printf("File saved");
	else
	{
		printf("Couldn't save file");
		destroy_image(&img1);
		free(nazwa_pliku1);
		free(nazwa_pliku2);
		return 2;
	}

	destroy_image(&img1);
	free(nazwa_pliku1);
	free(nazwa_pliku2);
	//_getch();
	return 0;
}