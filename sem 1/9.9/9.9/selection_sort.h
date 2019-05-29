#ifndef SELECTION_SORT_H_INCLUDED
#define SELECTION_SORT_H_INCLUDED

// selection sort iteracyjnie
void selection_sort_asc(int tab[], int size);
void selection_sort_desc(int tab[], int size);
void selection_sort(int tab[], int size, int dir);
// selection sort rekurencyjnie
void selection_sort_asc_rec(int tab[], int size, int index);
void selection_sort_desc_rec(int tab[], int size, int index);
void selection_sort_rec(int tab[], int size, int dir);
// max / min
int find_min(int tab[], int size, int start_index);
int find_max(int tab[], int size, int start_index);

#endif // !SELECTION_SORT_H_INCLUDED
