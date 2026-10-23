#include "grid.hpp"

#include <cstdlib>

Grid::Grid(int width, int height)
    : cells_(nullptr),
    width_(width),
    height_(height)
{
    cells_ = new Cell[width * height];
}

Grid::~Grid() {
    delete[] cells_;
}

void Grid::update_physics() {
    for (int y = height_ - 2;  y >= 0; y--) {
        for (int x = 0; x < width_; x++) {
            int current = y * width_ + x;

            if (cells_[current].type == CellType::SAND) {
                int below = (y + 1) * width_ + x;
                int below_left = (y + 1) * width_ + (x - 1);
                int below_right = (y + 1) * width_ + (x + 1);

                if (cells_[below].type == CellType::EMPTY) {
                    cells_[below].type = CellType::SAND;
                    cells_[current].type = CellType::EMPTY;
                } else {
                    int direction = (rand() % 2 == 0) ? 1 : -1;

                    if (direction == 1) {
                        if (x + 1 < width_ && cells_[below_right].type == CellType::EMPTY) {
                            cells_[below_right].type = CellType::SAND;
                            cells_[current].type = CellType::EMPTY;
                        } else if (x - 1 >= 0 && cells_[below_left].type == CellType::EMPTY) {
                            cells_[below_left].type = CellType::SAND;
                            cells_[current].type = CellType::EMPTY;
                        }
                    } else {
                        if (x - 1 >= 0 && cells_[below_left].type == CellType::EMPTY) {
                            cells_[below_left].type = CellType::SAND;
                            cells_[current].type = CellType::EMPTY;
                        } else if (x + 1 < width_ && cells_[below_right].type == CellType::EMPTY) {
                            cells_[below_right].type = CellType::SAND;
                            cells_[current].type = CellType::EMPTY;
                        }
                    }
                }
            }
        }
    }
}

bool Grid::in_bounds(int x, int y) const {
    return x >= 0 && x < width_ && y >= 0 && y < height_;
}

void Grid::set_cell(int x, int y, CellType type) {
    if (!in_bounds(x, y)) {
        return;
    }
    
    cells_[y * width_ + x].type = type;
}

const Cell& Grid::get_cell(int x, int y) const {
    return cells_[y * width_ + x];
}

const Cell* Grid::get_cells() const {
    return cells_;
}

int Grid::get_width() const {
    return width_;
}

int Grid::get_height() const {
    return height_;
}