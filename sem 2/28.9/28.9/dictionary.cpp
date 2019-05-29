#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dictionary.h"

struct dictionary_t* create_dictionary(int N)
{
	if (N < 1) return NULL;
	struct dictionary_t *dic;
	dic = (struct dictionary_t*)malloc(sizeof(struct dictionary_t));
	if (dic == NULL) return NULL;
	dic->wc = (struct word_count_t*)malloc(sizeof(struct word_count_t)*N);
	if (dic->wc == NULL)
	{
		free(dic);
		return NULL;
	}
	dic->capacity = N;
	dic->size = 0;
	return dic;
}

struct word_count_t* dictionary_find_word(const struct dictionary_t *d, const char *word)
{
	if (d == NULL || d->capacity < 1 || d->size < 1 || d->wc == NULL || word == NULL) return NULL;
	for (int i = 0; i < d->size; i++)
	{
		if (strcmp((d->wc + i)->word, word) == 0)
			return d->wc + i;
	}
	return NULL;
}

int dictionary_add_word(struct dictionary_t *d, const char *word)
{
	if (d == NULL || word == NULL || d->capacity <= 0 || d->size < 0 || d->wc == NULL) return 1;
	if (d->size == 0)
	{
		d->wc->word = (char *)malloc(strlen(word) + 1);
		strcpy(d->wc->word, word);
		d->wc->counter = 1;
		d->size++;
		return 0;
	}
	int x = 0, i;
	for (i = 0; i < d->size; i++) {
		if (strcmp((d->wc + i)->word, word) == 0) {
			(d->wc + i)->counter++;
			x = 1;
		}
	}
	if (x == 0) {
		if (d->size == d->capacity) {
			struct word_count_t *tym;
			tym = (struct word_count_t*)realloc(d->wc, d->capacity * 2 * sizeof(struct word_count_t));
			if (tym == NULL) return 2;
			d->capacity *= 2;
			d->wc = tym;
		}
		(d->wc + i)->word = (char*)malloc(strlen(word) + 1);
		if ((d->wc + i)->word == NULL) return 2;
		strcpy((d->wc + i)->word, word);
		(d->wc + i)->counter = 1;
		d->size++;
	}
	return 0;
}

void dictionary_display(const struct dictionary_t *d)
{
	if (d == NULL || d->capacity < 1 || d->size < 1 || d->wc == NULL || d->capacity<d->size) return;
	for (int i = 0; i < d->size; i++)
	{
		printf("%s %d\n", (d->wc + i)->word, (d->wc + i)->counter);
	}
}

void destroy_dictionary(struct dictionary_t **d)
{
	if (d == NULL) return;
	for (int i = 0; i < (*d)->size; i++)
	{
		if (((*d)->wc + i)->word != NULL) free(((*d)->wc + i)->word);
	}
	free((*d)->wc);
	free((*d));

}

int create(struct array_t *a, int N)
{
	if (N < 1 || a == NULL) return 1;

	a->ptr = (float*)malloc(sizeof(float) * N);
	if ((a->ptr) == NULL)
	{
		destroy(a);
		return 2;
	}
	a->capacity = N;
	a->size = 0;
	return 0;
}

int create_array(struct array_t **a, int N)
{
	if (N < 1 || a == NULL) return 1;
	if (N > 100) return 2;

	*a = (struct array_t*)malloc(sizeof(struct array_t));
	if (*a == NULL) return 2;

	if (create(*a, N) != 0)
	{
		destroy_array(a);
		return 2;
	}
	return 0;
}

void destroy_array(struct array_t **a)
{
	if (a != NULL)
	{
		destroy(*a);
		free(*a);
	}
}

void destroy(struct array_t *a)
{
	if (a != NULL) free(a->ptr);
}

int remove_no_letter(char *word)
{
	if (word == NULL) return 1;

	for (int i = 0; *(word + i) != '\0'; i++)
	{
		while (!((*(word + i) >= 'a' && *(word + i) <= 'z') || (*(word + i) >= 'A' && *(word + i) <= 'Z') || *(word + i) == '\0'))
		{
			for (int j = i;; j++)
			{
				if (*(word + j) == '\0')
				{
					*(word + j) = '\0';
					break;
				}
				*(word + j) = *(word + j + 1);
			}
		}
	}
	return 0;
}

float dot_product(const struct array_t *a, const struct array_t *b)
{
	if (a == NULL || a->ptr == NULL || a->capacity < 1 || a->size < 1) return -1;
	if (b == NULL || b->ptr == NULL || b->capacity < 1 || b->size < 1) return -1;
	if (a->size != b->size) return -1;
	if (b->capacity != a->capacity) return -1;

	float score = 0;
	int i, j;

	if (a->size >= b->size)
	{
		for (i = 0; i < b->size; i++)
		{
			score += *(a->ptr + i) * *(b->ptr + i);
		}

		for (j = i; j < a->size; j++)
		{
			score += *(a->ptr + j);
		}
	}
	else
	{
		for (i = 0; i < a->size; i++)
		{
			score += *(a->ptr + i) * *(b->ptr + i);
		}

		for (j = i; j < b->size; j++)
		{
			score += *(b->ptr + j);
		}
	}
	return score;
}

int add(struct array_t *a, float value)
{
	if (a == NULL || a->ptr == NULL || a->size < 0 || a->capacity < 1) return 1;
	if (a->size != a->capacity)
	{
		*(a->ptr + a->size) = value;
		a->size++;
	}
	else return 2;
	return 0;
}

float length(const struct array_t *a)
{
	if (a == NULL || a->ptr == NULL || a->capacity < 1 || a->size < 1) return -1;
	if (a->size > a->capacity) return -1;

	float sum = 0, l = 0;
	for (int i = 0; i < a->size; i++)
	{
		sum += (*(a->ptr + i) * *(a->ptr + i));
	}
	l = sqrt(sum);
	return l;
}