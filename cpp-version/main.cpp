#include "grid.hpp"
#include "render.hpp"

#include <cstdlib>
#include <ctime>
#include <SDL2/SDL.h>

int main() {
    constexpr int WIDTH = 320;
    constexpr int HEIGHT = 240;
    constexpr int SCALE = 4;
    
    std::srand(std::time(nullptr));

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
            world.set_cell(raw_x / SCALE, raw_y / SCALE, CellType::SAND);
        }

        world.update_physics();
        graphics.render_frame(world);

        // render delay
        SDL_Delay(16);
    }

    graphics.close_graphics();

    return 0;
}