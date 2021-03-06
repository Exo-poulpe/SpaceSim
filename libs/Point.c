// Author : Exo-poulpe
// Date   : 2020.09.28
// Description : Library for Point

#include "Point.h"

// Init vector with param
point point_init(double a,double b)
{
    point v;
    v.x = a;
    v.y = b;
    return v;
}

// Add vector with vector
point point_add(point a,point b)
{
    point res;
    res.x = a.x + b.x;
    res.y = a.y + b.y;
    return res;
}


point point_sub(point a, point b)
{
    point res;
    res.x = fabs(a.x - b.x);
    res.y = fabs(a.y - b.y);
    return res;
}

double point_norm(point a)
{
    return sqrt( pow(fabs(a.x),2) + pow(fabs(a.y),2) );
}

char* point_to_str(point a)
{
    char* str[20];
    snprintf(str,20,"%g, %g",a.x,a.y);
    return str;
}

point point_polar_vector_to_cart(point a)
{
    point res;
    res.x = a.x * sin(a.y);
    res.y = a.x * cos(a.y);
    return res;
}

void point_destroy(point* v)
{
    v->x = 0;
    v->y = 0;
}