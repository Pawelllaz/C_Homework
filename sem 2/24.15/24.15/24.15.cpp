#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <windows.h>
struct entry_t
{
	char name[20];
	char last_name[40];
	int number;
};

void display(const struct entry_t* p)
{
	if (p == NULL) return;
	printf("Name: %s\nLast name: %s\nPhone number: %d\n", p->name, p->last_name, p->number);
}
int load_phonebook_t(const char *filename, struct entry_t* p, int size)
{
	FILE *f;
	f = fopen(filename, "r");
	if (f == NULL) return -1;
	int counter = 0,x;
	char tym;
	for (int i = 0; i < size; i++)
	{
		for (int j=0;;j++)
		{
			x = fscanf(f, "%c", &tym);
			if (x != 1)
			{
				continue;
			}
			if (x == EOF) break;
			if (tym == ' ') continue;
			(p + i)->name[j] = tym;
		}
		x = fscanf(f, "%c", &tym);
		if (x == EOF) break;
		if (x != 1 || tym != '|') continue;
		x = fscanf(f, "%c", &tym);
		if (x == EOF) break;
		if (x != 1 || tym != ' ') continue;
		for (int j = 0;; j++)
		{
			x = fscanf(f, "%c", &tym);
			if (x == EOF) break;
			if (x != 1)
			{
				continue;
			}
			if ((p + i)->name[j] == ' ')
			{
				(p + i)->last_name[j] = tym;
				fscanf(f, "%c", &tym);
				if (tym == '|') continue;
				(p + i)->last_name[j] = tym;
			}
			(p + i)->last_name[j] = tym;
		}
		x = fscanf(f, "%c", &tym);
		if (x == EOF) break;
		if (x != 1 || tym != ' ') continue;
		int number;
		x = fscanf(f, "%d", &number);
		if (x == EOF) break;
		if (x != 1 || number<0) continue;
		(p + i)->number = number;
		counter++;
	}
	fclose(f);
	return counter;
}
const struct entry_t* find_by_last_name(const struct entry_t* p, int size, const char *name)
{
	if (p == NULL || name==NULL ) return NULL;
	for (int i = 0; i < size; i++)
	{
		if (strcmp((p + i)->last_name,name)==0)
		{
			return p + i;
		}
	}
	return NULL;
}
int main()
{
	int size;
	struct entry_t book[10];
	char sciezka[40],nazwisko[60];
	printf("wpisz: ");
	scanf("%39s", sciezka);
	printf("nazwisko: ");
	fgets(nazwisko, 60, stdin);
	scanf("%59s", nazwisko);
	size = load_phonebook_t(sciezka, book, 10);
	display(find_by_last_name(book, size, nazwisko));
	for (int i = 0; i < size; i++)
		display(book+i);
	system("PAUSE");
	return 0;
}