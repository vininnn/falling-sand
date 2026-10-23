#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#include "grid.h"
#include "render.h"

// Globals
#define WIDTH 320
#define HEIGHT 240
#define SCALE 4

int main(){
    srand(time(NULL));
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
    
        int rawX, rawY;
        Uint32 mouseState = SDL_GetMouseState(&rawX, &rawY);

        if (mouseState & SDL_BUTTON(SDL_BUTTON_LEFT)){
            int mouseX = rawX / SCALE;
            int mouseY = rawY / SCALE;
        
            if (mouseX >= 0 && mouseX < WIDTH && mouseY >= 0 && mouseY < HEIGHT){
                int index = mouseY * WIDTH + mouseX;
                world[index].type = SAND;
            }
        }

        update_physics(world, WIDTH, HEIGHT);
        render_frame(graphics, world, WIDTH, HEIGHT);

        // render delay
        SDL_Delay(16);
    }

    close_graphics(graphics);
    return 0;
}