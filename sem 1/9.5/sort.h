#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

// bubble sort
void bubble_sort(int tab[], int size, int dir);
void bubble_sort_desc(int tab[], int size);
void bubble_sort_asc(int tab[], int size);
// selection sort
void selection_sort_asc(int tab[], int size);
void selection_sort_desc(int tab[], int size);
void selection_sort(int tab[], int size, int dir);
// insertion sort
void insertion_sort_asc(int tab[], int size);
void insertion_sort_desc(int tab[], int size);
void insertion_sort(int tab[], int size, int dir);
// max / min
int find_min(int tab[], int size, int start_index);
int find_max(int tab[], int size, int start_index);

#endif // SORT_H_INCLUDED
