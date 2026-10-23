#include "render.hpp"
#include "grid.hpp"

#include <SDL2/SDL.h>

RenderContext::RenderContext(int logical_width, int logical_height, int scale)
    : window(nullptr),
    renderer(nullptr)
{

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Error SDL: %s\n", SDL_GetError());
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

    if (window || renderer) {
        printf("Error build/render window.\n");
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
    
    // Array linear (width * height * sizeof(Cell))
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = y * width + x; // Maping 2D into 1D

            if (cells[index].type == CellType::SAND) {
                SDL_SetRenderDrawColor(renderer, 194, 178, 128, 1);
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