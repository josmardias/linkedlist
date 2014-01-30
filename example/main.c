#include <stdio.h>
#include "person.h"

int main() {
    List *l = Person_newlist();

    List_add(l, Person_new(10));
    List_add(l, Person_new(1));
    List_add(l, Person_new(9));
    List_add(l, Person_new(8));

    puts("All people:");
    List_print(l);

    unsigned long long id = 3;
    Person * p = List_findOne(l, (void *)id);
    printf("\nPerson with id %llu:\n", id);
    Person_print(p);

    return 0;
}
