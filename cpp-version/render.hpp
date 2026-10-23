#pragma once

#include "grid.hpp"
#include <SDL2/SDL.h>

class RenderContext {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;

public:
    RenderContext(int logical_width, int logical_height, int scale);
    ~RenderContext();

    void render_frame(const Grid& grid);
    void close_graphics();
};