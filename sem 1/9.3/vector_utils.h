#ifndef VECTOR_UTILS_H_INCLUDED
#define VECTOR_UTILS_H_INCLUDED
//vector operate
int read_vector(int vec[], int size, int stop_value);
void display_vector(int vec[], int size);
// bubble
void bubble_sort(int tab[], int size, int dir);
void bubble_sort_desc(int tab[], int size);
void bubble_sort_asc(int tab[], int size);
// selection sort
void selection_sort_asc(int tab[], int size);
void selection_sort_desc(int tab[], int size);
void selection_sort(int tab[], int size, int dir);
int find_min(int tab[], int size, int start_index);
int find_max(int tab[], int size, int start_index);

#endif // VECTOR_UTILS_H_INCLUDED
