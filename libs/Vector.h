#ifndef VECTOR_HEADER
#define VECTOR_HEADER

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct _vector{
  double x,y;
} vector;

vector vector_init(double a,double b);

bool vector_is_null(vector *v);

vector vector_add(vector a,vector v);

vector vector_sub(vector a,vector b);

vector vector_smul(vector v,double m);

double vector_norm(vector a);

void vector_print(vector v);

void vector_print_line(vector v);

void vector_printn(vector v,char *name);

vector vector_cart_to_polar(vector v_cart);

vector vector_polar_to_cart(vector v_polar);

void vector_destroy(vector* v);

#endif
