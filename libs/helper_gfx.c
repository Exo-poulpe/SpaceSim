#include "helper_gfx.h"


// Draw fill circle
int draw_fill_circle(SDL_Renderer * renderer, int32_t x, int32_t y, int32_t radius)
{
    int32_t offsetx, offsety, d;
    int32_t status;

    offsetx = 0;
    offsety = radius;
    d = radius -1;
    status = 0;

    while (offsety >= offsetx) {

        status += SDL_RenderDrawLine(renderer, x - offsety, y + offsetx,
                                     x + offsety, y + offsetx);
        status += SDL_RenderDrawLine(renderer, x - offsetx, y + offsety,
                                     x + offsetx, y + offsety);
        status += SDL_RenderDrawLine(renderer, x - offsetx, y - offsety,
                                     x + offsetx, y - offsety);
        status += SDL_RenderDrawLine(renderer, x - offsety, y - offsetx,
                                     x + offsety, y - offsetx);

        if (status < 0) {
            status = -1;
            break;
        }

        if (d >= 2*offsetx) {
            d -= 2*offsetx + 1;
            offsetx +=1;
        }
        else if (d < 2 * (radius - offsety)) {
            d += 2 * offsety - 1;
            offsety -= 1;
        }
        else {
            d += 2 * (offsety - offsetx - 1);
            offsety -= 1;
            offsetx += 1;
        }
    }

    return status;
}


// Draw circle
void draw_circle(SDL_Renderer * renderer, int32_t centreX, int32_t centreY, int32_t radius)
{
   const int32_t diameter = (radius * 2);

   int32_t x = (radius - 1);
   int32_t y = 0;
   int32_t tx = 1;
   int32_t ty = 1;
   int32_t error = (tx - diameter);

   while (x >= y)
   {
      //  Each of the following renders an octant of the circle
      SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
      SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
      SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
      SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
      SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
      SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
      SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
      SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);

      if (error <= 0)
      {
         ++y;
         error += ty;
         ty += 2;
      }

      if (error > 0)
      {
         --x;
         tx += 2;
         error += (tx - diameter);
      }
   }
}

// Draw circle with color
void draw_circle_color(SDL_Renderer * renderer, int32_t centreX, int32_t centreY, int32_t radius,uint32_t color)
{
	SDL_SetRenderDrawColor(renderer,COLOR_GET_R(color),
	COLOR_GET_G(color),COLOR_GET_B(color),SDL_ALPHA_OPAQUE);
	draw_circle(renderer,  centreX, centreY, radius);
}

// Draw circle filled with color
void draw_fill_circle_color(SDL_Renderer * renderer, int32_t centreX, int32_t centreY, int32_t radius,uint32_t color)
{
	SDL_SetRenderDrawColor(renderer,COLOR_GET_R(color),
	COLOR_GET_G(color),COLOR_GET_B(color),SDL_ALPHA_OPAQUE);
	draw_fill_circle(renderer,  centreX, centreY, radius);
}

// Draw line betwen two point with color
void draw_line_color(SDL_Renderer * renderer, int32_t x1, int32_t y1, int32_t x2,int32_t y2,uint32_t color)
{
	SDL_SetRenderDrawColor(renderer,COLOR_GET_R(color),
	COLOR_GET_G(color),COLOR_GET_B(color),SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

void draw_point_color(SDL_Renderer * renderer,int32_t x,int32_t y,uint32_t color)
{
    SDL_SetRenderDrawColor(renderer,COLOR_GET_R(color),
	COLOR_GET_G(color),COLOR_GET_B(color),SDL_ALPHA_OPAQUE);
	SDL_RenderDrawPoint(renderer, x, y);
}
