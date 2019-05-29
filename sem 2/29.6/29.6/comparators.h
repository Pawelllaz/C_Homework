#ifndef COMPARATORS_H_INCLUDED
#define COMPARATORS_H_INCLUDED


int comp_int(int a, int b);
int comp_int_abs(int a, int b);
int comp_int_length(int a, int b);
int comp_int_digits_sum(int a, int b);
int sort_int(int *tab, int lenth, int(*ptr)(int, int));
void swap(int *a, int *b);
#endif // !COMPARATORS_H_INCLUDED
