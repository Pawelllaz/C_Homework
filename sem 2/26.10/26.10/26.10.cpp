#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
//#include <Windows.h>

struct circular_buffer_t {
	int *ptr;
	int begin;
	int end;
	int capacity;
	unsigned char full : 1;
};
int empty(const struct circular_buffer_t *cb);
//==========================================================================================================
int create(struct circular_buffer_t *cb, int N)
{
	if (cb == NULL || N < 1) return 1;
	cb->ptr = (int*)malloc(sizeof(int)*N);
	if ((*cb).ptr == NULL) return 2;
	cb->begin = 0;
	cb->capacity = N;
	cb->end = 0;
	cb->full = 0;
	return 0;
}
//==========================================================================================================
int create_circular_buffer(struct circular_buffer_t **cb, int N)
{
	if (cb == NULL || N < 1) return 1;
	*cb = (struct circular_buffer_t*)malloc(sizeof(struct circular_buffer_t));
	if (*cb == NULL) return 2;
	if (create(*cb, N) != 0 || N > 2000)
	{
		free(*cb);
		return 2;
	}
	return 0;
}
//==========================================================================================================
void destroy(struct circular_buffer_t *cb)
{
	if (cb == NULL || cb->ptr==NULL) return;
	free(cb->ptr);
}
//==========================================================================================================
void destroy_circular_buffer(struct circular_buffer_t **cb)
{
	if (cb == NULL) return;
	free(*cb);
	destroy(*cb);
}
//==========================================================================================================
int push_back(struct circular_buffer_t *cb, int value)
{
	if (cb == NULL) return 1;
	//if (cb->begin > cb->end) return 1;
	if (cb->end > cb->capacity) return 1;
	if (cb->ptr == NULL) return 1;
	if (cb->begin > cb->capacity) return 1;
	if (cb->begin < 0 || cb->end < 0 || cb->capacity < 1) return 1;
	/*
	if (cb->full == 1)
	{
		cb->end = cb->end%cb->capacity;
		*(cb->ptr + cb->end++) = value;
		cb->begin++;
	}
	else
	{
		cb->end = cb->end%cb->capacity;
		*(cb->ptr + cb->end++) = value;
	}
	if (cb->end%cb->capacity == cb->begin)
	{
		cb->end %= cb->capacity;
		cb->full = 1;
	}*/
	if (cb->end >= cb->capacity) cb->end = 0;
	if (cb->full)
	{
		*(cb->ptr + cb->begin) = value;
		cb->begin++;
		if (cb->begin >= cb->capacity) cb->begin = 0;
	}
	if (!cb->full) *(cb->ptr + cb->end) = value;
	cb->end++;
	if (cb->end >= cb->capacity) cb->end = 0;
	if (cb->begin == cb->end) cb->full = 1;
	return 0;
}
//==========================================================================================================
int pop_front(struct circular_buffer_t *cb, int *err_code)
{
	/*if (cb == NULL) return 1;
	if (cb->begin > cb->end) return 1;
	if (cb->end > cb->capacity) return 1;
	if (cb->ptr == NULL) return 1;
	if (cb->begin > cb->capacity) return 1;
	if (cb->begin < 0 || cb->end < 0 || cb->capacity < 1) return 1;*/
	
	if (cb == NULL || cb->ptr == NULL ||  cb->end<0 || cb->begin>cb->capacity || cb->begin<0 || cb->capacity <1 ||  cb->end>cb->capacity) 
	{
		if (err_code != NULL) *err_code = 1;
		return 1;
	}
	int liczba;
	if (cb->end == 0 && cb->full == 0 && cb->begin == 0) 
	{
		if (err_code != NULL) *err_code = 2;
		return 2;
	}
	if (empty(cb)==1)
	{
		if (err_code != NULL) *err_code = 2;
		return 2;
	}
	liczba = *(cb->ptr + cb->begin);
	cb->begin++;
	if (cb->begin >= cb->capacity) cb->begin = 0;
	if (err_code != NULL) *err_code = 0;
	cb->full = 0;
	return liczba;
	/*
	liczba = *(cb->ptr + cb->begin);
	cb->begin++;
	if (cb->full == 1) cb->full = 0;
	cb->begin %= cb->capacity;
	return liczba;*/
}
//==========================================================================================================
int pop_back(struct circular_buffer_t *cb, int *err_code)
{
	if (cb == NULL || cb->ptr == NULL || cb->end<0 || cb->begin>cb->capacity || cb->begin<0 || cb->capacity <1 || cb->end>cb->capacity)
	{
		if (err_code != NULL) *err_code = 1;
		return 1;
	}
	if (empty(cb) == 1)
	{
		if (err_code != NULL) *err_code = 2;
		return 2;
	}
	cb->end--;
	if (cb->full) cb->full = 0;
	if (cb->end<0) cb->end = cb->capacity - 1;
	int liczba = *(cb->ptr + cb->end);
	return liczba;
	/*
	if (cb->end == 0 && cb->full == 0 && cb->begin == 0)
	{
		if (err_code != NULL) *err_code = 2;
		return 2;
	}
	cb->end--;
	if (cb->full == 1) cb->full = 0;
	if (cb->end < 0) cb->end = cb->capacity - 1;
	int liczba = *(cb->ptr + cb->end);
	if(err_code!=NULL) *err_code = 0;
	return liczba;*/
}
//==========================================================================================================
int empty(const struct circular_buffer_t *cb)
{
	if (cb == NULL) return -1;
	if (cb->full == 0 && cb->begin == cb->end) return 1;
	return 0;
}
//==========================================================================================================
int full(const struct circular_buffer_t *cb)
{
	if (cb == NULL) return -1;
	if (cb->full == 0) return 0;
	return 1;
}
//==========================================================================================================
void display(const struct circular_buffer_t *cb)
{
	if (cb == NULL || cb->ptr == NULL || cb->end<0 || cb->begin>cb->capacity || cb->begin < 0 || cb->capacity <1 || cb->end>cb->capacity) return;
	if (empty(cb)) return;
	/*
	if (cb->full) 
	{
		int j = cb->begin;
		for (int i = 0; i<cb->capacity; i++) 
		{
			if (j == cb->capacity) j = 0;
			printf("%d ", *(cb->ptr + j++));
		}
	}
	else 
	{
		int n = 0, k = cb->begin;
		if (cb->end<cb->begin) 
		{
			n += cb->capacity - cb->begin + cb->end;
		}
		if (cb->end>cb->begin) 
		{
			n += cb->end - cb->begin;
		}
		for (int i = 0; i<n; i++) 
		{
			if (k == cb->capacity) k = 0;
			printf("%d ", *(cb->ptr + k++));
		}
	}
	*/

	printf("%d ", *(cb->ptr + cb->begin));
	int i=0;
	if (cb->begin == cb->capacity - 1) i = 0;
	else i = cb->begin + 1;
	for (;; i = (i + 1) % cb->capacity)
	{
		if (i == cb->end) break;
		printf("%d ", *(cb->ptr + i));
	}
}
//==========================================================================================================
int main()
{
	printf("wielkosc buforu: ");
	int wielkosc;
	scanf("%d", &wielkosc);
	struct circular_buffer_t *buf;
	int spr = create_circular_buffer(&buf, wielkosc);
	if (spr == 1)
	{
		printf("Error");
		return 1;
	}
	else if (spr == 2)
	{
		printf("Failed to allocate memory");
		return 2;
	}
	int wybor,err;
	for (;;)
	{
		/*for (int i = 0; i < 9; i++)
		{
			printf("%d ", *(buf->ptr + i));
		}
		printf("\n");
		for (int i = 0; i < 9; i++)
		{
			if (i == buf->begin) printf("b ");
			else if (i == buf->end) printf("e ");
			else printf("|");
		}*/
		printf(": ");
		scanf("%d", &wybor);
		int wartosc;
		switch (wybor)
		{
		case 0:
			destroy_circular_buffer(&buf);
			return 0;
		case 1:
			printf("podaj wartosc: ");
			scanf("%d", &wartosc);
			push_back(buf, wartosc);
			break;
		case 2:
			if (empty(buf)) printf("Buffer is empty\n");
			else
			{
				wartosc = pop_back(buf, &err);
				printf("%d\n", wartosc);
			}
			break;
		case 3:
			if (empty(buf) == 1) printf("Buffer is empty\n");
			else printf("%d\n", pop_front(buf, &err));
			break;
		case 4:
			if (empty(buf) == 1) printf("Buffer is empty\n");
			else
			{
				display(buf);
				printf("\n");
			}
			break;
		case 5:
			empty(buf) == 1 ? printf("1\n") : printf("0\n");
			break;
		case 6:
			full(buf) == 1 ? printf("1\n") : printf("0\n");
			break;
		default:
			printf("Incorrect input\n");
			break;
		}
	}
	if(empty(buf)==0) destroy(buf);
	destroy_circular_buffer(&buf);
	//system("PAUSE");
	return 0;
}