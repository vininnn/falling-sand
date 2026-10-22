#pragma once

enum class CellType {
    EMPTY,
    SAND
};

struct Cell {
    CellType type = CellType::EMPTY;
};

class Grid {
private:
    Cell* cells;
    int width;
    int height;

public:
    Grid(int width, int height);
    ~Grid();

    void update_physics();
};
