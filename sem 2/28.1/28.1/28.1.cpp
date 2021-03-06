#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
int zamiana(char a)
{
	if (a == '0') return 0;
	if (a == '1') return 1;
	if (a == '2') return 2;
	if (a == '3') return 3;
	if (a == '4') return 4;
	if (a == '5') return 5;
	if (a == '6') return 6;
	if (a == '7') return 7;
	if (a == '8') return 8;
	if (a == '9') return 9;
	return 0;
}
//============================================================================================
struct student_t
{
	char *name;
	char *surname;
	int index;
};
//=========================================================================================
struct student_t* read(int *err_code)
{
	struct student_t *p;
	p = (struct student_t*)malloc(sizeof(struct student_t));
	if (p == NULL)
	{
		if (err_code != NULL) *err_code = 1;
		return NULL;
	}
	p->name = (char*)malloc(20);
	if (p->name == NULL)
	{
		if (err_code != NULL) *err_code = 1;
		free(p);
		return NULL;
	}
	p->surname = (char*)malloc(40);
	if (p->surname == NULL)
	{
		if (err_code != NULL) *err_code = 1;
		free(p->name);
		free(p);
		return NULL;
	}
	p->index = 0;
	char tym;
	int spr = 0;
	printf("Podej dane: ");
	for (int i = 0;; i++)
	{
		spr = scanf("%c", &tym);
		if (spr != 1)
		{
			if (err_code != NULL) *err_code = 2;
			free(p->name);
			free(p->surname);
			free(p);
			return p;
		}
		if (tym == ',')
		{
			spr = 0;
			*((*p).name + i) = '\0';
			break;
		}
		else spr++;
		if ((tym >= 'a' && tym <= 'z') || (tym >= 'A' && tym <= 'Z')) *((*p).name + i) = tym;
		if (err_code != NULL) *err_code = 2;
		if (tym == '\n') break;
	}
	if (spr != 0)
	{
		if (err_code != NULL) *err_code = 2;
		free(p->name);
		free(p->surname);
		free(p);
		return p;
	}
	for (int i = 0;; i++)
	{
		scanf("%c", &tym);
		if (tym == ',')
		{
			spr = 0;
			*((*p).surname + i) = '\0';
			break;
		}
		else spr++;
		if ((tym >= 'a' && tym <= 'z') || (tym >= 'A' && tym <= 'Z') || tym == '-' || (tym == ' ' && i != 0)) *((*p).surname + i) = tym;
		else i--;
		if (err_code != NULL) *err_code = 2;
		if (tym == '\n') break;
	}
	if (spr != 0)
	{
		if (err_code != NULL) *err_code = 2;
		free(p->name);
		free(p->surname);
		free(p);
		return p;
	}
	int liczba;
	spr = scanf("%d", &liczba);
	if (spr != 1)
	{
		if (err_code != NULL) *err_code = 2;
		free(p->name);
		free(p->surname);
		free(p);
		return p;
	}
	p->index = liczba;
	if (err_code != NULL) *err_code = 0;
	return p;
}
//==================================================================================
void destroy(struct student_t **s)
{
	if (s == NULL||(*s)->name==NULL||(*s)->surname==NULL) return;
	free((*s)->name);
	free((*s)->surname);
	free(*s);
}
//======================================================================================
void show(const struct student_t* p)
{
	if (p == NULL|| p->name == NULL || p->surname == NULL) return;
	printf("%s %s, %d", p->name, p->surname, p->index);
}
//==============================================================================================
int main()
{
	struct student_t *student;
	int err;
	student=read(&err);
	if (err == 0) show(student);
	else if(err==1)
	{
		printf("error");
		return err;
	}
	else if (err == 2)
	{
		printf("error");
		return err;
	}
	destroy(&student);
	//_getch();
	return 0;
}