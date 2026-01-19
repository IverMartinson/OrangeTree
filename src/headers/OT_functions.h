#ifndef OT_FUNCTIONS_H
#define OT_FUNCTIONS_H

// - Returns the last element of a linked list
// - Takes in any element of the list
void* OT_get_last(void* operand);

// - Returns the first element of a linked list
// - Takes in any element of the list
void* OT_get_first(void* operand);

// - Removes an element from the linked list
// - Takes in specific element of the list
// - Returns -1 if the element was the last in the linked list
int OT_drop(void* operand);

// - Removes an element from the linked list and frees it
// - Takes in specific element of the list
// - Returns -1 if the element was the last in the linked list
int OT_erase(void* operand);

// - Adds an element to the end of a linked list
// - Takes in any element of the list and an element to add to the list
void OT_append(void* operand, void* appendee);

// - Adds and element to the beginning of a linked list
// - Takes in any element of the list and an element to add to the list
void OT_prepend(void* operand, void* prependee);

// - Adds an element to the left of an element in a linked list
// - Takes in specific element of the list and an element to add to the list
void OT_insert_left(void* operand, void* insertee);

// - Adds an element to the right of an element in a linked list
// - Takes in specific element of the list and an element to add to the list
void OT_insert_right(void* operand, void* insertee);

// - Frees entire list
// - Takes in any element of the list
void OT_free(void* operand);

// - Runs `(*user_function)` for every element in the linked list
// - Takes in any element of the list, a pointer that will be passed into the `user_function`, and `user_function`
// - `user_function` must be in the form `int func(void* operand, void* user_pointer)`
// - if 'user_function' returns -1, the loop will break
void OT_iterate(void* operand, void* user_pointer, void (*user_function)(void*, void*));

#endif