#include "stdafx.h"	
#include <stdio.h>
#include <string.h>
//#include <Windows.h>
//==================================================================================
struct file_t
{
	FILE *f;
	int size;
};
//=====================================================================================
int open_file(struct file_t* f, const char *filename)
{
	if (filename == NULL || f == NULL) return 0;
	int counter = 0;
	/*for (int i = 0;*(filename+i)!=0; i++)
	{
		counter++;
	}*/
	counter = strlen(filename);
	if (*(filename + --counter) != 't' || *(filename + --counter) != 'x' || *(filename + --counter) != 't' || *(filename + --counter) != '.') return 0;
	f->f = fopen(filename, "at+");
	if (f->f == NULL) return 0;
	fseek(f->f, 0, SEEK_END);
	f->size = ftell(f->f);
	fseek(f->f, 0, SEEK_SET);

	return 1;
}
//================================================================================
struct file_t* find_min(const struct file_t* files, int size)
{
	if (files == NULL || size <= 0) return NULL;
	int counter = 0;
	int wielkosc = files->size;
	for (int j = 0; j<size; j++) {
		if ((files + j)->size<wielkosc) {
			wielkosc = (files + j)->size;
			counter = j;
		}
	}
	return (struct file_t*) files + counter;
}
//=======================================================================================================
void close_file(struct file_t* f)
{
	if (f != NULL && f->f != NULL) fclose(f->f);
}
//======================================================================================================
int main()
{
	struct file_t p[5];
	int i = 0, j = 0;
	char name[50], *ptr_name = name;

	printf(": ");
	for (;;) {
		j = 0;
		for (;;) {
			scanf("%c", ptr_name + j);
			if (*(ptr_name + j) == '\n') break;
			j++;
		}
		if (j == 0) break;
		*(ptr_name + j) = '\0';
		if (open_file(p + i, name)) i++;
		if (i == 5) break;
	}
	if (i == 0) {
		printf("Error");
		return 1;
	}
	
	int counter = i;
	struct file_t  *ptr;
	printf("wpisz dane: ");
	char tab[1000], *p_tab = tab;
	int size = 0;
	char znak = getchar();
	ptr = find_min(p, counter);
	if (znak != '\n') putc(znak, ptr->f);
	for (;;) {
		j = 0;
		for (;;) {
			scanf("%c", p_tab + j);
			if (*(p_tab + j) == '\n') break;
			j++;
		}

		if (j == 0) break;
		*(p_tab + j + 1) = '\0';
		size = strlen(p_tab);
		ptr = find_min(p, counter);
		fwrite(p_tab, sizeof(char), size, ptr->f);
		ptr->size = ptr->size + size;
	}
	for (i = 0; i < counter; i++)
	{
		close_file((p + i));
	}
	printf("Files saved");
	
	//system("PAUSE");
	return 0;
}
