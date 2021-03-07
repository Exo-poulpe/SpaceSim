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
#include "Astre.h"


int main(void)
{
    int width = 1920, height = 1080;
    vector earth_speed_polar = vector_init(sqrt(500/350),0);
    point earth_position_cart = point_init(width/2,height - 100);

    vector moon_speed_polar = vector_init(sqrt(500/200),0);
    point moon_position_cart = point_init(width/2,height - 150);

    vector sun_speed = vector_init(0,0);
    point sun_position = point_init(width/2,height/2);

    vector mars_speed_polar = vector_init(0,sqrt(500/200));
    point mars_position = point_init(width/2-200,height/2);

    uint32_t size = 4;
    astre* lst_astres[size];
    lst_astres[0] = astre_create((char*)"Earth",6,earth_speed_polar,6,earth_position_cart,COLOR_BLUE);
    lst_astres[1] = astre_create((char*)"Sun",300,sun_speed,30,sun_position,COLOR_ORANGE);
    lst_astres[2] = astre_create((char*)"Mars",4,mars_speed_polar,4,mars_position,COLOR_RED);
    lst_astres[3] = astre_create((char*)"Moon",0.5,moon_speed_polar,2,moon_position_cart,COLOR_GRAY);
    // lst_astres[4] = astre_create((char*)"Sun",300,sun_speed,30,sun_position,COLOR_ORANGE);

    // astre_get_velocity_from_position(lst_astres[3],lst_astres[astre_get_index_most_mass_astre(lst_astres,size)]);

    astre_window(lst_astres,size,100);
    printf("Fin\n");
    for(uint32_t i=0; i<size; i+=1)
    {
        astre_destroy(lst_astres[i]);
    }
    return 0;
}