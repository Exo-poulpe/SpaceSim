
#include "Astre.h"



astre* astre_create(char* name, double mass,vector speed,uint32_t size,point position,uint32_t color)
{
    astre* a = malloc(1 * sizeof(astre));
    a->name = name;
    a->mass = mass;
    a->speed = speed;
    a->size = size;
    a->position_actual = position;
    a->position_old = stack_create(mass * 20);
    a->delta = point_init(0,0);
    a->color = color;
    return a;
}

void astre_print(astre* a)
{
    printf("Name : %s  Mass : %g  Speed : (%lf, %lf°)  Position : {%.2lf, %.2lf}\n",a->name,a->mass,
           vector_cart_to_polar(a->speed).x,vector_cart_to_polar(a->speed).y,a->position_actual.x,a->position_actual.y);
}

void astre_destroy(void* astr)
{
    astre* a = astr;
    a->name = NULL;
    a->mass = -1;
    vector_destroy(&a->speed);
    point_destroy(&a->position_actual);
    stack_destroy(a->position_old,point_destroy);
    a->color = 0;
    free(a);
}

void draw_gravity_force(lst_vector* lst_astres,uint32_t size,SDL_Renderer * renderer)
{
    
    uint32_t index = astre_get_index_most_mass_astre(lst_astres,size);

    for(uint32_t i=0; i<size; i+=1)
    {
        if(i==index)
        {
            continue;
        }
        astre* a = lst_vector_get(lst_astres,i);
        astre* b = lst_vector_get(lst_astres,index);
        draw_line_color(renderer,b->position_actual.x,b->position_actual.y,a->position_actual.x,a->position_actual.y,COLOR_WHITE);
    }
}

double astre_get_distance_x(astre* a,astre* b)
{
    return (a->position_actual.x - b->position_actual.x) * 3;
}

double astre_get_distance_y(astre* a,astre* b)
{
    return (a->position_actual.y - b->position_actual.y) * 3;
}

double astre_get_distance_hyp(astre* a,astre* b)
{
    return sqrt( pow(astre_get_distance_x(a,b),2) + pow(astre_get_distance_y(a,b),2) );
}

uint32_t astre_get_index_most_mass_astre(lst_vector* lst_astres,uint32_t size)
{
    uint32_t index = 0;
    for(uint32_t i=0; i<size; i+=1)
    {
        astre* a = lst_vector_get(lst_astres,i);
        astre* b = lst_vector_get(lst_astres,index);
        if(a->mass > b->mass)
        {
            index = i;
        }
    }
    return index;
}

void astre_get_velocity_from_position(astre* a,astre* most_astre)
{
    // var deg = Math.atan2(y - focusedObject.y, x - focusedObject.x);
    double deg = atan2( astre_get_distance_y(a,most_astre) ,astre_get_distance_x(a,most_astre)  ) * 2;

    double velocity_ref = sqrt(a->mass / sqrt(pow( astre_get_distance_x(a,most_astre) , 2) + pow(astre_get_distance_y(a,most_astre), 2)));

    a->speed.x += (cos(deg + M_PI / 2) * velocity_ref);
    a->speed.y +=  (sin(deg + M_PI / 2) * velocity_ref);
}


double astre_get_radius(astre* a)
{
    return cbrt( a->mass * 200 ) / (4/3*M_PI);
}

double astre_get_speed_norm(astre* a)
{
    return sqrt( pow(a->speed.x,2) + pow(a->speed.y,2));
}

double aster_get_momentum(astre* a)
{
    return astre_get_speed_norm(a) * a->mass;
}

void astre_force_compute(lst_vector* lst_astres,uint32_t size)
{
    for(uint32_t i=0;i<size;i+=1)
    {
        astre* a = lst_vector_get(lst_astres,i);
        for(uint32_t j=0;j<size;j+=1)
        {
            astre* b = lst_vector_get(lst_astres,j);
            if(a->name == b->name){continue;}
            double distance = astre_get_distance_hyp(a,b);

            double mass_angle = atan2(b->position_actual.y - a->position_actual.y,
                                        b->position_actual.x - a->position_actual.x);

            a->delta.x += cos(mass_angle) * (b->mass/pow(distance,2));
            a->delta.y += sin(mass_angle) * (b->mass/pow(distance,2));
        }
    }
}

void astre_apply_force(lst_vector* lst_astres,uint32_t size)
{

    uint32_t index_most_massiv = astre_get_index_most_mass_astre(lst_astres,size);
    for(uint32_t i=0;i<size;i+=1)
    {
        astre* a = lst_vector_get(lst_astres,i);
        a->speed.x += a->delta.x * 1;
        a->speed.y += a->delta.y * 1;


        a->position_actual.x += a->speed.x;
        a->position_actual.y += a->speed.y;
        
        if(i != index_most_massiv)
        {
            // printf("%s : x : %g, y = %g\n",a->name, a->position_actual.x, a->position_actual.y);
            double x,y;
            x = a->position_actual.x;
            y = a->position_actual.y;
            // printf("%g, %g\n",x,y);
            point* tmp = malloc(1 * sizeof(point));
            tmp->x = x;
            tmp->y = y;
            // printf("tmp :: %g, %g\n",tmp->x,tmp->y);

            stack_push(a->position_old,tmp,point_destroy);
            // point* p = stack_get(a->position_old,0);
            // printf("p :: %g, %g\n",p->x,p->y);
            free(tmp);
        }

        // a->position_actual = point_polar_vector_to_cart(a->position_actual);

        a->delta.x = 0;
        a->delta.y = 0;
    }
}

