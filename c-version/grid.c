#include <stdlib.h>
#include "grid.h"

Cell* init_grid(int width, int height){
    Cell* grid = (Cell*) malloc(width * height * sizeof(Cell));

    if (grid != NULL){
        for(int i = 0; i < width * height; i++){
            grid[i].type = EMPTY;
        }
    }

    return grid;
}

void free_grid(Cell* grid){
    if (grid != NULL){
        free(grid);
    }
}

void update_physics(Cell* grid, int width, int height){
    for(int y = height - 2; y >= 0; y--){
        for(int x = 0; x < width; x++){
            int current = y * width + x;

            if (grid[current].type == SAND){
                int below = (y + 1) * width + x;

                if (grid[below].type == EMPTY){
                    grid[below].type = SAND;
                    grid[current].type = EMPTY;
                }
            }
        }    
    }
}