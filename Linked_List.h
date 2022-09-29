#ifndef COMP348_A1_LINKED_LIST_H
#define COMP348_A1_LINKED_LIST_H
#include <stdio.h>

typedef enum {
    ATOM, LIST
} eltype;
typedef char atom;
struct _listnode;
typedef struct {
    eltype type;
    union {
        atom a;
        struct _listnode *l;
    };
} element;

typedef struct _listnode {
    element el;
    struct _listnode *next;
} *list;
const element NIL = {.type=LIST, .l=NULL};


element aasel(atom a);

element lasel(list l);

element car(element e);

list cdr(element e);

list cddr(element e);

list cons(element e, list);

list append(list l1, list l2);

void lfreer(list l);

void print(element e);


#endif //COMP348_A1_LINKED_LIST_H
