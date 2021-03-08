#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

#include <SDL2/SDL.h>

#include "libs/Vector.h"
#include "libs/Point.h"
#include "libs/helper_gfx.h"
#include "libs/lst_vector.h"
#include "Astre.h"


int main(void)
{
    int width = 1920, height = 1080;

    vector sun_speed = vector_init(0,0);
    point sun_position = point_init(width/2,height/2);

    vector mercury_speed_polar = vector_init(4,0);
    point mercury_position = point_init(width/2,height/2+50);

    vector venus_speed_polar = vector_init(3.4,0);
    point venus_position = point_init(width/2,height/2+90);

    vector earth_speed_polar = vector_init(3,0);
    point earth_position_cart = point_init(width/2,height/2+135);

    vector moon_speed_polar = vector_init(2.7,0);
    point moon_position_cart = point_init(width/2,height/2+142);

    vector mars_speed_polar = vector_init(2.5,0);
    point mars_position = point_init(width/2,height/2+190);

    vector jupiter_speed_polar = vector_init(1.9,0);
    point jupiter_position = point_init(width/2,height/2+300);

    vector saturn_speed_polar = vector_init(1.8,0);
    point saturn_position = point_init(width/2,height/2+350);
    
    vector uranus_speed_polar = vector_init(1.7,0);
    point uranus_position = point_init(width/2,height/2+400);

    vector neptune_speed_polar = vector_init(1.58,0);
    point neptune_position = point_init(width/2,height/2+450);

    // uint32_t size = 4;
    // astre* lst_astres[size];
    // lst_astres[0] = astre_create((char*)"Earth",6,earth_speed_polar,6,earth_position_cart,COLOR_BLUE);
    // lst_astres[1] = astre_create((char*)"Sun",300,sun_speed,30,sun_position,COLOR_ORANGE);
    // lst_astres[2] = astre_create((char*)"Mars",4,mars_speed_polar,4,mars_position,COLOR_RED);
    // lst_astres[3] = astre_create((char*)"Moon",0.5,moon_speed_polar,2,moon_position_cart,COLOR_GRAY);
    // lst_astres[4] = astre_create((char*)"Sun",300,sun_speed,30,sun_position,COLOR_ORANGE);

    astre* a1  = astre_create((char*)"Sun",10000,sun_speed,10,sun_position,COLOR_ORANGE); // 10000
    astre* a2  = astre_create((char*)"Mercury",1,mercury_speed_polar,1,mercury_position,COLOR_GRAY);
    astre* a3  = astre_create((char*)"Venus",1,venus_speed_polar,1,venus_position,COLOR_DARK_RED);
    astre* a4 = astre_create((char*)"Earth",6,earth_speed_polar,3,earth_position_cart,COLOR_LIGHT_BLUE);
    astre* a5  = astre_create((char*)"Moon",1,moon_speed_polar,1,moon_position_cart,COLOR_GRAY);
    astre* a6 = astre_create((char*)"Mars",4,mars_speed_polar,2,mars_position,COLOR_RED);
    astre* a7  = astre_create((char*)"Jupiter",10,jupiter_speed_polar,5,jupiter_position,COLOR_LIGHT_YELLOW);
    astre* a8  = astre_create((char*)"Saturn",7,saturn_speed_polar,3,saturn_position,COLOR_GRAY);
    astre* a9  = astre_create((char*)"Uranus",6,uranus_speed_polar,3,uranus_position,COLOR_YELLOW);
    astre* a10  = astre_create((char*)"Neptune",6,neptune_speed_polar,2,neptune_position,COLOR_BLUE);

    lst_vector* lst_astres = lst_vector_init();
    lst_astres = lst_vector_push(lst_astres,(void*)a1);
    lst_astres = lst_vector_push(lst_astres,(void*)a2);
    lst_astres = lst_vector_push(lst_astres,(void*)a3);
    lst_astres = lst_vector_push(lst_astres,(void*)a4);
    lst_astres = lst_vector_push(lst_astres,(void*)a5);
    lst_astres = lst_vector_push(lst_astres,(void*)a6);
    lst_astres = lst_vector_push(lst_astres,(void*)a7);
    lst_astres = lst_vector_push(lst_astres,(void*)a8);
    lst_astres = lst_vector_push(lst_astres,(void*)a9);
    lst_astres = lst_vector_push(lst_astres,(void*)a10);


    // astre_get_velocity_from_position(lst_astres[3],lst_astres[astre_get_index_most_mass_astre(lst_astres,size)]);

    uint32_t size = lst_vector_lenght(lst_astres);
    astre_window(lst_astres,size,100);
    printf("Fin\n");
    // size = lst_vector_lenght(lst_astres);
    // for(uint32_t i=0; i<size; i+=1)
    // {
    //     astre_destroy(lst_vector_get(lst_astres,i));
    // }
    lst_vector_empty(lst_astres,astre_destroy);
    return 0;
}
