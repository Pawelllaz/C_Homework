#ifndef INSERTION_SORT_H_INCLUDED
#define INSERTION_SORT_H_INCLUDED

void insertion_sort_asc_rec(int tab[], int size);
void insertion_sort_desc_rec(int tab[], int size);
void insertion_sort_rec(int tab[], int size, int dir);
void insertion_sort_asc(int tab[], int size);
void insertion_sort_desc(int tab[], int size);
void insertion_sort(int tab[], int size, int dir);

#endif // !INSERTION_SORT_H_INCLUDED
