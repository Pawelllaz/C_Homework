#pragma once

struct word_count_t
{
	char *word;
	int counter;
};
//=============================================================================================
struct array_t
{
	float *ptr;
	int size;
	int capacity;
};
//===============================================================================================
struct dictionary_t
{
	int size;
	int capacity;
	struct word_count_t *wc;
};
//============================================================================================
struct dictionary_t* create_dictionary(int N);
int create(struct array_t *a, int N);
int create_array(struct array_t **a, int N);
int add(struct array_t *a, float value);
int dictionary_add_word(struct dictionary_t *d, const char *word);
void dictionary_display(const struct dictionary_t *d);
float dot_product(const struct array_t *a, const struct array_t *b);
int remove_no_letter(char *word);
void destroy(struct array_t *a);
void destroy_dictionary(struct dictionary_t **d);
struct word_count_t* dictionary_find_word(const struct dictionary_t *d, const char *word);
void destroy_array(struct array_t **a);
float length(const struct array_t *a);

