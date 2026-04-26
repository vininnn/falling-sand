#include <stdio.h>
#include "render.h"

RenderContext init_graphics(int logical_width, int logical_height, int scale){
    RenderContext context = {NULL, NULL};

    if (SDL_Init(SDL_INIT_VIDEO) > 0){
        printf("Error SDL: %s\n", SDL_GetError());
        return context;
    }

    int real_width = logical_width * scale;
    int real_height = logical_height * scale;

    SDL_CreateWindowAndRenderer(real_width, real_height, 0, &context.window, &context.renderer);

    if (!context.window || !context.renderer){
        printf("Error build/render window.\n");
        return context;
    }

    SDL_RenderSetScale(context.renderer, scale, scale);

    return context;
}

void render_frame(RenderContext context, Cell* world, int widht, int height){
    SDL_SetRenderDrawColor(context.renderer, 0, 0, 0, 255);
    SDL_RenderClear(context.renderer);
    
    // Array linear (width * height * sizeof(Cell))
    for(int y = 0; y < height; y++){
        for(int x = 0; x < widht; x++){
            int index = y * widht + x; // Maping 2D into 1D

            SDL_SetRenderDrawColor(context.renderer, 255, 255, 255, 255);
            SDL_RenderDrawPoint(context.renderer, x, y);
        
        }
    }

    SDL_RenderPresent(context.renderer);
}

void close_graphics(RenderContext context){
    SDL_DestroyRenderer(context.renderer);
    SDL_DestroyWindow(context.window);
    SDL_Quit();
}