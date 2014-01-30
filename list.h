#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include <stdbool.h>

struct node {
    void * info;
    struct node *next;
};

typedef struct {
    int length;
    struct node *head;
    int (*cmp)(void *, void *);
    void (*print)(void *);
    bool (*query)(void *, void *);
} List;

List * List_new(
    int (*cmp)(void *, void *),
    void (*print)(void *), 
    bool (*query)(void *, void *));

void List_add(List *l, void *info);

void * List_findOne(List *l, void *query);

void List_each(List *l, void (*f)(void *));

void List_print(List * l);

#endif //_LINKEDLIST_H