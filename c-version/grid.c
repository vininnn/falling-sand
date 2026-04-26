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

void update_physics(Cell* grid, int width, int height){}