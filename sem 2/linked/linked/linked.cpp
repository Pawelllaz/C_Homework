#include "stdafx.h"
#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include <conio.h>

typedef struct linked_list_t list;
typedef struct node_t node;

struct node_t
{
	int data;
	struct node_t *next;
	struct node_t *prev;
};
struct linked_list_t
{
	struct node_t *head;
	struct node_t *tail;
};
struct linked_list_t* ll_create() {
	list *a = (list*)malloc(sizeof(list));
	if (a == NULL) return NULL;
	a->head = NULL;
	a->tail = NULL;
	return a;
}
int ll_push_back(struct linked_list_t* ll, int value) {
	if (ll == NULL) return 1;
	node *temp = (node*)malloc(sizeof(node));
	if (temp == NULL) {
		//	free(ll);
		return 2;
	}
	if (ll->head == NULL) {
		temp->data = value;
		temp->next = NULL;
		ll->head = temp;
		ll->tail = temp;
		temp->prev = NULL;
	}
	else {
		temp->data = value;
		temp->next = NULL;
		ll->tail->next = temp;
		temp->prev=ll->tail;
		ll->tail = temp;
	}
	return 0;
}
int ll_push_front(struct linked_list_t* ll, int value) {
	if (ll == NULL) return 1;
	node *temp = (node*)malloc(sizeof(node));
	if (temp == NULL) return 2;
	if (ll->head == NULL) {
		temp->data = value;
		temp->next = NULL;
		ll->head = temp;
		temp->prev = NULL;
		ll->tail = temp;
	}
	else {
		temp->data = value;
		temp->next = ll->head;
		temp->prev = NULL;
		ll->head->prev = temp;
		ll->head = temp;
	}
	return 0;
}
void ll_display_reverse(const struct linked_list_t* ll) {
	if (ll == NULL) return;
	node *temp = ll->tail;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->prev;
	}
}
void ll_display(const struct linked_list_t* ll) {
	if (ll == NULL) return;
	node *temp = ll->head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
}
int ll_pop_front(struct linked_list_t* ll, int *err_code) {
	if (ll == NULL) { if (err_code) *err_code = 1; return 0; }
	if (ll->head == NULL) { if (err_code) *err_code = 1; return 0; }
	int val = ll->head->data;
	if (ll->head->next == NULL) ll->tail = NULL;
	node *temp = ll->head->next;
	free(ll->head);
	temp->prev = NULL;
	ll->head = temp;
	if (err_code != NULL) *err_code = 0;
	return val;
}
int ll_pop_back(struct linked_list_t* ll, int *err_code) {
	if (ll == NULL) { if (err_code) *err_code = 1; return 0; }
	node *temp = NULL;
	int val;
	if (ll->head == NULL) { if (err_code) *err_code = 1; return 0; }
	node *ptr = ll->head;
	if (ll->head != NULL) {
		if (ll->head->next) {
			while (ptr->next->next != NULL)
				ptr = ptr->next;
			temp = ptr->next;
			val = temp->data;
			ptr->next = NULL;
			ll->tail = ptr;
		}
		else {
			temp = ll->head;
			val = temp->data;
			ll->head = NULL;
			ll->tail = NULL;
		}
	}
	free(temp);
	//free(ptr);
	if (err_code) *err_code = 0;
	return val;
}