void astre_list_speed(lst_vector* lst_astres, uint32_t size)
{
    for(uint32_t i=0;i<size;i+=1)
    {
        astre* a = lst_vector_get(lst_astres,i);
        for(uint32_t j=0;j<size;j+=1)
        {
            astre* b = lst_vector_get(lst_astres,j);
            point distance = point_sub(a->position_actual,b->position_actual);
            double ndistance = point_norm(distance);
            double v = sqrt((G * a->mass) / ndistance);
            vector vu = vector_init(-distance.y / ndistance, distance.x / ndistance);
            // vector_init(&vu, -distance.y / ndistance, distance.x / ndistance);
            vu = vector_smul(vu, v);
            b->speed = vu;
        }
    }
    
}

void astre_draw_old_point(SDL_Renderer * renderer,astre* a)
{
    for(uint32_t j=0;j<stack_length(a->position_old);j+=1)
    {
        // printf("%s : x = %g, y = %g\n",a[i]->name,((point*)stack_get(a[i]->position_old,j))->x,((point*)stack_get(a[i]->position_old,j))->y);

        draw_point_color(renderer,((point*)stack_get(a->position_old,j))->x,
        (*(point*)stack_get(a->position_old,j)).y,a->color);
    }

}

void astre_draw_random_asteroid(lst_vector* lst_astres,uint32_t* size,uint32_t chance,double max_mass_asteroid,uint32_t x,uint32_t y,uint32_t position_offset)
{
    if((uint32_t)rand() % 100 < chance)
    {
        uint32_t start_x = rand()%x + position_offset;
        uint32_t start_y = rand()%y + position_offset;
        point tmp_position = point_init(start_x,start_y);

        double mass = drand48();
        if(mass > max_mass_asteroid){mass -= max_mass_asteroid;}
        if(mass < 0){mass = 1;}
        vector tmp_speed = vector_init(rand()%2,rand()%2);

        uint32_t val_name = rand()%INT_MAX;
        char name[20];
        snprintf(name,20,"%u",val_name);
        
        astre* atmp  = astre_create((char*)name,mass,tmp_speed,1,tmp_position,COLOR_GRAY);
        lst_astres = lst_vector_push(lst_astres,(void*)atmp);
        *size += 1;
    }
}


int astre_window(lst_vector* lst_astres,uint32_t size,uint32_t speed)
{
    assert(lst_astres != NULL);

    if (SDL_Init(SDL_INIT_VIDEO) == 0)
    {
        SDL_Window* win = NULL;
        SDL_Renderer* renderer = NULL;

        SDL_DisplayMode DM;
        SDL_GetCurrentDisplayMode(0, &DM);
        int posX = 10, posY = 10, width = DM.w, height = DM.h;

        win = SDL_CreateWindow("SpaceSim", posX, posY, width, height, 0);
        renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
        
        if(win == NULL || renderer == NULL)
        {
            return 0;
        }
        SDL_SetWindowFullscreen(win,1);
        SDL_bool done = SDL_FALSE;


        while (!done)
        {
            SDL_Event event;

            SDL_SetRenderDrawColor(renderer, COLOR_GET_R(COLOR_DARK_GRAY), COLOR_GET_G(COLOR_DARK_GRAY), COLOR_GET_B(COLOR_DARK_GRAY), SDL_ALPHA_OPAQUE);
            SDL_RenderClear(renderer);

            uint32_t most_massiv = astre_get_index_most_mass_astre(lst_astres,size);
            // printf("most massiv : %s\n",((astre*)lst_vector_get(lst_astres,most_massiv))->name);


            for(uint32_t i=0; i<size; i+=1)
            {
                astre* a = lst_vector_get(lst_astres,i);
                // astre_print(a[i]);

                draw_fill_circle_color(renderer, a->position_actual.x, a->position_actual.y,a->size,a->color);
                
                // printf("%s => len : %u\n",a[i]->name,stack_length(a[i]->position_old));
                if(i == most_massiv){continue;}
                astre_draw_old_point(renderer, a);
            }

            // draw_gravity_force(lst_astres,size,renderer);

            SDL_RenderPresent(renderer);

            #ifdef _WIN32
            Sleep(1000/speed);
            #else
            usleep(1000000/speed);
            #endif

            astre_force_compute(lst_astres,size);
            astre_apply_force(lst_astres,size);
            // astre_draw_random_asteroid(lst_astres,&size,200,3,50,50,50);

            while (SDL_PollEvent(&event))
            {
                switch(event.type)
                {
                case SDL_SCANCODE_ESCAPE:
                case SDLK_ESCAPE:
                    done = SDL_TRUE; // set game state to done,(do what you want here)
                    break;
                case SDL_QUIT:
                    done = SDL_TRUE; // set game state to done,(do what you want here)
                    break;
                default:
                    break;
                }
                // if (event.type == SDL_Quit)
                // {
                //     done = SDL_TRUE;
                // }
            }
        }

        if (renderer)
        {
            SDL_DestroyRenderer(renderer);
        }
        if (win)
        {
            SDL_DestroyWindow(win);
        }
    }
    SDL_Quit();
    return 0;
}
