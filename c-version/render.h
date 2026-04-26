#ifndef RENDER_H
#define RENDER_H

#include <SDL2/SDL.h>
#include <stdbool.h>
#include "grid.h"

typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
} RenderContext;

RenderContext init_graphics(int logical_width, int logical_height, int scale);
void render_frame(RenderContext context, Cell* world, int widht, int height);
void close_graphics(RenderContext context);

#endif