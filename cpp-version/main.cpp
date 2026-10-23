#include "grid.hpp"
#include "render.hpp"

#include <stdlib.h>
#include <time.h>

#include <SDL2/SDL.h>

int main() {
    constexpr int WIDTH = 320;
    constexpr int HEIGHT = 240;
    constexpr int SCALE = 4;
    
    srand(time(NULL));

    Grid world(WIDTH, HEIGHT);
    RenderContext graphics(WIDTH, HEIGHT, SCALE);

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }
    
        int raw_x, raw_y;
        Uint32 mouseState = SDL_GetMouseState(&raw_x, &raw_y);

        if (mouseState & SDL_BUTTON(SDL_BUTTON_LEFT)) {
            int mouse_x = raw_x / SCALE;
            int mouse_y = raw_y / SCALE;
        
            if (mouse_x >= 0 && mouse_x < WIDTH && mouse_y >= 0 && mouse_y < HEIGHT) {
                world.set_cell(mouse_x, mouse_y, CellType::SAND);
            }
        }

        world.update_physics();
        graphics.render_frame(world);

        // render delay
        SDL_Delay(16);
    }

    graphics.close_graphics();

    return 0;
}