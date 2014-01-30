#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "person.h"

Person * Person_new(int age) {
    static unsigned long long id = 0;
    Person *p = (Person *)malloc(sizeof(Person));
    p->age = age;
    p->id = id++;
    return p;
}

int Person_cmp(Person *p1, Person *p2) {
    if (p1->age > p2->age) {
        return 1;
    }
    if (p1->age == p2->age) {
        return 0;
    }
    return -1;
}

void Person_print(Person *p) {
    if(!p)
        puts("nil\n");
    printf("id: %d, age: %d\n", p->id, p->age);
}

bool Person_query(Person *p, int id) {
    return p->id == id;
}

List * Person_newlist() {
    List *l = List_new(
        (int (*)(void *, void *))Person_cmp,
        (void (*)(void *))Person_print,
        (bool (*)(void *, void *))Person_query
        );
    return l;
}
