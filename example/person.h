#ifndef _PERSON_H
#define _PERSON_H

#include <stdbool.h>
#include "../list.h"

typedef struct {
    int id;
    int age;
} Person;

List * Person_newlist();
Person * Person_new(int age);
int Person_cmp(Person *p1, Person *p2);
void Person_print(Person *p);
bool Person_query(Person *p, int id);

#endif //_PERSON_H