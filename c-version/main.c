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

            if (event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEMOTION){
                int rawX = 0;
                int rawY = 0;
                bool paint = false;
                
                if (event.type == SDL_MOUSEBUTTONDOWN){
                    rawX = event.button.x;
                    rawY = event.button.y;
                    paint = true;
                }  else if (event.type == SDL_MOUSEMOTION){
                    if (event.motion.state & SDL_BUTTON_LMASK){
                        rawX = event.motion.x;
                        rawY = event.motion.y;
                        paint = true;
                    }
                }

                if (paint){
                    int mouseX = rawX / SCALE;
                    int mouseY = rawY / SCALE;

                    if (mouseX >= 0 && mouseX < WIDTH && mouseY >= 0 && mouseY < HEIGHT){
                        int index = mouseY * WIDTH + mouseX;
                        world[index].type = SAND;
                    }
                }
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