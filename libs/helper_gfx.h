#ifndef HEADER_HELPER_GFX
#define HEADER_HELPER_GFX

#include <SDL2/SDL.h>
#include <stdint.h>

#define COLOR_GET_B(color) (color & 0xff)
#define COLOR_GET_G(color) ((color >> 8) & 0xff)
#define COLOR_GET_R(color) ((color >> 16) & 0xff)

#define COLOR_BLACK  0x00000000
#define COLOR_RED    0x00FF0000
#define COLOR_GREEN  0x0000FF00
#define COLOR_BLUE   0x000000FF
#define COLOR_WHITE  0x00FFFFFF
#define COLOR_YELLOW 0x00FFFF00

#define COLOR_ORANGE 0x00FEBA49
#define COLOR_DARK_GRAY 	 0x001E1E1E
#define COLOR_GRAY 	 0x00757575

// Draw circle
void draw_circle(SDL_Renderer * renderer, int32_t centreX, int32_t centreY, int32_t radius);

// Draw circle filled with color
int32_t draw_fill_circle(SDL_Renderer * renderer, int32_t x, int32_t y, int32_t radius);

// Draw circle with color
void draw_circle_color(SDL_Renderer * renderer, int32_t centreX, int32_t centreY, int32_t radius,uint32_t color);

// Draw circle with color
void draw_fill_circle_color(SDL_Renderer * renderer, int32_t centreX, int32_t centreY, int32_t radius,uint32_t color);

// Draw line betwen two point with color
void draw_line_color(SDL_Renderer * renderer, int32_t x1, int32_t y1, int32_t x2,int32_t y2,uint32_t color);

void draw_point_color(SDL_Renderer * renderer,int32_t x,int32_t y,uint32_t color);

#endif