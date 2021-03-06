#ifndef _GFX_H_
#define _GFX_H_

#include <stdint.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#define MAKE_COLOR(r,g,b) ((uint32_t)b|((uint32_t)g<<8)|((uint32_t)r<<16))

#define COLOR_GET_B(color) (color & 0xff)
#define COLOR_GET_G(color) ((color >> 8) & 0xff)
#define COLOR_GET_R(color) ((color >> 16) & 0xff)

#define COLOR_BLACK  0x00000000
#define COLOR_RED    0x00FF0000
#define COLOR_GREEN  0x0000FF00
#define COLOR_BLUE   0x000000FF
#define COLOR_WHITE  0x00FFFFFF
#define COLOR_YELLOW 0x00FFFF00

typedef unsigned int  uint;
typedef unsigned long ulong;
typedef unsigned char uchar;

struct gfx_context_t {
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *texture;
	uint32_t *pixels;
	int width;
	int height;
};

extern void gfx_putpixel(struct gfx_context_t *ctxt, int x, int y, uint32_t color);
extern void gfx_clear(struct gfx_context_t *ctxt, uint32_t color);
extern struct gfx_context_t* gfx_create(char *text, uint width, uint height);
extern void gfx_destroy(struct gfx_context_t *ctxt);
extern void gfx_present(struct gfx_context_t *ctxt);
extern SDL_Keycode gfx_keypressed();

// int ellipseRGBA(SDL_Renderer * renderer, int16_t x, int16_t y, int16_t rx, int16_t ry, uint8_t r, uint8_t g, uint8_t b, uint8_t a, int32_t f);
// int filledEllipseRGBA(SDL_Renderer * renderer, int16_t x, int16_t y, int16_t rx, int16_t ry, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
// int ellipseColor(SDL_Renderer * renderer, int16_t x, int16_t y, int16_t rx, int16_t ry, uint32_t color);
// int filledCircleColor(SDL_Renderer * renderer, int16_t x, int16_t y, int16_t rad, uint32_t color);
// int drawQuadrants(SDL_Renderer * renderer,  int16_t x, int16_t y, int16_t dx, int16_t dy, int32_t f);
// int vlineRGBA(SDL_Renderer * renderer, int16_t x, int16_t y1, int16_t y2, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
// int vlineColor(SDL_Renderer * renderer, int16_t x, int16_t y1, int16_t y2, uint32_t color);
// int vline(SDL_Renderer * renderer, int16_t x, int16_t y1, int16_t y2);
// int hlineRGBA(SDL_Renderer * renderer, int16_t x1, int16_t x2, int16_t y, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
// int hlineColor(SDL_Renderer * renderer, int16_t x1, int16_t x2, int16_t y, uint32_t color);
// int hline(SDL_Renderer * renderer, int16_t x1, int16_t x2, int16_t y);
// int pixelRGBA(SDL_Renderer * renderer, int16_t x, int16_t y, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
// int pixelColor(SDL_Renderer * renderer, int16_t x, int16_t y, uint32_t color);
// int pixel(SDL_Renderer *renderer, int16_t x, int16_t y);

#endif
