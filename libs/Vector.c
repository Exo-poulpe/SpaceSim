// Author : Exo-poulpe
// Date   : 2020.09.28
// Description : Library for vector

#include "Vector.h"

// Init vector with param
vector vector_init(double a,double b)
{
    vector v;
    v.x = a;
    v.y = b;
    return v;
}

// Add vector with vector
vector vector_add(vector a,vector b)
{
    vector res;
    res.x = a.x + b.x;
    res.y = a.y + b.y;
    return res;
}

// a - b only
vector vector_sub(vector a,vector b)
{
    vector res;
    res.x = a.x - b.x;
    res.y = a.y - b.y;
    return res;
}

// Multiply vector with scalar value
vector vector_smul(vector v,double m)
{

    v.x *= m;
    v.y *= m;
    return v;
}

bool vector_is_null(vector *v)
{
    if(v->x == -1 && v->y == -1)
    {
        return true;
    }
    return false;
}

void vector_div(vector *v,double value)
{
    v->x = (v->x / value);
    v->y = (v->y / value);
}

// Norm of vector
double vector_norm(vector a)
{
    return hypot(a.x,a.y);
}

// Print vector
void vector_print(vector v)
{ 
    printf("Vecteur : \n%g / %g\n||vec|| : %g\n",v.x,v.y,vector_norm(v));
}

void vector_print_line(vector v)
{ 
    printf("%g / %g  ||vec|| : %g\t (%g, %g°)\n",v.x,v.y,vector_norm(v),sqrt( pow(v.x,2) + pow(v.y,2)),tan(v.y/v.x));
}

// Print vector
void vector_printn(vector v,char *name)
{ 
    printf("Vecteur : \n%.4lf / %.4lf\n||%s|| : %.4lf\n",v.x,v.y,name,vector_norm(v));
}

vector vector_cart_to_polar(vector v)
{
    vector res;
    res.y = tan(v.x/v.y);
    res.x = sqrt( pow(v.x,2) + pow(v.y,2) );
    return res;
}

vector vector_polar_to_cart(vector v_polar)
{
    vector res;
    res.x = v_polar.x * sin(v_polar.y);
    res.y = v_polar.x * cos(v_polar.y);
    return res;
}

void vector_destroy(vector* v)
{
    v->x = 0;
    v->y = 0;
}