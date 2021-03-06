#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//#include <conio.h>
#include "dictionary.h"

int main()
{
	FILE *f1, *f2;
	char *filename1, *filename2, *word;
	struct dictionary_t *d1, *d2, *common_d;
	struct  word_count_t *temp;
	struct array_t *vec1, *vec2;
	float counter1 = 0, counter2 = 0;

	filename1 = (char *)malloc(sizeof(char) * 50);
	if (filename1 == NULL)
	{
		printf("Failed to allocate memory");
		return 4;
	}

	printf("nazwa pliku: ");
	scanf("%49s", filename1);
	f1 = fopen(filename1, "r");
	if (f1 == NULL)
	{
		printf("File not found");
		free(filename1);
		return 2;
	}

	d1 = create_dictionary(5);
	if (d1 == NULL)
	{
		printf("Failed to allocate memory");
		free(filename1);
		fclose(f1);
		return 2;
	}

	for(;;)
	{
		word = (char *)malloc(sizeof(char) * 30);
		if (word == NULL)
		{
			printf("Failed to allocate memory");
			free(filename1);
			fclose(f1);
			destroy_dictionary(&d1);
			return 4;
		}

		if (fscanf(f1, "%29s", word) != 1)
		{
			free(word);
			break;
		}
		remove_no_letter(word);
		dictionary_add_word(d1, word);
		counter1++;
		free(word);
	}

	filename2 = (char *)malloc(sizeof(char) * 50);
	if (filename2 == NULL)
	{
		printf("Failed to allocate memory");
		free(filename1);
		fclose(f1);
		destroy_dictionary(&d1);
		return 4;
	}

	printf("nazwa drugiego pliku: ");
	scanf("%49s", filename2);
	f2 = fopen(filename2, "r");
	if (f2 == NULL)
	{
		printf("File not found");
		free(filename1);
		free(filename2);
		fclose(f1);
		destroy_dictionary(&d1);
		return 2;
	}

	d2 = create_dictionary(5);
	if (d2 == NULL)
	{
		printf("Failed to allocate memory");
		free(filename1);
		free(filename2);
		fclose(f1);
		fclose(f2);
		destroy_dictionary(&d1);
		return 4;
	}

	for(;;)
	{
		word = (char *)malloc(sizeof(char) * 30);
		if (word == NULL)
		{
			printf("Failed to allocate memory");
			free(filename1);
			free(filename2);
			fclose(f1);
			fclose(f2);
			destroy_dictionary(&d1);
			destroy_dictionary(&d2);
			return 4;
		}
		if (fscanf(f2, "%29s", word) != 1)
		{
			free(word);
			break;
		}
		remove_no_letter(word);
		dictionary_add_word(d2, word);
		counter2++;
		free(word);
	}

	common_d = create_dictionary(5);
	if (common_d == NULL)
	{
		printf("Failed to allocate memory");
		free(filename1);
		free(filename2);
		fclose(f1);
		fclose(f2);
		destroy_dictionary(&d1);
		destroy_dictionary(&d2);
		return 4;
	}

	for (int i = 0; i < (d1->size); i++)
		dictionary_add_word(common_d, (((d1->wc) + i)->word));

	for (int i = 0; i < (d2->size); i++)
		dictionary_add_word(common_d, (((d2->wc) + i)->word));
	int x = create_array(&vec1, (common_d->size));
	if (x != 0)
	{
		printf("Failed to allocate memory");
		free(filename1);
		free(filename2);
		fclose(f1);
		fclose(f2);
		destroy_dictionary(&d1);
		destroy_dictionary(&d2);
		destroy_dictionary(&common_d);
		return 4;
	}
	x = create_array(&vec2, (common_d->size));
	if (x != 0)
	{
		printf("Failed to allocate memory");
		free(filename1);
		free(filename2);
		fclose(f1);
		fclose(f2);
		destroy_dictionary(&d1);
		destroy_dictionary(&d2);
		destroy_array(&vec1);
		destroy_dictionary(&common_d);
		return 4;
	}

	for (int i = 0; i < common_d->size; i++)
	{
		if ((temp = dictionary_find_word(d1, (((common_d->wc) + i)->word))) != NULL)
		{
			float liczba = (float)(temp->counter) / counter1;
			add(vec1, liczba);
		}
		else add(vec1, 0.0);

		if ((temp = dictionary_find_word(d2, (((common_d->wc) + i)->word))) != NULL)
		{
			float liczba = (float)(temp->counter) / counter2;
			add(vec2, liczba);
		}
		else add(vec2, 0.0);
	}

	float l1 = length(vec1), l2 = length(vec2), scalar = dot_product(vec1, vec2), score;
	score = (scalar / (l1 * l2));
	printf("%.5f", score);
	
	free(filename1);
	free(filename2);
	fclose(f1);
	fclose(f2);
	destroy_dictionary(&d1);
	destroy_dictionary(&d2);
	destroy_array(&vec1);
	destroy_array(&vec2);
	destroy_dictionary(&common_d);

	//_getch();
	return 0;
}