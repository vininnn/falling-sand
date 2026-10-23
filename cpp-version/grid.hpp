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
    Cell* cells_;
    int width_;
    int height_;

public:
    Grid(int width, int height);
    ~Grid();

    void update_physics();
    
    bool in_bounds(int x, int y) const;

    // setter
    void set_cell(int x, int y, CellType type);

    // getter
    const Cell& get_cell(int x, int y) const;
    const Cell* get_cells() const;
    int get_width() const;
    int get_height() const;
};
