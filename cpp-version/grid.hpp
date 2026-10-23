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
    
    const Cell* get_cell() const;
    int get_width() const;
    int get_height() const;
};
