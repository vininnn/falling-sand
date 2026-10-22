#include "grid.hpp"

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

void Grid::update_physics(int width, int height) {

}