#include "stack_list.h"


stack_list* stack_create(uint32_t max_size)
{
    stack_list* st = malloc(1 * sizeof(stack_list));
    st->max_size = max_size;
    st->list = NULL;
    return st;
}

uint32_t stack_length(stack_list* stack)
{
    assert(stack != NULL);

    if(stack->list == NULL){return 0;}

    element_stack* tmp = stack->list;
    uint32_t cpt = 0;
    while(tmp != NULL)
    {
        tmp = tmp->next;
        cpt += 1;
    }
    return cpt;
}

void stack_push(stack_list* stack,void* elem,void (*freedom)(void*))
{
    element_stack* value = malloc(1 * sizeof(element_stack));
    value->data = elem;
    value->next = stack->list;
    stack->list = value;
    if(stack_length(stack) >= stack->max_size){
        stack_remove(stack,stack->max_size,freedom);
    }
}

void* stack_pop(stack_list* stack)
{
    assert(stack != NULL);

    if(stack->list == NULL){return NULL;}

    element_stack* tmp = stack->list;
    while(tmp != NULL)
    {
        tmp = tmp->next;
    }
    return tmp->data;
}

void stack_remove(stack_list* stack,uint32_t index,void (*freedom)(void*))
{
    assert(stack != NULL);

    if(stack->list == NULL){return;}

    element_stack* tmp = stack->list;
    element_stack* old = tmp;
    uint32_t cpt = 1;
    while(tmp != NULL)
    {
        if(cpt == index)
        {
            old->next = tmp->next;
            freedom(tmp->data);
            free(tmp);
            return;
        }
        old = tmp;
        tmp = tmp->next;
        cpt += 1;
    }

}

uint32_t stack_size(stack_list* stack)
{
    return stack->max_size;
}

void* stack_get(stack_list* stack,uint32_t index)
{
    assert(stack != NULL);

    if(stack->list == NULL){return;}

    element_stack* tmp = stack->list;
    element_stack* old = tmp;
    uint32_t cpt = 0;
    while(tmp != NULL)
    {
        if(cpt == index)
        {
            return (void*)tmp->data;
        }
        tmp = tmp->next;
        cpt += 1;
    }
}

void stack_fprint(stack_list* stack,FILE* out,char* (*get_string_from_data)(void*))
{
    assert(stack != NULL);

    if(stack->list == NULL){return 0;}

    element_stack* tmp = stack->list;
    while(tmp != NULL)
    {
        char* str = get_string_from_data(tmp->data);
        fprintf(out,"%s\n",str);
        free(str);
        tmp = tmp->next;
    }
}

void stack_printf(stack_list* stack,char* (*get_string_from_data)(void*))
{
    stack_fprint(stack,stdout,get_string_from_data);
}

void stack_destroy(stack_list* stack,void (*freedom)(void*))
{
    assert(stack != NULL);

    if(stack->list == NULL){
        free(stack);
        return;
    }

    element_stack* tmp = stack->list;
    element_stack* old = tmp;
    while(tmp != NULL)
    {
        old = tmp;
        tmp = tmp->next;

        freedom(old->data);
        free(old);
    }

    free(stack);
}