#include "stdafx.h"
#include <stdio.h>


struct date_t
{
	int day;
	int month;
	int year;
};
//=========================================================================================
struct date_t* set_date(struct date_t* d, int day, int month, int year, int *err_code)
{
	if (d == NULL)
	{
		if (err_code != NULL) *err_code = 1;
		return NULL;
	}

	d->day = day;
	d->month = month;
	d->year = year;

	if (err_code != NULL) *err_code = 0;
	return d;
}
//==========================================================================================
void show(const struct date_t* d)
{
	if (d == NULL) return;
	printf("%d-%d-%d", d->day, d->month, d->year);
}
//========================================================================================
struct date_t* read(struct date_t* d, int *err_code)
{
	if (d == NULL)
	{
		if (err_code != NULL) *err_code = 1;
		return NULL;
	}
	int spr = 0;
	spr = scanf("%d-%d-%d", &d->day, &d->month, &d->year);
	if (spr!=3) 
	{
		*err_code = 1;
		return NULL;
	}
	if (err_code != NULL) *err_code = 0;
	return d;
}
//=======================================================================================
int validate(const struct date_t* d)
{
	if (d == NULL) return -1;
	if (d->day <= 0 || d->day > 31) return 0;
	if (d->month <= 0 || d->month > 12) return 0;
	if ((d->month == 4 || d->month == 6 || d->month == 9 || d->month == 11) && d->day > 30) return 0;
	if (d->year%4!=0 && d->month == 2 && d->day > 28) return 0;
	return 1;
}
//=======================================================================================
int main()
{
	int err = 0;
	struct date_t data;
	printf("podaj date: ");
	read(&data, &err);
	if (err)
	{
		printf("Incorrect input");
		return 1;
	}
	if (validate(&data))
	{
		printf("podana data to: ");
		show(&data);
		printf("\nCorrect");
	}
	else
	{
		printf("Incorrect");
	}	

	return 0;
}