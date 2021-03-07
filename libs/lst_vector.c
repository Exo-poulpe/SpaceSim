

#include "lst_vector.h"

lst_vector* lst_vector_init()
{
    // lst_vector v = (lst_vector)malloc(1 * sizeof(element*));
    // v->data = NULL;
    // v->next = NULL;
    // free(v);
    return NULL;
}

// NOT tested but tested
uint32_t lst_vector_lenght(lst_vector *v) 
{
    if(*v == NULL){
        return 0;
    }

    element* vec = *v;
    uint32_t cpt = 1;

    while(vec->next != NULL){
        // printf("%d\n",cpt);
        vec = vec->next;
        cpt+=1;
    }

    return cpt;
}

// Function in param for free data
// NOT tested but ok
void lst_vector_empty(lst_vector* v,void (*func_free)(void*))
{
    assert(v != NULL);

    lst_vector vec = (*v); // v = ((element*)*)* deref => element**
    lst_vector old = vec;
    uint32_t limit = lst_vector_lenght(v);

    for(uint32_t i=0;i < limit;i+=1)
    {
        old = vec;
        vec = vec->next;
        func_free(old->data);
        free(old);
    }
    free(v);
}


// NOT tested but ok
lst_vector* lst_vector_push(lst_vector *v, void *data)
{
    // Temporary element*
    element* elem = malloc(1 * sizeof(element)); // Create New element*
    if(v == NULL)
    {
        v = malloc(1 * sizeof(element*));
        elem->next = NULL; // Set next to *v 
    }else if(v != NULL)
    {
        elem->next = *v; // Set next to *v 
    }
    elem->data = data; // Set data
    *v = elem;
    return v;
}


// NOT tested but tested
void* lst_vector_get(lst_vector *v, uint32_t index)
{
    assert(v != NULL);
    assert(index < lst_vector_lenght(v));
    lst_vector tmp = *v; 
    void* value = NULL;
    
    for(uint32_t i=0;i < index + 1;i+=1)
    {
        if(i == index)
        {
            value = tmp->data;
            break;
        }
        tmp = tmp->next;
    }
    
    return value;
}

void* lst_vector_remove(lst_vector *v, uint32_t index)
{
    assert(v != NULL);
    lst_vector tmp = *v;
    void* value = NULL;
    lst_vector old = tmp; 
        
    printf("Index : %d\n",index);

    if(index == 0)
    {
        value = tmp->data;
        free(tmp);
        *v = tmp->next;
    }else
    {
    
        for(uint32_t i=0;i < index + 1;i+=1)
        {
            tmp = tmp->next;
            if(i == index)
            {
                value = tmp->data;
                old->next = tmp->next;
                free(tmp);
                break;
            }
            old = tmp;
        }
    }
    
    return value;
}


void* lst_vector_pop(lst_vector *v)
{
    return lst_vector_remove(v, 0);
}


void lst_vector_push_back(lst_vector *v,void* elem)
{
    lst_vector_insert(v,lst_vector_lenght(v),elem);
}

lst_vector lst_vector_set(lst_vector *v, uint32_t index, void *elem)
{
    assert(index < lst_vector_lenght(v));
    lst_vector tmp = *v;

    for(uint32_t i=0;i < index + 1;i+=1)
    {
        if(i == index)
        {
            tmp->data = elem;
            break;
        }
        tmp = tmp->next;
    }
    
    return *v;
}

void lst_vector_insert(lst_vector *v, uint32_t index, void *elem)
{
    // assert(index < lst_vector_lenght(v));
    lst_vector tmp = *v;
    lst_vector old = tmp;

    for(uint32_t i=0;i < index + 1;i+=1)
    {
        tmp = tmp->next;
        if(i == index - 1)
        {
            element* tmp_elem = (element*)malloc(sizeof(element*));
            old->next = tmp_elem;
            tmp_elem->data = elem;
            tmp_elem->next = tmp;
            break;
        }
        old = tmp;
    }
}


lst_vector* lst_vector_map(lst_vector *v, void* (*f)(void *))
{
    assert(v != NULL);
    uint32_t limit = lst_vector_lenght(v);
    lst_vector tmp = *v;
    lst_vector* res = lst_vector_init();
        
    
    for(uint32_t i=0;i<limit;i+=1)
    {
        lst_vector_push_back(res,f(tmp->data));
        tmp = tmp->next;
    }

    return res;
}

lst_vector* lst_vector_filter(lst_vector *v, void* (*f)(void *))
{
    assert(v != NULL);
    uint32_t limit = lst_vector_lenght(v);
    lst_vector tmp = *v;
    lst_vector* res = lst_vector_init();
        
    
    for(uint32_t i=0;i<limit;i+=1)
    {
        if(*(bool*)(f(tmp->data)) == true)
        {
            lst_vector_push_back(res,tmp);
        }
        tmp = tmp->next;
    }

    return res;
}
