#include "render.hpp"
#include "grid.hpp"

#include <iostream>
#include <SDL2/SDL.h>

RenderContext::RenderContext(int logical_width, int logical_height, int scale)
    : window(nullptr),
    renderer(nullptr)
{

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Error SDL: " << SDL_GetError() << "\n";
        return;
    }

    int real_width = logical_width * scale;
    int real_height = logical_height * scale;

    SDL_CreateWindowAndRenderer(
        real_width, 
        real_height, 
        0, 
        &window, 
        &renderer
    );

    if (!window || !renderer) {
        std::cout << "Error build/render window.\n";
        return;
    }

    SDL_RenderSetScale(renderer, scale, scale);

    return;
}

RenderContext::~RenderContext() {}

void RenderContext::render_frame(const Grid& grid) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    const Cell* cells = grid.get_cell();
    int height = grid.get_height();
    int width = grid.get_width();
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = y * width + x;

            if (cells[index].type == CellType::SAND) {
                SDL_SetRenderDrawColor(renderer, 194, 178, 128, 255);
                SDL_RenderDrawPoint(renderer, x, y);
            }
        }
    }

    SDL_RenderPresent(renderer);
}

void RenderContext::close_graphics() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}