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

    element* tmp = stack->list;
    uint32_t cpt = 1;
    while(tmp != NULL)
    {
        tmp = tmp->next;
        cpt += 1;
    }
    return cpt;
}

void stack_push(stack_list* stack,void* elem)
{
    element* value = malloc(1 * sizeof(element));
    value->data = elem;
    value->next = stack->list;
    stack->list = value->next;
}

void stack_remove(stack_list* stack,uint32_t index)
{
    assert(stack != NULL);

    if(stack->list == NULL){return;}

    element* tmp = stack->list;
    element* old = tmp;
    uint32_t cpt = 1;
    while(tmp != NULL)
    {
        if(cpt == index)
        {
            old->next = tmp->next;
            return;
        }
        old = tmp;
        tmp = tmp->next;
        cpt += 1;
    }

}
void stack_fprint(stack_list* stack,FILE* out,char* (*get_string_from_data)(void*))
{
    assert(stack != NULL);

    if(stack->list == NULL){return 0;}

    element* tmp = stack->list;
    uint32_t cpt = 1;
    while(tmp != NULL)
    {
        fprintf(out,"%s\n",get_string_from_data(tmp->data));
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

    if(stack->list == NULL){return;}

    element* tmp = stack->list;
    element* old = tmp;
    while(tmp != NULL)
    {
        old = tmp;
        tmp = tmp->next;

        freedom(old->data);
        free(old);
    }

    free(stack);
}