#ifndef POINT_HEADER
#define POINT_HEADER

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct _point{
  double x,y;
} point;



point point_init(double a,double b);
point point_add(point a,point b);
void point_destroy(point* v);
point point_sub(point a, point b);
double point_norm(point a);
point point_polar_vector_to_cart(point a);

#endif
