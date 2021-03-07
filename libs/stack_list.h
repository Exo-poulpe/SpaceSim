#ifndef HEADER_STACK_LIST
#define HEADER_STACK_LIST

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

typedef struct _element {
    void* data;
    struct _element* next;
} element;

typedef struct _stack_list{
    uint32_t max_size;
    element* list;
} stack_list;

stack_list* stack_create(uint32_t max_size);
void stack_push(stack_list* stack,void* elem,void (*freedom)(void*));
void stack_remove(stack_list* stack,uint32_t index,void (*freedom)(void*));
void stack_destroy(stack_list* stack,void (*freedom)(void*));
uint32_t stack_length(stack_list* stack);
void stack_fprint(stack_list* stack,FILE* out,char* (*get_string_from_data)(void*));
void stack_printf(stack_list* stack,char* (*get_string_from_data)(void*));
void* stack_pop(stack_list* stack);
void* stack_get(stack_list* stack,uint32_t index);

#endif