#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"
//#include <conio.h>

int main()
{
	FILE *f;
	char *filename = (char*)malloc(50);
	if (filename == NULL)
	{
		printf("Failed to allocate memory");
		return 2;
	}
	printf("wpisz nazwe pliku: ");
	scanf("%49s", filename);
	f = fopen(filename, "r");
	if (f == NULL)
	{
		printf("File not found");
		free(filename);
		return 1;
	}

	char *one_word = (char*)malloc(50);
	if (one_word == NULL) 
	{
		printf("Failed to allocate memory");
		free(filename);
		fclose(f);
		return 2;
	}
	struct dictionary_t *d= create_dictionary(10);
	if (d == NULL)
	{
		printf("Failed to allocate memory");
		free(one_word);
		free(filename);
		fclose(f);
		return 2;
	}
	while (fscanf(f, "%49s", one_word)!=EOF)
	{
		if (*(one_word + strlen(one_word) - 1) == '.') *(one_word + strlen(one_word) - 1) = '\0';
		if (dictionary_add_word(d, one_word) == 2) {
			printf("Failed to allocate memory");
			destroy_dictionary(&d);
			free(filename);
			free(one_word);
			fclose(f);
			return 2;
		}
	}

	dictionary_display(d);
	destroy_dictionary(&d);
	free(filename);
	free(one_word);
	fclose(f);
	return 0;
}