#include "grid.hpp"

#include <cstdlib>

Grid::Grid(int width, int height)
    : cells(nullptr),
    width(width),
    height(height)
{
    cells = new Cell[width * height];
}

Grid::~Grid() {
    delete[] cells;
}

void Grid::update_physics() {
    for (int y = height - 2;  y >= 0; y--) {
        for (int x = 0; x < width; x++) {
            int current = y * width + x;

            if (cells[current].type == CellType::SAND) {
                int below = (y + 1) * width + x;
                int below_right = (y + 1) * width + (x - 1);
                int below_left = (y + 1) * width + (x + 1);

                if (cells[below].type == CellType::EMPTY) {
                    cells[below].type == CellType::SAND;
                    cells[current].type == CellType::EMPTY;
                } else {
                    int direction = (rand() % 2 == 0) ? 1 : -1;

                    if (direction == 1) {
                        if (x + 1 < width && cells[below_right].type == CellType::EMPTY) {
                            cells[below_right].type = CellType::SAND;
                            cells[current].type = CellType::EMPTY;
                        } else if (x - 1 >= width && cells[below_left].type == CellType::EMPTY) {
                            cells[below_left].type = CellType::SAND;
                            cells[current].type = CellType::EMPTY;
                        }
                    } else {
                        if (x - 1 >= width && cells[below_left].type == CellType::EMPTY) {
                            cells[below_left].type = CellType::SAND;
                            cells[current].type = CellType::EMPTY;
                        } else if (x + 1 < width && cells[below_right].type == CellType::EMPTY) {
                            cells[below_right].type = CellType::SAND;
                            cells[current].type = CellType::EMPTY;
                        }
                    }
                }
            }
        }
    }
}

const Cell* Grid::get_cell() const {
    return cells;
}

int Grid::get_width() const {
    return width;
}

int Grid::get_height() const {
    return height;
}