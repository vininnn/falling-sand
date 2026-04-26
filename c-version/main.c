#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "grid.h"
#include "render.h"

// Globals
#define WIDTH 320
#define HEIGHT 240
#define SCALE 4

int main(){
    RenderContext graphics = init_graphics(WIDTH, HEIGHT, SCALE);
    Cell* world = init_grid(WIDTH, HEIGHT);

    bool running = true;
    SDL_Event event;

    while(running){
        while(SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT){
                running = false;
            }
        }

        render_frame(graphics, world, WIDTH, HEIGHT);
    }

    close_graphics(graphics);
    return 0;
}