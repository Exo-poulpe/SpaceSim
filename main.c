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
    vector earth_speed_polar = vector_init(sqrt(500/70),0);
    point earth_position_cart = point_init(width/2,height/2+200);

    vector moon_speed_polar = vector_init(sqrt(500/100),0);
    point moon_position_cart = point_init(width/2,height/2+208);

    vector sun_speed = vector_init(0,0);
    point sun_position = point_init(width/2,height/2);

    vector mars_speed_polar = vector_init(sqrt(500/50),0);
    point mars_position = point_init(width/2,height/2+120);

    vector mercury_speed_polar = vector_init(sqrt(500/20),0);
    point mercury_position = point_init(width/2,height/2+50);

    vector jupyter_speed_polar = vector_init(sqrt(500/100),0);
    point jupyter_position = point_init(width/2,height/2+300);

    // uint32_t size = 4;
    // astre* lst_astres[size];
    // lst_astres[0] = astre_create((char*)"Earth",6,earth_speed_polar,6,earth_position_cart,COLOR_BLUE);
    // lst_astres[1] = astre_create((char*)"Sun",300,sun_speed,30,sun_position,COLOR_ORANGE);
    // lst_astres[2] = astre_create((char*)"Mars",4,mars_speed_polar,4,mars_position,COLOR_RED);
    // lst_astres[3] = astre_create((char*)"Moon",0.5,moon_speed_polar,2,moon_position_cart,COLOR_GRAY);
    // lst_astres[4] = astre_create((char*)"Sun",300,sun_speed,30,sun_position,COLOR_ORANGE);

    astre* a1 = astre_create((char*)"Earth",6,earth_speed_polar,3,earth_position_cart,COLOR_BLUE);
    astre* a2  = astre_create((char*)"Sun",10000,sun_speed,10,sun_position,COLOR_ORANGE);
    astre* a3 = astre_create((char*)"Mars",4,mars_speed_polar,2,mars_position,COLOR_RED);
    astre* a4  = astre_create((char*)"Moon",1,moon_speed_polar,1,moon_position_cart,COLOR_GRAY);
    astre* a5  = astre_create((char*)"Mercury",1,mercury_speed_polar,1,mercury_position,COLOR_GRAY);
    astre* a6  = astre_create((char*)"Jupyter",10,jupyter_speed_polar,5,jupyter_position,COLOR_GREEN);

    lst_vector* lst_astres = lst_vector_init();
    lst_astres = lst_vector_push(lst_astres,(void*)a1);
    lst_astres = lst_vector_push(lst_astres,(void*)a2);
    lst_astres = lst_vector_push(lst_astres,(void*)a3);
    lst_astres = lst_vector_push(lst_astres,(void*)a4);
    lst_astres = lst_vector_push(lst_astres,(void*)a5);
    lst_astres = lst_vector_push(lst_astres,(void*)a6);


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
