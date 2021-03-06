#include "stdafx.h"
#include <stdio.h>
//#include <Windows.h>
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
struct student_t
{
	char name[20];
	char surname[40];
	int index;
	char field[50];
	char faculty[80];
	int year;
};
struct student_t* read(struct student_t* p, int *err_code)
{
	if (p == NULL)
	{
		if(err_code!=NULL) *err_code = 1;
		return p;
	}
	p->index = 0;
	char tym;
	int spr = 0;
	printf("Mickiewicz\n");
	for (int i = 0;; i++)
	{
		spr = scanf("%c", &tym);
		if (spr != 1)
		{
			if (err_code != NULL) *err_code = 1;
			return p;
		}
		if (tym == ',')
		{
			spr = 0;
			*((*p).name + i) = 0;
			break;
		}
		else spr++;
		if ((tym >= 'a' && tym <= 'z') || (tym >= 'A' && tym <= 'Z') || tym=='.') *((*p).name + i) = tym;
		if (err_code != NULL) *err_code = 2;
		if (tym == '\n') break;
	}
	if (spr != 0)
	{
		if (err_code != NULL) *err_code = 1;
		return p;
	}
	for (int i = 0;; i++)
	{
		scanf("%c", &tym);
		if (tym == ',')
		{
			spr = 0;
			*((*p).surname + i) = 0;
			break;
		}
		else spr++;
		if ((tym >= 'a' && tym <= 'z') || (tym >= 'A' && tym <= 'Z') || tym == '-' || (tym == ' ' && i != 0) || tym=='.') *((*p).surname + i) = tym;
		else i--;
		if (err_code != NULL) *err_code = 3;
		if (tym == '\n') break;
	}
	if (spr != 0)
	{
		if (err_code != NULL) *err_code = 2;
		return p;
	}
	for (;;)
	{
		scanf("%c", &tym);
		if (tym == '\n')
		{
			if (err_code != NULL) *err_code = 3;
			return p;
		}
		if (tym == ' ') break;
	}
	int liczba;
	scanf("%c", &tym);
	if (tym == '\n')
	{
		if (err_code != NULL) *err_code = 3;
		return p;
	}
	else
	{
		spr = scanf("%d", &liczba);
		if (spr != 1)
		{
			if (err_code != NULL) *err_code = 1;
			return p;
		}
		p->index = liczba;
		liczba = 100000 * zamiana(tym);
		p->index += liczba;
	}
	for (;;)
	{
		scanf("%c", &tym);
		if (tym == ' ') break;
		if (tym == '\n')
		{
			if (err_code != NULL) *err_code = 4;
			return p;
		}
	}
	for (int i = 0;; i++)
	{
		scanf("%c", &tym);
		if (tym == ',')
		{
			spr = 0;
			*((*p).field + i) = 0;
			break;
		}
		else spr++;
		if ((tym >= 'a' && tym <= 'z') || (tym >= 'A' && tym <= 'Z') || tym == '-' || (tym == ' ' && i != 0)) *((*p).field + i) = tym;
		else i--;
		if (err_code != NULL) *err_code = 5;
		if (tym == '\n') break;
	}
	if (spr != 0)
	{
		if(err_code!=NULL) *err_code = 4;
		return p;
	}
	for (;;)
	{
		scanf("%c", &tym);
		if (tym == ' ') break;
		if (tym == '\n')
		{
			if (err_code != NULL) *err_code = 5;
			return p;
		}
	}
	for (int i = 0;; i++)
	{
		scanf("%c", &tym);
		if (tym == ',')
		{
			spr = 0;
			*((*p).faculty + i) = 0;
			break;
		}
		else spr++;
		if ((tym >= 'a' && tym <= 'z') || (tym >= 'A' && tym <= 'Z') || tym == '-' || (tym == ' ' && i != 0)) *((*p).faculty + i) = tym;
		else i--;
		if (err_code != NULL) *err_code = 6;
		if (tym == '\n') break;
	}
	if (spr != 0)
	{
		if (err_code != NULL) *err_code = 5;
		return p;
	}
	spr = scanf("%d", &liczba);
	if (spr != 1)
	{
		if (err_code != NULL) *err_code = 1;
		return p;
	}
	p->year = liczba;
	if (err_code != NULL) *err_code = 0;
	return p;

}
//==========================================================================
struct student_t* set_name(struct student_t* student, const char * name, int *err_code)
{
	if (student == NULL || name == NULL)
	{
		if (err_code != NULL) *err_code = 1;
		return student;
	}
	for (int i = 0;; i++)
	{
		if (*(name + i) == 0 || *(name + i) == '\n')
		{
			*((*student).name + i) = 0;
			break;
		}
		if (i == 19)
		{
			if (err_code != NULL) *err_code = 1;
			return student;
		}
		*((*student).name + i) = *(name + i);
	}
	if (err_code != NULL) *err_code = 0;
	return student;
}
struct student_t* set_surname(struct student_t* student, const char * surname, int *err_code)
{
	if (student == NULL || surname == NULL)
	{
		if (err_code != NULL) *err_code = 1;
		return student;
	}
	for (int i = 0;; i++)
	{
		if (*(surname + i) == 0 || *(surname + i) == '\n')
		{
			*((*student).surname + i) = 0;
			break;
		}
		if (i == 39)
		{
			if (err_code != NULL) *err_code = 1;
			return student;
		}
		*((*student).surname + i) = *(surname + i);
	}
	if (err_code != NULL) *err_code = 0;
	return student;
}
struct student_t* set_field(struct student_t* student, const char * field, int *err_code)
{
	if (student == NULL || field == NULL)
	{
		if (err_code != NULL) *err_code = 1;
		return student;
	}
	for (int i = 0;; i++)
	{
		if (*(field + i) == 0 || *(field + i) == '\n')
		{
			*((*student).field + i) = 0;
			break;
		}       if (i == 49)
		{
			if (err_code != NULL) *err_code = 1;
			return student;
		}
		*((*student).field + i) = *(field + i);
	}
	if (err_code != NULL) *err_code = 0;
	return student;
}
struct student_t* set_faculty(struct student_t* student, const char * faculty, int *err_code)
{
	if (student == NULL || faculty == NULL)
	{
		if (err_code != NULL) *err_code = 1;
		return student;
	}
	for (int i = 0;; i++)
	{
		if (*(faculty + i) == 0 || *(faculty + i) == '\n')
		{
			*((*student).faculty + i) = 0;
			break;
		}
		if (i == 79)
		{
			if (err_code != NULL) *err_code = 1;
			return student;
		}
		*((*student).faculty + i) = *(faculty + i);
	}
	if (err_code != NULL) *err_code = 0;
	return student;
}
struct student_t* set_year(struct student_t* student, int year, int *err_code)
{
	if (student == NULL)
	{
		if (err_code != NULL) *err_code = 1;
		return student;
	}
	student->year = year;
	if (err_code != NULL) *err_code = 0;
	return student;
}
struct student_t* set_index(struct student_t* student, int index, int *err_code)
{
	if (student == NULL)
	{
		if (err_code != NULL) *err_code = 1;
		return student;
	}
	student->index = index;
	if (err_code != NULL) *err_code = 0;
	return student;
}
//===================================================================================
struct student_t* set(struct student_t* student, const char * name,
	const char * surname, int index,
	const char * field, const char * faculty,
	int year, int *err_code)
{
	if (student == NULL || name == NULL || surname == NULL || field == NULL || faculty == NULL)
	{
		if (err_code != NULL) *err_code = 1;
		return student;
	}
	for (int i = 0;; i++)
	{
		if (*(name + i) == 0 || *(name + i) == '\n')
		{
			*((*student).name + i) = 0;
			break;
		}
		if (i == 19)
		{
			if (err_code != NULL) *err_code = 1;
			return student;
		}
		*((*student).name + i) = *(name + i);
	}
	for (int i = 0;; i++)
	{
		if (*(surname + i) == 0 || *(surname + i) == '\n')
		{
			*((*student).surname + i) = 0;
			break;
		}
		if (i == 39)
		{
			if (err_code != NULL) *err_code = 1;
			return student;
		}
		*((*student).surname + i) = *(surname + i);
	}
	for (int i = 0;; i++)
	{
		if (*(field + i) == 0 || *(field + i) == '\n')
		{
			*((*student).field + i) = 0;
			break;
		}       if (i == 49)
		{
			if (err_code != NULL) *err_code = 1;
			return student;
		}
		*((*student).field + i) = *(field + i);
	}
	for (int i = 0;; i++)
	{
		if (*(faculty + i) == 0 || *(faculty + i) == '\n')
		{
			*((*student).faculty + i) = 0;
			break;
		}
		if (i == 79)
		{
			if (err_code != NULL) *err_code = 1;
			return student;
		}
		*((*student).faculty + i) = *(faculty + i);
	}
	student->year = year;
	student->index = index;
	if (err_code != NULL) *err_code = 0;
	return student;
}
//=================================================================================
void display(const struct student_t* p)
{
	if (p == NULL) return;
	if (*p->field == 'a' || *p->field == 'A' || *p->field == 'e' || *p->field == 'E' || *p->field == 'i' || *p->field == 'I' || *p->field == 'o' || *p->field == 'O' || *p->field == 'u' || *p->field == 'U' || *p->field == 'Y' || *p->field == 'y')
		printf("%s %s, index number: %d, was an %s student at the %s in %d.", p->name, p->surname, p->index, p->field, p->faculty, p->year);
	else printf("%s %s, index number: %d, was a %s student at the %s in %d.", p->name, p->surname, p->index, p->field, p->faculty, p->year);
}
//=============================================================================================
void display_name(const struct student_t* student)
{
	if (student == NULL) return;
	printf("Student name: %s\n", student->name);
}
void display_surname(const struct student_t* student)
{
	if (student == NULL) return;
	printf("Student surname: %s\n", student->surname);
}
void display_field(const struct student_t* student)
{
	if (student == NULL) return;
	printf("Field: %s\n", student->field);
}
void display_faculty(const struct student_t* student)
{
	if (student == NULL) return;
	printf("Faculty: %s\n", student->faculty);
}
void display_year(const struct student_t* student)
{
	if (student == NULL) return;
	printf("Year: %d\n", student->year);
}
void display_index(const struct student_t* student)
{
	if (student == NULL) return;
	printf("Index: %d\n", student->index);
}
//==================================================================================================
int main()
{
	struct student_t student1, student2;
	int err;
	read(&student1, &err);
	if (err == 0) display(&student1);
	else
	{
		printf("Error\nerror?");
		return err;
	}
	printf("\n");
	set_name(&student2, "Pawel", &err);
	if (err)
	{
		printf("error");
		return err;
	}
	set_surname(&student2, "Lazicki", &err);
	if (err)
	{
		printf("error");
		return err;
	}
	set_field(&student2, "Informatyka", &err);
	if (err)
	{
		printf("error");
		return err;
	}
	set_faculty(&student2, "Weeia", &err);
	if (err)
	{
		printf("error");
		return err;
	}
	set_index(&student2, 215801, &err);
	if (err)
	{
		printf("error");
		return err;
	}
	set_year(&student2, 2017, &err);
	if (err)
	{
		printf("error");
		return err;
	}
	display(&student2); printf("\n");
	display_name(&student1);
	display_surname(&student1);
	display_index(&student1);
	display_field(&student1);
	display_faculty(&student1);
	display_year(&student1);

	//system("PAUSE");
	return 0;
}