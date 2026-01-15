#include <stdio.h>
#include "../headers/orangetree.h"

typedef struct {
    void* OT_next;
    void* OT_prev;
    char* string;
} blahblahblah;

void iteration_function(void* operand, void* user_pointer){
    blahblahblah* oper = (blahblahblah*)(operand);
    
    printf(oper->string);
}

int main(){
    blahblahblah a = {NULL, NULL, "Hello, "};
    blahblahblah b = {NULL, NULL, "World!"};
    blahblahblah c = {NULL, NULL, "Linked Lists "};
    blahblahblah d = {NULL, NULL, "\b!"};
    blahblahblah e = {NULL, NULL, "Laura the linked list lover says: "};

    // see current state of linked list
    OT_iterate(&a, NULL, iteration_function);
    printf("\n");

    // add B to end of linked list that contains A
    OT_append(&a, &b);

    // see current state of linked list
    OT_iterate((void*)&a, NULL, iteration_function);
    printf("\n");

    // add C to the left of B in the linked list that contains B
    OT_insert_left(&b, &c);

    // see current state of linked list
    OT_iterate((void*)&a, NULL, iteration_function);
    printf("\n");

    // remove B from the linked list that contains B
    OT_drop(&b);

    // add D to end of the linked list that contains A
    OT_append(&a, &d);

    // see current state of linked list
    OT_iterate((void*)&a, NULL, iteration_function);
    printf("\n");

    // add E to the beginning of the linked list that contains A
    OT_prepend(&a, &e);

    // see current state of linked list
    OT_iterate((void*)&a, NULL, iteration_function);
    printf("\n");

    return 0;
}