int ll_front(const struct linked_list_t* ll, int *err_code) {
	if (ll == NULL || ll->head == NULL) {
		if (err_code != NULL) *err_code = 1;
		return 0;
	}
	if (err_code) *err_code = 0;
	return ll->head->data;
}
int ll_back(const struct linked_list_t* ll, int *err_code) {
	if (ll == NULL || ll->head == NULL) {
		if (err_code != NULL) *err_code = 1;
		return 0;
	}
	if (err_code) *err_code = 0;
	if (ll->tail == NULL) return ll->head->data;
	return ll->tail->data;
}
struct node_t* ll_begin(struct linked_list_t* ll) {
	if (ll == NULL || ll->head == NULL)
		return NULL;
	return ll->head;
}
struct node_t* ll_end(struct linked_list_t* ll) {
	if (ll == NULL || ll->head == NULL)
		return NULL;
	return ll->tail;
}
int ll_size(const struct linked_list_t* ll) {
	if (ll == NULL) return -1;
	int i = 0;
	node *check = ll->head;
	while (check != NULL) {
		i++;
		check = check->next;
	}
	return i;
}
int ll_is_empty(const struct linked_list_t* ll) {
	if (ll == NULL) return -1;
	if (ll->head == NULL) return 1;
	return 0;
}
int ll_at(const struct linked_list_t* ll, unsigned int index, int *err_code) {
	if (ll == NULL) {
		if (err_code) *err_code = 1;
		return 0;
	}
	node *temp = ll->head;
	unsigned size = 0, flag = 0;;
	while (temp != NULL) {
		if (size == index) {
			flag = 1;
			break;
		}
		temp = temp->next;
		size++;
	}
	if (!flag) {
		if (err_code) *err_code = 1;
		return 1;
	}
	if (err_code) *err_code = 0;
	return temp->data;
}
int ll_insert(struct linked_list_t* ll, unsigned int index, int value) {
	if (ll == NULL || (unsigned)ll_size(ll) < index) return 1;
	if (index == 0) { if (ll_push_front(ll, value)) return 2; return 0; }
	if (index == (unsigned)ll_size(ll)) { if (ll_push_back(ll, value)) return 2; return 0; }
	node *temp = ll->head;
	for (unsigned i = 0; i < index - 1; i++)
		temp = temp->next;
	node *new1 = (node*)malloc(sizeof(node));
	if (new1 == NULL) return 2;
	new1->data = value;
	temp->next->prev = new1;
	new1->next = temp->next;
	new1->prev = temp;
	temp->next = new1;
	return 0;
}
int ll_remove(struct linked_list_t* ll, unsigned int index, int *err_code) {
	if (ll == NULL || index>(unsigned)ll_size(ll)) {
		if (err_code) *err_code = 1;
		return 1;
	}
	if ((int)index < 0 || (int)index >= ll_size(ll)) {
		if (err_code) *err_code = 1;
		return 0;
	}
	if (index == 0) {
		int error;
		int a = ll_pop_front(ll, &error);
		if (error) {
			if (err_code) *err_code = 1;
			return 0;
		}
		if (err_code) *err_code = 0;
		return a;
	}
	node *current = ll->head;
	node* prev = NULL;
	for (unsigned i = 0; i < index; i++) {
		prev = current;
		current = current->next;
	}
	prev->next = current->next;
	int a = current->data;
	free(current); 
	if (err_code) *err_code = 0;
	return a;
}
void ll_clear(struct linked_list_t* ll) {
	if (ll == NULL) return;
	node *current = ll->head;
	node *next;
	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}
	ll->head = NULL;
	return;
}
void ll_display_one(struct linked_list_t* ll, unsigned index) {
	if (ll == NULL) return;
	node *temp = ll->head;
	for (unsigned i = 0; i < index; i++)
		temp = temp->next;
	printf("%d\n", temp->data);
}
int ll_sort(struct linked_list_t* ll){

	if (ll == NULL) return 1;
	int size = ll_size(ll);
	for (int i = 0; i < size; i++) {
		node *temp = ll->head;
		while (temp->next != NULL) {
			if (temp->data > temp->next->data) {
				int liczba = temp->next->data;
				temp->next->data = temp->data;
				temp->data = liczba;
			}	
			temp = temp->next;
		}
	}
	return 0;
}
int main()
{
	int x;
	struct linked_list_t *ll;
	ll = ll_create();
	x = ll_push_back(ll, 5);
	x = ll_push_back(ll, 53);
	x = ll_push_front(ll, 23);
	x = ll_push_front(ll, 2);
	ll_display(ll);
	printf("\n");
	ll_display_reverse(ll);
	/*printf("\npop front = %d\n", ll_pop_front(ll, NULL));
	ll_display(ll);
	printf("\n");
	ll_display_reverse(ll);
	//printf("\npopback = %d\n", ll_pop_back(ll, NULL));
	ll_display(ll);
	printf("\n");
	ll_display_reverse(ll);*/
	printf("\n");
	ll_insert(ll, 1, 18);
	ll_display(ll);
	printf("\n");
	ll_display_reverse(ll);
	printf("\n");
	ll_sort(ll);
	ll_display(ll);
	printf("\n");
	ll_display_reverse(ll);
	printf("\n");


	// zrob laczenie dwoch list 
	_getch();
	return 0;
}