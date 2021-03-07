#ifndef HEADER_LST_VECTOR
#define HEADER_LST_VECTOR

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct _element 
{
    void *data;
    struct _element* next;
} element;

typedef element* lst_vector;


lst_vector* lst_vector_init(); // OK

void* lst_vector_pop(lst_vector *v); // OK

uint32_t lst_vector_lenght(lst_vector *v); // OK

void* lst_vector_get(lst_vector *v, uint32_t index); // OK

void* lst_vector_remove(lst_vector *v, uint32_t index); // OK

void lst_vector_push_back(lst_vector *v,void* elem); // OK

lst_vector* lst_vector_push(lst_vector *v, void *data); // OK

void lst_vector_insert(lst_vector *v, uint32_t index,void *elem); // OK

void lst_vector_empty(lst_vector* v,void (*func_free)(void*)); // OK

lst_vector lst_vector_set(lst_vector *v, uint32_t index, void *elem); // OK

lst_vector* lst_vector_map(lst_vector *v, void* (*f)(void *));

lst_vector* lst_vector_filter(lst_vector *v, void* (*f)(void *));


#endif