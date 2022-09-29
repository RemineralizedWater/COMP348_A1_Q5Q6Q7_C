#include "Linked_List.h"
#include <stdio.h>
#include <stdlib.h>

element aasel(atom a) {
    element e;
    e.type = ATOM;
    e.a = a;
    return e;
}

element lasel(list l) {
    element e;
    e.type = LIST;
    e.l = l;
    return e;
}


element car(element e) {
    if (e.type != LIST)
        return NIL;
    else
        return e.l->el;
}

list cdr(element e) {
    if (e.type != LIST || e.l == NULL || e.l->next == NULL)
        return NULL;
    else
        return e.l->next;
}


list cddr(element e) {
    return cdr(lasel(cdr(e)));
}

list cons(element e, list l) {
    list new_list = (list) malloc(sizeof(struct _listnode));
    if (new_list == NULL) {
        printf("ERROR: Out of memory.\n");
        return 1;
    }
    new_list->el = e;
    new_list->next = l;
    return new_list;
}

list append(list l1, list l2) {
    if (l1 == NULL) {
        return l2;
    } else if (l2 == NULL) {
        return l1;
    } else {
        list new_list = l1;
        struct _listnode *ptr = new_list;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = l2;
        return new_list;
    }
}


void lfreer(list l) {
    list new_list = l;
    while (new_list != NULL) {
        if (new_list->el.type == LIST) {
            lfreer(new_list->el.l);
        }
        list temp = new_list->next;
        free((void *) new_list);
        new_list = temp;
    }
}


void print(element e) {
    if (e.type == ATOM)
        printf(" %c ", e.a);
    if (e.type == LIST && e.l == NULL) {
        printf("NIL");
    }
    if (e.type == LIST && e.l != NULL) {
        list current = e.l;
        printf("(");
        while (current != NULL) {
            print(current->el);
            current = current->next;
        }
        printf(")");
    }
}

int main() {
    element a = aasel('a');
    element b = aasel('b');
    element c = aasel('c');
    element d = aasel('d');
    element e = aasel('e');

    list bc = cons(lasel(cons(b, cons(c, NULL))), NULL);
    list a_bc = cons(a, bc);
    list a_bc_d = append(a_bc, cons(d, NULL));
    list a_bc_d_e = (append(a_bc_d, cons(e, NULL)));

    print(lasel(a_bc_d_e));
    printf("\n");

    print(car(lasel(a_bc_d_e)));
    printf("\n");

    print(lasel(cdr(lasel(a_bc_d_e))));
    printf("\n");

    print((car(car(lasel(a_bc_d_e)))));

    lfreer(a_bc_d_e);
}


