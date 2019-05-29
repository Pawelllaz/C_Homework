#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"

struct dictionary_t* create_dictionary(int N)
{
	if (N < 1) return NULL;

	struct dictionary_t *dic;
	dic = (struct dictionary_t*)malloc(sizeof(struct dictionary_t));
	//printf("int: %d wskaznik na word_count: %d wskaznik na word: %d\n", sizeof(dic->capacity), sizeof(dic->wc),sizeof(dic->wc->word));
	//printf("%li\n", sizeof(struct dictionary_t));
	if (dic == NULL) return NULL;
	dic->wc = (struct word_count_t*)malloc(sizeof(struct word_count_t)*N);
	//printf("int: %d wskaznik na word_count: %d wskaznik na word: %d\n", sizeof(dic->capacity), sizeof(dic->wc), sizeof(dic->wc->word));

	//printf("%li\n", sizeof(struct word_count_t)*N);
	if (dic->wc == NULL)
	{
		free(dic);
		return NULL;
	}/*
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		//printf("debug\n");
		(dic->wc + i)->word = (char*)malloc(10);
		sum += 10;
		if ((dic->wc + i)->word == NULL)
		{
			for (int j = i-1; j >= 0; j--)
			{
				free((dic->wc + j)->word);
			}
			free(dic->wc);
			free(dic);
			return NULL;
		}
		(dic->wc + i)->counter = 0;
	}*/
	//printf("%d\n", sum);
	dic->capacity = N;
	dic->size = 0;
	return dic;
}
void destroy_dictionary(struct dictionary_t** d)
{
	if (d == NULL ) return;
	for (int i = 0; i < (*d)->size; i++)
	{
		if (((*d)->wc + i)->word != NULL) free(((*d)->wc + i)->word);
	}
	free((*d)->wc);
	free((*d));
}
struct word_count_t* dictionary_find_word(const struct dictionary_t *d, const char *word)
{
	if (d == NULL || d->capacity < 1 || d->size < 1 || d->wc == NULL || word==NULL) return NULL;
	for (int i = 0; i < d->size; i++)
	{
		if (strcmp((d->wc + i)->word, word) == 0)
			return d->wc + i;
	}
	return NULL;
}
void dictionary_display(const struct dictionary_t *d)
{
	if (d == NULL || d->capacity < 1 || d->size < 1 || d->wc == NULL || d->capacity<d->size) return;
	for (int i = 0; i < d->size; i++)
	{
		printf("%s %d\n", (d->wc + i)->word, (d->wc + i)->counter);
	}
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