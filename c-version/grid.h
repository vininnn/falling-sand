#ifndef GRID_H
#define GRID_H

typedef enum {
    EMPTY = 0,
    SAND = 1,
    WALL = 2,
} CellType;

typedef struct {
    CellType type;
} Cell;

Cell* init_grid(int width, int height);
void free_grid(Cell* grid);
void update_physics(Cell* grid, int width, int height);

#endif

