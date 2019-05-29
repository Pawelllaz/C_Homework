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
//	printf("int: %d wskaznik na word_count: %d wskaznik na word: %d\n", sizeof(dic->capacity), sizeof(dic->wc),sizeof(dic->wc->word));
	//printf("%li\n", sizeof(struct dictionary_t));
	if (dic == NULL) return NULL;
	dic->wc= (struct word_count_t*)malloc(sizeof(struct word_count_t)*N);
	//printf("int: %d wskaznik na word_count: %d wskaznik na word: %d\n", sizeof(dic->capacity), sizeof(dic->wc), sizeof(dic->wc->word));

	//printf("%li\n", sizeof(struct word_count_t)*N);
	if (dic->wc == NULL)
	{
		free(dic);
		return NULL;
	}
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		printf("debug\n");
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
	}
	printf("%d\n", sum);
	dic->capacity = N;
	dic->size = 0;
	return dic;
}
void destroy_dictionary(struct dictionary_t** d)
{
	if (d == NULL || (*d)->wc == NULL) return;
	for (int i = 0; i < (*d)->capacity; i++)
	{
		free(((*d)->wc + i)->word);
		free(((*d)->wc + i));
	}
	free((*d));
}
struct word_count_t* dictionary_find_word(const struct dictionary_t *d, const char *word)
{
	if (d == NULL || d->capacity < 1 || d->size < 1 || d->wc == NULL) return NULL;
	for (int i = 0; i < d->size; i++)
	{
		if (strcmp(word, (d->wc + i)->word) == 0)
			return (d->wc + i);
	}
	return NULL;
}
void dictionary_display(const struct dictionary_t *d)
{
	if (d == NULL || d->capacity < 1 || d->size < 1 || d->wc == NULL) return;
	for (int i = 0; i < d->size; i++)
	{
		printf("%s %d\n", d->wc->word, d->wc->counter);
	}
}
int dictionary_add_word(struct dictionary_t *d, const char *word)
{
	if (d == NULL || d->capacity < 1 || d->size < 1 || d->wc == NULL) return 1;
	struct word_count_t *wd;
	wd = dictionary_find_word(d, word);
	if (wd == NULL)
	{
		if (d->capacity >= d->size)
		{
			(d->wc + d->size)->word = '\0';
			strcat((d->wc + d->size)->word, word);
			d->size++;
			(d->wc + d->size)->counter = 1;
		}
		else
		{
			struct dictionary_t	*new_d;
			new_d = (struct dictionary_t*)realloc(d, sizeof(struct dictionary_t)*d->capacity * 2);
			if (new_d == NULL)
			{
				destroy_dictionary(&d);
				return 2;
			}
			else d = new_d;
			new_d->wc = (struct word_count_t*)realloc(d, d->capacity * 2);
			if (new_d->wc == NULL)
			{
				destroy_dictionary(&d);
				return 2;
			}
			else d = new_d;
			d->capacity *= 2;
			for (int i = d->size; i < d->capacity; i++)
			{
				(d->wc + i)->word = (char*)malloc(30);
				if ((d->wc + i)->word == NULL)
				{
					for (int j = i-1; j >= 0; j--)
					{
						free((d->wc + j)->word);
					}
					free(d->wc);
					free(d);
					return 2;
				}
				(d->wc + i)->counter = 0;
			}
			(d->wc + d->size)->word = '\0';
			strcat((d->wc + d->size)->word, word);
			d->size++;
			(d->wc + d->size)->counter = 1;
		}
	}
	else wd->counter++;
	return 0;
}