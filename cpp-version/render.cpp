#include "render.hpp"

#include <iostream>
#include <SDL2/SDL.h>

RenderContext::RenderContext(int logical_width, int logical_height, int scale)
    : window_(nullptr),
    renderer_(nullptr)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Error SDL: " << SDL_GetError() << "\n";
        return;
    }

    int real_width = logical_width * scale;
    int real_height = logical_height * scale;

    SDL_CreateWindowAndRenderer(
        real_width, 
        real_height, 
        0, 
        &window_, 
        &renderer_
    );

    if (!window_ || !renderer_) {
        std::cerr << "Error build/render window.\n";
        return;
    }

    SDL_RenderSetScale(renderer_, scale, scale);
}

RenderContext::~RenderContext() {}

void RenderContext::render_frame(const Grid& grid) {
    SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
    SDL_RenderClear(renderer_);

    const Cell* cells = grid.get_cells();
    int height = grid.get_height();
    int width = grid.get_width();
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = y * width + x;

            if (cells[index].type == CellType::SAND) {
                SDL_SetRenderDrawColor(renderer_, 194, 178, 128, 255);
                SDL_RenderDrawPoint(renderer_, x, y);
            }
        }
    }

    SDL_RenderPresent(renderer_);
}

void RenderContext::close_graphics() {
    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(window_);
    SDL_Quit();
}