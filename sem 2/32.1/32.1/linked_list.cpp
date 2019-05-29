#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

struct node_t
{
	int data;
	struct node_t *next;
};
struct linked_list_t
{
	struct node_t *head;
	struct node_t *tail;
};

struct linked_list_t* ll_create()
{
	struct linked_list_t *list;
	list = (struct linked_list_t*)malloc(sizeof(struct linked_list_t));
	if (list == NULL) return NULL;
	list->head = NULL;
	list->tail = NULL;
	return list;
}
int ll_push_back(struct linked_list_t* ll, int value)
{
	if (ll == NULL) return 1;
	struct node_t *node;
	node = (struct node_t*)malloc(sizeof(struct node_t));
	if (node == NULL) return 2;
	if (ll->tail == NULL)
	{
		node->data = value;
		node->next = NULL;
		ll->tail = node;
		ll->head = node;
	}
	else
	{
		node->next = NULL;
		ll->tail->next = node;
		node->data = value;
		ll->tail = node;
	}
	return 0;
}
int ll_push_front(struct linked_list_t* ll, int value)
{
	if (ll == NULL) return 1;
	struct node_t *node;
	node = (struct node_t*)malloc(sizeof(struct node_t));
	if (node == NULL) return 2;
	if (ll->head == NULL) return ll_push_back(ll, value);
	else
	{
		node->next = ll->head;
		ll->head = node;
		node->data = value;
	}
	return 0;
}
int ll_pop_front(struct linked_list_t* ll, int *err_code)
{
	int tym = 0;
	if (ll->head->next == NULL)
	{
		tym = ll->head->data;
		free(ll->head);
		ll->head = NULL;
		ll->tail = NULL;
	}
	else
	{
		while (ll->head->next!=NULL)
		{

		}
	}
}
int ll_pop_back(struct linked_list_t* ll, int *err_code);
int ll_back(const struct linked_list_t* ll, int *err_code);
int ll_front(const struct linked_list_t* ll, int *err_code);
struct node_t* ll_begin(struct linked_list_t* ll);
struct node_t* ll_end(struct linked_list_t* ll);
int ll_size(const struct linked_list_t* ll);
int ll_is_empty(const struct linked_list_t* ll);
int ll_at(const struct linked_list_t* ll, unsigned int index, int *err_code);
int ll_insert(struct linked_list_t* ll, unsigned int index, int value);
int ll_remove(struct linked_list_t* ll, unsigned int index, int *err_code);
void ll_clear(struct linked_list_t* ll);*/
void ll_display(const struct linked_list_t* ll)
{
	struct node_t *p;
	p = ll->head;
	while (p!=NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}