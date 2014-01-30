#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include "list.h"

List * List_new(int (*cmp)(void *, void *),
	void (*print)(void *), 
	bool (*query)(void *, void *)) {

	List *l = (List *)malloc(sizeof(List));
	l->length = 0;
	l->head = NULL;

	l->cmp = cmp;
	l->query = query;
	l->print = print;

	return l;
}

void List_add(List *l, void *info) {
	struct node * node;
	struct node * newNode;

	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->info = info;
	newNode->next = 0;

	l->length++;

	if (l->length == 1) {
		l->head = newNode;
		return;
	}

	node = l->head;
	//smaller than the head
	if (!l->cmp || l->cmp(info, node->info) < 0) {
		l->head = newNode;
		newNode->next = node;
		return;
	}

	for (; node->next != NULL; node=node->next) {
        //cmp(a, b) returns <0 when b>a
		if (l->cmp(info, node->next->info) < 0) {
			break;
		}
	}

	newNode->next = node->next;
	node->next = newNode;
}

void * List_findOne(List *l, void *query) {
	struct node * node;

	if (l->length == 0)
		return NULL;

	for (node=l->head; node!=NULL; node=node->next) {
		if(l->query(node->info, query))
			break;
	}

	if (node == NULL)
		return NULL;
	return node->info;
}

void List_each(List *l, void (*f)(void *)) {
	struct node * node;
	for (node=l->head; node!=NULL; node=node->next) {
		f(node->info);
	}
}

void List_print(List * l) {
	//printf("%d ", l->length);
	List_each(l, l->print);
}
