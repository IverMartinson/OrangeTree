#include "../headers/orangetree.h"

void* OT_get_last(void* operand){
    struct OT_operand* cur_oper = (struct OT_operand*)(operand);

    while (cur_oper->OT_next)
        cur_oper = (struct OT_operand*)(cur_oper->OT_next);

    return (void*)cur_oper;
}

void* OT_get_first(void* operand){
    struct OT_operand* cur_oper = (struct OT_operand*)(operand);

    while (cur_oper->OT_prev)
        cur_oper = (struct OT_operand*)(cur_oper->OT_prev);

    return (void*)cur_oper;
}

int OT_drop(void* operand){
    struct OT_operand* oper = (struct OT_operand*)operand;
    
    struct OT_operand* prev = (struct OT_operand*)oper->OT_prev;
    struct OT_operand* next = (struct OT_operand*)oper->OT_next;

    if (prev) prev->OT_next = (void*)next;
    if (next) next->OT_prev = (void*)prev;

    if (!prev && !next) return -1;
    
    return 0;
}

int OT_erase(void* operand){
    struct OT_operand* oper = (struct OT_operand*)operand;
    
    struct OT_operand* prev = (struct OT_operand*)oper->OT_prev;
    struct OT_operand* next = (struct OT_operand*)oper->OT_next;

    if (prev) prev->OT_next = (void*)next;
    if (next) next->OT_prev = (void*)prev;

    free(operand);

    if (!prev && !next) return -1;
    
    return 0;
}

void OT_append(void* operand, void* appendee){
    if (!operand){
        operand = appendee;

        return;
    }

    struct OT_operand* app = (struct OT_operand*)appendee;
    
    struct OT_operand* last_element = (struct OT_operand*)OT_get_last(operand);

    last_element->OT_next = appendee;
    app->OT_prev = (void*)last_element;
}

void OT_prepend(void* operand, void* prependee){
    if (!operand){
        operand = prependee;

        return;
    }

    struct OT_operand* pre = (struct OT_operand*)prependee;
    
    struct OT_operand* first_element = (struct OT_operand*)OT_get_first(operand);

    first_element->OT_prev = prependee;
    pre->OT_next = (void*)first_element;
}

void OT_insert_left(void* operand, void* insertee){
    if (!operand){
        operand = insertee;

        return;
    }

    struct OT_operand* oper = (struct OT_operand*)operand;
    struct OT_operand* ins = (struct OT_operand*)insertee;

    struct OT_operand* oper_prev = oper->OT_prev;

    ins->OT_prev = oper->OT_prev;
    ins->OT_next = operand;

    oper_prev->OT_next = insertee;
    oper->OT_prev = insertee;
}

void OT_insert_right(void* operand, void* insertee){
    if (!operand){
        operand = insertee;

        return;
    }

    struct OT_operand* oper = (struct OT_operand*)operand;
    struct OT_operand* ins = (struct OT_operand*)insertee;

    struct OT_operand* oper_next = oper->OT_prev;

    ins->OT_prev = operand;
    ins->OT_next = oper->OT_prev;

    oper->OT_next = insertee;
    oper_next->OT_prev = insertee;
}

void OT_free(void* operand){
    struct OT_operand* cur_oper = (struct OT_operand*)OT_get_first(operand);

    while (cur_oper){
        struct OT_operand* next = (struct OT_operand*)(cur_oper->OT_next);
        
        free(cur_oper);
        
        cur_oper = next;
    }
}

void OT_iterate(void* operand, void* user_pointer, int (*user_function)(void*, void*)){
    struct OT_operand* cur_oper = (struct OT_operand*)OT_get_first(operand);

    while (cur_oper){
        struct OT_operand* next = (struct OT_operand*)(cur_oper->OT_next);
        
        if ((*user_function)(cur_oper, user_pointer) == -1) break;

        cur_oper = next;
    }
}
