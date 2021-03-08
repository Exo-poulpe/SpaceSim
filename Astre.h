#ifndef HEADER_ASTRE
#define HEADER_ASTRE

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <assert.h>

#include <SDL2/SDL.h>

#include "libs/Vector.h"
#include "libs/Point.h"
#include "libs/helper_gfx.h"
#include "libs/stack_list.h"
#include "libs/lst_vector.h"

static const double G = 6.67430E-11;

typedef struct _astre
{
    char* name;
    double mass;
    vector speed;
    uint32_t size;
    point position_actual;
    stack_list* position_old;
    point delta;
    uint32_t color;
} astre;


astre* astre_create(char* name, double mass,vector speed,uint32_t size,point position,uint32_t color);

void astre_print(astre* a);

void astre_destroy(astre* a);

int mass_to_size(double mass);

void draw_gravity_force(lst_vector* lst_astres,uint32_t size,SDL_Renderer * renderer);

void astre_draw_random_asteroid(lst_vector* lst_astres,uint32_t* size, uint32_t chance,double max_mass_asteroid,uint32_t x,uint32_t y,uint32_t position_offset);

void astre_draw_old_point(SDL_Renderer * renderer,astre* a);

// void astre_update_position(lst_vector* lst_astres,uint32_t size);

double astre_get_distance_x(astre* a,astre* b);

double astre_get_distance_y(astre* a,astre* b);

double astre_get_distance_hyp(astre* a,astre* b);

void astre_get_velocity_from_position(astre* a,astre* most_astre);

uint32_t astre_get_index_most_mass_astre(lst_vector* lst_astres,uint32_t size);

void astre_list_speed(lst_vector* lst_astres, uint32_t size);

void astre_apply_force(lst_vector* lst_astres,uint32_t size);

void astre_force_compute(lst_vector* lst_astres,uint32_t size);

int astre_window(lst_vector* lst_astres,uint32_t size,uint32_t speed);


#endif