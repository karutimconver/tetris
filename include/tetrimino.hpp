#pragma once

#include "raylib.h"
#include "grid.hpp"
#include "globals.hpp"
#include <array>
#include <unordered_map>

class Tetrimino {
protected:
    unsigned short int color;
    unsigned short int rotation_state = 0;
    std::unordered_map<int, std::array<std::array<int, 2>, 4>> cells;
    Vector2 position;
public:
    Tetrimino();
    void update();
    void rotate();
    void draw(Grid* grid);
};

class LTetrimino : public Tetrimino {
public:
    LTetrimino();
};

class ReverseLTetrimino: public Tetrimino {
public:
    ReverseLTetrimino();
};
